//
// Created by Cristian Ursu on 09/10/2022.
//

#include <stdlib.h>
#include <stdio.h>

#include "../Header/show.h"
#include "../Header/map.h"

// ░▒▓█

void show(Map map, short type){
    // Print test: Show map
    for (int i = 0; i < map.y; i++) {
        for (int y = 0; y < map.x; y++) {
            if (!type){
                printf("%c ", map.map[i][y]);
            }else{
                switch (map.map[i][y]) {
                  case 'X':
                    printf("X|");
                    break;
                  case '0':
                    printf(" |");
                    break;
                  case 1:
                    printf("U|");
                    break;
                  case 'm':
                    printf("n|");
                    break;
                  case 'q':
                    printf("Q|");
                    break;
                  case '*':
                    printf("*|");
                    break;
                }
            }
        }
        printf("\n");
    }
}
