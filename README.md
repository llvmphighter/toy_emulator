# TOY_Emulator
[![Build Status](https://travis-ci.org/llvmphighter/TOY_Emulator.svg?branch=main)](https://travis-ci.org/llvmphighter/TOY_Emulator)

This repository contains an experimental CPU **TOY**.

## Instruction Set
* MOVi
* ADDri
* SUBri
* STORErr
* LOADrr
* CALL
* RET

## Prerequisites
* gcc/g++ compilers and libraries on Ubuntu Linux 16.04 or later:
```shell
$ sudo apt install build-essential
```
* libelf-dev
``` shell
$ sudo apt-get install libelf-dev
```
## Build
```shell
$ mkdir <path-to-build-directory> && cd <path-to-build-directory>
$ cmake <path-to-toy-emulator>
$ make
```

## Test
Under the build directory 
```shell
$  ./test/verifier

