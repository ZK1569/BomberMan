//
// Created by Cristian Ursu on 09/10/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/player.h"
#include "../Header/Bomb.h"

int sizeMapX = 14;
int sizeMapY = 8;

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
    new.nbrBomb = 3;
    new.myBomb = malloc(sizeof(Bomb) * new.nbrBomb); // nbr bomb (a mettre dans une variable)
    for (int i = 0; i < new.nbrBomb; ++i)
    {
        new.myBomb[i].x = 0;
        new.myBomb[i].y = 0;
        new.myBomb[i].range = 2;
        new.myBomb[i].life = 0;
    }
    new.alive = 1;

    map->map[y][x] = show;

    return new;
}

void applyItemOnPlayer(char item, Player *player, Config *config) {
  switch (item) {
    case 'u':
      player->nbrBomb++;
      break;
    case 'd':
      if (player->nbrBomb <= 0) return;
      player->nbrBomb--;
      break;
    case 'y':
      player->myBomb->range++;
      break;
    case 'b':
      if (player->myBomb->range <= 1) return;
      player->myBomb->range--;
      break;
    case 'r':
      player->myBomb->range = config->rows > config->columns ? config->rows : config->columns ;
      break;
//    case 'h':
//
//      break;
//    case 'h':
//
//      break;
//    case 'h':
//
//      break;
//    case 'h':
//
//      break;
//    case 'h':
//
//      break;
    default:
      printf("Un objet n'est pas géré...\n");
      break;
  }
}

int move(char direction, Player *player, Map *map, Player *allPlayers, Config *config){

    // Mettre ici la fonction qui supprime les * et # de la map
    explosionGone(map);

    // set the action of the player
    map->map[player->y][player->x] = player->back;
    if(player->back != '0'){
        player->back = '0';
    }


    switch (direction) {
        int nextMove = 0;
        case MOVE_UP:
            nextMove = player->y-1;
            if (nextMove < 0){
                nextMove = sizeMapY;
            }
            if (isDirectionPossible(player->x, nextMove, map)) {
                applyItemOnPlayer(map->map[nextMove][player->x], player, config);
                player->y = nextMove;
            }else{
                map->map[player->y][player->x] = player->show;
                return 2;
            }
            break;
        case MOVE_RIGHT:
            nextMove = player->x+1;
            if (nextMove > sizeMapX){
                nextMove = 0;
            }
            if (isDirectionPossible(nextMove, player->y, map)) {
                applyItemOnPlayer(map->map[player->y][nextMove], player, config);
                player->x = nextMove;
                if (player->x > sizeMapX){
                    player->x = 0;
                }
            }else{
                map->map[player->y][player->x] = player->show;
                return 2;
            }
            break;
        case MOVE_DOWN:
            nextMove = player->y+1;
            if (nextMove > sizeMapY){
                nextMove = 0;
            }
            if(isDirectionPossible(player->x, nextMove, map)){
                applyItemOnPlayer(map->map[nextMove][player->x], player, config);
                player->y = nextMove;
            }else{
                map->map[player->y][player->x] = player->show;
                return 2;
            }
            break;
        case MOVE_LEFT:
            nextMove = player->x-1;
            if (nextMove < 0){
                nextMove = sizeMapX;
            }
            if(isDirectionPossible(nextMove, player->y, map)) {
                applyItemOnPlayer(map->map[player->y][nextMove], player, config);
                player->x = nextMove;
            }else{
                map->map[player->y][player->x] = player->show;
                return 2;
            }
            break;
        case MOVE_NO:
            printf("Ne rien faire \n");
            break;
        case ACTION_PLACE_BOMB:
//            if(player->nbrBomb < 3){ // 3 est le nombre de bombe ( a mettre dans un variable )
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
//            }
            break;
        default:
            printf("Please enter a good direction \n");
            map->map[player->y][player->x] = player->show;
            return 0;
    }

    map->map[player->y][player->x] = player->show;

    if (player->nbrBomb >= 1){ // If the player has at less a bomb
        for (int i = 0; i < player->nbrBomb; ++i) { //3 = nbr bomb (a mettre dans une variable)
            if (player->myBomb[i].life == 0 && player->myBomb[i].x != 0 && player->myBomb[i].y != 0){
                map->map[player->myBomb[i].y][player->myBomb[i].x] = '0';
                explose(player->myBomb[i].x, player->myBomb[i].y, player->myBomb->range, map, allPlayers);
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
