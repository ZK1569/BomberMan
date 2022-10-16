//
// Created by Cristian Ursu on 16/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "../Header/Bomb.h"
#include "../Header/Structure.h"

char whatToPut(int x, int y, Map *map){
    switch (map->map[y][x]) {
        case 'm':
            return '#';
        case '0':
            return '*';
    }
}

void explose(int x, int y, int sizeExposion, Map *map){

//    caseExploded(x,y,sizeExposion);

    for (int i = 1; i <= sizeExposion; ++i) {
        // Up
        printf("%c %d\n",map->map[y-i][x], i);
        if (map->map[y-i][x] != 'X'){
            map->map[y-i][x] = whatToPut(x, y-i, map);
        }else{
            break;
        }
    }
    for (int i = 1; i <= sizeExposion; ++i) {
        // Down
        if (map->map[y+i][x] != 'X'){
            map->map[y+i][x] = whatToPut(x, y+i, map);
        }else{
            break;
        }
    }
    for (int i = 1; i <= sizeExposion; ++i) {
        // Right
        if (map->map[y][x+i] != 'X'){
            map->map[y][x+i] = whatToPut(x+i, y, map);
        }else{
            break;
        }
    }
    for (int i = 1; i <= sizeExposion; ++i) {
        // Left
        if (map->map[y][x-i] != 'X'){
            map->map[y][x-i] = whatToPut(x-i, y, map);
        }else{
            break;
        }
    }

    if(map->map[y][x] == 'm'){
        map->map[y][x] = '#';
    }else{
        map->map[y][x] = '*';
    }
}

void explosionGone(Map *map){
    for (int i = 0; i < map->y; ++i) {
        for (int j = 0; j < map->x; ++j) {
            if (map->map[i][j] == '*' || map->map[i][j] == '#'){
                map->map[i][j] = '0';
            }
        }
    }
}
