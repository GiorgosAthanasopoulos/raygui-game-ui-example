#include "coreRaylib.h"
#include "game.h"

int main() {
  initRaylib();
  Game g;

  while (!g.ShouldClose()) {
    g.Update();
    g.Draw();
  }

  closeGame();
}
