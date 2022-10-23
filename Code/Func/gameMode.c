#include <printf.h>
#include "../Header/gameMode.h"
#include "../Header/utils.h"

#define TRUE 1
#define FALSE 0

int setGameMode(void) {
  int isModeAvailable = FALSE;
  int chosenMode;

  printf("--------------------------------\n"
         "MENU (choisir le chiffre du mode de jeu):\n"
         "1️⃣ Démarrer\n"
         "2️⃣ Démarrer le serveur (indisponible)\n"
         "3️⃣ Rejoindre le serveur (indisponible)\n"
         "--------------------------------\n");

  do {
    chosenMode = getUserInput();

    switch (chosenMode) {
      case START:
        isModeAvailable = TRUE;
        break;
      case START_SERVER:
      case JOIN_SERVER:
      default:
        isModeAvailable = FALSE;
        printf("Erreur : veuillez choisir un des modes disponibles.\n");
        break;
    }
  } while (!isModeAvailable);

  return chosenMode;
}
