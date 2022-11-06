#include <stdio.h>
#include <stdlib.h>

#include "Header/Structure.h"
#include "Header/config.h"
#include "Header/map.h"
#include "Header/player.h"
#include "Header/show.h"
#include "Header/gameMode.h"
#include "Header/utils.h"

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

//    Map map = newMap( config->rows, config->columns);
//    createBorderMap(map);

    Map map = openMap("../Code/Maps/map1.txt");


    /*
     *   Initialize three players
     *   Store them in an array
     *   keep count of the number of players
     */
    Player testPlayer = newPlayer("Abdou", 1, 1, 1, &map);
    Player secondPlayer = newPlayer("Cristian", 8, 1, 2, &map);
    Player thirdPlayer = newPlayer("Loic", 1, 7, 3, &map);
    Player players[3] = {testPlayer, secondPlayer, thirdPlayer};

    Player *currentPlayer = &testPlayer;



    int numberOfPlayer = 3;
    int playerTurn = 0;

//    map.map[2][7] = 'X';
//    map.map[4][7] = 'm';
//    map.map[4][6] = 'm';
//    map.map[2][2] = 'm';

    show(map, 1, config);

    // The game
    char direction;
    int valid = 1;
    int isInputAllowed = 0;
    char lastPlayer;
    char winner = "";

    // every loop iteration we change the current player
    while (valid)
    {
        lastPlayer = currentPlayer->show;
        char *currentPlayerCharacter = setCurrentPlayerCharacter(playerTurn, config);

        // Fait une boucle temps que la jouer n'a pas rentré une direction possible
        do {
            printf("%s %s : ", currentPlayerCharacter, currentPlayer->name);

            direction = getPlayerInput();
            isInputAllowed = isMovementValid(direction) || isActionValid(direction);

            while (!isInputAllowed) {
              printf("Action invalide. %s %s : ", currentPlayerCharacter, currentPlayer->name);

              direction = getPlayerInput();
              isInputAllowed = isMovementValid(direction) || isActionValid(direction);
            };

            valid = move(direction, currentPlayer, &map, players, config);

        }while(valid==2);

        show(map, 1, config);

        int iteration = 0 ;
        do {
            playerTurn = (playerTurn + 1) % numberOfPlayer;
            currentPlayer = &players[playerTurn];
            iteration++;
            if (iteration >= 4 ){
                printf("il passe ici ? ");
                valid=0;
            }
        }while(!currentPlayer->alive && iteration <= 4);

        if (lastPlayer == currentPlayer->show ){
            valid=0;
//            winner = currentPlayer->name;
        }
    }

    printf("%s est le grand gagnant", winner);

    // Free the map
    for (int i = 0; i < map.y; ++i)
    {
        free(map.map[i]);
    }
    free(map.map);
    return 0;
}
