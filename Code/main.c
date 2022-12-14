#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Header/Structure.h"
#include "Header/config.h"
#include "Header/map.h"
#include "Header/player.h"
#include "Header/show.h"
#include "Header/gameMode.h"
#include "Header/utils.h"
#include "./graphical/game/game.h"

int main()
{

    // Switch 1 for devMode 0 for real game
    int devMode = 0;
    Config *config = malloc(sizeof(Config));
    int isConfigLoaded = getConfig(config, "app.config");

    if (!isConfigLoaded)
    {
        printf("Invalid config file!");
        return 1;
    }

    int chosenMode = setGameMode();
    switch (chosenMode)
    {
    case START:
        // TODO: call the function for playing against CPU
        break;
    case START_GRAPHICAL:
    {

        // ask for how many players
        int playerCount = 0;
        do
        {
            printf("How many players? (1-4): ");
            scanf("%d", &playerCount);
        } while (playerCount < 1 || playerCount > 4);

        start_game(playerCount);
    }
        return 0;
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

    Map map;

    if (devMode)
    {
        map = openMap(whatMap(0));
    }
    else
    {

        // Choix des cartes au debut de la game
        showAllMaps(config);
        int choiceMap = 0;
        do
        {
            printf("Quel map voulez-vous utiliser : ");
            choiceMap = getUserInput();
            printf("\n");
        } while (choiceMap < 0 && choiceMap <= 3); // 3 est le nombre total de map

        map = openMap(whatMap(choiceMap));
    }
    printf("Map = %d, %d\n", map.x, map.y);

    srand(NULL);

    /*
     *   Initialize three players
     *   Store them in an array
     *   keep count of the number of players
     */
    Player testPlayer = newPlayer("Abdou", 1, 1, 1, &map);
    Player secondPlayer = newPlayer("Cristian", map.x - 2, 1, 2, &map);
    //    Player thirdPlayer = newPlayer("Loic", 1, map.y-2, 3, &map);
    //    Player fourPlayer = newPlayer("test", map.x-2, map.y-2, 4, &map);
    //    Player players[4] = {testPlayer, secondPlayer, thirdPlayer,fourPlayer};
    Player players[2] = {testPlayer, secondPlayer};

    Player *currentPlayer = &players[0];

    // TODO: Si vous changger le nomrbre de joueur tot

    int numberOfPlayer = sizeof(players) / sizeof(Player);
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

    // every loop iteration we change the current player
    while (valid)
    {
        lastPlayer = currentPlayer->show;
        char *currentPlayerCharacter = setCurrentPlayerCharacter(playerTurn, config);

        // Show bombs of the current player in devMode
        if (devMode)
        {
            for (int i = 0; i < 3; ++i)
            {
                printf("%d: Bomb(%d,%d), life = %d \n", i, currentPlayer->myBomb[i].x, currentPlayer->myBomb[i].x, currentPlayer->myBomb[i].life);
            }
            printf("Nombre Total bomb = %d\n", currentPlayer->nbrBomb);
        }

        // Fait une boucle temps que la jouer n'a pas rentr?? une direction possible
        do
        {
            printf("%s %s : ", currentPlayerCharacter, currentPlayer->name);

            direction = getPlayerInput();
            isInputAllowed = isMovementValid(direction) || isActionValid(direction);

            while (!isInputAllowed)
            {
                printf("Action invalide. %s %s : ", currentPlayerCharacter, currentPlayer->name);

                direction = getPlayerInput();
                isInputAllowed = isMovementValid(direction) || isActionValid(direction);
            };

            valid = move(direction, currentPlayer, &map, players, config, numberOfPlayer);

        } while (valid == 2);

        show(map, 1, config);

        // Passe au joueur suivant vivant et que au minimum 1 joueur est vivant
        int change = 0;
        do
        {
            playerTurn = (playerTurn + 1) % numberOfPlayer;
            currentPlayer = &players[playerTurn];
            change++;
        } while (!currentPlayer->alive && change < numberOfPlayer);

        if (lastPlayer == currentPlayer->show || change > numberOfPlayer)
        {
            valid = 0;
        }
    }

    printf("%s est le grand gagnant", currentPlayer->name);

    // Free the map
    for (int i = 0; i < map.y; ++i)
    {
        free(map.map[i]);
    }
    free(map.map);
    return 0;
}
