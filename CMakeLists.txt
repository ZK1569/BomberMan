cmake_minimum_required(VERSION 3.22.0)
project(BomberMan C)

set(CMAKE_C_STANDARD 99)

add_executable(BomberMan Code/main.c Code/Func/config.c Code/Header/config.h Code/Func/map.c Code/Header/map.h Code/Header/Structure.h Code/Func/show.c Code/Header/show.h Code/Func/player.c Code/Header/player.h)
