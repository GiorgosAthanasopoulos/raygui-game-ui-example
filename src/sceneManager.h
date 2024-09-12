#pragma once

#include "scene.h"
#include "sceneMain.h"
#include "sceneSettings.h"

class SceneManager {
public:
  SceneManager();
  void Update();
  void Draw();

private:
  Scene current;
  MainScene ms;
  SettingsScene ss;
};
