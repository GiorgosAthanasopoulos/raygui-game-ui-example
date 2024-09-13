#include "sceneLobby.h"
#include "external/raygui.h"
#include "scene.h"
#include "settings.h"
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
  float centerX = w / 2;
  float betweenControlPaddingY = aspectYH / 2;
  float betweenControlPaddingX = aspectYH / 4;

  y += beforeTitlePadding;
  {
    // title
    const char *title = LOBBY_TITLE;
    float titleW = MeasureText(title, titleFontSize);

    DrawText(title, centerX - titleW / 2, y + titleFontSize / 2, titleFontSize,
             LOBBY_TITLE_FG);
  }
  y += titleFontSize;

  // TODO:

  Vector2 buttonSize = {w / 3 / 2, aspectYH / 2};
  {
    // back button
    Vector2 pos = {10, h - 10 - buttonSize.y};
    Rectangle bounds = {pos.x, pos.y, buttonSize.x, buttonSize.y};

    if (GuiButton(bounds, "BACK")) {
      return MAIN;
    }
  }
  y += buttonSize.y;

  return LOBBY;
}
