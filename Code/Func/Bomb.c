//
// Created by Cristian Ursu on 16/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "../Header/Bomb.h"
#include "../Header/Structure.h"
#include "../Header/player.h"
#include "../Header/item.h"

void whoseBomb(int x, int y, Player *allPlayers, int nbrPlayers) {
  // Cherche la personne qui a la bombe au coordonnée x y
  for (int i = 0; i < nbrPlayers; ++i) {
    Player player = allPlayers[i];
    for (int j = 0; j < 3; ++j) { //TODO: Changer le 3 en nombre de bomb total que la personne peut avoir
      if (player.myBomb[j].x == x && player.myBomb[j].y == y) {
        player.myBomb[j].x = 0;
        player.myBomb[j].y = 0;
        player.myBomb[j].life = 0;
        player.nbrBomb--;
        break;
      }
    }
  }
}

void applyBombExplosionEffectOn(Player *player) {
  player->isOnBomb = 0;
  if (!(player->hasVestItem)) player->heartLife--;
  if (player->heartLife < 0) player->healthPoint--;
}

char whatToPut(int x, int y, Map *map, Player *allPlayers, int nbrPlayers, Player *player) {
  switch (map->map[y][x]) {
    case '#':
      return '#';
    case '*':
      return '*';
    case 'm':
      return (rand() % (100 + 1)) < 50 ? '#' : popItem();
    case '0':
      return '*';
    case 'q':
      whoseBomb(x, y, allPlayers, nbrPlayers);
      explose(x, y, player->myBomb->range, map, allPlayers, nbrPlayers, player); //TODO: attention la taille des bombes n'est pas changer ici
      return '*';
    case 1:
      applyBombExplosionEffectOn(player);

      if (player->hasVestItem && player->vestLife >= 0) {
        printf("%s a un gilet protégeant des bombes.\n", player->name);
        return 1;
      }
      if (player->hasHeartItem && player->heartLife >= 0) {
        printf("%s a perdu son super cœur !\n", player->name);
        return 1;
      }
      if (player->healthPoint >= 1) {
        printf("%s a eu mal !\n", player->name);
        return 1;
      }

      killPlayer(x, y, allPlayers);
      return 'D';
    case 2:
      applyBombExplosionEffectOn(player);

      if (player->hasVestItem && player->vestLife >= 0) {
        printf("%s a un gilet protégeant des bombes.\n", player->name);
        return 2;
      }
      if (player->hasHeartItem && player->heartLife >= 0) {
        printf("%s a perdu son super cœur !\n", player->name);
        return 2;
      }
      if (player->healthPoint >= 0) {
        printf("%s a eu mal !\n", player->name);
        return 2;
      }

      killPlayer(x, y, allPlayers);
      return 'D';
    case 3:
      applyBombExplosionEffectOn(player);

      if (player->hasVestItem && player->vestLife >= 0) {
        printf("%s a un gilet protégeant des bombes.\n", player->name);
        return 3;
      }
      if (player->hasHeartItem && player->heartLife >= 0) {
        printf("%s a perdu son super cœur !\n", player->name);
        return 3;
      }
      if (player->healthPoint >= 0) {
        printf("%s a eu mal !\n", player->name);
        return 3;
      }

      killPlayer(x, y, allPlayers);
      return 'D';
    case 4:
      applyBombExplosionEffectOn(player);

      if (player->hasVestItem && player->vestLife >= 0) {
        printf("%s a un gilet protégeant des bombes.\n", player->name);
        return 4;
      }
      if (player->hasHeartItem && player->heartLife >= 0) {
        printf("%s a perdu son super cœur !\n", player->name);
        return 4;
      }
      if (player->healthPoint >= 0) {
        printf("%s a eu mal !\n", player->name);
        return 4;
      }

      killPlayer(x, y, allPlayers);
      return 'D';
    default:
//      printf("whatToPut default \n");
      return '0';
  }
}

void explose(int x, int y, int sizeExposion, Map *map, Player *allPlayers, int nbrPlayers, Player *player) {
  //    caseExploded(x,y,sizeExposion);
  // Fait exploser le centre
  if (map->map[y][x] == 1 || map->map[y][x] == 2 || map->map[y][x] == 3 || map->map[y][x] == 4) {
    map->map[y][x] = whatToPut(x, y, map, allPlayers, nbrPlayers, player);
  }
  else {
    map->map[y][x] = '*';
  }

  int next = 0;
  for (int i = 1; i <= sizeExposion; ++i) {
    // Up
    next = y - i;
    if (next < 0) {
      next = map->y - i;
    }

    if (map->map[next][x] == 'X') {
      break;
    } else if (map->map[next][x] == 'm' || map->map[next][x] == 'q') {
      map->map[next][x] = whatToPut(x, next, map, allPlayers, nbrPlayers, player);
      break;
    } else {
      map->map[next][x] = whatToPut(x, next, map, allPlayers, nbrPlayers, player);
    }
  }
  for (int i = 1; i <= sizeExposion; ++i) {
    // Down
    next = y + i;
    if (next > map->y - i) {
      next = 0;
    }

    if (map->map[next][x] == 'X') {
      break;
    } else if (map->map[next][x] == 'm' || map->map[next][x] == 'q') {
      map->map[next][x] = whatToPut(x, next, map, allPlayers, nbrPlayers, player);
      break;
    } else {
      map->map[next][x] = whatToPut(x, next, map, allPlayers, nbrPlayers, player);
    }
  }
  for (int i = 1; i <= sizeExposion; ++i) {
    // Right
    next = x + i;
    if (next > map->x - i) {
      next = 0;
    }

    if (map->map[y][next] == 'X') {
      break;
    } else if (map->map[y][next] == 'm' || map->map[y][next] == 'q') {
      map->map[y][next] = whatToPut(next, y, map, allPlayers, nbrPlayers, player);
      break;
    } else {
      map->map[y][next] = whatToPut(next, y, map, allPlayers, nbrPlayers, player);
    }
  }

  for (int i = 1; i <= sizeExposion; ++i) {
    // Left
    next = x - i;
    if (next < 0) {
      next = map->x - 1;
    }

    if (map->map[y][next] == 'X') {
      break;
    } else if (map->map[y][next] == 'm' || map->map[y][next] == 'q') {
      map->map[y][next] = whatToPut(next, y, map, allPlayers, nbrPlayers, player);
      break;
    } else {
      map->map[y][next] = whatToPut(next, y, map, allPlayers, nbrPlayers, player);
    }
  }
}

void explosionGone(Map *map) {
  for (int i = 0; i < map->y; ++i) {
    for (int j = 0; j < map->x; ++j) {
      if (map->map[i][j] == '*' || map->map[i][j] == '#' || map->map[i][j] == 'D') {
        map->map[i][j] = '0';
      }
    }
  }
}