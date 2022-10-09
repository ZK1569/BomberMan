#include <stdio.h>
#include <stdlib.h>

#include "Header/map.h"
#include "Header/show.h"
#include "Header/player.h"

int main() {

    Map map = newMap(15, 7);
    createBorderMap(map);

    Player testPlayer = newPlayer(1, 1, 1, &map);


//    map.map[5][7] = 'm';
//    map.map[3][7] = 'X';
//
//    map.map[2][2] = 'm';


    show(map, 1);


    // The game
    char direction;
    int valid = 1;
    while (valid){
        printf("testPlayer : ");
        scanf("%s", &direction);
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
