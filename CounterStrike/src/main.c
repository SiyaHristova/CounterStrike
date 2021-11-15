#include <stdlib.h>

#include "BattleField.h"

int main() {
  BattleField battleField;

  createPlayers(&battleField);
  startBattle(&battleField);

  return EXIT_SUCCESS;
}
