cmake_minimum_required(VERSION 3.26)
project(SortExp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SortExp main.cpp implementations/QuickSort.h implementations/MergeSort.h implementations/LCPMergeSort.h)

target_link_libraries(SortExp stdc++)