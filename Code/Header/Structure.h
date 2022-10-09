//
// Created by Cristian Ursu on 09/10/2022.
//

#ifndef BOMBERMAN_STRUCTURE_H
#define BOMBERMAN_STRUCTURE_H

typedef struct {
    int x;
    int y;
    char **map;
}Map;

typedef struct {
    int x;
    int y;
    char show;
}Player;

#endif //BOMBERMAN_STRUCTURE_H
