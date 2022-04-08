#ifndef GDB_HPP
#define GDB_HPP

#include "global.h"
#include <avr/io.h>
#include "sys.hpp"

// declarations

namespace gdb {

	const uint8_t BUFFER_SIZE = 96; // 137;

	enum BufferState { idle = 0, ctrlc, data, esc, chk1, chk2, chk2err, exec, execovf, send, waitack };

	struct Buffer {
		enum BufferState state;
		uint8_t wpos;
		uint8_t rpos;
		uint8_t chkSum;
		char    buffer[BUFFER_SIZE];
	};

	struct Gdb {
		uint8_t errCnt;
		struct Buffer buf;

	};

	extern struct Gdb gdb;

	void init ();
	void main ();
	void handleUartIsrByte (char c);

}

#endif // GDB_HPP
