#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../Header/Structure.h"

int getConfig(Config *config, char *configFile) {
  if (strcmp(configFile, "app.config") != 0) return 0;

  FILE *file = fopen(configFile, "r");
  if (file == NULL) {
    file = fopen(configFile, "w+");
    char *configProperties = "ROWS=15\n"
                             "COLUMNS=7\n"
                             "STRONG_WALL=⬜️\n"
                             "WEAK_WALL=🟫\n"
                             "DESTROYED_WALL=💥\n"
                             "EMPTY_SPACE=◾️\n"
                             "\n"
                             "PLAYER_1=🙂\n"
                             "PLAYER_2=😛\n"
                             "PLAYER_3=🙁\n"
                             "PLAYER_4=😮\n"
                             "BOMB=💣\n"
                             "BOMB_FIRE=🔥\n"
                             "\n"
                             "BOMB_DOWN=🔽\n"
                             "BOMB_UP=🔼\n"
                             "YELLOW_FIRE=🟡\n"
                             "BLUE_FIRE=🔵\n"
                             "RED_FIRE=🔴\n"
                             "BOMB_PASS=🏃\n"
                             "KICK=👟\n"
                             "VEST=🦺\n"
                             "HEART=💖\n"
                             "ONE_UP=🆙";

    fprintf(file, "%s", configProperties);
  }

  char line[256];
  char *key ;
  char *value;

  while (fgets(line, sizeof(line), file) != NULL) {
    int i = 0;
    int j;

    while (line[i] != '\0') {
      if (line[i] == 61) {
        key = malloc(sizeof(char) * 256);
        for (j = 0; j < i; j++) {
          key[j] = line[j];
        }
        key[i] = '\0';

        value = malloc(sizeof(char) * 256);
        for (j = 0; line[i + 1 + j] != '\n'; j++) {
          value[j] = line[i + 1 + j];
        }
        value[j] = '\0';

        break;
      }

      i++;
    }

    if (strcmp(key, "ROWS") == 0) {
      config->rows = atoi(value);
      printf("ROWS: %d\n", config->rows);
    }
    else if (strcmp(key, "COLUMNS") == 0) {
      config->columns = atoi(value);
    }
    else if (strcmp(key, "STRONG_WALL") == 0) {
      config->strongWall = value;
    }
    else if (strcmp(key, "WEAK_WALL") == 0) {
      config->weakWall = value;
    }
    else if (strcmp(key, "DESTROYED_WALL") == 0) {
      config->destroyedWall = value;
    }
    else if (strcmp(key, "EMPTY_SPACE") == 0) {
      config->emptySpace = value;
    }
    else if (strcmp(key, "PLAYER_1") == 0) {
      config->player1 = value;
    }
    else if (strcmp(key, "PLAYER_2") == 0) {
      config->player2 = value;
    }
    else if (strcmp(key, "PLAYER_3") == 0) {
      config->player3 = value;
    }
    else if (strcmp(key, "PLAYER_4") == 0) {
      config->player4 = value;
    }
    else if (strcmp(key, "BOMB") == 0) {
      config->bomb = value;
    }
    else if (strcmp(key, "BOMB_FIRE") == 0) {
      config->bombFire = value;
    }
    else if (strcmp(key, "BOMB_DOWN") == 0) {
      config->bombDown = value;
    }
    else if (strcmp(key, "BOMB_UP") == 0) {
      config->bombUp = value;
    }
    else if (strcmp(key, "YELLOW_FIRE") == 0) {
      config->yellowFire = value;
    }
    else if (strcmp(key, "BLUE_FIRE") == 0) {
      config->blueFire = value;
    }
    else if (strcmp(key, "RED_FIRE") == 0) {
      config->redFire = value;
    }
    else if (strcmp(key, "BOMB_PASS") == 0) {
      config->bombPass = value;
    }
    else if (strcmp(key, "KICK") == 0) {
      config->kick = value;
    }
    else if (strcmp(key, "VEST") == 0) {
      config->vest = value;
    }
    else if (strcmp(key, "HEART") == 0) {
      config->heart = value;
    }
    else if (strcmp(key, "ONE_UP") == 0) {
      config->oneUp = value;
    }
    else {
      printf("something is not handled");
    }
  }

  fclose(file);
  return 1;
}