#include "sceneSettings.h"
#include "external/raygui.h"
#include "settings.h"
#include <raylib.h>

void initSettingsScene(SettingsScene &ss) {
  ss.music = MUSIC_INITIAL_VOLUME;
  ss.sound = SOUND_INITIAL_VOLUME;
}

Scene updateSettingsScene() {
  if (IsKeyPressed(KEY_ESCAPE)) {
    return MAIN;
  }

  return SETTINGS;
}

void drawSettingsScene(SettingsScene &ss) {
  float w = GetRenderWidth();
  float h = GetRenderHeight();

  float aspectYH = h / Y_ASPECT_RATIO;
  float titleFontSize = aspectYH;
  float beforeTitlePadding = aspectYH;
  float y = 0;
  float beforeMusicPadding = aspectYH;
  float centerX = w / 2;
  float betweenControlPadding = aspectYH;

  y += beforeTitlePadding;
  {
    // title
    const char *title = SETTINGS_TITLE;
    float titleW = MeasureText(title, titleFontSize);
    DrawText(title, centerX - titleW / 2, y + titleFontSize / 2, titleFontSize,
             SETTINGS_TITLE_FG);
  }
  y += titleFontSize;

  y += beforeMusicPadding;
  Vector2 musicSize = {w / 3, aspectYH};
  {
    // music
    Vector2 pos = {centerX, y + musicSize.y / 2};
    const char *text = SETTINGS_MUSIC_TEXT;
    float textW = MeasureText(text, RAYGUI_FONT_SIZE);
    Rectangle bounds = {pos.x - textW / 2, pos.y, musicSize.x, musicSize.y};
    GuiSlider(bounds, text, "", &ss.music, MUSIC_MIN_VOLUME, MUSIC_MAX_VOLUME);
  }
  y += musicSize.y;

  y += betweenControlPadding;
  Vector2 soundSize = musicSize;
  {
    // sound
    Vector2 pos = {centerX, y + soundSize.y / 2};
    const char *text = SETTINGS_SOUND_TEXT;
    float textW = MeasureText(text, RAYGUI_FONT_SIZE);
    Rectangle bounds = {pos.x - textW / 2, pos.y, musicSize.x, musicSize.y};
    GuiSlider(bounds, text, "", &ss.sound, SOUND_MIN_VOLUME, SOUND_MAX_VOLUME);
  }
  y += soundSize.y;

  y += betweenControlPadding;
  // TODO:
  {
    // resolution
  }

  {
    // fullscreen
  }
}
