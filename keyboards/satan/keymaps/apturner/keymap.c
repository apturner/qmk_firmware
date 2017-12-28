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

#include "apturner.h"
#include "satan.h"

// TO DO
// Add mouse control layer, perhaps with exit key like the Plover layer
// Add music controls

// Treats CAPS_LOCK LED as backlight, comment to disable
#define BACKLIGHT_CAPS

// Layer declarations
enum satan_layers {
    _QWERTY,
    _FN1,
    _FN2,
    _NUM,
};

// Keycode declarations
// enum satan_keycodes {
//     QWERTY = NEW_SAFE_RANGE,
// };

// Tap Dance declarations
enum {
    TD_SHIFT,
};

#define ____ KC_TRNS
#define XXXX KC_NO

// Custom macros
#define NUM_SPC LT(_NUM, KC_SPC) // Tap for Space, hold for NUM layer
#define SFT_UN  LGUI(KC_U)       // Soft undo in Sublime
#define SFT_RE  SCMD(KC_U)       // Soft redo in Sublime
#define TAB_CAG LCAG_T(KC_TAB)   // Tap for Tab, hold for Ctrl+Alt+GUI


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _QWERTY: (Base Layer) Default Layer
     * ,-------------------------------------------------------------------------.
     * |ESC`| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  | BACKSP |
     * |-------------------------------------------------------------------------|
     * |TABCAG| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  |  \   |
     * |-------------------------------------------------------------------------|
     * |  FN1  | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |  RETURN  |
     * |-------------------------------------------------------------------------|
     * |SHIFT(CAP| Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |   SHIFT)    |
     * |-------------------------------------------------------------------------|
     * |CTRL | GUI | ALT |          SPACE/NUM          | ALT  | GUI  | FN2 |CTRL |
     * `-------------------------------------------------------------------------'
     */
    [_QWERTY] = KEYMAP_ANSI(
             KC_GESC,    KC_1,    KC_2, KC_3, KC_4, KC_5,    KC_6, KC_7, KC_8,    KC_9,    KC_0,  KC_MINS,   KC_EQL,  KC_BSPC, \
             TAB_CAG,    KC_Q,    KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I,    KC_O,    KC_P,  KC_LBRC,  KC_RBRC,  KC_BSLS, \
            MO(_FN1),    KC_A,    KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K,    KC_L, KC_SCLN,  KC_QUOT,             KC_ENT, \
        TD(TD_SHIFT),             KC_Z, KC_X, KC_C, KC_V,    KC_B, KC_N, KC_M, KC_COMM,  KC_DOT,  KC_SLSH,            KC_RSPC, \
             KC_LCTL, KC_LGUI, KC_LALT,                   NUM_SPC,                      KC_RALT,  KC_RGUI, MO(_FN2), KC_RCTL),

    /* Keymap _FN1: Function Layer
     *  -------------------------------------------------------------------------.
     * |    | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |  DEL   |
     * |-------------------------------------------------------------------------|
     * |      |    |SFUN|UNDO|REDO|SFRE|PGUP|HOME| UP |END |    |    |    |      |
     * |-------------------------------------------------------------------------|
     * |       |    |CUT |COPY|PSTE|    |PGDN|LEFT|DOWN|RGHT|INS |    |          |
     * |-------------------------------------------------------------------------|
     * |         |    |    |    |    |    |    |    |    |    |    |             |
     * |-------------------------------------------------------------------------|
     * |     |     |     |                             |      |      |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_FN1] = KEYMAP_ANSI(
        ____,  KC_F1,   KC_F2,    KC_F3,    KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, \
        ____,   ____,  SFT_UN,  KC_UNDO, KC_AGAIN, SFT_RE, KC_PGUP, KC_HOME,   KC_UP,  KC_END,   ____,   ____,   ____,   ____, \
        ____, KC_CUT, KC_COPY, KC_PASTE,     ____,   ____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,   ____,           ____, \
        ____,            ____,     ____,     ____,   ____,    ____,    ____,    ____,    ____,   ____,   ____,           ____, \
        ____,   ____,    ____,                                ____,                              ____,   ____,   ____,  ____),

    /* Keymap _FN2: Function Layer
     *  -------------------------------------------------------------------------.
     * |MAKE|    |    |    |    |    |    |    |    |    |    |SWAP|NORM|        |
     * |-------------------------------------------------------------------------|
     * |RESET |    |    |    |    |    |    |    |    |    |    |BL- |BL+ |BL_TOG|
     * |-------------------------------------------------------------------------|
     * |       |PREW|PREM| PP |NXTM|NXTW|    |    |    |    |    |    |          |
     * |-------------------------------------------------------------------------|
     * |         |    |    |    |    |    |    |    |MUTE| V- | V+ |             |
     * |-------------------------------------------------------------------------|
     * |     |     |     |                             |      |      |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_FN2] = KEYMAP_ANSI(
        KC_MAKE,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,    ____,    ____, AG_SWAP, AG_NORM,    ____, \
          RESET,    ____,    ____,    ____,    ____,    ____, ____, ____, ____,    ____,    ____,  BL_DEC,  BL_INC, BL_TOGG, \
           ____, KC_MPRV, KC_MRWD, KC_MPLY, KC_MFFD, KC_MNXT, ____, ____, ____,    ____,    ____,    ____,             ____, \
           ____,             ____,    ____,    ____,    ____, ____, ____, ____, KC_MUTE, KC_VOLD, KC_VOLU,             ____, \
           ____,    ____,    ____,                            ____,                         ____,    ____,    ____,   ____),

    /* Keymap _NUM: Keypad Layer
     *  -------------------------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |    |        |
     * |-------------------------------------------------------------------------|
     * |      |    |    |    |    |    |    |NUM7|NUM8|NUM9|    |    |    |      |
     * |-------------------------------------------------------------------------|
     * |       |    |    |    |    |    |    |NUM4|NUM5|NUM6|    |    |          |
     * |-------------------------------------------------------------------------|
     * |         |    |    |    |    |    |NUM0|NUM1|NUM2|NUM3|    |             |
     * |-------------------------------------------------------------------------|
     * |     |     |     |                             |      |      |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_NUM] = KEYMAP_ANSI(
        ____, ____, ____, ____, ____, ____, ____,    ____,    ____,    ____,    ____, ____, ____,  ____, \
        ____, ____, ____, ____, ____, ____, ____, KC_KP_7, KC_KP_8, KC_KP_9,    ____, ____, ____,  ____, \
        ____, ____, ____, ____, ____, ____, ____, KC_KP_4, KC_KP_5, KC_KP_6,    ____, ____,        ____, \
        ____,       ____, ____, ____, ____, ____, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, ____,        ____, \
        ____, ____, ____,                   ____,                               ____, ____, ____, ____),
};

//Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Esc, twice for Caps Lock
    [TD_SHIFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LSPO, KC_CAPS),
};

// void persistent_default_layer_set(uint16_t default_layer) {
//     eeconfig_update_default_layer(default_layer);
//     default_layer_set(default_layer);
// }

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    // switch (keycode) {
    //     case QWERTY:
    //         if (record->event.pressed) {
    //             persistent_default_layer_set(1UL<<_QWERTY);
    //         }
    //         return false; // Skip all further processing of this key
    //         break; // Exit switch
    // }
    return true; // Process all other keycodes normally
}
