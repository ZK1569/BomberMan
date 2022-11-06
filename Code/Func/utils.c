#include <stdio.h>
#include <ctype.h>

#include "../Header/player.h"
#include "../Header/utils.h"

#define LIMIT 24
#define TRUE 1
#define FALSE 0

void inviteToValidAction(void) {
  printf("Erreur : veuillez faire une action valide.");
}

int getUserInput(void) {
  char text[LIMIT];
  int count = 0;
  int overflow = FALSE;
  char t = '\0';

  /* read in a string */
  while (t != '\n') {
    t = getchar();
    text[count] = t;
    count++;

    if (count >= LIMIT) {
      overflow = TRUE;
      count = 0;
    }
  }

  if (overflow) return -1;
  if (count != 2) return -1;

  return text[0] >= '1' && text[0] <= '3'
         ? text[0] - '0'
         : -1;
}

char getPlayerInput(void) {
  char text[LIMIT];
  int count = 0;
  int overflow = FALSE;
  char t = '\0';

  /* read in a string */
  while (t != '\n') {
    t = getchar();
    text[count] = t;
    count++;

    if (count >= LIMIT) {
      overflow = TRUE;
      count = 0;
    }
  }

  if (overflow) return 0;
  if (count != 2) return 0;

  if (text[0] >= 'A' && text[0] <= 'Z') {
    text[0] = tolower(text[0]);
  }

  return text[0];
}

int isMovementValid(char character) {
  return character == MOVE_UP
         || character == MOVE_LEFT
         || character == MOVE_DOWN
         || character == MOVE_RIGHT
         || character == MOVE_NO;
}

int isActionValid(char character) {
  return character == ACTION_PLACE_BOMB;
}

int strlen(char *str){
    int c = 0;
    while(*str != '\0'){
        c++;
        str++;
    }
    return c;
}