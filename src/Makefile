SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall -g -O3 -ffast-math -fomit-frame-pointer
LDLIBS=-lm

TARGET=ljmd-serial.x
TEST_A=test-a.x

.SUFFIXES:
all: $(TARGET)

test_b: $(TEST_B)

$(TARGET): datafile.o input.o helpers.o force.o main.o output.o velverlet.o
	$(CC) -o $(TARGET) $(CFLAGS) $(LDLIBS) $^

$(TEST_B): datafile.o input.o helpers.o force.o test_a.o output.o velverlet.o
	$(CC) -o $(TEST_B) $(CFLAGS) $(LDLIBS) $^

%.o: %.c
	$(CC) -c $< $(CFLAGS)





clean:
	rm -f *.mod *.o $(TARGET) $(TEST_A) *~
