//
// Created by Cristian Ursu on 09/10/2022.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include "Structure.h"

Player newPlayer(int x, int y, char show, Map *map);

int move(char direction, Player *player, Map *map);

#endif //BOMBERMAN_PLAYER_H
