cmake_minimum_required(VERSION 3.26.4)
set(CMAKE_CXX_STANDARD 11)
project(CPU-Sim)
add_executable(cpu main.cpp cpu.cpp ram.cpp)
