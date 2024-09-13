#include "sceneManager.h"
#include "scene.h"
#include "sceneLobby.h"
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
    current = updateSettingsScene(ss);
    break;
  case LOBBY:
    current = updateLobbyScene();
    break;
  }
}

void SceneManager::Draw() {
  switch (current) {
  case MAIN:
    current = drawMainScene(ms);
    break;
  case SETTINGS:
    current = drawSettingsScene(ss);
    break;
  case LOBBY:
    current = drawLobbyScene();
    break;
  }
}
