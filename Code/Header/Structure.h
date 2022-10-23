//
// Created by Cristian Ursu on 09/10/2022.
//

#ifndef BOMBERMAN_STRUCTURE_H
#define BOMBERMAN_STRUCTURE_H

typedef struct
{
    // map
    int rows;
    int columns;
    char *strongWall;
    char *weakWall;
    char *emptySpace;

    // players
    char *player1;
    char *player2;
    char *player3;
    char *player4;
    char *bomb;
    char *bombFire;

    // random items
    char *bombDown;
    char *bombUp;
    char *yellowFire;
    char *blueFire;
    char *redFire;
    char *bombPass;
    char *kick;
    char *vest;
    char *heart;
    char *oneUp;
} Config;

typedef struct
{
    int x;
    int y;
    char **map;
} Map;

typedef struct
{
    int x;
    int y;
    int life;
} Bomb;

typedef struct
{
    int x;
    int y;
    char show;
    char back;
    char name[20];
    int nbrBomb;
    Bomb *myBomb;
} Player;

#endif // BOMBERMAN_STRUCTURE_H
