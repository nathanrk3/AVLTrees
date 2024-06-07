cmake_minimum_required(VERSION 3.27)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVLTree
               src/main.cpp
        src/tree.h
        src/tree.cpp)
