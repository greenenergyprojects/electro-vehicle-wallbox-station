#ifndef GLOBAL_H
#define GLOBAL_H

#define LF "\r\n"
#define GLOBAL_UART0_BITRATE     115200
#define GLOBAL_UART1_BITRATE     115200
#define GLOBAL_UART_RECBUFSIZE   16

#define GLOBAL_LCD

#define F_CPU 20000000UL
#define USERBOARD 1
#ifndef __AVR_ATmega324P__
    #define __AVR_ATmega324P__
#endif

#ifdef __cplusplus
extern "C" {
#endif
    
#ifdef __cplusplus
}
#endif
    
#endif // GLOBAL_H