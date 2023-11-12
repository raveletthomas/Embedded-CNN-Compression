# Embedded-CNN-Compression

The aim of this university project, which is taking place at the Technical University of Vienna, is to implement various compression/decompression algorithms in C++ for use with convolutional neural networks (CNNs) on embedded systems.

## Overview

- Layer.h / Layer.cpp : class representing a layer of a CNN as a flattened array (e.g. 32 filters of size (5x5) applied on a 3 dimension depht input is represented as a (1, 32 * (5 * 5 * 3 + 1)) = 2432) array.
- benchmark.h / benchmark.cpp : Performs a benchmark on the time and memory capacities of a selected algorithm (for the moment, only Run-Length-Encoding is implemented) 
- comp_algo.h / comp_algo.cpp : implementation of the different compression and decompression algorithms

## Project Layout

```
.
├── README.md               # this file
├── src                     # sources
│   ├── source              # source .cpp files
│   └── include             # header .h files 
├── build                   # builder folder
│   ├── Makefile            # Makefile
|   ├── file_1.o            # object file from file 1 after compilation
|   ├── ...                 # ...
|   └── file_n.o            # object file from file n after compilation
├── bin                     # executable folder
│   └── prog.exe            # executable file after compilation
├── .gitignore              # file patterns to be ignored by git by default when committing
└── .git                    # internal git bookkeeping
```

## Build, perform benchmark, and remove files

**All the following sequences must be run from the project root folder.**
**Once in the build folder, there is no need to retype "cd build".**

Sequence of commands to build:
```shell
cd build
make # generate object (.o) files in current folder and the bin folder with the executable file
```

Sequence of commands to perform benchmark after the project has been built :
```shell
cd build
make run # execute the prog.exe file previously generated in the bin folder 
```

**The following sequences only works on a windows environment. In order to make it works on a linux environment, please replace "del" by "rm -f" in /build/Makefile**

Sequence of commands to remove object files:
```shell
cd build
make clean # remove all object (.o) files from the build folder 
```

Sequence of commands to remove object files and executable file:
```shell
cd build
make cleanall # remove all object (.o) files and the executable (.exe) file from the project
```