cmake_minimum_required(VERSION 3.27)
project(multithreaded_sorts)

set(CMAKE_CXX_STANDARD 11)

add_executable(multithreaded_sorts main.cpp
        multithreaded_quicksort.h
        multithreaded_mergesort.h)
