
avrdude -c usbasp -p atmega324p -U efuse:w:0xff:m -U hfuse:w:0xd9:m -U lfuse:w:0xd6:m

avrdude -c usbasp -p atmega324p -e -U flash:w:dist/userboard-atmega324p-12.elf.hex:i