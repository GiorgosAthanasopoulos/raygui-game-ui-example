#include "coreRaylib.h"
#include "game.h"

int main() {
  initRaylib();
  Game g;

  while (!gameShouldClose()) {
    gameUpdate(g);
    gameDraw(g);
  }

  closeGame();
}
