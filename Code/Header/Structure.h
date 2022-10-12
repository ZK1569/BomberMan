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
    int life;
}Bomb;

typedef struct {
    int x;
    int y;
    char show;
    char back;
    int nbrBomb;
    Bomb *myBomb;
}Player;

#endif //BOMBERMAN_STRUCTURE_H
