#include <stdio.h>
#include <stdlib.h>

#include "Header/map.h"
#include "Header/show.h"
#include "Header/player.h"
#include "Header/chooseGameMode.h"

int main() {

    char choice = chooseGameMode();

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
