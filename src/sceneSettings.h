#pragma once

#include "scene.h"

struct SettingsScene {
  float music;
  float sound;
  int activeRes;
  bool resEdit;
  bool fullScreen;
};

void initSettingsScene(SettingsScene &ss);
Scene updateSettingsScene(SettingsScene &ss);
Scene drawSettingsScene(SettingsScene &ss);
