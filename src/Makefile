SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall -O3 -ffast-math -pg # -fomit-frame-pointer
LDLIBS=-lm

TARGET=ljmd-serial.x

all: $(TARGET)

$(TARGET): datafile.o input.o helpers.o force.o main.o output.o velverlet.o
	$(CC) -o $(TARGET) $(CFLAGS) $^

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.mod *.o $(TARGET)

run:
	cp ../examples/argon* .
	./ljmd-serial.x < argon_108.inp
