//
// Created by Cristian Ursu on 09/10/2022.
//

#include "../Header/map.h"

#include <stdio.h>
#include <stdlib.h>

#include "../Header/Structure.h"
#include "../Header/utils.h"
#include "../Header/show.h"

char *whatMap(int number){
    switch (number) {
        case 0:
            return "../Code/Maps/test.txt";
        case 1:
            return "../Code/Maps/map1.txt";
        case 2:
            return "../Code/Maps/map2.txt";
        case 3:
            return "../Code/Maps/map3.txt";
    }
}

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

void showAllMaps(Config *config){
    // La fonction qui affiche touts les maps dans le menu au debut d'une game
    char ligneMap1[50] = {0};
    char ligneMap2[50] = {0};
    char ligneMap3[50] = {0};

    int sizeMap1 = getSizeYFile("../Code/Maps/map1.txt");
    int sizeMap2 = getSizeYFile("../Code/Maps/map2.txt");
    int sizeMap3 = getSizeYFile("../Code/Maps/map3.txt");
    int sizeMap = 0;

    if (sizeMap1 > sizeMap){
        sizeMap = sizeMap1;
    }else if (sizeMap2 > sizeMap){
        sizeMap = sizeMap2;
    }else if (sizeMap3 > sizeMap){
        sizeMap = sizeMap3;
    }

    FILE *map1 = fopen("../Code/Maps/map1.txt", "r");
    FILE *map2 = fopen("../Code/Maps/map2.txt", "r");
    FILE *map3 = fopen("../Code/Maps/map3.txt", "r");

    // Print les maps ligne par ligne
    for (int i = 0; i < sizeMap; ++i) {
        if (i < sizeMap1){
            fscanf(map1, "%s", ligneMap1);
            showLine(ligneMap1, strlen(ligneMap1), 1, config);
            printf("  |  ");
        }
        if (i < sizeMap2){
            fscanf(map2, "%s", ligneMap2);
            showLine(ligneMap2, strlen(ligneMap2), 1, config);
            printf("  |  ");
        }
        if (i < sizeMap3){
            fscanf(map3, "%s", ligneMap3);
            showLine(ligneMap3, strlen(ligneMap3), 1, config);
            printf("  |  ");
        }
        printf("\n");
    }

    // Print la dernierre ligne avec les informations
    for (int i = 0; i < strlen(ligneMap1)/2-1; ++i) {
        printf("%s ", config->emptySpace);
    }
    printf("[1] ");
    for (int i = 0; i < strlen(ligneMap1)/2; ++i) {
        printf("%s ", config->emptySpace);
    }
    printf(" |  ");
    for (int i = 0; i < strlen(ligneMap2)/2; ++i) {
        printf("%s ", config->emptySpace);
    }
    printf("[2] ");
    for (int i = 0; i < strlen(ligneMap2)/2; ++i) {
        printf("%s ", config->emptySpace);
    }
    printf(" |  ");
    for (int i = 0; i < strlen(ligneMap3)/2; ++i) {
        printf("%s ", config->emptySpace);
    }
    printf("[3] ");
    for (int i = 0; i < strlen(ligneMap3)/2; ++i) {
        printf("%s ", config->emptySpace);
    }
    printf(" |\n");


    fclose(map1);
    fclose(map2);
    fclose(map3);
}


