#include "coreRaylib.h"
#include "settings.h"
#define RAYGUI_IMPLEMENTATION
#include "external/raygui.h"
#include <raylib.h>

void initRaylib() {
  SetConfigFlags(WIN_FLAGS);
  InitWindow(WIN_W, WIN_H, WIN_TITLE);
  SetWindowState(
      FLAG_FULLSCREEN_MODE); // NOTE: not in WIN_FLAGS because of problem with
                             // wayland fullscreen on init
  SetTargetFPS(WIN_TARGET_FPS);
  SetExitKey(KEY_EXIT);
  SetWindowMinSize(WIN_MIN_W, WIN_MIN_H);
  InitAudioDevice();

  GuiSetStyle(DEFAULT, TEXT_SIZE, RAYGUI_FONT_SIZE);
}

void closeRaylib() {
  CloseAudioDevice();
  CloseWindow();
}

void closeGame() {
  closeRaylib();
  exit(0);
}
