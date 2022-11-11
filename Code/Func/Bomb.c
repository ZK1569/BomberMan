//
// Created by Cristian Ursu on 16/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Header/Bomb.h"
#include "../Header/Structure.h"
#include "../Header/player.h"
#include "../Header/item.h"

void whoseBomb(int x, int y, Player *allPlayers){
    // Cherche la personne qui a la bombe au coordonnée x y
    for (int i = 0; i < 3; ++i) { //TODO: Changer le 3 en nombre de jouer
        Player player = allPlayers[i];
        for (int j = 0; j < 3; ++j) { //TODO: Changer le 3 en nombre de bomb total que la personne peut avoir
            if (player.myBomb[j].x == x && player.myBomb[j].y == y){
                player.myBomb[j].x = 0;
                player.myBomb[j].y = 0;
                player.myBomb[j].life = 0;
                player.nbrBomb--;
                break;
            }
        }
    }
}

char whatToPut(int x, int y, Map *map, Player *allPlayers, Player *player) {
    if (map == NULL) {
        player->alive = 0;
        return 'D';
    }

    switch (map->map[y][x]) {
        case 'm':
            srand(time(0));
            return rand() % 100 + 1 < 50 ? '#' : popItem();
        case '0':
            return '*';
        case 'q':
            whoseBomb(x, y, allPlayers);
            explose(x, y,2, map, allPlayers, player);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
//          if (player->vestItemCounter > 0) {
//            player->vestItemCounter--;
//            return player->show;
//          }

          killPlayer(x,y,allPlayers);
          return 'D';
    }
}

void explose(int x, int y, int sizeExposion, Map *map, Player *allPlayers, Player *player){

//    caseExploded(x,y,sizeExposion);
    // Fait exploser le centre
<<<<<<< HEAD
      if (map->map[y][x] == 1 || map->map[y][x] == 2 || map->map[y][x] == 3 || map->map[y][x] == 4) {
        map->map[y][x] = whatToPut(-1, -1, NULL, NULL, player);
      }
      else {
        map->map[y][x] = '*';
      }

      for (int i = 1; i <= sizeExposion; ++i) {
=======
    printf("taille explosion = %d\n", sizeExposion);
    map->map[y][x] = '*';
    int next = 0;
    for (int i = 1; i <= sizeExposion; ++i) {
>>>>>>> 417ba1a (debug and explosion pass)
        // Up
        next = y-i;
        if (next < 0){
            next = map->y-1;
        }
        if (map->map[next][x] == 'X'){
          break;
        }
<<<<<<< HEAD
        else if (map->map[y-i][x] == 'm') {
          map->map[y-i][x] = whatToPut(x, y-i, map, allPlayers, NULL);
          break;
        }
        else{
          map->map[y-i][x] = whatToPut(x, y-i, map, allPlayers, NULL);
=======
        else if (map->map[next][x] == 'm') {
          map->map[next][x] = whatToPut(x, next, map, allPlayers);
          break;
        }
        else{
          map->map[next][x] = whatToPut(x, next, map, allPlayers);
>>>>>>> 417ba1a (debug and explosion pass)
        }
      }
      for (int i = 1; i <= sizeExposion; ++i) {
        // Down
          next = y+i;
          if (next > map->y-1){
              next = 0;
          }
        if (map->map[next][x] == 'X'){
          break;
        }
<<<<<<< HEAD
        else if (map->map[y+i][x] == 'm') {
          map->map[y+i][x] = whatToPut(x, y+i, map, allPlayers, NULL);
          break;
        }
        else{
          map->map[y+i][x] = whatToPut(x, y+i, map, allPlayers, NULL);
=======
        else if (map->map[next][x] == 'm') {
          map->map[next][x] = whatToPut(x, next, map, allPlayers);
          break;
        }
        else{
          map->map[next][x] = whatToPut(x, next, map, allPlayers);
>>>>>>> 417ba1a (debug and explosion pass)
        }
      }
      for (int i = 1; i <= sizeExposion; ++i) {
        // Right
        next = x+i;
        if (next > map->x-i){
          next = 0;
        }
        if (map->map[y][next] == 'X'){
          break;
        }
<<<<<<< HEAD
        else if (map->map[y][x+i] == 'm') {
          map->map[y][x+i] = whatToPut(x+i, y, map, allPlayers, NULL);
          break;
        }
        else{
          map->map[y][x+i] = whatToPut(x+i, y, map, allPlayers, NULL);
        }
      }
      for (int i = 1; i <= sizeExposion; ++i) {
        // Left
        if (map->map[y][x-i] == 'X'){
          break;
        }
        else if (map->map[y][x-i] == 'm') {
          map->map[y][x-i] = whatToPut(x-i, y, map, allPlayers, NULL);
          break;
        }
        else{
          map->map[y][x-i] = whatToPut(x-i, y, map, allPlayers, NULL);
=======
        else if (map->map[y][next] == 'm') {
          map->map[y][next] = whatToPut(next, y, map, allPlayers);
          break;
        }
        else{
          map->map[y][next] = whatToPut(next, y, map, allPlayers);
>>>>>>> 417ba1a (debug and explosion pass)
        }
    }
  for (int i = 1; i <= sizeExposion; ++i) {
    // Left
      next = x-i;
      if (next < 0){
          next = map->x-1;
      }
    if (map->map[y][next] == 'X'){
      break;
    }
    else if (map->map[y][next] == 'm') {
      map->map[y][next] = whatToPut(next, y, map, allPlayers);
      break;
    }
    else{
      map->map[y][next] = whatToPut(next, y, map, allPlayers);
    }
  }
}

void explosionGone(Map *map){
    for (int i = 0; i < map->y; ++i) {
        for (int j = 0; j < map->x; ++j) {
            if (map->map[i][j] == '*' || map->map[i][j] == '#' || map->map[i][j] == 'D'){
                map->map[i][j] = '0';
            }
        }
    }
}