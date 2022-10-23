cmake_minimum_required(VERSION 3.22.0)
project(BomberMan C)

set(CMAKE_C_STANDARD 99)

# add all executables from the Code directory
file(GLOB_RECURSE SOURCES "Code/*.c")
add_executable(BomberMan ${SOURCES})
