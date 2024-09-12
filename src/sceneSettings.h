#pragma once

#include "scene.h"

struct SettingsScene {
  float music;
  float sound;
};

void initSettingsScene(SettingsScene &ss);
Scene updateSettingsScene();
void drawSettingsScene(SettingsScene &ss);
