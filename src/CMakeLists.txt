# CMakeList.txt : Source level CMake file

# Sets CMake version
cmake_minimum_required (VERSION 3.16)
set (CMAKE_CXX_STANDARD 20)
project (Hash-map)

# Adds the executable called "main" that is built from the source files "main.cpp".
add_executable (Hash-map "main.cpp")