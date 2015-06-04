#!/bin/sh

#set -x

MYPWD=`pwd`

rm -rf build
mkdir -p build
cd build

cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_VERBOSE_MAKEFILE=0 ../
#cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_VERBOSE_MAKEFILE=1 ../
make

