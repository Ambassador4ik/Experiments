cmake_minimum_required(VERSION 3.26)
project(StringGen)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(StringGen main.cpp StringGenerator.cpp)

target_link_libraries(StringGen stdc++)