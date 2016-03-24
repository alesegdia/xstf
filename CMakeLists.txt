cmake_minimum_required(VERSION 2.6)
project(xstf)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

add_library(xstf include/xstf/testbench.h src/testbench.cpp)
include_directories(include)

set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/lib)
