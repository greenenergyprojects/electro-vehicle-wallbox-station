
#include "app.hpp"
#include "sys.hpp"
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

namespace app {

struct App app;

	// ----------------------------------------------------------
	// init() is called one time at startup
	// ----------------------------------------------------------
	void init () {
		// fprintf(uart0out, "Hello world to UART0\n\r");
		// fprintf(uart1out, "Hello world to UART1\n\r");
	}


	// ----------------------------------------------------------
	// main() is recalled by main loop (out of interrupt)
	// ----------------------------------------------------------
	void main () {
	}


	// ------------------------------------------------------------
	// Task functions called inside timer interrupt service routine.
	// Functions should end as fast as possible, max. 500 µs
	// Interrupts are enabled!
	// ------------------------------------------------------------
	void task1ms () {
		static uint16_t timer = 0;
		timer++;
		if (timer > 3000) {
			timer = 0;
			sys::setLifeLed(0);
		} else if (timer > 2900) {
			sys::setLifeLed(1);
		}
	}

	void task2ms () {
	}

	void task4ms () {
	}

	void task8ms () {
	}

	void task16ms () {
	}

	void task32ms () {
	}

	void task64ms () {
	}

	void task128ms () {

	}

}
