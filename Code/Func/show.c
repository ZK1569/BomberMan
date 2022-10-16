//
// Created by Cristian Ursu on 09/10/2022.
//

#include <stdlib.h>
#include <stdio.h>

#include "../Header/show.h"
#include "../Header/map.h"

// ░▒▓█ ♛

void show(Map map, short type){
    // Print test: Show map
    for (int i = 0; i < map.y; i++) {
        for (int y = 0; y < map.x; y++) {
            if (!type){
                printf("%c ", map.map[i][y]);
            }else{
                switch (map.map[i][y]) {
                    case 'X':
                        printf("█|");
                        break;
                    case '0':
                        printf(" |");
                        break;
                    case 1:
                        printf("♛|");
                        break;
                    case 'm':
                        printf("░|");
                        break;
                    case 'q':
                        printf("Q|");
                        break;
                    case '*':
                        printf("*|");
                        break;
                    case '#':
                        printf("#|");
                        break;
                    default:
                        printf("?|");
                }
            }
        }
        printf("\n");
    }
}
