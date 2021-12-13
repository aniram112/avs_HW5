cmake_minimum_required(VERSION 3.20)
project(avs_hw5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")


add_executable(avs_hw5 main.cpp Book.h Library.h Row.h Shelf.h)
