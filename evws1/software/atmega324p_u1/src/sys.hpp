#ifndef SYS_HPP
#define SYS_HPP

#include "global.h"

#if SYS_UART0_RECBUFSIZE > 255
	#error "Error: SYS_UART0_RECBUFSIZE value over maximum (255)"
#endif

#include <stdio.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

// declarations

// UART0 / UART1 streams for fprintf, fgets, ...
extern FILE *uart0out;
extern FILE *uart0in;
extern FILE *uart1out;
extern FILE *uart1in;

namespace sys {

	// defines

	// declarations

	typedef uint8_t Event;

	struct UartX {
		uint8_t wpos_u8;
		uint8_t rpos_u8;
		uint8_t errcnt_u8;
		uint8_t rbuffer_u8[255];
	};

	struct Uart0 {
		uint8_t wpos_u8;
		uint8_t rpos_u8;
		uint8_t errcnt_u8;
		uint8_t rbuffer_u8[GLOBAL_UART0_RECBUFSIZE];
	};

	struct Uart1 {
		uint8_t wpos_u8;
		uint8_t rpos_u8;
		uint8_t errcnt_u8;
		uint8_t rbuffer_u8[GLOBAL_UART1_RECBUFSIZE];
	};

	struct Sys {
		uint8_t flags_u8;
		uint8_t taskErr_u8;
		Event eventFlag;
		struct Uart0 uart0;
		struct Uart1 uart1;
	};

	extern struct Sys sys;


	// functions

	void init ();
	void main ();

	void println (const char *__fmt, ...);
	void putnchar (char c, uint8_t count);
	void printBin (uint8_t value, char sep);
	void printHexBin8 (uint8_t value);
	void printHexBin16 (uint16_t value);
	void printStringFromFlash (PGM_P str);

	Event setEvent (Event event);
	Event clearEvent (Event event);
	Event isEventPending (Event event);

	uint8_t getAvailableUart0Bytes ();
	uint8_t getAvailableUart1Bytes ();
	int16_t getUart0BufferByte (uint8_t pos);
	int16_t getUart1BufferByte (uint8_t pos);
	void flushUart0 ();
	void flushUart1 ();

	// project specific declarations

	void toggleLifeLed ();
	void setLifeLed (bool on);
	int8_t hexValueFromChar (char c);
	int16_t hex2uint8 (char s[]);


}

#endif /* SYS_HPP */
