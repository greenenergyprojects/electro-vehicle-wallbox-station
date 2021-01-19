#include "mon.hpp"
#include "sys.hpp"
#include "app.hpp"

#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>


namespace mon {

	#ifdef GLOBAL_MONITOR

		// defines
		// ...

		// declarations and definations

		int8_t cmdInfo (uint8_t argc, char *argv[]);
		int8_t cmdTest (uint8_t argc, char *argv[]);

		const char LINESTART[] = "\n\r> ";

		const char LINE_WELCOME[] PROGMEM = "Line-Mode: CTRL-X, CTRL-Y, CTRL-C, Return  \n\r";
		const char CMD_INFO[] PROGMEM = "info\0Application infos\0info";
		const char CMD_TEST[] PROGMEM = "test\0commando for test\0test ...";

		const struct MonCmdInfo PMEMSTR_CMDS[] PROGMEM = {
			{ CMD_INFO, cmdInfo }
			, { CMD_TEST, cmdTest }
		};

		struct Mon mon;

	#endif // GLOBAL_MONITOR

	// ----------------------------------------------------------
	// init() is called one time at startup
	// ----------------------------------------------------------
	void init () {
	#ifdef GLOBAL_MONITOR
	memset((void *)&mon, 0, sizeof(mon));
	printf(mon::LINESTART);
	#endif
	}

	// ----------------------------------------------------------
	// main() is recalled by main loop (out of interrupt)
	// ----------------------------------------------------------
	void main () {
	}

	#ifdef GLOBAL_MONITOR

		uint8_t getCmdCount () {
			return sizeof(PMEMSTR_CMDS) / sizeof(struct MonCmdInfo);
		}


		// --------------------------------------------------------
		// Monitor commands of the application
		// --------------------------------------------------------

		int8_t cmdInfo (uint8_t argc, char *argv[]) {
			printf("app.flags_u8  : ");
			sys::printHexBin8(sys::sys.flags_u8);
			printf("\n");
			return 0;
		}


		int8_t cmdTest (uint8_t argc, char *argv[]) {
			for (uint8_t i = 0; i < argc; i++) {
				printf("%u: %s\n\r", i, argv[i]);
			}
			return 0;
		}


		// --------------------------------------------------------
		// Monitor-Line for continues output
		// --------------------------------------------------------

		int8_t printLineHeader (uint8_t lineIndex) {
		if (lineIndex==0)
			sys::printStringFromFlash(LINE_WELCOME);

			switch (lineIndex) {
				case 0: printf("L0 | app.flags_u8"); return 20;
				case 1: printf("L1 | counter  (press 'c' for reset)"); return 40;
				default: return -1; // this line index is not valid
			}
		}

		int8_t printLine (uint8_t lineIndex, char keyPressed) {

			switch (lineIndex) {
				case 0: {
					printf("   | "); sys::printBin(app::app.errCnt, 0);
					return 2;
				}

				case 1: {
					static uint16_t cnt = 0;
					if (keyPressed == 'c') {
						cnt = 0;
					}
					printf("   |  0x%04x   ", cnt++);
					return 2;
				}

				default: return -1;
			}
		}

	#endif // GLOBAL_MONITOR
}
