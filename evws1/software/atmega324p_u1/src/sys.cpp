
#include "global.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <util/delay.h>

#include "sys.hpp"
#include "mon.hpp"
#include "app.hpp"

FILE *uart0out;
FILE *uart0in;
FILE *uart1out;
FILE *uart1in;


namespace sys {

	struct Sys sys;

	#ifdef GLOBAL_MONITOR

	const uint8_t MONITOR_FLAG_LINEMODE = 0x01;
	const uint8_t MONITOR_FLAG_LINE     = 0x02;
	const uint8_t MONITOR_FLAG_CONT     = 0x04;

	const uint8_t MONITOR_CTRL_C = 0x03;
	const uint8_t MONITOR_CTRL_X = 0x18;
	const uint8_t MONITOR_CTRL_Y = 0x19;

	struct SysMonitor {
		uint8_t flags;
		uint8_t lineIndex;
		uint8_t cursorPos;
		char cmdLine[40];
	};
	struct SysMonitor sysMonitor;

	int8_t moncmd_help (uint8_t argc, char *argv[]);
	int8_t moncmd_sinfo (uint8_t argc, char *argv[]);
	int8_t moncmd_hexdump (uint8_t argc, char *argv[]);
	int8_t moncmd_setmem (uint8_t argc, char *argv[]);

	// globale Konstante im Flash
	const char MON_PMEM_ERR0[] PROGMEM = "Error ";
	const char MON_PMEM_ERR1[] PROGMEM = "Error: Unknown command\n\r";
	const char MON_PMEM_ERR2[] PROGMEM = " -> Syntax error\n\rUsage: ";
	const char MON_PMEM_CMD_HELP[] PROGMEM = "help\0Use help[command] for more...\0help [command]";
	#ifdef GLOBAL_MONCMD_SINFO
		const char MON_PMEM_CMD_SINFO[] PROGMEM = "sinfo\0Systeminformation\0sinfo";
	#endif
	#ifdef GLOBAL_MONCMD_HEXDUMP
		const char MON_PMEM_CMD_HEXDUMP[] PROGMEM = "hexdump\0Hexdump of memory content\0hexdump {f|s|e} start [length]";
	#endif // GLOBAL_MONCMD_HEXDUMP
	#ifdef GLOBAL_MONCMD_SETMEM
		const char MON_PMEM_CMD_SETMEM[] PROGMEM = "setmem\0Write bytes into SRAM/EEPROM\0setmem [s|e] address value";
	#endif // GLOBAL_MONCMD_SETMEM

	const struct mon::MonCmdInfo MON_PMEMSTR_CMDS[] PROGMEM = {
		  { MON_PMEM_CMD_HELP, moncmd_help }
		#ifdef GLOBAL_MONCMD_SINFO
		, { MON_PMEM_CMD_SINFO, moncmd_sinfo }
		#endif // GLOBAL_MONCMD_SINFO
		#ifdef GLOBAL_MONCMD_HEXDUMP
		, { MON_PMEM_CMD_HEXDUMP, moncmd_hexdump }
		#endif // GLOBAL_MONCMD_HEXDUMP
		#ifdef GLOBAL_MONCMD_SETMEM
		, { MON_PMEM_CMD_SETMEM, moncmd_setmem }
		#endif // GLOBAL_MONCMD_SETMEM
	};

	#endif // GLOBAL_MONITOR

	static FILE sys_uart0_out;
	static FILE sys_uart0_in;
	static FILE sys_uart1_out;
	static FILE sys_uart1_in;

	int uart0_putch (char c, FILE *f);
	int uart0_getch (FILE *f);
	int uart1_putch (char c, FILE *f);
	int uart1_getch (FILE *f);

	int uart_putch (char c, FILE *f);
	int uart_getch (FILE *f);
	void monMain ();


	void init () {
		memset((void *)&sys, 0, sizeof(sys));

		UBRR0L = (F_CPU / GLOBAL_UART0_BITRATE + 4) / 8 - 1;
		UBRR0H = 0x00;
		UCSR0A = (1 << U2X0);
		UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
		UCSR0B = (1 << RXCIE0) | (1 << TXEN0) | (1 << RXEN0);

		UBRR1L = (F_CPU / GLOBAL_UART1_BITRATE + 4) / 8 - 1;
		UBRR1H = 0x00;
		UCSR1A = (1 << U2X1);
		UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);
		UCSR1B = (1 << RXCIE1) | (1 << TXEN1) | (1 << RXEN1);

		OCR0A  = (F_CPU+4)/8/10000-1;
		TCCR0A = (1 << WGM01);
		TCCR0B = (1 << CS01);
		TIMSK0 = (1 << OCIE0A);
		TIFR0  = (1 << OCF0A);

		// connect libc functions printf(), gets()... to UART
		// fdevopen(sys_uart_putch, sys_uart_getch);
		fdev_setup_stream(&sys_uart0_out, uart0_putch, NULL, _FDEV_SETUP_WRITE);
		fdev_setup_stream(&sys_uart1_out, uart1_putch, NULL, _FDEV_SETUP_WRITE);
		fdev_setup_stream(&sys_uart0_in, NULL, uart0_getch, _FDEV_SETUP_READ);
		fdev_setup_stream(&sys_uart1_in, NULL, uart1_getch, _FDEV_SETUP_READ);

		stdout   = &sys_uart0_out;
		stdin    = &sys_uart0_in;
		stderr   = &sys_uart1_out;
		uart0out = &sys_uart0_out;
		uart0in  = &sys_uart0_in;
		uart1out = &sys_uart1_out;
		uart1in  = &sys_uart1_in;
		_delay_ms(150);
	}


	void main () {
		#ifdef GLOBAL_MONITOR
			monMain();
		#endif
	}


	Event setEvent (Event event) {
		cli();
		uint8_t eventIsPending = (sys.eventFlag & event) != 0;
		sys.eventFlag |= event;
		sei();
		return eventIsPending;
	}

	Event clearEvent (Event event) {
		cli();
		uint8_t eventIsPending = (sys.eventFlag & event) != 0;
		sys.eventFlag &= ~event;
		sei();
		return eventIsPending;
	}

	Event isEventPending (Event event) {
		return (sys.eventFlag & event) != 0;
	}

	// -------------------------------------------------------

	int getCharFromUart (struct Uart *pUart) {
		cli();
		if (pUart->wpos_u8 == pUart->rpos_u8) {
			sei();
		return _FDEV_EOF;
		}
		uint8_t c = pUart->rbuffer_u8[pUart->rpos_u8++];
		if (pUart->rpos_u8 >= GLOBAL_UART_RECBUFSIZE) {
		   pUart->rpos_u8 = 0;
		}
		sei();
		return (int) c;

	}

	int uart0_getch (FILE *f) {
		if (f != uart0in) {
			return _FDEV_EOF;
		}
		return getCharFromUart(&sys.uart0);
	}

	int uart1_getch (FILE *f) {
		if (f != uart1in) {
			return _FDEV_EOF;
		}
		return getCharFromUart(&sys.uart1);
	}

	int uart0_putch (char c, FILE *f) {
		if (f != uart0out) {
			return _FDEV_EOF;
		}
		while (!(UCSR0A & (1 << UDRE0))) {
		}
		UDR0 = c;
		// return (int)c;
		return 0; // 0 ... OK
	}

	int uart1_putch (char c, FILE *f) {
		if (f != uart1out) {
			return _FDEV_EOF;
		}
		while (!(UCSR1A & (1 << UDRE1))) {
		}
		UDR1 = c;
		// return (int)c;
		return 0; // 0 ... OK
	}


	uint8_t getAvailableUartBytes (struct Uart *pUart) {
		return pUart->wpos_u8 >= pUart->rpos_u8
			   ? pUart->wpos_u8 - pUart->rpos_u8
			   : ((int16_t)pUart->wpos_u8) + GLOBAL_UART_RECBUFSIZE - pUart->rpos_u8;
	}

	uint8_t getAvailableUart0Bytes () {
		return getAvailableUartBytes(&sys.uart0);
	}

	uint8_t getAvailableUart1Bytes () {
		return getAvailableUartBytes(&sys.uart1);
	}


	int16_t getUartBufferByte (struct Uart *pUart, uint8_t pos) {
		int16_t rv;
		cli();
		if (pos >= getAvailableUartBytes(pUart)) {
			rv = -1;
		} else {
			uint8_t bufpos = pUart->rpos_u8 + pos;
			if (bufpos >= GLOBAL_UART_RECBUFSIZE) {
				bufpos -= GLOBAL_UART_RECBUFSIZE;
			}
			rv = pUart->rbuffer_u8[bufpos];
		}
		sei();
		return rv;
	}

	int16_t getUart0BufferByte (uint8_t pos) {
		return getUartBufferByte(&sys.uart0, pos);
	}

	int16_t getUart1BufferByte (uint8_t pos) {
		return getUartBufferByte(&sys.uart1, pos);
	}

	void flushUart (struct Uart *pUart) {
		cli();
		if (pUart == &sys.uart0) {
			if (UCSR0A & (1 << RXC0)) {
				volatile __attribute__((unused)) uint8_t c = UDR0;
			}
		} else {
			if (UCSR1A & (1 << RXC0)) {
				volatile __attribute__((unused)) uint8_t c = UDR1;
			}
		}
		pUart->rpos_u8 = 0;
		pUart->wpos_u8 = 0;
		pUart->errcnt_u8 = 0;
		sei();
	}

	void flushUart0 () {
		flushUart(&sys.uart0);
	}

	void flushUart1 () {
		flushUart(&sys.uart1);
	}

	void handleUartReceiveInterrupt (struct Uart *pUart, char c) {
		pUart->rbuffer_u8[pUart->wpos_u8++] = c;
		if (pUart->wpos_u8 >= GLOBAL_UART_RECBUFSIZE) {
			pUart->wpos_u8 = 0;
		}
		if (pUart->wpos_u8 == pUart->rpos_u8) {
			pUart->wpos_u8 == 0
				? pUart->wpos_u8 = GLOBAL_UART_RECBUFSIZE - 1
				: pUart->wpos_u8--;
			if (pUart->errcnt_u8 < 0xff) {
				pUart->errcnt_u8++;
			}
		}
		pUart->rbuffer_u8[pUart->wpos_u8] = 0;
	}

	// -------------------------------------------------------

	void println (const char *format, ...) {
		if (format != NULL) {
			va_list args;
			va_start (args, format);
			vprintf (format, args);
			va_end (args);
		}
		printf(LF);
	}


	void putnchar (char c, uint8_t count) {
		for (; count > 0; count--) {
			putchar(c);
		}
	}


	void printBin (uint8_t value, char sep) {
		uint8_t i;

		for (i = 0; i < 8; i++, value <<= 1) {
			putchar(value&0x80 ? '1' : '0');
			if (i == 3 && sep) {
			putchar(sep);
			}
		}
	}


	void printHexBin8 (uint8_t value) {
		printf("0x%02x (", value);
		printBin(value, ' ');
		putchar(')');
	}


	void printHexBin16 (uint16_t value) {
		printf("0x%04x (", value);
		printBin(value >> 8, ' ');
		putchar(' ');
		printBin(value & 0xff, ' ');
		putchar(')');
	}


	void printStringFromFlash (PGM_P str) {
		char c;

		while (1) {
			memcpy_P(&c, str++, 1);
			if (!c) {
				break;
			}
			putchar(c);
		}
	}

	// -------------------------------------------------------

	#ifdef GLOBAL_MONITOR

	int16_t getMemoryByte (char typ, uint16_t address) {
		uint8_t value = 0;

		switch (typ) {
			case 'f': { // flash
				if (address > FLASHEND) { return -1; }
				memcpy_P(&value, (PGM_P) address, 1);
				break;
			}

			case 's': { // SRAM
				if (address > RAMEND ) { return -1; }
				value = *((uint8_t *)address);
				break;
			}

			case 'e': { // EEPROM
				if (address > E2END) { return -1; }
				//value = eeprom_read_byte((uint8_t *)add);
				break;
			}

			default: {
				return -1;
			}
		}

		return value;
	}


	int16_t readArgument (char *str, int16_t max) {
		int16_t value;

		if (str[0] == '0' && str[1] == 'x') {
			value = strtol(str, NULL, 16);
		} else {
			value = strtol(str, NULL, 10);
		}
		if (value > max) {
			return -1;
		}

		return value;
	}


	// *****************************************************************
	// Monitor Handling
	// *****************************************************************

	struct mon::MonCmdInfo getMonCmdInfo (uint8_t index) {
		struct mon::MonCmdInfo ci = { NULL, NULL} ;
		PGM_P p;

		if (index < sizeof(MON_PMEMSTR_CMDS) / sizeof(struct mon::MonCmdInfo)) {
			p = (PGM_P)&(MON_PMEMSTR_CMDS[index]);
		} else {
			index -= sizeof(MON_PMEMSTR_CMDS) / sizeof(struct mon::MonCmdInfo);
			if (index >= mon::getCmdCount()) {
				return ci;
			}
			p = (PGM_P)&(mon::PMEMSTR_CMDS[index]);
		}

		memcpy_P(&ci, p, sizeof(struct mon::MonCmdInfo));
		return ci;
	}


	void printMonUsageInfo (struct mon::MonCmdInfo *pCmdInfo) {
		PGM_P p = pCmdInfo->pInfo;
		for (uint8_t i = 0; i < 2; i++) {
			char c;
			do {
				memcpy_P(&c, p++, 1);
			} while (c != 0);
		}
		printStringFromFlash(p);
	}


	void executeMonCmd () {
		struct SysMonitor *pmon = (struct SysMonitor *)&sysMonitor;

		uint8_t i;
		char *argv[GLOBAL_MON_MAXARGV];
		uint8_t argc;

		char *ps = pmon->cmdLine;
		argc = 0;

		for (i = 0; i < GLOBAL_MON_MAXARGV && *ps; i++) {
			while(*ps == ' ') { ps++; } // ignore leading spaces
			if (*ps == 0) { break; }
			argv[i] = ps;
			argc++;
			while (*ps != ' ' && *ps) {
				ps++;
			}
			if (*ps==' ') {
				*ps++ = 0;
			}
		}
		for (; i < GLOBAL_MON_MAXARGV; i++) {
			argv[i] = NULL;
		}

			/*
		println("\r\nargc=%u", argc);
		for (i = 0; i < GLOBAL_MON_MAXARGV; i++) {
			printf("  argv[%u]=0x%04x", i, (uint16_t)argv[i]);
			if (argv[i] != NULL) {
				printf(" len=%u cmd='%s'", (uint16_t)strlen(argv[i]), argv[i]);
				printf(LF);
			}
		}
		*/

		if (argc > 0 && *argv[0] != 0) {
			printf(LF);
			i = 0;
			while (1) {
				struct mon::MonCmdInfo ci = getMonCmdInfo(i++);
				if (ci.pFunction == NULL) {
					printStringFromFlash(MON_PMEM_ERR1);
					break;
				} else if (strcmp_P(pmon->cmdLine, ci.pInfo) == 0) {
					int8_t retCode = (*ci.pFunction)(argc, argv);
					if (retCode) {
						printStringFromFlash(MON_PMEM_ERR0);
						printf("%d", retCode);
						if (retCode < 0) {
							printStringFromFlash(MON_PMEM_ERR2);
							printMonUsageInfo(&ci);
						}
					}
					printf(LF);
					break;
				}
			}
		}

		if (argc > 0) {
			printf(mon::LINESTART);
		}
		pmon->cursorPos = 0;
		pmon->cmdLine[0] = 0;
	}


	void monCmdLineBack () {
		struct SysMonitor *pmon = (struct SysMonitor *)&sysMonitor;
		if (pmon->cursorPos == 0) {
			return;
		}
		printf("\b \b");
		pmon->cmdLine[--pmon->cursorPos] = 0;
	}



	void monMain () {
		struct SysMonitor *pmon = (struct SysMonitor *)&sysMonitor;
		char c = 0;
		int8_t incLineIndex = 0;
		static uint8_t lastbyte = 0;

		if (pmon->flags & MONITOR_FLAG_LINEMODE) {
			while (getAvailableUart0Bytes() > 0) {
				c = getchar();
				if (lastbyte != '\n' && c == '\r') {
					c = '\n';
				} else {
					lastbyte = c;
				}
				if (c == '\n') {
					pmon->flags &= ~(MONITOR_FLAG_LINEMODE | MONITOR_FLAG_LINE);
					printf("\r\n");
					printf(mon::LINESTART);
					return;
				}
			}
			if (c == MONITOR_CTRL_X) {
				incLineIndex = 1;
				pmon->flags &= ~MONITOR_FLAG_LINE;
			} else if (c == MONITOR_CTRL_Y) {
				incLineIndex = -1;
				pmon->flags &= ~MONITOR_FLAG_LINE;
			} else if (c == MONITOR_CTRL_C) {
				if (pmon->flags & MONITOR_FLAG_CONT) {
					pmon->flags &= ~(MONITOR_FLAG_CONT | MONITOR_FLAG_LINE);
				} else {
					pmon->flags |= MONITOR_FLAG_CONT;
				}
			}

			if (pmon->flags & MONITOR_FLAG_LINE) {
				int8_t lenSpaces = mon::printLine(pmon->lineIndex, c);
				putnchar(' ', lenSpaces);
				printf("\r");
				if (pmon->flags & MONITOR_FLAG_CONT) {
					printf(LF);
				}
			} else {
				int8_t len;
				println(LF);
				do {
					if (incLineIndex) {
						pmon->lineIndex = incLineIndex > 0 ? pmon->lineIndex + 1 : pmon->lineIndex - 1;
					}
					len = mon::printLineHeader(pmon->lineIndex);
				} while (len < 0 && pmon->lineIndex != 0);

				printf(LF);
				if (len > 0) {
					putnchar('-', len);
				}
				printf(LF);
				pmon->flags |= MONITOR_FLAG_LINE;
			}

		} else {
			while (getAvailableUart0Bytes() > 0) {
				c = getchar();
				if (lastbyte != '\n' && c == '\r') {
					c = '\n';
				} else {
					lastbyte = c;
				}

				if (c == MONITOR_CTRL_X || c == MONITOR_CTRL_Y) {
					pmon->flags |= MONITOR_FLAG_LINEMODE;
				} else if (c == '\n') {
					executeMonCmd();
				} else if (c == 127) {
					; // ignore Taste 'Entf' -> maybe implemented later
				} else if (c == '\b') {
					monCmdLineBack();
				} else if (c < ' ' || c > 126) {
					; // ignore control codes
				} else if (pmon->cursorPos < (sizeof(pmon->cmdLine)-1)) {
					#ifdef GLOBAL_MON_ONLYLOCASE
						c = tolower(c);
					#endif
					pmon->cmdLine[pmon->cursorPos++] = c;
					pmon->cmdLine[pmon->cursorPos] = 0;
					putchar(c);
				}
			}
		}
	}


	//****************************************************************************
	// Monitor Commands
	//****************************************************************************

	int8_t moncmd_help (uint8_t argc, char *argv[]) {
		// struct SysMonitor *pmon = (struct SysMonitor *)&sysMonitor;
		uint8_t i, max;

		i = 0; max = 0;
		while (true) {
			struct mon::MonCmdInfo ci = getMonCmdInfo(i++);
			if (ci.pFunction == NULL) {
				break;
			}
			uint8_t len = strlen_P(ci.pInfo);
			max = (len > max) ? len : max;
		}

		i = 0;
		while (true) {
			struct mon::MonCmdInfo ci = getMonCmdInfo(i++);
			if (ci.pFunction == NULL) {
				break;
			}
			if (argc > 1) {
				if (strcmp_P(argv[1], ci.pInfo) == 0) {
					printMonUsageInfo(&ci);
					return 0;
				}

			} else {
				printStringFromFlash(ci.pInfo);
				for (uint8_t j = strlen_P(ci.pInfo); j < max + 2; j++) {
					putchar(' ');
				}
				printStringFromFlash(ci.pInfo + strlen_P(ci.pInfo) + 1);
				printf(LF);
			}
		}
		if (argc > 1) {
			printStringFromFlash(MON_PMEM_ERR1);
			// printf("%s not found", argv[1]);
		}

		return 0;
	}

	int8_t moncmd_sinfo (uint8_t argc, char *argv[]) {
		printf("sys.flags_u8  : ");
		printHexBin8(sys.flags_u8);
		printf(LF);
		printf("sys.taskErr_u8: ");
		printHexBin8(sys.taskErr_u8);
		printf(LF);
		return 0;
	}



	#ifdef GLOBAL_MONCMD_SETMEM
	int8_t moncmd_setmem (uint8_t argc, char *argv[]) {
		char     typ;    // 1st parameter (s='SRAM | 'e'=EEPROM)
		uint16_t add;    // 2nd parameter (address)
		uint16_t value;  // 3rd parameter (value)
		char     *padd, *pval;

		if (argc == 3) {
			typ = 's'; // default is set of SRAM-Byte
			padd = argv[1];
			pval = argv[2];
		} else if (argc == 4) {
			typ = argv[1][0];
			padd = argv[2];
			pval = argv[3];
		} else {
			return -1; // Syntax Error
		}

		add = readArgument(padd, RAMEND);
		value = readArgument(pval, 255);
		if (value < 0) {
			return -2;
		}
		printf("set 0x%02x to address 0x%04x\n\r", value, add);

		switch (typ) {
			case 's': {
				*((uint8_t *)add) = value;
				break;
			}

			case 'e': {
				eeprom_write_byte((uint8_t *)add, value);
				eeprom_busy_wait();
				break;
			}
		}

		return 0;
	}
	#endif // GLOBAL_MONCMD_SETMEM


	#ifdef GLOBAL_MONCMD_HEXDUMP
	int8_t moncmd_hexdump (uint8_t argc, char *argv[]) {
		if (argc < 3 || argc > 4) {
			return -1;
		}
		char     typ; // 1st parameter ('s'=SRAM | 'f'=FLASH | 'e'=EEPROM)
		uint16_t add; // 2nd parameter (start address of hexdump)
		uint16_t len; // [3rd parameter] (number of bytes to dump)

		typ = argv[1][0];
		if (typ != 'f' && typ != 's' && typ != 'e') {
			return -1;
		}
		if (argv[2][0] == '0' && argv[2][1] == 'x') {
			add = strtol(&argv[2][2], NULL, 16);
		} else {
			add = strtol(argv[2], NULL, 10);
		}

		if (argc == 4) {
			if (argv[3][0] == '0' && argv[3][1] == 'x') {
				len = strtol(&argv[3][2], NULL, 16);
			} else {
				len = strtol(&argv[3][0], NULL, 10);
			}
		} else {
			len = 32;
		}

		char s[19] = "  ";
		s[18] = 0;
		uint16_t i;

		for (i = 0; i < len; add++, i++) {
			int16_t i16 = getMemoryByte(typ, add);
			if (i16 < 0) {
				break;
			}
			uint8_t value = (uint8_t)i16;

			if (i % 16 == 0) {
				printf("0x%04x: ", add);
			} else if (i % 4 == 0) {
				putchar(' ');
			}

			s[(i%16) + 2] = value >= 32 && value < 127 ? value : '.';
			printf("%02x ", value);
			if (i % 16 == 15) {
				printf(s);
				printf(LF);
			}
		}

		if ((i % 16) != 0) {
			for (; (i % 16) != 0; i++) {
				printf("   ");
				s[(i % 16) + 2] = ' ';
				if (i%4 == 0) {
					putchar(' ');
				}
			}
			printf(s);
			printf(LF);
		}

		return 0;
	}
	#endif // GLOBAL_MONCMD_HEXDUMP

	#endif // GLOBAL_MONITOR
}

// ------------------------------------
// Interrupt Service Routines
// ------------------------------------

ISR (USART0_RX_vect) {
	static uint8_t lastChar;
	uint8_t c = UDR0;

	if (c == 'R' && lastChar == '@') {
		wdt_enable(WDTO_15MS);
		wdt_reset();
		while(1) {};
	}
	lastChar = c;
	sys::handleUartReceiveInterrupt(&(sys::sys.uart0), c);
}


ISR (USART1_RX_vect) {
	static uint8_t lastChar;
	uint8_t c = UDR1;

	if (c == 'R' && lastChar == '@') {
		wdt_enable(WDTO_15MS);
		wdt_reset();
		while(1) {};
	}
	lastChar = c;
	sys::handleUartReceiveInterrupt(&(sys::sys.uart1), c);
}

// Timer 0 Output/Compare Interrupt
// called every 100us
ISR (TIMER0_COMPA_vect) {
	static uint8_t cnt100us = 0;
	static uint8_t cnt500us = 0;
	static uint8_t busy = 0;

	cnt100us++;
	if (cnt100us >= 5) {
		cnt100us = 0;
		cnt500us++;
		if (busy) {
			if (sys::sys.taskErr_u8 < 0xff) {
				sys::sys.taskErr_u8++;
			}
		} else {
			busy = 1;
			sei();
			if      (cnt500us & 0x01) app::task1ms();
			else if (cnt500us & 0x02) app::task2ms();
			else if (cnt500us & 0x04) app::task4ms();
			else if (cnt500us & 0x08) app::task8ms();
			else if (cnt500us & 0x10) app::task16ms();
			else if (cnt500us & 0x20) app::task32ms();
			else if (cnt500us & 0x40) app::task64ms();
			else if (cnt500us & 0x80) app::task128ms();
			busy = 0;
		}
	}
}

