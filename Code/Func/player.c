//
// Created by Cristian Ursu on 09/10/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/player.h"
#include "../Header/Structure.h"
#include "../Header/Bomb.h"

int killPlayer(int x, int y, Player *allPlayers){
    for (int i = 0; i < 3; ++i) { // TODO: changer le 3 en nombre de jouer
        if (allPlayers[i].x == x && allPlayers[i].y == y && allPlayers[i].alive){
            allPlayers[i].alive = 0;
        }
    }
}

int isDirectionPossible(int x, int y, Map *map)
{
    // Check if the next move is possible
    if ((map->map[y][x] != 'X') &&
        (map->map[y][x] != 'm') &&
        (map->map[y][x] != 'q') &&
        (map->map[y][x] != 1) &&
        (map->map[y][x] != 2) &&
        (map->map[y][x] != 3) &&
        (map->map[y][x] != 4)
    )
    {
        return 1;
    }
    return 0;
}

Player newPlayer(char *name, int x, int y, char show, Map *map)
{
    // Create a new player
    Player new;
    new.x = x;
    new.y = y;
    strncpy(new.name, name, strlen(name) + 1);
    new.show = show;
    new.back = '0';
    new.nbrBomb = 0;
    new.myBomb = malloc(sizeof(Bomb) * 3); // 3 = nbr bomb (a mettre dans une variable)
    for (int i = 0; i < 3; ++i)
    {
        new.myBomb[i].x = 0;
        new.myBomb[i].y = 0;
        new.myBomb[i].life = 0;
    }
    new.alive = 1;

    map->map[y][x] = show;

    return new;
}

int move(char direction, Player *player, Map *map, Player *allPlayers){

    // Mettre ici la fonction qui supprime les * et # de la map
    explosionGone(map);

    // set the action of the player
    map->map[player->y][player->x] = player->back;
    if(player->back != '0'){
        player->back = '0';
    }


    switch (direction) {
        case MOVE_UP:
            if (isDirectionPossible(player->x, player->y-1, map)) {
                player->y -= 1;
            }
            break;
        case MOVE_RIGHT:
            if (isDirectionPossible(player->x+1, player->y, map)) {
                player->x += 1;
            }
            break;
        case MOVE_DOWN:
            if(isDirectionPossible(player->x, player->y+1, map)){
                player->y += 1;
            }
            break;
        case MOVE_LEFT:
            if(isDirectionPossible(player->x-1, player->y, map)){
                player->x -= 1;
            }
            break;
        case ACTION_PLACE_BOMB:
            if(player->nbrBomb < 3){ // 3 est le nombre de bombe ( a mettre dans un variable )
                for (int i = 0; i < 3; ++i) {
                    if (player->myBomb[i].x == 0 || player->myBomb[i].y == 0){
                        player->myBomb[i].x = player->x;
                        player->myBomb[i].y = player->y;
                        player->myBomb[i].life = 5; //5 a mettre dans une variable = nbr de tour avant quel explose
                        player->nbrBomb++;
                        break;
                    }
                }
                player->back = MOVE_LEFT;
            }
            break;
        default:
            printf("Please enter a good direction \n");
            map->map[player->y][player->x] = player->show;
            return 0;
    }

    map->map[player->y][player->x] = player->show;




    if (player->nbrBomb != 0){ // If the player has at less a bomb
        for (int i = 0; i < 3; ++i) { //3 = nbr bomb (a mettre dans une variable)
            if (player->myBomb[i].life == 0 && player->myBomb[i].x != 0 && player->myBomb[i].y != 0){
                map->map[player->myBomb[i].y][player->myBomb[i].x] = '0';
                explose(player->myBomb[i].x, player->myBomb[i].y, 2, map, allPlayers);
                player->myBomb[i].x = 0;
                player->myBomb[i].y = 0;
                player->nbrBomb--;
            }
            if ((player->myBomb[i].x != 0) && (player->myBomb[i].y != 0)){ // Pour les bombes qu'il a mais qui sont sur la map et pas en reserve
                player->myBomb[i].life--; // Enleve une vie a la bombe
            }
        }
    }



    return 1;
}

char *setCurrentPlayerCharacter(int playerTurn, Config *config){
  char *currentPlayerCharacter;

  switch (playerTurn) {
    case 0:
      currentPlayerCharacter = config->player1;
      break;
    case 1:
      currentPlayerCharacter = config->player2;
      break;
    case 2:
      currentPlayerCharacter = config->player3;
      break;
    case 3:
      currentPlayerCharacter = config->player4;
      break;
    default:
      printf("Tour à gérer...\n");
      currentPlayerCharacter = "❓";
      break;
  }

  return currentPlayerCharacter;
}
