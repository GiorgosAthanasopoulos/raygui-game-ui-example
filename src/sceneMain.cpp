#include "sceneMain.h"
#include "coreRaylib.h"
#include "external/raygui.h"
#include "scene.h"
#include "settings.h"
#include <raylib.h>

void initMainScene(MainScene &ms) { ms.exitWindowVisible = false; }

void updateMainScene(MainScene &ms) {
  if (IsKeyPressed(KEY_ESCAPE)) {
    ms.exitWindowVisible = !ms.exitWindowVisible;
  }
}

Scene drawMainScene(MainScene &ms) {
  float w = GetRenderWidth();
  float h = GetRenderHeight();

  float aspectYH = h / Y_ASPECT_RATIO;

  float titleFontSize = aspectYH;

  float beforeTitlePadding = aspectYH;
  float beforePlayPadding = aspectYH;
  float betweenButtonPadding = aspectYH;

  float y = 0;

  float centerX = w / 2;
  Vector2 buttonSize = {w / 4, aspectYH};
  float buttonX = centerX - buttonSize.x / 2;

  if (ms.exitWindowVisible) {
    Vector2 winSize = {w / 2, h / 2};
    Vector2 winPos = {w / 2 - winSize.x / 2, h / 2 - winSize.y / 2};
    Rectangle win = {winPos.x, winPos.y, winSize.x, winSize.y};

    float aspectYH = win.height / Y_ASPECT_RATIO;
    float titleFontSize = aspectYH;
    float beforeTitlePadding = aspectYH;
    float y = 0;
    float beforeTextPadding = aspectYH;
    float textFontSize = titleFontSize / 2;
    Vector2 buttonSize2 = {buttonSize.x / 2, buttonSize.y / 2};
    float buttonPadding = aspectYH;

    DrawRectangleRec(win, EXIT_BG);

    y += beforeTitlePadding;
    {
      // title
      const char *title = EXIT_TITLE;
      float titleW = MeasureText(title, titleFontSize);
      DrawText(title, win.x + win.width / 2 - titleW / 2,
               win.y + y + titleFontSize / 2, titleFontSize, EXIT_TITLE_FG);
    }
    y += titleFontSize;

    y += beforeTextPadding;
    {
      // text
      const char *text = EXIT_TEXT;
      float textW = MeasureText(text, textFontSize);
      DrawText(text, win.x + win.width / 2 - textW / 2,
               win.y + y + textFontSize / 2, textFontSize, EXIT_TEXT_FG);
    }
    y += textFontSize;

    {
      // confirm
      Vector2 pos = {win.x + (win.width / 2 / 2) - buttonSize2.x / 2,
                     win.y + win.height - buttonPadding - buttonSize2.y / 2};
      Rectangle bounds = {pos.x, pos.y, buttonSize2.x, buttonSize2.y};
      if (GuiButton(bounds, EXIT_CONFIRM_TEXT)) {
        closeGame();
      }
    }

    {
      // no
      Vector2 pos = {win.x + win.width - (win.width / 2 / 2) -
                         buttonSize2.x / 2,
                     win.y + win.height - buttonPadding - buttonSize2.y / 2};
      Rectangle bounds = {pos.x, pos.y, buttonSize2.x, buttonSize2.y};
      if (GuiButton(bounds, EXIT_DENY_TEXT)) {
        ms.exitWindowVisible = !ms.exitWindowVisible;
      }
    }

    return MAIN;
  }

  y += beforeTitlePadding;
  {
    // title
    const char *title = MAIN_TITLE;
    float titleW = MeasureText(title, titleFontSize);
    DrawText(title, centerX - titleW / 2, y + titleFontSize / 2, titleFontSize,
             MAIN_TITLE_FG);
  }
  y += titleFontSize;

  y += beforePlayPadding;
  {
    // play button
    Vector2 pos = {buttonX, y + buttonSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, buttonSize.x, buttonSize.y};
    if (GuiButton(bounds, MAIN_PLAY_TEXT)) {
      return LOBBY;
    }
  }
  y += buttonSize.y;

  y += betweenButtonPadding;
  {
    // settings button
    Vector2 pos = {buttonX, y + buttonSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, buttonSize.x, buttonSize.y};
    if (GuiButton(bounds, MAIN_SETTINGS_TEXT)) {
      return SETTINGS;
    }
  }
  y += buttonSize.y;

  y += betweenButtonPadding;
  {
    // exit button
    Vector2 pos = {buttonX, y + buttonSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, buttonSize.x, buttonSize.y};
    if (GuiButton(bounds, MAIN_EXIT_TEXT)) {
      ms.exitWindowVisible = !ms.exitWindowVisible;
    }
  }
  y += buttonSize.y;

  return MAIN;
}
