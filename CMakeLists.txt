cmake_minimum_required(VERSION 3.7)
project(ZMPO4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Matrix.cpp Matrix.h)
add_executable(ZMPO4 ${SOURCE_FILES})