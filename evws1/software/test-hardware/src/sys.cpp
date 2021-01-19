
#include "global.h"

#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>

#include "sys.hpp"
#include "app.hpp"

FILE *uart0out;
FILE *uart0in;
FILE *uart1out;
FILE *uart1in;

#ifdef GLOBAL_LCD
FILE *lcd;
#endif

namespace sys {

    struct Sys sys;

    static FILE sys_uart0_out;
    static FILE sys_uart0_in;
    static FILE sys_uart1_out;
    static FILE sys_uart1_in;
    
    int uart0_putch (char c, FILE *f);
    int uart0_getch (FILE *f);
    int uart1_putch (char c, FILE *f);
    int uart1_getch (FILE *f);
    
    #ifdef GLOBAL_LCD
    const uint8_t FLAG_7SEG_ENABLED    = 0x01;
    const uint8_t FLAG_LCD_ENABLED     = 0x02;
    const uint8_t SEG7_DIGIT_MINUS     = 0x10;
    const uint8_t SEG7_DIGIT_UNDERLINE = 0x11;
    const uint8_t SEG7_DIGIT_OFF       = 0x13;
    static FILE sys_lcd;
    void initLcd ();
    int putLcdCharacter (char c, FILE *stream);
    #endif
    
    void init () {
        memset((void *)&sys, 0, sizeof(sys));
	DDRB |= (1 << PB1); // test signal

	DDRB |= (1 << PB0); // ~K1-ON via SW6D or Life-LED via JP9
	
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

	#ifdef GLOBAL_LCD
	initLcd();
        fdev_setup_stream(&sys_lcd, putLcdCharacter, NULL, _FDEV_SETUP_WRITE);       
	::lcd = &sys_lcd;
	setLcdCursorPosition(0, 0);
	fprintf(::lcd, "A2345678901234567890");
	setLcdCursorPosition(1, 0);
	fprintf(::lcd, "Bbcdefghijklmnopqrst");
	setLcdCursorPosition(2, 0);
	fprintf(::lcd, "C2345678901234567890");
	setLcdCursorPosition(3, 0);
	fprintf(::lcd, "Dbcdefghijklmnopqrst");
        #endif
	
	_delay_ms(150);
	
    }


    void main () {
    }    
    
    void saveSei () {
        if (sys.flags_u8 & FLAG_SREG_I) {
            sei();
        }
    }


    void saveCli () {
        if (SREG & 0x80) {
            sys.flags_u8 |= FLAG_SREG_I;
        } else {
            sys.flags_u8 &= ~FLAG_SREG_I;
        }
    }


    Event setEvent (Event event) {
	saveCli();
	uint8_t eventIsPending = (sys.eventFlag & event) != 0;
	sys.eventFlag |= event;
	saveSei();
	return eventIsPending;
    }
    
    Event clearEvent (Event event) {
	saveCli();
	uint8_t eventIsPending = (sys.eventFlag & event) != 0;
	sys.eventFlag &= ~event;
	saveSei();
	return eventIsPending;
    }
    
    Event isEventPending (Event event) {
	return (sys.eventFlag & event) != 0;
    }
    
    // -------------------------------------------------------
    
    int getCharFromUart (struct Uart *pUart) {
	saveCli();
        if (pUart->wpos_u8 == pUart->rpos_u8) {
            saveSei();
	    return _FDEV_EOF;
        }
        uint8_t c = pUart->rbuffer_u8[pUart->rpos_u8++];
        if (pUart->rpos_u8 >= GLOBAL_UART_RECBUFSIZE) {
           pUart->rpos_u8 = 0;
        }
	saveSei();
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
        saveCli();
        if (pos >= getAvailableUartBytes(pUart)) {
            rv = -1;
        } else {
            uint8_t bufpos = pUart->rpos_u8 + pos;
            if (bufpos >= GLOBAL_UART_RECBUFSIZE) {
                bufpos -= GLOBAL_UART_RECBUFSIZE;
            }
            rv = pUart->rbuffer_u8[bufpos];
        }
        saveSei();
        return rv;
    }
    
    int16_t getUart0BufferByte (uint8_t pos) {
	return getUartBufferByte(&sys.uart0, pos);
    }
    
    int16_t getUart1BufferByte (uint8_t pos) {
	return getUartBufferByte(&sys.uart1, pos);
    }

    void flushUart (struct Uart *pUart) {
        saveCli();
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
        saveSei();
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


   //*************************************************************************
    // LCD Handling (only for SURE Board)
    //*************************************************************************

    #ifdef GLOBAL_LCD

    // LCD-Display 4x20 Zeichen, 5x8 Pixel/Zeichen
    // Controller KS0076B
    // Data: Port C (PC7:4 = D7:4)
    // RS=PB2, RW=PA6, E=PC3, VO (Kontrast) ueber Poti, Backlight PB1 (via T6)

    const uint8_t LCD_PULSE_LENGTH = 15;
    #define LCD_DATA_IN  DDRC &= ~0xf0;    
    #define LCD_DATA_OUT DDRC |= 0xf0;
    #define LCD_SET_DATA(x) PORTC = (PORTC & 0x0f) | ((x) << 4);
    #define LCD_RS_OUT   DDRB  |=  (1 << PB2);
    #define LCD_SET_RS   PORTB |=  (1 << PB2); // Signal RS=1
    #define LCD_CLR_RS   PORTB &= ~(1 << PB2); // Signal RS=0
    #define LCD_RW_OUT   DDRA  |=  (1 << PA6);
    #define LCD_SET_RW   PORTA |=  (1 << PA6); // Signal RW=1
    #define LCD_CLR_RW   PORTA &= ~(1 << PA6); // Signal RW=0
    #define LCD_E_OUT    DDRC  |=  (1 << PC3);    
    #define LCD_SET_E    PORTC |=  (1 << PC3); // Signal E=1 
    #define LCD_CLR_E    PORTC &= ~(1 << PC3); // Signal E=0 

    const uint8_t LCD_CMD_DISPLAY_CLEAR  = 0x01;  // Display clear
    const uint8_t LCD_CMD_CURSOR_HOME    = 0x02;  // Move cursor digit 1
    const uint8_t LCD_CMD_SET_ENTRY_MODE = 0x04;  // Entry Mode Set
    const uint8_t LCD_CMD_DISPLAY_ON_OFF = 0x08;  // Display on/off
    const uint8_t LCD_CMD_SHIFT          = 0x10;  // Display shift
    const uint8_t LCD_CMD_SET_FUNCTION   = 0x20;  // 4/8 Bits...
    const uint8_t LCD_CMD_SET_CGRAM_ADDR = 0x40;  // Character Generator ROM
    const uint8_t LCD_CMD_SET_DDRAM_ADDR = 0x80;  // Display Data RAM
    const uint8_t LCD_BUSY_FLAG          = 0x80;    
    
    void setLcdRegister (uint8_t cmd);
    uint8_t isLcdReady (uint16_t timeoutMicros);
    void waitOnLcdIsReady ();
    void setLcdDRAddr (uint8_t address);
    int putcharToLcd (char c);
    
    void initLcd () {
	uint8_t i;

	printf("%sLCD init...", LF);
	
	LCD_RS_OUT;
	LCD_RW_OUT;
	LCD_E_OUT;
	    
	//_delay_ms(16);
	sys.lcd.status = 0;
	for (i=0; i < 4; i++) {
	    
	    setLcdRegister(LCD_CMD_SET_FUNCTION | 0x08); // 4 Bit, 2 Zeilen, 5x7
	    if (i==0) { 
		_delay_ms(5);
	    } else {
		_delay_us(100);
	    }
	}

	_delay_us(100);
	setLcdRegister(LCD_CMD_DISPLAY_ON_OFF | 0x04); // display on, cursor off
	if (!isLcdReady(50)) { 
	    sys.lcd.status = -1;
	} else {
	    setLcdRegister(LCD_CMD_DISPLAY_ON_OFF | 0x04); // display on, cursor off
	    if (!isLcdReady(50)) {
		sys.lcd.status = -3;
	    } else {
		setLcdRegister(LCD_CMD_DISPLAY_CLEAR);
		if (!isLcdReady(1200)) {
		    sys.lcd.status = -4;
		} else {
		    sys.lcd.status = 1;	    
		}
	    }
	}
	
	printf(" done (status = %d)%s", sys.lcd.status, LF);
    }


    uint8_t isLcdReady (uint16_t timeoutMicros) {
	if (sys.lcd.status < 0) {
	    return 0;
	}
	setPB1(1);
	uint8_t busy;
	LCD_SET_DATA(0xff);
	LCD_DATA_IN;
	do {
	  LCD_SET_RW;
	  LCD_CLR_RS;
	  _delay_us(1);
	  LCD_SET_E;
	  _delay_us(LCD_PULSE_LENGTH);
	  sys.lcd.data = LCD_DATA_IN;
	  busy = sys.lcd.data & LCD_BUSY_FLAG;
	  LCD_CLR_E;
	  LCD_CLR_RW;
	  timeoutMicros = (timeoutMicros >= 11) ? timeoutMicros - 11 : 0;
	} while (timeoutMicros > 0 && busy);

	if (sys.lcd.status == 1 && busy) {
	    sys.lcd.status = -5;
	}
	LCD_DATA_IN;
	setPB1(0);
	return busy == 0;
    }


    void setLcdRegister (uint8_t cmd) {
	LCD_CLR_E;
        LCD_CLR_RW;
        LCD_CLR_RS;
        LCD_DATA_OUT;
        
        LCD_SET_DATA(cmd >> 4); // send High-Byte
        LCD_SET_E;
        _delay_us(LCD_PULSE_LENGTH);
        LCD_CLR_E;
        _delay_us(1);

        LCD_SET_DATA(cmd); // send Low-Byte
        LCD_SET_E;
        _delay_us(LCD_PULSE_LENGTH);
        LCD_CLR_E;
        _delay_us(1);
	
	LCD_DATA_IN;
    }


    void waitOnLcdIsReady () {
	if (isLcdReady(50) == 0) {
	    sys.lcd.status = -6;
	}
    }


    void setLcdDisplayOff () {
	waitOnLcdIsReady();
	setLcdRegister(LCD_CMD_DISPLAY_ON_OFF); // display off
	waitOnLcdIsReady();
    }


    void setLcdDisplayOn () {
	waitOnLcdIsReady();
	setLcdRegister(LCD_CMD_DISPLAY_ON_OFF | 0x04); // display on
	waitOnLcdIsReady();
    }


    void clearLcd () {
	waitOnLcdIsReady();
	setLcdRegister(LCD_CMD_DISPLAY_CLEAR);
	while (!isLcdReady(1200)) { };
    }


    void setLcdDRAddr (uint8_t address) {
	waitOnLcdIsReady();
	setLcdRegister(LCD_CMD_SET_DDRAM_ADDR | address);
	waitOnLcdIsReady();
    }


    // 1.Line->rowIndex=0, 1.Column->colIndex=0
    void setLcdCursorPosition (uint8_t rowIndex, uint8_t columnIndex) {
	if (sys.lcd.status != 1 || rowIndex > 3) { 
	    return;
	}
	switch (rowIndex) {
	    case 0: setLcdDRAddr(columnIndex); break;
	    case 1: setLcdDRAddr(0x40 + columnIndex); break;
	    case 2: setLcdDRAddr(0x14 + columnIndex); break;
	    case 3: setLcdDRAddr(0x54 + columnIndex); break;
	}
    }

    
    int putcharToLcd (char c) {
	if (sys.lcd.status != 1) { 
	    return _FDEV_EOF;
	}
	waitOnLcdIsReady();

	LCD_CLR_E;
        LCD_CLR_RW;
        LCD_SET_RS;
        LCD_DATA_OUT;
        
        LCD_SET_DATA(c >> 4); // send High-Byte
        LCD_SET_E;
        _delay_us(LCD_PULSE_LENGTH);
        LCD_CLR_E;
        _delay_us(1);

        LCD_SET_DATA(c); // send Low-Byte
        LCD_SET_E;
        _delay_us(LCD_PULSE_LENGTH);
        LCD_CLR_E;
        _delay_us(1);
        LCD_CLR_RS;
        _delay_us(1);
	LCD_DATA_IN;
	return 0;
    }

    int putLcdCharacter (char c, FILE *stream) {
	if (stream != ::lcd) { 
	    return _FDEV_EOF;
	}
	int rv = putcharToLcd(c);
	return rv;
    }

    #endif // GLOBAL_SURE_LCD    
    
    // ----------------------------------------------------------------------
    
    void toggleLifeLed () {
	PORTB ^= (1 << PB0);
    }
    
    void setLifeLed (bool on) {
	if (on) {
	    PORTB |= (1 << PB0);
	} else {
	    PORTB &= ~(1 << PB0);
	}
    }
    
    void togglePB1 () {
	PORTB ^= (1 << PB1);
    }
    
    void setPB1 (bool on) {
	if (on) {
	    PORTB |= (1 << PB1);
	} else {
	    PORTB &= ~(1 << PB1);
	}
    }

    
    
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
