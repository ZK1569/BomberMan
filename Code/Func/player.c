//
// Created by Cristian Ursu on 09/10/2022.
//

#include <stdio.h>
#include "../Header/player.h"
#include "../Header/Structure.h"

int isDirectionPossible(int x, int y, Map *map){
    // Check if the next move is possible
    if ((map->map[y][x] != 'X') && (map->map[y][x] != 'm')) {
        return 1;
    }
    return 0;
}

Player newPlayer(int x, int y, char show, Map *map){
    // Create a new player
    Player new;
    new.x = x;
    new.y = y;
    new.show = show;

    map->map[y][x] = show;

    return new;
}

int move(char direction, Player *player, Map *map){
    // set the action of the player
    map->map[player->y][player->x] = '0';
    switch (direction) {
        case 'z':
            if (isDirectionPossible(player->x, player->y-1, map)) {
                player->y -= 1;
            }
            break;
        case 'd':
            if (isDirectionPossible(player->x+1, player->y, map)) {
                player->x += 1;
            }
            break;
        case 's':
            if(isDirectionPossible(player->x, player->y+1, map)){
                player->y += 1;
            }
            break;
        case 'q':
            if(isDirectionPossible(player->x-1, player->y, map)){
                player->x -= 1;
            }
            break;
        default:
            printf("Please enter a good direction \n");
            map->map[player->y][player->x] = player->show;
            return 0;
    }
    map->map[player->y][player->x] = player->show;
    return 1;
}