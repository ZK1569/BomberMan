#include <stdio.h>

#define LIMIT 24
#define TRUE 1
#define FALSE 0

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