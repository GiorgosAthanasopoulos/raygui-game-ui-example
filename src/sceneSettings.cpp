#include "sceneSettings.h"
#include "external/raygui.h"
#include "scene.h"
#include "settings.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <raylib.h>

void initSettingsScene(SettingsScene &ss) {
  ss.music = MUSIC_INITIAL_VOLUME;
  ss.sound = SOUND_INITIAL_VOLUME;
  ss.activeRes = SETTINGS_RES_INITIAL_INDEX;
  ss.resEdit = false;
  ss.fullScreen = WIN_FULLSCREEN;
}

Scene updateSettingsScene(SettingsScene &ss) {
  if (IsKeyPressed(KEY_ESCAPE)) {
    return MAIN;
  }

  return SETTINGS;
}

Scene drawSettingsScene(SettingsScene &ss) {
  float w = GetRenderWidth();
  float h = GetRenderHeight();

  float aspectYH = h / Y_ASPECT_RATIO;
  float titleFontSize = aspectYH;
  float beforeTitlePadding = aspectYH / 2;
  float y = 0;
  float beforeResPadding = aspectYH / 2;
  float centerX = w / 2;
  float betweenControlPadding = aspectYH / 2;

  y += beforeTitlePadding;
  {
    // title
    const char *title = SETTINGS_TITLE;
    float titleW = MeasureText(title, titleFontSize);

    DrawText(title, centerX - titleW / 2, y + titleFontSize / 2, titleFontSize,
             SETTINGS_TITLE_FG);
  }
  y += titleFontSize;

  y += beforeResPadding;
  Vector2 resSize = {w / 3, aspectYH};
  {
    // resolution
    Vector2 pos = {centerX - resSize.x / 2, y + resSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, resSize.x, resSize.y};

    const char *text = SETTINGS_RES_TEXT;

    int tempActiveRes = ss.activeRes;
    if (GuiDropdownBox(bounds, text, &tempActiveRes, ss.resEdit) == 1) {
      ss.resEdit = !ss.resEdit;
    }

    if (tempActiveRes != ss.activeRes) {
      ss.activeRes = tempActiveRes;

      int resCount = 0;
      const char **resolutions = TextSplit(text, ';', &resCount);
      assert(resCount == SETTINGS_RES_COUNT);

      const char *currentResolution = resolutions[ss.activeRes];
      char *res = (char *)malloc(strlen(currentResolution));
      memcpy(res, currentResolution, strlen(currentResolution));

      int coordCount = 0;
      const char **coords = TextSplit(res, 'x', &coordCount);
      assert(coordCount == 2);

      const char *xStr = coords[0];
      const char *yStr = coords[1];

      int x = TextToInteger(xStr);
      int y = TextToInteger(yStr);

      SetWindowSize(x, y);

      free(res);
    }
  }
  y += resSize.y;

  if (ss.resEdit) {
    return SETTINGS;
  }

  y += betweenControlPadding;
  Vector2 fullSize = {w / 3, aspectYH};
  {
    // fullscreen
    Vector2 pos = {centerX - fullSize.x / 2, y + fullSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, fullSize.x, fullSize.y};

    bool tempFullscreen = ss.fullScreen;
    GuiToggle(bounds, SETTINGS_FULL_TEXT, &tempFullscreen);

    if (tempFullscreen != ss.fullScreen) {
      ss.fullScreen = tempFullscreen;
      if (ss.fullScreen != IsWindowFullscreen()) {
        ToggleFullscreen();
      }
    }
  }
  y += fullSize.y;

  y += betweenControlPadding;
  Vector2 musicSize = resSize;
  {
    // music

    const char *text = SETTINGS_MUSIC_TEXT;
    float textW = MeasureText(text, RAYGUI_FONT_SIZE);

    Vector2 pos = {centerX, y + musicSize.y / 2};
    Rectangle bounds = {pos.x - textW / 2, pos.y, musicSize.x, musicSize.y};

    GuiSlider(bounds, text, "", &ss.music, MUSIC_MIN_VOLUME, MUSIC_MAX_VOLUME);
  }
  y += musicSize.y;

  y += betweenControlPadding;
  Vector2 soundSize = musicSize;
  {
    // sound
    const char *text = SETTINGS_SOUND_TEXT;
    float textW = MeasureText(text, RAYGUI_FONT_SIZE);

    Vector2 pos = {centerX - textW / 2, y + soundSize.y / 2};
    Rectangle bounds = {pos.x, pos.y, soundSize.x, soundSize.y};

    GuiSlider(bounds, text, "", &ss.sound, SOUND_MIN_VOLUME, SOUND_MAX_VOLUME);
  }
  y += soundSize.y;

  y += betweenControlPadding;
  Vector2 buttonSize = {w / 3 / 2, aspectYH / 2};
  {
    // back button
    Vector2 pos = {10, h - 10 - buttonSize.y};
    Rectangle bounds = {pos.x, pos.y, buttonSize.x, buttonSize.y};

    if (GuiButton(bounds, "BACK")) {
      return MAIN;
    }
  }

  return SETTINGS;
}
