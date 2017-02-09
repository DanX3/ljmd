SHELL=/bin/sh
CC=gcc
CFLAGS=-Wall -O3 -ffast-math -pg # -fomit-frame-pointer
LDLIBS=-lm

TARGET=ljmd-serial.x
TEST_A=test-a.x
TEST_C=test-c.x

.SUFFIXES:
all: $(TARGET)

test_a: $(TEST_A)
test_c: $(TEST_C)

$(TARGET): datafile.o input.o helpers.o force.o main.o output.o velverlet.o
	$(CC) -o $(TARGET) $(CFLAGS) $(LDLIBS) $^

$(TEST_A): datafile.o input.o helpers.o force.o test_a.o output.o velverlet.o
	$(CC) -o $(TEST_A) $(CFLAGS) $(LDLIBS) $^

$(TEST_C): datafile.o input.o helpers.o force.o test_c.o output.o velverlet.o
	$(CC) -o $(TEST_C) $(CFLAGS) $(LDLIBS) $^

%.o: %.c
	$(CC) -c $< $(CFLAGS)





clean:
	rm -f *.mod *.o $(TARGET) $(TEST_A) *~
