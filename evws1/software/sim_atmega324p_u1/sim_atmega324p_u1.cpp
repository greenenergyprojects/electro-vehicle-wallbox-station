#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include <simavr/sim_avr.h>
#include <simavr/avr_ioport.h>
#include <simavr/sim_elf.h>
#include <simavr/sim_gdb.h>
#include <simavr/sim_vcd_file.h>

// #include "sim_avr.h"
// #include "avr_ioport.h"
// #include "sim_elf.h"
// #include "sim_gdb.h"
// #include "sim_vcd_file.h"


uint8_t	pin_state = 0;	// current port B0
avr_t * avr = NULL;

uint64_t timeStampMicros () {
	static uint64_t offset = 0;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	uint64_t tsMicros = 1000000 * tv.tv_sec + tv.tv_usec;
	if (offset == 0) {
		offset = tsMicros;
	}
	return tsMicros;
}

void pin_changed_hook (struct avr_irq_t *irq, uint32_t value, void *param) {
	pin_state = (pin_state & ~(1 << irq->irq)) | (value << irq->irq);
}

int main (int argc, char *argv[]) {
	printf("EVWS1 - SIMULATION\n");

	elf_firmware_t f;
	const char * fname =  "atmega324p_u1.axf";
	elf_read_firmware(fname, &f);
	printf("  firmware %s f=%d mmcu=%s\n", fname, (int)f.frequency, f.mmcu);
	
	avr = avr_make_mcu_by_name(f.mmcu);
	if (!avr) {
		fprintf(stderr, "%s: AVR '%s' not known\n", argv[0], f.mmcu);
		return 1;
	}
	avr_init(avr);
	avr_load_firmware(avr, &f);

	// connect pin PORTB0 on port B to our callback
	avr_irq_register_notify(
		avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('B'), 0),
		pin_changed_hook, 
		NULL
	);

	// even if not setup at startup, activate gdb if crashing
	avr->gdb_port = 1234;
	if (0) {
		//avr->state = cpu_Stopped;
		avr_gdb_init(avr);
	}

	// pthread_t run;
	// pthread_create(&run, NULL, avr_run_thread, NULL);

	uint8_t oldPinState = -1;
	double startMicros = (double)timeStampMicros();
	double startUcMicros = avr->cycle / 20.0;

	while (avr->state != ) {
		avr_run(avr);
		if (pin_state != oldPinState) {
			double oldMicros = startMicros;
			double oldUcMicros = startUcMicros;
			startMicros = (double)timeStampMicros();
			startUcMicros = avr->cycle / 20.0;
			double diffMicros = startMicros - oldMicros;
			double diffUcMicros = startUcMicros - oldUcMicros;
			if (diffMicros < diffUcMicros) {
				usleep((unsigned long)(diffUcMicros - diffMicros));
			}

			// uint64_t ts = avr_get_time_stamp(avr);
			uint64_t ts = 0;
			printf("  Pin: %d  %.3lfs  %.2lf %.2lf\n", pin_state, ts / 1E6, startUcMicros / 1E6, startMicros / 1E6);
		}
		oldPinState = pin_state;
	}

	return 0;
}
