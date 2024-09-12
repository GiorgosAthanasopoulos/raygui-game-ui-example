#include "game.h"
#include "settings.h"
#include <raylib.h>

bool Game::ShouldClose() { return WindowShouldClose(); }

void Game::Update() { sm.Update(); }

void Game::Draw() {
  BeginDrawing();
  ClearBackground(WIN_BG);

  sm.Draw();

  EndDrawing();
}
