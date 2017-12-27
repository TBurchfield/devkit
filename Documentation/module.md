# Sample Module Layout

- Every executable feature of devkit is a module
- Each module exists as its own directory under `Modules/`
- Code that is repeated across modules should be moved out into the shared
Library section
- Modules are responsible for their own tests, which must be run via `make test`
(so the main module may test the code before building)

- Each module should have its own Makefile, which the core makefile can call by
`cd`-ing into the main directory, running `make` and referencing the resultant output file.

So for Example, the following module `test` must support:
```
cd /path/to/test
# verify all code. TESTS SHOULD PASS
make test

# produces test.o
make
```
