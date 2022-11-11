//
// Created by Cristian Ursu on 16/10/2022.
//

#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include "map.h"

void explose(int x, int y, int sizeExposion, Map *map, Player *allPlayers, int nbrPlayers);

void explosionGone(Map *map);

#endif //BOMBERMAN_BOMB_H
