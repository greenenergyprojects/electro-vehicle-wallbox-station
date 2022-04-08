#include <stdio.h>
#include <avr/pgmspace.h>


// #include "/work/sx/simavr/simavr/sim/avr/avr_mcu_section.h"
// AVR_MCU(F_CPU, "atmega324p");
// AVR_MCU_VOLTAGES(5000, 5000, 2500);

#ifndef F_CPU
	#define F_CPU 20000000L
#endif

#ifndef __AVR_ATmega324P__
	#define __AVR_ATmega324P__
#endif

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef __cplusplus
	}
#endif

// defines
// ...

// declarations and definations
// ...

// constants located in program flash and SRAM
const char FLASHSTRING_WELCOME[] PROGMEM = "0123456789";
const char FLASHSTRING_DATE[] PROGMEM = __DATE__;
const char FLASHSTRING_TIME[] PROGMEM = __TIME__;

const char *WELCOME [] = {
	FLASHSTRING_WELCOME,
	FLASHSTRING_DATE,
	FLASHSTRING_TIME,
};

void /* __attribute__((optimize("O0"))) */ printStringFromFlash (PGM_P str) {
	char c;

	while (1) {
		memcpy_P(&c, str++, 1);
		if (!c) {
			break;
		}
		putchar(c);
	}
}


int /* __attribute__((optimize("O0"))) */ main () {
	for (uint8_t i = 0; i < sizeof(WELCOME) / sizeof(WELCOME[0]); i++) {
		if (i > 0) {
			putchar(' ');
		}
		printStringFromFlash(WELCOME[i]);
	}

	return 0;
}





