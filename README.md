# PBN

PBN is a command line tool for working with Portable Bridge Notation files. 

Credit project (zápočtový program) for Cpp Programming course at MFF Cuni.

## Used libraries

PBN utilizes some libraries:

- Boost::program_options

## Supported functions

- parse a file and validate it 
- printing overview information about a file
- stripping a file of unnecessary parts
- creating board analyses in a file

## Features plan

- exports to pdf, html
- stricter adherence to PBN standard (currently it is not fully compliant)
  - validate
  - support more obscure import variant
  - check used features against declared version
- pbn generation using external tools (e.g. Bigdeal)

## User docs

User documentation can be found in [guide.md](guide.md)

## Building

PBN is written in C++20 and uses CMake as build system.

### Step 0: Dependencies

To build PBN, you need to configure CMake to be able to find boost.

### Step 1: Configure

Create a directory where you want to build and enter it.

Run CMake with the `CMakeLists.txt` file as argument:

```bash
cmake CMakeLists.txt
```

To use a different generator, you can use the `-G` flag:

```bash
cmake CMakeLists.txt -G "MinGW Makefiles"
```

### Step 2: Build

To build, run

```bash
cmake --build .
```

## Documentation

This project uses Doxygen to create documentation.

To build the documentation, use the provided Doxyfile or create or own and run

```bash
doxygen Doxyfile
```

## Testing

To run the tests, build the project. A second target of pbn_test should be built, simply execute it:

```bash
./run_tests
```

Additionally, more options can be provided, run with help flag to see.

```bash
./run_test --help
```

## Authors

[Zdeněk Tomis](zdenektomis.eu)
