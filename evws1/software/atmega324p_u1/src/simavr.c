#include "/work/sx/simavr/simavr/sim/avr/avr_mcu_section.h"

#include "global.h"

#include <avr/io.h>

AVR_MCU(F_CPU, "atmega324p");
AVR_MCU_VOLTAGES(5000, 5000, 2500);

/*
 * This small section tells simavr to generate a VCD trace dump with changes to these
 * registers.
 * Opening it with gtkwave will show you the data being pumped out into the data register
 * UDR0, and the UDRE0 bit being set, then cleared
 */
const struct avr_mmcu_vcd_trace_t _mytrace[]  _MMCU_ = {
	{ AVR_MCU_VCD_SYMBOL("UDR0"), .what = (void*)&UDR0, },
	{ AVR_MCU_VCD_SYMBOL("UDRE0"), .mask = (1 << UDRE0), .what = (void*)&UCSR0A, },
	{ AVR_MCU_VCD_SYMBOL("UDR1"), .what = (void*)&UDR1, },
	{ AVR_MCU_VCD_SYMBOL("UDRE1"), .mask = (1 << UDRE1), .what = (void*)&UCSR1A, },
};
