$(shell mkdir -p dist >/dev/null)
$(shell mkdir -p build >/dev/null)

## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature
#CFLAGS = -g -O0
CFLAGS = -Os -Wall -gdwarf-2
LFLAGS = -gdwarf-2
DEVICE = atmega324p

all: dist/atmega324p_u1.axf dist/atmega324p_u1.elf dist/atmega324p_u1.hex dist/atmega324p_u1.bin

dist/atmega324p_u1.hex: dist/atmega324p_u1.elf
	avr-objcopy -O ihex $< $@

dist/atmega324p_u1.bin: dist/atmega324p_u1.axf
	avr-objcopy -O binary $< $@

dist/atmega324p_u1.elf: build/main.o build/sys.o build/mon.o build/gdb.o build/app.o
	avr-gcc -o $@ $(LFLAGS) -mmcu=$(DEVICE) $^
	@echo
	@echo "==> $@ ==========="
	@avr-size --mcu=$(DEVICE) --format=avr dist/atmega324p_u1.elf


build/main.o: src/main.cpp src/global.h src/sys.hpp src/app.hpp src/gdb.hpp src/sys.cpp src/app.cpp src/mon.cpp src/gdb.cpp
	avr-g++ -o $@ $(CFLAGS) -mmcu=$(DEVICE) -c -DCOMPILE $<

build/sys.o: src/sys.cpp src/global.h src/mon.hpp src/app.hpp src/sys.hpp
	avr-g++ -o $@ $(CFLAGS) -mmcu=$(DEVICE) -c -DCOMPILE $<

build/gdb.o: src/gdb.cpp src/global.h src/gdb.hpp src/app.hpp src/sys.hpp
	avr-g++ -o $@ $(CFLAGS) -mmcu=$(DEVICE) -c -DCOMPILE $<

build/mon.o: src/mon.cpp src/global.h src/global.h src/mon.hpp src/app.hpp src/sys.hpp
	avr-g++ -o $@ $(CFLAGS) -mmcu=$(DEVICE) -c -DCOMPILE $<

build/app.o: src/app.cpp src/global.h src/global.h src/mon.hpp src/app.hpp src/sys.hpp
	avr-g++ -o $@ $(CFLAGS) -mmcu=$(DEVICE) -c -DCOMPILE $<

u1: dist/atmega324p_u1.hex
	avrdude -c usbasp -p $(DEVICE) -e -U flash:w:$<:i

u1bl: dist/atmega324p_u1.hex ../bootloader_u1/bootloader_atmega324p_115200_12MHz.hex
	avrdude -c usbasp -p $(DEVICE) -e -U flash:w:$<:i
	avrdude -c usbasp -p $(DEVICE) -D -U flash:w:../bootloader_u1/bootloader_atmega324p_115200_20MHz.hex:i

easy: dist/atmega324p_u1.hex
	nohup /bin/bash htl ep dist/atmega324p_u1.hex atmega324p 57600 /dev/ttyUSB0 &

sim: dist/atmega324p_u1.elf
	simavr -g -m $(DEVICE) dist/atmega324p_u1.elf

build/simavr.o: src/simavr.c
	avr-gcc -o $@ -Os -std=gnu99 -Wall -gdwarf-2 -mmcu=$(DEVICE) -c -DCOMPILE $<

axf: dist/atmega324p_u1.axf

dist/atmega324p_u1.axf: build/main.o build/sys.o build/mon.o build/gdb.o build/app.o build/simavr.o
	avr-gcc -Wall -gdwarf-2 -mmcu=$(DEVICE) -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 -o ${@} $^
	@echo "==> $@ ==========="
	@avr-size --mcu=$(DEVICE) --format=avr dist/atmega324p_u1.axf

#test: build/main.o build/sys.o build/mon.o build/gdb.o build/app.o build/simavr.o
#		avr-gcc -Wall -gdwarf-2 -Os -mmcu=$(DEVICE) -DF_CPU=20000000 \
#                        -fno-inline-small-functions \
#                        -ffunction-sections -fdata-sections \
#                        -Wl,--relax,--gc-sections \
#                        -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 \
#                        -I/work/sx/simavr/simavr/sim/avr \
#                         -o ${@} $^


clean:
	-@rm -r dist
	-@rm -r build
