#include <stdio.h>
#include <stdlib.h>

#include "Header/map.h"
#include "Header/show.h"
#include "Header/utils.h"

int main()
{

    Map map = newMap(15, 7);
    createBorderMap(map);

    /*
     *   Initialize three players
     *   Store them in an array
     *   keep count of the number of players
     */
    Player testPlayer = newPlayer("Abdou", 10, 3, 1, &map);
    Player secondPlayer = newPlayer("Cristian", 11, 4, 1, &map);
    Player thirdPlayer = newPlayer("Loic", 9, 5, 1, &map);
    Player players[3] = {testPlayer, secondPlayer, thirdPlayer};

    Player *currentPlayer = &testPlayer;

    int numberOfPlayer = 3;
    int playerTurn = 0;

    map.map[4][7] = 'm';
    map.map[2][7] = 'X';
    map.map[2][2] = 'm';

    show(map, 1);

    // The game
    char direction;
    int valid = 1;

    // every loop iteration we change the current player
    while (valid)
    {

        printf("%s : ", currentPlayer->name);
        scanf(" %c", &direction);
        getchar();
        valid = move(direction, currentPlayer, &map);
        show(map, 1);

        playerTurn = (playerTurn + 1) % numberOfPlayer;
        currentPlayer = &players[playerTurn];
    }

    // Free the map
    for (int i = 0; i < map.y; ++i)
    {
        free(map.map[i]);
    }
    free(map.map);

    return 0;
}
