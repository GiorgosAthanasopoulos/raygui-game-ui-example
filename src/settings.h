#pragma once

#include "raylib.h"

// window
#define WIN_FLAGS FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE
#define WIN_W 1280
#define WIN_H 720
#define WIN_TITLE "RAYGUI"
#define WIN_TARGET_FPS 60
#define WIN_MIN_W 640
#define WIN_MIN_H 480
#define WIN_BG BLACK
#define WIN_FULLSCREEN false

// keybinds
#define KEY_EXIT KEY_NULL

// raygui
#define RAYGUI_FONT_SIZE 40

// music
#define MUSIC_INITIAL_VOLUME 70
#define MUSIC_MIN_VOLUME 0
#define MUSIC_MAX_VOLUME 100

// sound
#define SOUND_INITIAL_VOLUME 100
#define SOUND_MIN_VOLUME 0
#define SOUND_MAX_VOLUME 100

// scenes
#define SCENE_INITIIAL MAIN

#define Y_ASPECT_RATIO 9

// exit game window
#define EXIT_BG WHITE
#define EXIT_TITLE "EXIT"
#define EXIT_TITLE_FG RED
#define EXIT_TEXT "Are you sure you want to exit?"
#define EXIT_TEXT_FG GRAY
#define EXIT_CONFIRM_TEXT "YES"
#define EXIT_DENY_TEXT "NO"

// main scene
#define MAIN_TITLE "RAYGUI";
#define MAIN_TITLE_FG RED
#define MAIN_PLAY_TEXT "PLAY"
#define MAIN_SETTINGS_TEXT "SETTINGS"
#define MAIN_EXIT_TEXT "EXIT"

// settings scene
#define SETTINGS_TITLE "SETTINGS"
#define SETTINGS_TITLE_FG RED
#define SETTINGS_MUSIC_TEXT "Music Volume"
#define SETTINGS_SOUND_TEXT "Sound Volume"
#define SETTINGS_RES_TEXT "3840x2160;2560x1440;1920x1080;1280x720;640x480"
#define SETTINGS_RES_COUNT 5
#define SETTINGS_FULL_TEXT "Fullscreen"
#define SETTINGS_RES_INITIAL_INDEX 3

// lobby scene
#define LOBBY_TITLE "Lobby"
#define LOBBY_TITLE_FG RED
