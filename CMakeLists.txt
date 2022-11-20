cmake_minimum_required(VERSION 3.22.0)
project(BomberMan C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# add all executables from the Code directory
file(GLOB_RECURSE SOURCES "Code/*.c")
add_executable(BomberMan ${SOURCES} Code/Func/Bomb.c Code/Header/Bomb.h)
target_link_libraries(BomberMan ${SDL2_LIBRARIES} -lSDL2_image -lSDL2_ttf)
