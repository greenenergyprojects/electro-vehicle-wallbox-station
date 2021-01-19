#ifndef GLOBAL_H
#define GLOBAL_H

#define GLOBAL_UART0_BITRATE    115200
#define GLOBAL_UART1_BITRATE    115200
#define GLOBAL_UART_RECBUFSIZE  16
#define LF "\r\n"

#define GLOBAL_MONITOR
#define GLOBAL_MON_MAXARGV 4
#define GLOBAL_MONCMD_SINFO
#define GLOBAL_MONCMD_SETMEM
#define GLOBAL_MONCMD_HEXDUMP
#define GLOBAL_MON_ONLYLOCASE

#define F_CPU 12000000UL
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
