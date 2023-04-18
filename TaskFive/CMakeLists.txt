cmake_minimum_required(VERSION 3.24)
project(TaskFive)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaskFive WIN32 main.cpp Person.cpp Person.h Student.cpp Student.h Vector.cpp Vector.h Organism.cpp Organism.h)
