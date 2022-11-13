//
// Created by Cristian Ursu on 09/10/2022.
//

#ifndef BOMBERMAN_MAP_H
#define BOMBERMAN_MAP_H

#include "Structure.h"
char **createMap(int x, int y);

Map newMap(int x, int y);

char *whatMap(int number);

Map openMap(char *path);

void createBorderMap(Map map);

void showAllMaps(Config *config);


#endif //BOMBERMAN_MAP_H
