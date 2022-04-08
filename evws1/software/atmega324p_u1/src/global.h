#ifndef GLOBAL_H
#define GLOBAL_H

#define GLOBAL_UART0_BITRATE    115200
#define GLOBAL_UART1_BITRATE    115200
#define GLOBAL_UART0_RECBUFSIZE 1
#define GLOBAL_UART1_RECBUFSIZE 16
#define LF "\r\n"

#define GLOBAL_GDB
#define GLOBAL_GDB_STDOUT uart0out

//#define GLOBAL_MONITOR
//#define GLOBAL_MON_MAXARGV 4
//#define GLOBAL_MONCMD_SINFO
//#define GLOBAL_MONCMD_SETMEM
//#define GLOBAL_MONCMD_HEXDUMP
//#define GLOBAL_MON_ONLYLOCASE

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

#endif // GLOBAL_H
