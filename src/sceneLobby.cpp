#include "sceneLobby.h"
#include "external/raygui.h"
#include "scene.h"
#include "settings.h"
#include <iostream>
#include <raylib.h>

Scene updateLobbyScene() {
  if (IsKeyPressed(KEY_ESCAPE)) {
    return MAIN;
  }

  return LOBBY;
}

Scene drawLobbyScene() {
  float w = GetRenderWidth();
  float h = GetRenderHeight();

  float aspectYH = h / Y_ASPECT_RATIO;
  float titleFontSize = aspectYH;
  float beforeTitlePadding = aspectYH / 2;
  float y = 0;
  float x = 0;
  float centerX = w / 2;
  float betweenControlPaddingY = aspectYH / 2;
  float betweenControlPaddingX = aspectYH / 4;

  Vector2 buttonSize = {w / 5, aspectYH};
  const int buttonsPerRow = 3;
  float buttonTotalW = buttonsPerRow * buttonSize.x;
  float paddingTotalW = betweenControlPaddingX * (buttonsPerRow - 1);
  float remainingW = w - buttonTotalW - paddingTotalW;
  float buttonLeftPadding = remainingW / 2;

  y += beforeTitlePadding;
  {
    // title
    const char *title = LOBBY_TITLE;
    float titleW = MeasureText(title, titleFontSize);

    DrawText(title, centerX - titleW / 2, y + titleFontSize / 2, titleFontSize,
             LOBBY_TITLE_FG);
  }
  y += titleFontSize;

  x += buttonLeftPadding;
  y += betweenControlPaddingY;
  {
    // level 1
    Vector2 pos = {x + buttonSize.x / 2, y + buttonSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, buttonSize.x, buttonSize.y};
    if (GuiButton(bounds, "LEVEL 1")) {
      return LEVEL1;
    }
  }
  x += buttonSize.x;

  x += betweenControlPaddingX;
  {
    // level 2
    Vector2 pos = {x + buttonSize.x / 2, y + buttonSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, buttonSize.x, buttonSize.y};
    if (GuiButton(bounds, "LEVEL 2")) {
      return LEVEL2;
    }
  }
  x += buttonSize.x;

  x += betweenControlPaddingX;
  {
    // level 3
    Vector2 pos = {x + buttonSize.x / 2, y + buttonSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, buttonSize.x, buttonSize.y};
    if (GuiButton(bounds, "LEVEL 3")) {
      return LEVEL3;
    }
  }
  x += buttonSize.x;
  y += buttonSize.y;

  y += betweenControlPaddingY;
  Vector2 buttonSize2 = {w / 3 / 2, aspectYH / 2};
  {
    // back button
    Vector2 pos = {10, h - 10 - buttonSize2.y};
    Rectangle bounds = {pos.x, pos.y, buttonSize2.x, buttonSize2.y};

    if (GuiButton(bounds, "BACK")) {
      return MAIN;
    }
  }
  y += buttonSize2.y;

  return LOBBY;
}
