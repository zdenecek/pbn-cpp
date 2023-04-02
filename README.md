# PBN

PBN is a command line tool for working with Portable Bridge Notation files. 

Credit project (zápočtový program) for Cpp Programming course at MFF Cuni.

## Used libraries

PBN utilizes some libraries:

- Boost::program_options

## Supported functions

- printing overview information about a file
- stripping a file of unnecessary parts
- creating board analyses in a file

## User docs


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


