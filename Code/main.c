#include <stdio.h>
#include <stdlib.h>

#include "Header/Structure.h"
#include "Header/config.h"
#include "Header/map.h"
#include "Header/player.h"
#include "Header/show.h"
#include "Header/gameMode.h"

int main()
{
    Config *config = malloc(sizeof(Config));
    int isConfigLoaded = getConfig(config, "app.config");

    if (!isConfigLoaded)
    {
        printf("Invalid config file!");
        return 1;
    }

    int chosenMode = setGameMode();
    switch (chosenMode) {
      case START:
        // TODO: call the function for playing against CPU
        break;
      case START_SERVER:
        // TODO: call the function for starting a local server
        break;
      case JOIN_SERVER:
        // TODO: call the function for joining a server
        break;
      default:
        // TODO:
        //  either call the same function as "START" case.
        //  or EXIT.
        break;
    }

    Map map = newMap( config->rows, config->columns);
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

    show(map, 1, config);

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
        show(map, 1, config);

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
