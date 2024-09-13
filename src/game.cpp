#include "game.h"
#include "settings.h"
#include <raylib.h>

bool gameShouldClose() { return WindowShouldClose(); }

void gameUpdate(Game &g) { g.sm.Update(); }

void gameDraw(Game &g) {
  BeginDrawing();
  ClearBackground(WIN_BG);

  g.sm.Draw();

  EndDrawing();
}
