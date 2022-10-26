//
// Created by Cristian Ursu on 16/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "../Header/Bomb.h"
#include "../Header/Structure.h"
#include "../Header/player.h"

void whoseBomb(int x, int y, Player *allPlayers){
    // Cherche la personne qui a la bombe au coordonnée x y
    for (int i = 0; i < 3; ++i) { //TODO: Changer le 3 en nombre de jouer
        Player player = allPlayers[i];
        for (int j = 0; j < 3; ++j) { //TODO: Changer le 3 en nombre de bomb total que la personne peut avoir
            if (player.myBomb[j].x == x && player.myBomb[j].y == y){
                player.myBomb[j].x = 0;
                player.myBomb[j].y = 0;
                player.myBomb[j].life = 0;
                break;
            }
        }
    }
}

char whatToPut(int x, int y, Map *map, Player *allPlayers){
    switch (map->map[y][x]) {
        case 'm':
            return '#';
        case '0':
            return '*';
        case 'q':
            whoseBomb(x, y, allPlayers);
            explose(x, y,2, map, allPlayers);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            killPlayer(x,y,allPlayers);
    }
}

void explose(int x, int y, int sizeExposion, Map *map, Player *allPlayers){

//    caseExploded(x,y,sizeExposion);
    // Fait exploser le centre
    map->map[y][x] = '*';

    for (int i = 1; i <= sizeExposion; ++i) {
        // Up
        if (map->map[y-i][x] != 'X'){
            map->map[y-i][x] = whatToPut(x, y-i, map, allPlayers);
        }else{
            break;
        }
    }
    for (int i = 1; i <= sizeExposion; ++i) {
        // Down
        if (map->map[y+i][x] != 'X'){
            map->map[y+i][x] = whatToPut(x, y+i, map, allPlayers);
        }else{
            break;
        }
    }
    for (int i = 1; i <= sizeExposion; ++i) {
        // Right
        if (map->map[y][x+i] != 'X'){
            map->map[y][x+i] = whatToPut(x+i, y, map, allPlayers);
        }else{
            break;
        }
    }
    for (int i = 1; i <= sizeExposion; ++i) {
        // Left
        if (map->map[y][x-i] != 'X'){
            map->map[y][x-i] = whatToPut(x-i, y, map, allPlayers);
        }else{
            break;
        }
    }
}

void explosionGone(Map *map){
    for (int i = 0; i < map->y; ++i) {
        for (int j = 0; j < map->x; ++j) {
            if (map->map[i][j] == '*' || map->map[i][j] == '#'){
                map->map[i][j] = '0';
            }
        }
    }
}