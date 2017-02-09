SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall -g -O3 -ffast-math -fomit-frame-pointer
LDLIBS=-lm

TARGET=ljmd-serial.x

all: $(TARGET)

$(TARGET): datafile.o input.o helpers.o force.o main.o output.o velverlet.o
	$(CC) -o $(TARGET) $(CFLAGS) $^

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.mod *.o $(TARGET)
