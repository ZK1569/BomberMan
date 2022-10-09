//
// Created by Cristian Ursu on 09/10/2022.
//

#ifndef BOMBERMAN_MAP_H
#define BOMBERMAN_MAP_H

#include "Structure.h"
char **createMap(int x, int y);

Map newMap(int x, int y);

void createBorderMap(Map map);


#endif //BOMBERMAN_MAP_H
