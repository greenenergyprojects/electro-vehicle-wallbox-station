#ifndef SYS_HPP
#define SYS_HPP

#include "global.h"

#if SYS_UART_RECBUFSIZE > 255
  #error "Error: SYS_UART0_RECBUFSIZE value over maximum (255)"
#endif

#include <stdio.h>
#include <avr/io.h>

// declarations

// UART0 / UART1 streams for fprintf, fgets, ...
extern FILE *uart0out;
extern FILE *uart0in;
extern FILE *uart1out;
extern FILE *uart1in;

#ifdef GLOBAL_LCD
extern FILE *lcd;
#endif


namespace sys {

    // defines

    // FLAG_SREG_I must have same position as I-Bit in Status-Register!!
    #define FLAG_SREG_I 0x80

    // declarations
    
    typedef uint8_t Event;
    
    struct Uart {
        uint8_t rpos_u8;
        uint8_t wpos_u8;
        uint8_t errcnt_u8;
        uint8_t rbuffer_u8[GLOBAL_UART_RECBUFSIZE];
    };

    #ifdef GLOBAL_LCD
    struct Lcd {
	int8_t  status;  // 0=not initialized, 1=ready, <0->error
	uint8_t data;
    };
    #endif

    
    struct Sys {
        uint8_t flags_u8;
        uint8_t taskErr_u8;
        Event eventFlag;
        struct Uart uart0;
	struct Uart uart1;
	#ifdef GLOBAL_LCD
	struct Lcd lcd;
	#endif
    };

    
    
    extern struct Sys sys;
    
    // functions

    void init ();
    void main ();

    void saveSei ();
    void saveCli ();

    Event setEvent (Event event);
    Event clearEvent (Event event);
    Event isEventPending (Event event);

    uint8_t getAvailableUart0Bytes ();
    uint8_t getAvailableUart1Bytes ();
    int16_t getUart0BufferByte (uint8_t pos);
    int16_t getUart1BufferByte (uint8_t pos);
    void flushUart0 ();
    void flushUart1 ();
    
     #ifdef GLOBAL_LCD
    void setLcdDisplayOff ();
    void setLcdDisplayOn ();
    void clearLcd ();
    void setLcdCursorPosition (uint8_t rowIndex, uint8_t columnIndex);
    extern FILE *lcd; // for fputc, fprintf, ...
    #endif // GLOBAL_LCD
    
    void toggleLifeLed ();
    void setLifeLed (bool on);
    void togglePB1 ();
    void setPB1 (bool on);
}

#endif /* SYS_HPP */

