#include "satan.h"

// treats CAPS_LOCK LED as backlight, comment to disable
#define BACKLIGHT_CAPS

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum satan_layers {
    _QWERTY,
//    _QWERTY40,
    _FUN1,
    _FUN2,
//    _LOWER,
//    _RAISE,
//    _ADJUST
};

enum satan_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE
};

#define ____ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define ALT_GRV     ALT_T(KC_GRV)               // Tap for Backtick, hold for Alt
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Shift+Alt)
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QWERTY: (Base Layer) Default Layer
   * ,-------------------------------------------------------------------------.
   * |Esc`| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  | Backsp |
   * |-------------------------------------------------------------------------|
   * | Tab  | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  |  \   |
   * |-------------------------------------------------------------------------|
   * |  FN1  | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |  Return  |
   * |-------------------------------------------------------------------------|
   * |  Shift  | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |    Shift    |
   * |-------------------------------------------------------------------------|
   * |Ctrl | Gui | Alt |            Space            | Alt  | Gui  | FN2 |Ctrl |
   * `-------------------------------------------------------------------------'
   */
  [_QWERTY] = KEYMAP_ANSI(
      KC_GESC,    KC_1,    KC_2, KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,    KC_0, KC_MINS,    KC_EQL,  KC_BSPC, \
       KC_TAB,    KC_Q,    KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,    KC_P, KC_LBRC,   KC_RBRC,  KC_BSLS, \
    MO(_FUN1),    KC_A,    KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L, KC_SCLN, KC_QUOT,              KC_ENT, \
      KC_LSFT,             KC_Z, KC_X, KC_C, KC_V,   KC_B, KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,             KC_RSFT, \
      KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                      KC_RALT, KC_RGUI, MO(_FUN2), KC_RCTL),

  /* Keymap _FUN1: Function Layer
   *  -------------------------------------------------------------------------.
   * |    | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |  Del   |
   * |-------------------------------------------------------------------------|
   * |      |    |    |    |    |    |    |    | UP |    |    |    |    |      |
   * |-------------------------------------------------------------------------|
   * |       |    |    |    |    |    |    |LEFT|DOWN|RGHT|    |    |          |
   * |-------------------------------------------------------------------------|
   * |         |    |    |    |    |    |    |    |    |    |    |             |
   * |-------------------------------------------------------------------------|
   * |     |     |     |                             |      |      |     |     |
   * `-------------------------------------------------------------------------'
   */
  [_FUN1] = KEYMAP_ANSI(
    ____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,    KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, \
    ____,  ____,  ____,  ____,  ____,  ____,  ____,     ____,   KC_UP,    ____,   ____,   ____,   ____,   ____, \
    ____,  ____,  ____,  ____,  ____,  ____,  ____,  KC_LEFT, KC_DOWN, KC_RGHT,   ____,   ____,           ____, \
    ____,         ____,  ____,  ____,  ____,  ____,     ____,    ____,    ____,   ____,   ____,           ____, \
    ____,  ____,  ____,                       ____,                               ____,   ____,   ____,  ____),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
