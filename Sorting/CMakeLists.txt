cmake_minimum_required(VERSION 3.24)
project(Sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorting main.cpp Sorting.h InsertionSort.cpp SelectionSort.cpp CountSort.cpp Homework1__Medium_to_Hard/InsertionSort_V2.cpp)
