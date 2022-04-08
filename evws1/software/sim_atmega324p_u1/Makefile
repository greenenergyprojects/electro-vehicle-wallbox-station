
CPPFLAGS = 
CPPFLAGS += --std=c++11
#CPPFLAGS += -Isimavr/simavr/sim
CPPFLAGS += -O2
CPPFLAGS += -Wall
CPPFLAGS += -Wextra
CPPFLAGS += -Wno-unused-parameter
CPPFLAGS += -Wno-unused-result
CPPFLAGS += -Wno-missing-field-initializers
CPPFLAGS += -Wno-sign-compare
CPPFLAGS += -g
CPPFLAGS += -fPIC
CPPFLAGS += -MMD

LFLAGS =
LFLAGS += -MMD -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-result -Wno-missing-field-initializers -Wno-sign-compare -g -fPIC
#LFLAGS += -Wl,-rpath,/home/steiner/Private/work/simavr/simavr/obj-x86_64-linux-gnu
#LFLAGS += -lsimavr/simavr/obj-x86_64-linux-gnu/libsimavr.so
#LFLAGS += -llibsimavr.a

LPATH=
#LPATH=-L/home/steiner/Private/work/simavr/simavr/obj-x86_64-linux-gnu
LIBS=
LIBS += -lsimavr
LIBS += -lelf

#LFLAGS += -lelf

all: dist/sim_atmega324p_u1.elf

build/sim_atmega324p_u1.o: sim_atmega324p_u1.cpp
	gcc -c $(CPPFLAGS) -o $@  $<

dist/sim_atmega324p_u1.elf: build/sim_atmega324p_u1.o
	gcc $(LFLAGS) $(LPATH) -o  $@ $^ $(LIBS)

test:
	gcc -I/usr/include/libdrm --std=gnu99 -Wall -I. -I../parts -I../..//include -I../..//simavr/sim -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-result -Wno-missing-field-initializers -Wno-sign-compare -g -fPIC -MMD \
        evws1.c  -c -o obj-x86_64-linux-gnu/evws1.o
	cc -MMD -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-result -Wno-missing-field-initializers -Wno-sign-compare -g -fPIC  -Wl,-rpath,/home/steiner/Private/work/simavr/examples/board_evws1/../../simavr/obj-x86_64-linux-gnu -o obj-x86_64-linux-gnu/evws1.elf ../parts/obj-x86_64-linux-gnu/button.o obj-x86_64-linux-gnu/evws1.o -lpthread -lGLU -lGL -lglut -L/home/steiner/Private/work/simavr/examples/board_evws1/../../simavr/obj-x86_64-linux-gnu -lsimavr -lm -lelf

clean:
	rm -rf dist
	rm -rf build
	mkdir build dist
