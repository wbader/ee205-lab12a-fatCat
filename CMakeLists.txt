cmake_minimum_required(VERSION 3.16)
project(fatCat)

set(CMAKE_CXX_STANDARD 14)

add_executable(fatCat main.cpp Weight.h Weight.cpp config.h)
add_executable(fatCat_test test.cpp Weight.h Weight.cpp config.h )