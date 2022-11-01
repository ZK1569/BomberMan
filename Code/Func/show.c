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
                    printf("%s ", config->strongWall);
                    break;
                  case 'm':
                    printf("%s ", config->weakWall);
                    break;
                  case '#':
                    printf("%s ", config->destroyedWall);
                    break;
                  case '0':
                    printf("%s ", config->emptySpace);
                    break;
                  case 1:
                    printf("%s ", config->player1);
                    break;
                  case 2:
                    printf("%s ", config->player2);
                    break;
                  case 3:
                    printf("%s ", config->player3);
                    break;
                  case 4:
                    printf("%s ", config->player4);
                    break;
                  case 'D':
                    printf("%s ", config->playerDead);
                    break;
                  case 'q':
                    printf("%s ", config->bomb);
                    break;
                  case '*':
                    printf("%s ", config->bombFire);
                    break;
                  case 'd':
                    printf("%s ", config->bombDown);
                    break;
                  case 'u':
                    printf("%s ", config->bombUp);
                    break;
                  case 'y':
                    printf("%s ", config->yellowFire);
                    break;
                  case 'b':
                    printf("%s ", config->blueFire);
                    break;
                  case 'r':
                    printf("%s ", config->redFire);
                    break;
                  case 'p':
                    printf("%s ", config->bombPass);
                    break;
                  case 'k':
                    printf("%s ", config->kick);
                    break;
                  case 'v':
                    printf("%s ", config->vest);
                    break;
                  case 'h':
                    printf("%s ", config->heart);
                    break;
                  case 'o':
                    printf("%s ", config->oneUp);
                    break;
                  default:
                    printf("%s ", config->emptySpace);
                }
            }
        }
        printf("\n");
    }
}
