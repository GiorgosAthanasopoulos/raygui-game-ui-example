#pragma once

#include "scene.h"

struct MainScene {
  bool exitWindowVisible;
};

void initMainScene(MainScene &ms);
void updateMainScene(MainScene &ms);
Scene drawMainScene(MainScene &ms);
