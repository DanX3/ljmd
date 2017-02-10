##README

### Makefile instructions

The Makefile is inside the source directory.

- type `make` inside `/src/` for build the program and the shared library required for python interface. The `.so` file will be inside the `/interface/lib` directory.

- type `make test-(a,b,c or d)` for build the relative test binary.

- type `make run_tests` for compile and run all the tests.

- type `make test_interface` for a rough test of the python interface: it produces a C_output.txt file and a py_output.txt to be compared.


### Python interface issues

The python interface works correctly. It is basically a transposition of the `main.c` file inside the `\src` folder.

The syntax for launching form python is:

`python "path to input file"`

While the output have been tested by hand (using vimdiff) to be the same of the one obtained with the C code, a rough `test_interface` can be made by the make file to produce to rough output for comparison.
