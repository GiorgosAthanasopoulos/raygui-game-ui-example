#include "sceneManager.h"
#include "scene.h"
#include "sceneMain.h"
#include "sceneSettings.h"
#include "settings.h"

SceneManager::SceneManager() {
  current = SCENE_INITIIAL;
  initMainScene(ms);
  initSettingsScene(ss);
}

void SceneManager::Update() {
  switch (current) {
  case MAIN:
    updateMainScene(ms);
    break;
  case SETTINGS:
    current = updateSettingsScene();
    break;
  case LOBBY:
    break;
  }
}

void SceneManager::Draw() {
  switch (current) {
  case MAIN:
    current = drawMainScene(ms);
    break;
  case SETTINGS:
    drawSettingsScene(ss);
    break;
  case LOBBY:
    break;
  }
}
