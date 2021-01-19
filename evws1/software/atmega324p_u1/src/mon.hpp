#ifndef MON_HPP
#define MON_HPP

#include "global.h"
#include <avr/io.h>
#include "sys.hpp"

// declarations

namespace mon {

	void init ();
	void main ();

	#ifdef GLOBAL_MONITOR

		extern const char LINESTART[];

		struct MonCmdInfo {
			PGM_P pInfo;
			int8_t (*pFunction)(uint8_t, char *[]);
		};

		struct Mon {
			uint8_t flags_u8;
		};
		extern struct Mon mon;
		extern const struct MonCmdInfo PMEMSTR_CMDS[];

		// functions

		uint8_t getCmdCount ();
		int8_t printLineHeader (uint8_t lineIndex);
		int8_t printLine (uint8_t lineIndex, char keyPressed);

	#endif // GLOBAL_MONITOR

}

#endif /* MON_HPP */
