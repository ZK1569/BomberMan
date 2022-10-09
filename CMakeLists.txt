cmake_minimum_required(VERSION 3.23)
project(BomberMan C)

set(CMAKE_C_STANDARD 99)

add_executable(BomberMan Code/main.c Code/Func/map.c Code/Header/map.h Code/Header/Structure.h Code/Func/show.c Code/Header/show.h Code/Func/player.c Code/Header/player.h)
