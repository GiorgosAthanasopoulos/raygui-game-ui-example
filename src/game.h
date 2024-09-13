#pragma once

#include "sceneManager.h"

struct Game {
  SceneManager sm;
};

bool gameShouldClose();
void gameUpdate(Game &g);
void gameDraw(Game &g);
