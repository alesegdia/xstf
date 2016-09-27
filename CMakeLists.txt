cmake_minimum_required(VERSION 2.6)
project(xstf)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

add_library(xstf src/xstf.h src/xstf.cpp)
include_directories(xstf src)

set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/lib)
