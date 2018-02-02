/*
Copyright 2017 Andrew Turner <apturner@mit.edu> @apturner

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum custom_keycodes {
	KC_MAKE = SAFE_RANGE,
	NEXT,
    PREV,
    MUTE,
    VOLD,
    VOLU,
    UNDO,
    REDO,
    CUT,
    COPY,
    PASTE,
	NEW_SAFE_RANGE  //use NEW_SAFE_RANGE for keymap specific codes
};

// Custom macros
#define ____ KC_TRNS
#define XXXX KC_NO

#define SOFT_UN LGUI(KC_U)       // Soft undo in Sublime
#define SOFT_RE SCMD(KC_U)       // Soft redo in Sublime
#define MAC_DIM KC_F14           // Mac brightness down
#define MAC_BRI KC_F15           // Mac brightness up
#define CAG LCTL(LALT(KC_LGUI))  // Ctrl-Alt-Gui

extern bool osx;

#endif
