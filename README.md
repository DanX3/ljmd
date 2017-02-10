##README

### Makefile instructions

The Makefile is inside the source directory.

- type `make` inside `/src/` for build the program and the shared library required for python interface. The `.so` file will be inside the `/interface/lib` directory.

- type `make test-(a,b,c or d)` for build the relative test binary.

- type `make run_tests` for compile and run all the tests.


### Python interface issues

We have noticed that when passing the struct `sys` to a C function, inside the c enviornment all values of sys are 0. Moreover every changes inside the c environment are not passed to the `sys` variable in python.
