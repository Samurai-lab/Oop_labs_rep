cmake_minimum_required(VERSION 3.25)
project(TaskTen)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaskTen main.cpp LinkedList.h Pair.cpp Pair.h Iterator.cpp Iterator.h LinkedList.cpp FileIO.cpp FileIO.h)
