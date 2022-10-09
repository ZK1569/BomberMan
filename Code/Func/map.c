//
// Created by Cristian Ursu on 09/10/2022.
//

#include "../Header/map.h"

#include <stdio.h>
#include <stdlib.h>

#include "../Header/Structure.h"

char **createMap(int x, int y){
    char **map = malloc(sizeof(char*)*y);
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char)*x);
        // Set every cell to '0';
        for (int j = 0; j < x; j++) {
            map[i][j] = '0';
        }
    }
    return map;
}

Map newMap(int x, int y){
    Map new;
    new.x = x;
    new.y = y;
    new.map = createMap(x, y);

    return new;
}

void createBorderMap(Map map){

    // Set the first and last line to 'X'
    for (int i = 0; i < map.x; ++i) {
        map.map[0][i] = 'X';
        map.map[map.y-1][i] = 'X';
    }
    for (int i = 0; i < map.y; ++i) {
        map.map[i][0] = 'X';
        map.map[i][map.x-1] = 'X';
    }
}



