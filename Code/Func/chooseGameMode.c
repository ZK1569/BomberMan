#include <stdio.h>

char chooseGameMode() {
  int isChoiceMade = 0;
  char choice;

  printf("--------------------------------\n"
         "MENU (choisir le chiffre correspondant à votre choix):\n"
         "1️⃣ Démarrer\n"
         "2️⃣ Démarrer le serveur (indisponible)\n"
         "3️⃣ Rejoindre le serveur (indisponible)\n"
         "--------------------------------\n");

  do {
    scanf("%c", &choice);

    switch (choice) {
      case '1':
        isChoiceMade = 1;
        break;
      case '2':
      case '3':
      default:
        printf("Erreur ! Veuillez entrer un des chiffres proposés.\n");
        break;
    }
  } while (isChoiceMade == 0);

  return choice;
}