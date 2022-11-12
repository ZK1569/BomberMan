//
// Created by Cristian Ursu on 09/10/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/player.h"
#include "../Header/Bomb.h"

int killPlayer(int x, int y, Player *allPlayers){
    for (int i = 0; i < 3; ++i) { // TODO: changer le 3 en nombre de jouer
        if (allPlayers[i].x == x && allPlayers[i].y == y && allPlayers[i].alive){
            allPlayers[i].alive = 0;
        }
    }
}

int isDirectionPossibleWithoutBombPassItem(int x, int y, Map *map) {
//int isDirectionPossible(Player *player, int x, int y, Map *map) {
  // Check if the next move is possible
  if ((map->map[y][x] != 'X') &&
      (map->map[y][x] != 'm') &&
      (map->map[y][x] != 'q') &&
      (map->map[y][x] != 1) &&
      (map->map[y][x] != 2) &&
      (map->map[y][x] != 3) &&
      (map->map[y][x] != 4)
          ) {
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
    new.myBomb = malloc(sizeof(Bomb) * 3); // Tout les joueurs commencent avec 3 Bomb
    for (int i = 0; i < 3; ++i)
    {
        new.myBomb[i].x = 0;
        new.myBomb[i].y = 0;
        new.myBomb[i].range = 2;
        new.myBomb[i].life = 0;
    }
    new.alive = 1;

  new.hasBombPassItem = 0;
  new.hasKickItem = 0;
  new.isOnBomb = 0;
  new.alive = 1;

  map->map[y][x] = show;

  return new;
}

void applyItemOnPlayer(char item, Player *player, Config *config) {
  switch (item) {
    case '0': // ⬛️
    case 'q': // 💣
      break;
    case 'u': // 🔼
      player->nbrBomb++;
      break;
    case 'd': // 🔽
      if (player->nbrBomb <= 0) return;
      player->nbrBomb--;
      break;
    case 'y': // 🟡
      player->myBomb->range++;
      break;
    case 'b': // 🔵
      if (player->myBomb->range <= 1) return;
      player->myBomb->range--;
      break;
    case 'r': // 🔴
      player->myBomb->range = config->rows > config->columns ? config->rows : config->columns;
      break;
    case 'p': // 🏃
      player->hasBombPassItem = 1;
      player->hasKickItem = 0;
      break;
    case 'k': // 👟
      player->hasKickItem = 1;
      player->hasBombPassItem = 0;
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
    default:
      printf("Un objet n'est pas géré...\n");
      break;
  }
}

void setBombCoordinates(Player *player, int x, int y) {
  player->myBomb->x = x;
  player->myBomb->y = y;
}

void kickBomb(Map *map, char direction, Player *player, Config *config) {
  int kickRange = config->rows > config->columns ? config->rows : config->columns;

  switch (direction) {
    case MOVE_UP:
      for (int i = 2; i <= kickRange; ++i) {
          if (player->y - i >= 0 && map->map[player->y - i][player->x] == '0') continue;
          map->map[player->y - 1][player->x] = '0';

//        if (player->y - i <= -1 && map->map[config->columns - 1][player->x] == '0') {
//          player->y = config->columns -1 ;
//          break;
//        }
//        else if (player->y - i <= -1 && map->map[config->columns - 1][player->x] != '0') {
//          map->map[player->y - 1][player->x] = '0';
//          map->map[0][player->x] = 'q';
//          break;
//        }

        if (map->map[player->y - i][player->x] != '0') {
          map->map[player->y - i + 1][player->x] = 'q';
          setBombCoordinates(player, player->x, player->y - i + 1);
        } else {
          map->map[player->y - i][player->x] = 'q';
          setBombCoordinates(player, player->x, player->y - i);
        }

        break;
      }

      break;

    case MOVE_RIGHT:
      for (int i = 2; i <= kickRange; ++i) {
        if (player->x + i <= config->rows - 1 && map->map[player->y][player->x + i] == '0') continue;
        map->map[player->y][player->x + 1] = '0';

        if (map->map[player->y][player->x + i] != '0') {
          map->map[player->y][player->x + i - 1] = 'q';
          setBombCoordinates(player, player->x + i - 1, player->y);
        } else {
          map->map[player->y][player->x + i] = 'q';
          setBombCoordinates(player, player->x + i, player->y);
        }

        break;
      }
      break;

    case MOVE_DOWN:
      for (int i = 2; i <= kickRange; ++i) {
        if (player->y + i < config->columns && map->map[player->y + i][player->x] == '0') continue;
        map->map[player->y + 1][player->x] = '0';

        if (map->map[player->y + i][player->x] != '0') {
          map->map[player->y + i - 1][player->x] = 'q';
          setBombCoordinates(player, player->x, player->y + i - 1);
        } else {
          map->map[player->y + i][player->x] = 'q';
          setBombCoordinates(player, player->x, player->y + i);
        }

        break;
      }
      break;

    case MOVE_LEFT:
      for (int i = 2; i <= kickRange; ++i) {
        if (player->x - i >= 0 && map->map[player->y][player->x - i] == '0') continue;
        map->map[player->y][player->x - 1] = '0';

        if (map->map[player->y][player->x - i] != '0') {
          map->map[player->y][player->x - i + 1] = 'q';
          setBombCoordinates(player, player->x - i + 1, player->y);
        } else {
          map->map[player->y][player->x - i] = 'q';
          setBombCoordinates(player, player->x - i, player->y);
        }

        break;
      }
      break;
  }
}

int move(char direction, Player *player, Map *map, Player *allPlayers, Config *config, int nbrPlayers) {

  // Mettre ici la fonction qui supprime les * et # de la map
  explosionGone(map);

  // set the action of the player
  map->map[player->y][player->x] = player->back;
  if (player->back != '0') {
    player->back = '0';
  }

  switch (direction) {
    int nextMove = 0;

    case MOVE_UP:
      nextMove = player->y-1;
      if (nextMove < 0){
        nextMove = map->y-1;
      }

      if (isDirectionPossibleWithoutBombPassItem(player->x, nextMove, map)) {
        applyItemOnPlayer(map->map[nextMove][player->x], player, config);

        if (player->isOnBomb && player->myBomb->life >= 1) {
          map->map[player->y][player->x] = 'q';
        }
        player->y = nextMove;
        player->isOnBomb = 0;

        break;
      }

      if (map->map[nextMove][player->x] == 'q' && player->hasBombPassItem) {
        player->y = nextMove;
        player->isOnBomb = 1;
        break;
      }
      else if (map->map[nextMove][player->x] == 'q' && player->hasKickItem) {
        kickBomb(map, direction, player, config);
      } else {
        map->map[player->y][player->x] = player->show;
        return 2;
      }

      break;

    case MOVE_RIGHT:
      nextMove = player->x+1;
      if (nextMove > map->x-1){
        nextMove = 0;
      }

      if (isDirectionPossibleWithoutBombPassItem(nextMove, player->y, map)) {
        applyItemOnPlayer(map->map[player->y][nextMove], player, config);

        if (player->isOnBomb && player->myBomb->life >= 1) {
          map->map[player->y][player->x] = 'q';
        }
        player->x = nextMove;
        player->isOnBomb = 0;

        break;
      }

      if (map->map[player->y][nextMove] == 'q' && player->hasBombPassItem) {
        player->x = nextMove;
        player->isOnBomb = 1;
        break;
      }
      else if (map->map[player->y][nextMove] == 'q' && player->hasKickItem) {
        kickBomb(map, direction, player, config);
      } else {
        map->map[player->y][player->x] = player->show;
        return 2;
      }

      break;

    case MOVE_DOWN:
      nextMove = player->y+1;
      if (nextMove > map->y-1){
        nextMove = 0;
      }

      if (isDirectionPossibleWithoutBombPassItem(player->x, nextMove, map)) {
        applyItemOnPlayer(map->map[nextMove][player->x], player, config);

        if (player->isOnBomb && player->myBomb->life >= 1) {
          map->map[player->y][player->x] = 'q';
        }
        player->y = nextMove;
        player->isOnBomb = 0;

        break;
      }

      if (map->map[nextMove][player->x] == 'q' && player->hasBombPassItem) {
        player->y = nextMove;
        player->isOnBomb = 1;
        break;
      }
      else if (map->map[nextMove][player->x] == 'q' && player->hasKickItem) {
        kickBomb(map, direction, player, config);
      }
      else {
        map->map[player->y][player->x] = player->show;
        return 2;
      }

      break;

    case MOVE_LEFT:
      nextMove = player->x-1;
      if (nextMove < 0){
        nextMove = map->x-1;
      }

      if (isDirectionPossibleWithoutBombPassItem(nextMove, player->y, map)) {
        applyItemOnPlayer(map->map[player->y][nextMove], player, config);

        if (player->isOnBomb && player->myBomb->life >= 1) {
          map->map[player->y][player->x] = 'q';
        }
        player->x = nextMove;
        player->isOnBomb = 0;

        break;
      }

      if (map->map[player->y][nextMove] == 'q' && player->hasBombPassItem) {
        player->x = nextMove;
        player->isOnBomb = 1;
        break;
      }
      else if (map->map[player->y][nextMove] == 'q' && player->hasKickItem) {
        kickBomb(map, direction, player, config);
      } else {
        map->map[player->y][player->x] = player->show;
        return 2;
      }

      break;

    case MOVE_NO:
      printf("Ne rien faire \n");
      break;

    case ACTION_PLACE_BOMB:
      if (player->isOnBomb) break;
      player->isOnBomb = 1;

//            if(player->nbrBomb < 3){ // 3 est le nombre de bombe ( a mettre dans un variable )
      for (int i = 0; i < 3; ++i) {
        if (player->myBomb[i].x == 0 || player->myBomb[i].y == 0) {
          printf("Une 💣 bombe a été posée.\n");
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

  if (player->nbrBomb >= 1) { // If the player has at less a bomb
    for (int i = 0; i < 3; ++i) { //3 = nbr bomb (a mettre dans une variable)
      if (player->myBomb[i].life == 0) {
          if(!(player->myBomb[i].x == 0 && player->myBomb[i].y == 0)){
              // Fait exploser la bombe d'un joueur qui a jouer si la vie de la bomb est a 0
              // et si elle est sur la map
              explose(player->myBomb[i].x, player->myBomb[i].y, player->myBomb->range, map, allPlayers, nbrPlayers, player);
              player->myBomb[i].x = 0;
              player->myBomb[i].y = 0;
              player->nbrBomb--;
          }
      }
      if (!(player->myBomb[i].x == 0 && player->myBomb[i].y == 0)) { // Pour les bombes qu'il a mais qui sont sur la map et pas en reserve
        player->myBomb[i].life--; // Enleve une vie a la bombe
      }
    }
  }

  return 1;
}

char *setCurrentPlayerCharacter(int playerTurn, Config *config) {
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
