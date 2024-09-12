# Raygui Game UI Example

Example for creating ui/menu system with `raylib/raygui`.

## Dependencies

- `g++` with `-std=c++11` support,
- GNU core utils for `mkdir`, (if you want the automatic creation of the bin folder the first run you compile. Otherwise remove mkdir command from the build make subcommand in `makefile` and create the directory yourself)
- `raylib`. (it needs to be available on the system path as well. otherwise you will need to edit `CFLAGS` and `LDFLAGS` variables in `makefile` accordingly)

## Getting Started

Run `make` to compile and run the program. Tested on PLATFORM_DESKTOP + GNU/Linux + Wayland.

## File Structure

- `src/external/`: external library headers,
- `src/coreRaylib.*`: raylib specific/boilerplate/init code,
- `src/game.*`: game is the global app class that controls everything,
- `src/main.c`: main app entry point,
- `src/scene*.*`: Specific scene files,
    - Exceptions:
        - `src/scene.h`: enum for all the scenes for easy managing/switching between them,
        - `src/sceneManager.*`: a manager for all of the game's scenes.
- `src/settings.h`: global settings file.

## TODO

- [x] Main Scene
- [ ] Settings Scene (50%)
- [ ] Lobby Scene
- [ ] In-Game UI
