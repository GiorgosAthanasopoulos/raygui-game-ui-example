#pragma once

#include "sceneManager.h"
class Game {
public:
  bool ShouldClose();
  void Update();
  void Draw();

private:
  SceneManager sm;
};
