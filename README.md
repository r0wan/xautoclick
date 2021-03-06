# xAutoClick

![CodeQL analysis](https://github.com/qarkai/xautoclick/workflows/CodeQL%20analysis/badge.svg)

## Note

It's the fork of [xAutoClick](http://xautoclick.sourceforge.net/).

## Description

This autoclicker application enables you to automatically click the left mousebutton. It is designed to reduce strain on the wrist muscles caused by repetitive mouse clicking, which can lead to serious injury or impair (RSI, Carpal Tunnel Syndrome, et cetera). By specifying the interval, a random factor and the number of times to click, the program simulates natural clicking.

Possible fields of use are (obviously) programs that require a lot of repetitive clicking, but it can also be used to click restart every ten minutes in a presentation program.

In order to temporary disable clicking hold left mouse button.

Currently, xAutoClick has GUI front-ends for X11/CLI, X11/FLTK, X11/GTK+ 3.0 and X11/Qt 5.x and has been tested on Linux/x86.

## Installation

[![AUR package](https://repology.org/badge/version-for-repo/aur/xautoclick.svg)](https://aur.archlinux.org/packages/xautoclick/)

### Optional dependencies

* `FLTK` for FLTK GUI
* `GTK3` for GTK GUI
* `Qt5` for Qt GUI

## Compilation

### Dependencies

Dependency | Arch Linux | Debian / Ubuntu
-- | -- | --
CMake | `cmake` | `cmake`

At least one of clicker engines

X11 clicker engine | Arch Linux | Debian / Ubuntu
-- | -- | --
libxtst | `libxtst` | `libxtst-dev`

Udev clicker engine | Arch Linux | Debian / Ubuntu
-- | -- | --
libevdev   | `libevdev` | `libevdev-dev`
pkg-config | `pkgconf`  | `pkgconf` or `pkg-config`

Optional GUI

GUI | Arch Linux | Debian / Ubuntu
-- | -- | --
FLTK | `fltk`     | `libfltk1.3-dev`
GTK3 | `gtk3`     | `libgtk-3-dev`
Qt5  | `qt5-base` | `qtbase5-dev`

### Build

To prepare, run:

```sh
mkdir build
cd build
cmake ..
```

To build if all is fine (at least one GUI must be set to yes), run:

```sh
cmake --build .
```

### Install

To install, run:

```sh
sudo cmake --build . --target install
```

### Run

To run without installation, use one of compiled executables in `./build` according to:

GUI | Executable
-- | --
ASCII | `aautoclick`
CLI   | `cautoclick`
FLTK  | `fltkautoclick`
GTK   | `gautoclick3`
Qt    | `qt5autoclick`

## Authors

Core, ASCII, GTK1, GTK2, QT3, QT4, FLTK, Command Line, build system: [Ivo van Poorten](https://github.com/ivop) <ivop@euronet.nl> <ivop@free.fr>

GTK3, Qt5, CMake build system, libevdev: [Arkadiy Illarionov](https://github.com/qarkai)
