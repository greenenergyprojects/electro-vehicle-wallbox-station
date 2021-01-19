//***********************************************************************
// AIIT Template Level 3 for user specific board (Atmega324P 12MHz)
// ----------------------------------------------------------------------
// Description: Template with UART-Support and Task/Event-System
// ----------------------------------------------------------------------
// Created: 16. March 2020 (SX)
// 
//***********************************************************************

#include "global.h"

#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "sys.hpp"
#include "app.hpp"

// defines
// ...

// declarations and definations
// ...

// constants located in program flash and SRAM
const char MAIN_WELCOME[] = "\n\rLevel 3 EVWS1 (Atmega324P 20MHz)";
const char MAIN_DATE[] = __DATE__;
const char MAIN_TIME[] = __TIME__;
const char MAIN_HELP[] = "\r\n";



int main () {
    sys::init();
    app::init();
    printf("%s %s %s %s", MAIN_WELCOME, MAIN_DATE, MAIN_TIME, MAIN_HELP);
        
    // enable interrupt system
    sei();

    while (1) {
        sys::main();
        app::main();
    }
    return 0;
}

