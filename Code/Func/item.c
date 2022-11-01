#include <stdlib.h>
#include <time.h>

char popItem() {
  srand(time(0));
  int dice = rand() % 101;

  // rare items
  if (dice >= 90) {
    int dice = rand() % 101;

    if (dice == 100) {
      return 'r'; // 🔴
    }
    else if (dice >= 90) {
      return 'o'; // 🆙
    }
    else if (dice >= 45 && dice <= 90) {
      return 'h'; // 💖
    }
    else {
      return 'v'; // 🦺
    }
  }

  // ordinary items
  dice = rand() % 101;

  if (dice >= 75) {
    return rand() % 101 < 50 ? 'k' : 'p' ; // 👟 - 🏃
  }
  else if (dice >= 50 && dice < 75) {
    return rand() % 101 < 50 ? 'b' : 'y'; // 🔵 - 🟡
  }
  else {
    return rand() % 101 ? 'd' : 'u'; // 🔽 - 🔼
  }
}