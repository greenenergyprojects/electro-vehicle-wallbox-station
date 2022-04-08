#include "gdb.hpp"
#include "sys.hpp"
#include "app.hpp"

#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>


// https://sourceware.org/gdb/current/onlinedocs/gdb/Overview.html#Overview
// https://www.embecosm.com/appnotes/ean4/embecosm-howto-rsp-server-ean4-issue-2.html
// https://github.com/buserror/simavr
// https://www.codeproject.com/Articles/5160447/Creating-and-Debugging-Arduino-Programs-in-Visua-2

namespace gdb {

	#ifdef GLOBAL_GDB

	struct Gdb gdb;

	void sendResponse ();

	// ------------------------------------------------------------------------

	void init () {
		memset((void *)&gdb, 0, sizeof(gdb));
	}

	void /* __attribute__((optimize("O0"))) */ main () {
		struct Buffer *p = &gdb.buf;
		cli();
		if (p->state == exec || p->state == execovf) {
			uint8_t sum = 0;
			uint8_t i;
			for (i = 0; i < p->rpos; i++) {
				char c = p->buffer[i];
				sum += c;
				if (c == ':') {
					break;
				}
			}
			p->wpos = 0;
			p->state = send;
			sei();
			p->buffer[(p->rpos < 64) ? p->rpos : 64] = 0;
			printf("\n\r{i=%d,sum=%02x}:%s\n\r", i, sum, p->buffer);
			// https://sourceware.org/gdb/current/onlinedocs/gdb/General-Query-Packets.html
			if (i == 10 && sum == 0x71) { // qSupported:
				p->wpos = sprintf(p->buffer, "PacketSize=%d;QNonStop+", BUFFER_SIZE);
			} else if (i == 1 && sum == 0x3f) { // ?
				// p->wpos = sprintf(p->buffer, "S05");
				p->wpos = sprintf(p->buffer, "OK");
			} else if ((i == 4 && sum == 0x09) // Hc-1
			       || (i == 3 && sum == 0xdf)  // Hg0
				   || (i == 4 && sum == 0xf0)  // Hg-1
				   || (i == 10 && sum == 0x33) // vKill)
				   || (i == 8 && sum == 0x5c) // QNonStop:1
				   || (i == 1 && sum == 0x44) // D (gdb command detach)
				   || (i == 7  && sum == 0x21)) { // qSymbol
				p->wpos = sprintf(p->buffer, "OK");
			} else if (i == 8 && sum == 0x4b) { // qOffset
				p->wpos = sprintf(p->buffer, "Text=0;Data=0;Bss=0");
			} else if (i == 1 && sum == 0x67) { // g
				p->wpos = 72;
				for (i = 0; i < 72; i++) {
					p->buffer[i] = '0';
				}
			} else if (i == 8 && sum == 0x5c) { // QNonStop:0
				p->wpos = sprintf(p->buffer, "E00");
			} else if (i == 12 && sum==0xbb) { // qfThreadInfo
				p->wpos = sprintf(p->buffer, "m1"); // start ThreadInfo list thith thread 1
			} else if (i == 12 && sum==0xc8) { // qsThreadInfo
				p->wpos = sprintf(p->buffer, "l"); // end of ThreadInfo list
			} else if (i == 9 && sum==0x8f) { // qAttached
				p->wpos = sprintf(p->buffer, "1"); // attached to existing process
			} else if (i == 8 && sum == 0x49) { // qTStatus
				p->wpos = sprintf(p->buffer, "T0;tnotrun:0"); // No trace has been run yet.
			}

			// (i==4 && sum == 0x81) // qTfV



		} else if (p->state == send) {
			sei();
			sendResponse();

		} else {
			sei();
		}


	}

	void sendResponse () {
		cli(); {
			gdb.buf.state = waitack;
		} sei();
	 	uint8_t chkSum = 0;
		fputc('$', GLOBAL_GDB_STDOUT);
		char *p = gdb.buf.buffer;
		for (uint8_t i = 0; i < gdb.buf.wpos; i++) {
			char c = *p++;
			if (c == '$' || c== '#' || c == '}') {
				fputc('}', GLOBAL_GDB_STDOUT);
				chkSum += c;
				c ^= 0x20;
			}
			fputc(c, GLOBAL_GDB_STDOUT);
			chkSum += c;
		}
		fprintf(GLOBAL_GDB_STDOUT, "#%02x", chkSum);
	}

	void incUint8Cnt (uint8_t *cnt) {
		if ((*cnt) < 0xff) {
			(*cnt)++;
		}
	}

	void reset () {
		memset((void *)&gdb.buf, 0, sizeof(gdb.buf) - BUFFER_SIZE);
	}

	void pushRecivedByte (uint8_t b) {
		struct Buffer *p = &gdb.buf;
		if (p->rpos == BUFFER_SIZE ) {
			incUint8Cnt(&gdb.errCnt);
			p->rpos++;
		} else if (p->rpos < BUFFER_SIZE) {
			p->buffer[p->rpos++] = b;
		}
	}

	void handleUartIsrByte (char c) {
		struct Buffer *p = &gdb.buf;
		if (c == 0x03) { // CTRL-C}
			if (p->state != idle) {
				p->state = ctrlc;
			}
		} else if (c == '$') {
			if (p->state != idle) {
				incUint8Cnt(&gdb.errCnt);
			}
			reset();
			p->state = data;

		} else {
			switch (p->state) {
				case data: {
					if (c == '#') {
						p->state = chk1;
					} else {
						p->chkSum += c;
						if (c == '}') {
							p->state = esc;
						} else {
							pushRecivedByte(c);
						}
					}
					break;
				}

				case esc: {
					p->chkSum += c;
					pushRecivedByte(c ^ 0x20);
					p->state = data;
					break;
				}

				case chk1: {
					int8_t v = sys::hexValueFromChar(c);
					if (v < 0) {
						p->state = chk2err;
					} else {
						p->chkSum -= (v << 4);
						p->state = chk2;
					}
					break;
				}

				case chk2: {
					int8_t v = sys::hexValueFromChar(c);
					if (v >= 0) {
						p->chkSum -= v;
					}
					if (v < 0 || p->chkSum != 0) {
						incUint8Cnt(&gdb.errCnt);
						fputc('-', GLOBAL_GDB_STDOUT);
						reset();

					} else {
						p->state = p->rpos <= BUFFER_SIZE ? exec : execovf;
						fputc('+', GLOBAL_GDB_STDOUT);

					}
					break;
				}

				case waitack: {
					if (c == '-') {
						p->state = send;
					} else  {
						if (c != '+') {
							incUint8Cnt(&gdb.errCnt);
						}
						reset();
					}
					break;
				}


				default: case exec: case execovf: case send: {
					incUint8Cnt(&gdb.errCnt);
					reset();
					break;
				}
			}
		}

	}



	#endif // GLOBAL-GDB

}
