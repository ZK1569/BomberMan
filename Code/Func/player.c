//
// Created by Cristian Ursu on 09/10/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "../Header/player.h"
#include "../Header/Structure.h"

int isDirectionPossible(int x, int y, Map *map){
    // Check if the next move is possible
    if ((map->map[y][x] != 'X') && (map->map[y][x] != 'm') && (map->map[y][x] != 'q')) {
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
    new.back = '0';
    new.nbrBomb = 0;
    new.myBomb = malloc(sizeof(Bomb)*3); //3 = nbr bomb (a mettre dans une variable)
    for (int i = 0; i < 3; ++i) {
        new.myBomb[i].x = 0;
        new.myBomb[i].y = 0;
        new.myBomb[i].life = 0;
    }

    map->map[y][x] = show;

    return new;
}

int move(char direction, Player *player, Map *map){
    // set the action of the player
    map->map[player->y][player->x] = player->back;
    if(player->back != '0'){
        player->back = '0';
    }
    // Mettre ici l'inrementation pour les bombes
    // Si x ou y != 0;
    if (player->nbrBomb != 0){ // If the player has at less a bomb
        for (int i = 0; i < 3; ++i) { //3 = nbr bomb (a mettre dans une variable)
            if (player->myBomb[i].life == 0){
                // print une + sur la map (function a faire)
                // Supprime la bombe et la met dans la poche
                player->myBomb->x = 0;
                player->myBomb->y = 0;
                // Eleve le nombre total de bomb qu'il a
                player->nbrBomb--;

            }
            else (player->myBomb[i].x != 0 || player->myBomb[i].y != 0){ // Pour les bombes qu'il a mais qui sont sur la map et pas en reserve
                player->myBomb[i].life--; // Enleve une vie a la bombe
            }
        }
    }
    switch (direction) {
        case 'z':
            // Go Up
            if (isDirectionPossible(player->x, player->y-1, map)) {
                player->y -= 1;
            }
            break;
        case 'd':
            // Go right
            if (isDirectionPossible(player->x+1, player->y, map)) {
                player->x += 1;
            }
            break;
        case 's':
            // Go Down
            if(isDirectionPossible(player->x, player->y+1, map)){
                player->y += 1;
            }
            break;
        case 'q':
            // Go left
            if(isDirectionPossible(player->x-1, player->y, map)){
                player->x -= 1;
            }
            break;
        case 'e':
            // Place a Bomb
            // Ne pas mettre les bombes a l'index du nombre mais dans le 1er place touver x et y
            // Si verifier qu'il en a pas trop placé
            if(player->nbrBomb < 3){ // 3 est le nombre de bombe ( a mettre dans un variable )
                player->myBomb[player->nbrBomb].x = player->x;
                player->myBomb[player->nbrBomb].y = player->y;
                player->myBomb[player->nbrBomb].life = 3 + 1 ; // 3 est le nombre de tour avant que la bombe explose / Je sais pas pourquoi +1
            }
            player->back = 'q';
            break;
        default:
            printf("Please enter a good direction \n");
            map->map[player->y][player->x] = player->show;
            return 0;
    }
    map->map[player->y][player->x] = player->show;
    return 1;
}