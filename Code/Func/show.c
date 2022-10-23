//
// Created by Cristian Ursu on 09/10/2022.
//

#include <stdlib.h>
#include <stdio.h>

#include "../Header/show.h"
#include "../Header/map.h"

// ░▒▓█

void show(Map map, short type, Config *config){
    // Print test: Show map
    for (int i = 0; i < map.y; i++) {
        for (int y = 0; y < map.x; y++) {
            if (!type){
                printf("%c ", map.map[i][y]);
            }else{
                switch (map.map[i][y]) {
                  case 'X':
                    printf("%s|", config->strongWall);
                    break;
                  case '0':
                    printf("%s|", config->emptySpace);
                    break;
                  case 1:
                    printf("%s|", config->player1);
                    break;
                  case 'm':
                    printf("%s|", config->weakWall);
                    break;
                  case 'q':
                    printf("%s|", config->bomb);
                    break;
                  case '*':
                    printf("%s|", config->bombFire);
                    break;
                  case '#':
                    printf("%s|", config->destroyedWall);
                    break;
                  default:
                    printf("%s|", config->emptySpace);
                }
            }
        }
        printf("\n");
    }
}
