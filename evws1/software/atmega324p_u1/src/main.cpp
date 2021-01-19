//***********************************************************************
// Software for Wallbox Station EVWS1 (component U1, Atmega324P)
// ----------------------------------------------------------------------
// Description:
// ----------------------------------------------------------------------
// Based on template:
// https://git.htl-mechatronik.at/public/?p=sx/fiv-templates.git;a=tree;f=userboard_4_atmega324p_12;\hb=4917f40
//***********************************************************************

#include "global.h"

#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "sys.hpp"
#include "mon.hpp"
#include "app.hpp"

// defines
// ...

// declarations and definations
// ...

// constants located in program flash and SRAM
const char FLASHSTRING_WELCOME[] PROGMEM = "\n\rLevel 4 user specific board (Atmega324P 12MHz)";
const char FLASHSTRING_DATE[] PROGMEM = __DATE__;
const char FLASHSTRING_TIME[] PROGMEM = __TIME__;
const char FLASHSTRING_HELP[] PROGMEM = "\r\n";

const char *WELCOME [] = {
	FLASHSTRING_WELCOME,
	FLASHSTRING_DATE,
	FLASHSTRING_TIME,
	FLASHSTRING_HELP
};


int main () {
	sys::init();
	app::init();
	for (uint8_t i = 0; i < sizeof(WELCOME) / sizeof(WELCOME[0]); i++) {
		sys::printStringFromFlash(WELCOME[i]);
		printf(" ");
	}
	mon::init();

	// enable interrupt system
	sei();

	while (1) {
		sys::main();
		mon::main();
		app::main();
	}
	return 0;
}
