# Raygui Game UI Example

Example for creating ui/menu system with `raylib/raygui`.

## Dependencies

- `g++` with `-std=c++11` support,
- GNU core utils for `mkdir`, (if you want the automatic creation of the bin folder the first run you compile. Otherwise remove mkdir command from the build make subcommand in `makefile` and create the directory yourself)
- `raylib`. (it needs to be available on the system path as well. otherwise you will need to edit `CFLAGS` and `LDFLAGS` variables in `makefile` accordingly)

## Getting Started

Run `make` to compile and run the program. Tested on PLATFORM_DESKTOP + GNU/Linux + Wayland.
