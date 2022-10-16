#include <stdio.h>
#include <stdlib.h>

#include "Header/Structure.h"
#include "Header/config.h"
#include "Header/map.h"
#include "Header/player.h"
#include "Header/show.h"

int main() {
    Config *config = malloc(sizeof(Config));
    int isConfigLoaded = getConfig(config, "app.config");

    if (!isConfigLoaded) {
      printf("Invalid config file!");
      return 1;
    }

    Map map = newMap(15, 7);
    createBorderMap(map);

    Player testPlayer = newPlayer(10, 3, 1, &map);


    map.map[4][7] = 'm';
    map.map[2][7] = 'X';

    map.map[2][2] = 'm';


    show(map, 1);



    // The game
    char direction;
    int valid = 1;
    while (valid){
        printf("testPlayer : ");
        scanf(" %c", &direction);
        getchar();
        valid = move(direction, &testPlayer, &map);
        show(map, 1);
    }


    // Free the map
    for (int i = 0; i < map.y; ++i) {
        free(map.map[i]);
    }
    free(map.map);



    return 0;
}
