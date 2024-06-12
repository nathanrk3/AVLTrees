cmake_minimum_required(VERSION 3.27)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVLTREETEST
        src/tree.h
        src/tree.cpp
        test-unit/test.cpp
)
