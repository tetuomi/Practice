cmake_minimum_required(VERSION 3.5.1)

add_definitions("-Wall --std=c++11")
include_directories(include)
add_executable(fivestone.out
    src/main.cpp
    src/fivestone.cpp
)
