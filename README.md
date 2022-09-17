# OOP Class

## Dependencies

Make sure your system have those tools installed:

```
git cmake gcc(or other C/C++ compiler)
```

> My current machine is using Arch Linux and clang 14 as my building environment, but any Linux distro(including WSL) should work out of the box as well. Not sure if this works natively on Windows.

## Quick Start

To configure and build the project, run:

```bash
cmake -B build
cmake --build build

./build/OOP # this is the actual binary
--- OR ---
./build/ut_all # this is the unittest binary
```