SHELL=/bin/sh
CC=gcc -std=c99
CFLAGS=-Wall -O3 -ffast-math -pg # -fomit-frame-pointer
LDLIBS=-lm

SRCS=$(find -name '*.c')



TARGET=ljmd-serial.x
SHARED_OBJ=libljmd.so
TEST_A=test-a.x
TEST_B=test-b.x
TEST_C=test-c.x
TEST_D=test-d.x


.SUFFIXES:
all: $(TARGET) $(SHARED_OBJ)
so: datafile.so input.so helpers.so force.so output.so velverlet.so

test_a: $(TEST_A)
test_b: $(TEST_B)
test_c: $(TEST_C)
test_d: $(TEST_D)

$(TARGET): datafile.o input.o helpers.o force.o main.o output.o velverlet.o
	$(CC) -o $(TARGET) $(CFLAGS) $(LDLIBS) $^

$(TEST_A): datafile.o input.o helpers.o force.o test_a.o output.o velverlet.o
	$(CC) -o $(TEST_A) $(CFLAGS) $(LDLIBS) $^

$(TEST_B): datafile.o input.o helpers.o force.o test_b.o output.o velverlet.o
	$(CC) -o $(TEST_B) $(CFLAGS) $(LDLIBS) $^


$(TEST_C): datafile.o input.o helpers.o force.o test_c.o output.o velverlet.o
	$(CC) -o $(TEST_C) $(CFLAGS) $(LDLIBS) $^

$(TEST_D): datafile.o input.o helpers.o force.o test_d.o output.o velverlet.o
	$(CC) -o $(TEST_D) $(CFLAGS) $(LDLIBS) $^

run_tests: $(TEST_A) $(TEST_B) $(TEST_C) $(TEST_D)
	cp $(TEST_A) $(TEST_B) $(TEST_C) $(TEST_D) ../test/
	./../test/test-a.x
	./../test/test-b.x
	./../test/test-c.x
	./../test/test-d.x < ../test/test-d.inp

test_interface: $(TARGET) $(SHARED_OBJ)
	cp ../examples/argon* .
	./ljmd-serial.x < argon_108.inp > C_output
	cd ../interface && \
	python launcher.py ../examples/argon_108.inp > py_output
	cp ../interface/py_output .
	cat C_output | tail -n +3 | head -n -1 > C_output && \
	cat py_output | tail -n +3 | head -n -1 > py_output && \
	echo "Now use vdiff on C_output and py_output"


%.o: %.c
	$(CC) -c $< $(CFLAGS) -fPIC

%.so: %.o
	$(CC) -shared $< -o $@

$(SHARED_OBJ): so
	$(CC) -fPIC -shared *.o -o $@
	mkdir -p ../interface/lib/
	cp $@ ../interface/lib/


clean:

	rm -f *.mod *.o *.so $(TARGET) $(TEST_A) *~ *.x *.txt


run:
	cp ../examples/argon* .
	./ljmd-serial.x < argon_108.inp
