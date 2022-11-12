//
// Created by Cristian Ursu on 09/10/2022.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include "Structure.h"

typedef enum {
    MOVE_UP = 'z',
    MOVE_LEFT = 'q',
    MOVE_DOWN = 's',
    MOVE_RIGHT = 'd',
    MOVE_NO = 'a',
} Movement;

typedef enum {
    ACTION_PLACE_BOMB = 'e',
} Action;

Player newPlayer(char *name, int x, int y, char show, Map *map);

void applyItemOnPlayer(char item, Player *player, Config *config);
char getPlayerInput(void);
int move(char direction, Player *player, Map *map, Player *players, Config *config, int nbrPlayers);
char *setCurrentPlayerCharacter(int playerTurn, Config *config);
int killPlayer(int x, int y, Player *allPlayers);

#endif // BOMBERMAN_PLAYER_H
