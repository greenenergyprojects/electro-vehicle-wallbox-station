
#include "app.hpp"
#include "sys.hpp"

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


namespace app {
    
    // ----------------------------------------------------------
    // init() is called one time at startup
    // ----------------------------------------------------------
    void init () {
	// fprintf(stderr, "OK\n");
    }
    
    void test1 () {
	#ifdef TEST1
	static int lastChar = -1;
	
	fprintf(uart0out, "%4d   ", lastChar);
	fprintf(uart1out, "%4d   ", lastChar);

	fprintf(uart0out, "%u %u   ", sys::sys.uart0.wpos_u8, sys::sys.uart0.rpos_u8);
	fprintf(uart0out, "%u %u   ", sys::sys.uart1.wpos_u8, sys::sys.uart1.rpos_u8);
	
	fprintf(uart1out, "%u %u   ", sys::sys.uart0.wpos_u8, sys::sys.uart0.rpos_u8);
	fprintf(uart1out, "%u %u   ", sys::sys.uart1.wpos_u8, sys::sys.uart1.rpos_u8);

	if (sys::sys.uart0.wpos_u8 % 4 == 0) {
	    int c = fgetc(uart0in);
	    if (c >= 0) {
		lastChar = c;
	    }
	}
	
	if (sys::sys.uart1.wpos_u8 % 4 == 0) {
	    int c = fgetc(uart1in);
	    if (c >= 0) {
		lastChar = c;
	    }
	}

	fprintf(uart0out, "\r    ");
	fprintf(uart1out, "\r    ");
	#endif
    }

    void test2 () {
	// VCP1
	#ifdef TEST2
	ADMUX = (1 << REFS0) | (1 << ADLAR) | 2; // external VREF, Left Adjust, ADC2
	ADCSRA = (1 << ADEN) | 7;
	_delay_ms(1);
	ADCSRA = (1 << ADEN) | (1 << ADSC) | 7; // Prescaler 128
	_delay_ms(2);
	uint8_t adc = ADCH;
	printf("PA2 (AD-VC1): %02x\r ", adc);
	#endif
    }
    
    struct I2CDev { uint8_t address; const char *name; };
    const uint8_t I2C_STATUS_START_TRANSMITTED          = 0x08;
    const uint8_t I2C_STATUS_REPEATED_START_TRANSMITTED = 0x10;
    const uint8_t I2C_STATUS_ADDRESS_ACK                = 0x18;
    const uint8_t I2C_STATUS_ADDRESS_NACK               = 0x20;
    
    void testI2C (uint8_t address, long bitrate) {
	printf("test I2C address 0x%02x ... ", address);

	TWSR = 0; // Bit rate prescaler 1 
	TWBR = (F_CPU - bitrate * 16) / 2 / bitrate / 4; // ... / 4^Prescaler
	// TWBR = 23;
	
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while ( !(TWCR & (1 << TWINT)) ) {}
	if (( TWSR & 0xf8) != I2C_STATUS_START_TRANSMITTED) {
	    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	    printf("Error 1: no start\n\r");
	    return;
	}
	
	// TWDR = 0x92; // ADC PCF8591
	// TWDR = 0x45; // Port Expander PCF8574
	TWDR = address;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while ( !(TWCR & (1 << TWINT)) ) {}
	if (( TWSR & 0xf8) != I2C_STATUS_ADDRESS_ACK) {
	    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	    printf("Error 2: no ACK\n\r");
	    return;
	}
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	printf("ACK received\n\r");
	
	
	// TWCR = 0;
    }
    
    void test3 () {
	#ifdef TEST_ALL_ADDRESSES
	for (uint8_t add = 1; add < 127; add++) {
	    _delay_ms(500);
	    testI2C(add << 1, 50000L);
	}
	#endif
	const struct I2CDev devices[] = {
	    { 0x4e, "LCD2" },
	    { 0x74, "U9 PortExp" },
	    { 0x92, "U4 ADC" },
	    { 0xa0, "U8 EE512K" },
	    { 0xd0, "U7 DS1307ZN" },
	    { 0x00, NULL }
	    
	};
	const struct I2CDev *pDev = devices;
	while (pDev->name != NULL) {
	    printf("%12s ", pDev->name); testI2C(pDev->address, 100000L);
	    _delay_ms(1000);
	    pDev++;
	}
	printf("\n\r");
	_delay_ms(2000);
	
    }
    
    // ----------------------------------------------------------
    // main() is recalled by main loop (out of interrupt) 
    // ----------------------------------------------------------
    void main () {
        // test1();
        // test2();
        test3();
	
    }
    
    // ------------------------------------------------------------
    // Task functions called inside timer interrupt service routine.
    // Functions should end as fast as possible, max. 500 µs
    // Interrupts are enabled!
    // ------------------------------------------------------------
    void task1ms () {
        // test PWM2 -> CP1
        DDRD |= (1 << PD5);
        PORTD ^= (1 << PD5);
        
        // test PWM1 -> CP2 (PLC)
        DDRD |= (1 << PD4);
        PORTD ^= (1 << PD4);
        
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

	static uint8_t timer = 0;
	if (++timer >= 4) {
	    timer = 0;
	    sys::toggleLifeLed();

	}
    }
    

    
}
