$(shell mkdir -p dist >/dev/null)
$(shell mkdir -p build >/dev/null)

## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature
CFLAGS = -g -O0
#CFLAGS = -Os -Wall -gdwarf-2
LFLAGS = -gdwarf-2
DEVICE = atmega324p
NAME = test


all: dist/$(NAME).afx dist/$(NAME).elf dist/$(NAME).hex dist/$(NAME).bin

dist/$(NAME).hex: dist/$(NAME).elf
	avr-objcopy -O ihex $< $@

dist/$(NAME).bin: dist/$(NAME).afx
	avr-objcopy -O binary $< $@

dist/$(NAME).elf: build/main.o
	avr-gcc -o $@ $(LFLAGS) -mmcu=$(DEVICE) $^
	@echo
	@echo "==> $@ ==========="
	@avr-size --mcu=$(DEVICE) --format=avr dist/$(NAME).elf


build/main.o: src/main.cpp
	avr-g++ -o $@ $(CFLAGS) -mmcu=$(DEVICE) -c -DCOMPILE $<

sim: dist/$(NAME).elf
	simavr -g -m $(DEVICE) dist/$(NAME).elf

build/simavr.o: src/simavr.c
	avr-gcc -o $@ -Os -std=gnu99 -Wall -gdwarf-2 -mmcu=$(DEVICE) -c -DCOMPILE $<

afx: dist/$(NAME).afx

dist/$(NAME).afx: build/main.o build/simavr.o
	avr-gcc -Wall -gdwarf-2 -mmcu=$(DEVICE) -o ${@} -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 $^
	@echo "==> $@ ==========="
	@avr-size --mcu=$(DEVICE) --format=avr dist/$(NAME).afx

test: build/main.o build/sys.o build/mon.o build/gdb.o build/app.o build/simavr.o
		avr-gcc -Wall -gdwarf-2 -Os -mmcu=$(DEVICE) -DF_CPU=20000000 \
                        -fno-inline-small-functions \
                        -ffunction-sections -fdata-sections \
                        -Wl,--relax,--gc-sections \
                        -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 \
                        -I/work/sx/simavr/simavr/sim/avr \
                         -o ${@} $^


clean:
	-@rm -r dist
	-@rm -r build
