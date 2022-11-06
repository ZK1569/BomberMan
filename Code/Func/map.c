//
// Created by Cristian Ursu on 09/10/2022.
//

#include "../Header/map.h"

#include <stdio.h>
#include <stdlib.h>

#include "../Header/Structure.h"
#include "../Header/utils.h"

char **createMap(int x, int y){
    char **map = malloc(sizeof(char*)*y);
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char)*x);
        // Set every cell to '0';
        for (int j = 0; j < x; j++) {
            map[i][j] = '0';
        }
    }
    return map;
}

Map newMap(int x, int y){
    Map new;
    new.x = x;
    new.y = y;
    new.map = createMap(x, y);

    return new;
}

int getSizeYFile(char *path){
    char data[50] = {0};

    int sizeY = 0;
    FILE *f = fopen(path, "r");
    if(f == NULL) {
        printf("Fichier pas trouvé");
        return 0;
    }
    while(fscanf(f, "%s", data) == 1){
        sizeY++;
    }
    fclose(f);
    return sizeY;
}


Map openMap(char *path){
    char data[50] = {0};

    int sizeY = getSizeYFile(path);
    int sizeX = 0;

    FILE *file = fopen(path, "r");
    if(file == NULL) {
        printf("Fichier pas trouvé");
    }

    int i = 0;
    char **map = malloc(sizeof(char*)*sizeY);
    while(fscanf(file, "%s", data) == 1){
        sizeX = strlen(data);
        map[i] = malloc(sizeof(char)*sizeX);
        for (int j = 0; j < sizeX; j++) {
            map[i][j] = data[j];
        }
        i++;
    }

    fclose(file);

    Map new;
    new.x = sizeX;
    new.y = sizeY;
    new.map = map;

    return new;
}


void createBorderMap(Map map){

    // Set the first and last line to 'X'
    for (int i = 0; i < map.x; ++i) {
        map.map[0][i] = 'X';
        map.map[map.y-1][i] = 'X';
    }
    for (int i = 0; i < map.y; ++i) {
        map.map[i][0] = 'X';
        map.map[i][map.x-1] = 'X';
    }
}



