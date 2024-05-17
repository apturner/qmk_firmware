 /* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAKDHM,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAKDHM,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Vol Dn|Vol Up| Ctrl | Alt  | GUI  |Sp/Low|Ent/Ra|   [  |   ]  |   -  |   =  | Bksp |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,  KC_5,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ESC,
   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  KC_HYPR,    KC_A,    KC_S,    KC_D,    KC_F,  KC_G,  KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SC_RSPC,
  KC_VOLD, KC_VOLU, KC_LCTL, KC_LALT, KC_LGUI, LOWER, RAISE, KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL, KC_BSPC
),

/* ColemakDHm
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Hyper |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift(|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Vol Dn|Vol Up| Ctrl | Alt  | GUI  |Sp/Low|Ent/Ra|   [  |   ]  |   -  |   =  | Bksp |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAKDHM] = LAYOUT_preonic_grid(
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,  KC_5,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ESC,
   KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,  KC_B,  KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSLS,
  KC_HYPR,    KC_A,    KC_R,    KC_S,    KC_T,  KC_G,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_D,  KC_V,  KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, SC_RSPC,
  KC_VOLD, KC_VOLU, KC_LCTL, KC_LALT, KC_LGUI, LOWER, RAISE, KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL, KC_BSPC
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |   /  |   *  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   ,  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      |      |      |      |   0  |   0  |   .  |Enter |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_P7,   KC_P8,   KC_P9, KC_PPLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_P4,   KC_P5,   KC_P6, KC_PCMM, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_P1,   KC_P2,   KC_P3, KC_PEQL, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRANS,   KC_P0,   KC_P0, KC_PDOT, KC_PENT, KC_PENT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |WheelL|WheelD|MouseU|WheelU|WheelR|PageUp|MAcc1 |  Up  |MAcc0 |MAcc2 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MouseL|MouseD|MouseR|      |PageDn| Left | Down |Right |      |Grave |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Btn 1 | Home | End  |Insert|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Btn 1 |Btn 2 |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  KC_TRNS, KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R, KC_PGUP, KC_ACL1,   KC_UP, KC_ACL0, KC_ACL2, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,  KC_GRV,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_HOME,  KC_END,  KC_INS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |Debug |      |      |      |      |      |      |      |      |      |Sleep |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |AGNorm|AGSwap|      |      |      |      |      |Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Scale+|Voice-|Voice+|Mus On|MusOff|      | Mute |Vol Dn|Vol Up|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud On|AudOff|Mid On|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  QK_BOOT, DB_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_SLEP,
  AG_NORM, AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  QWERTY, COLEMAKDHM, KC_TRNS, KC_TRNS, KC_TRNS,
  MU_NEXT, AU_PREV, AU_NEXT,   MU_ON,  MU_OFF, KC_TRNS, KC_MUTE, KC_VOLD,    KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,   AU_ON,  AU_OFF,   MI_ON,  MI_OFF, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAKDHM:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAKDHM);
          }
          return false;
          break;
        case LOWER:
          if (record->tap.count && record->event.pressed) {
            tap_code16(KC_SPC); // Intercept tap function to send Space
          }
          else if (record->event.pressed) {
            layer_on(_LOWER); // Intercept hold function to activate _LOWER
            update_tri_layer(_LOWER, _RAISE, _ADJUST); // Activate _ADJUST if both RAISE and LOWER
          } else {
            layer_off(_LOWER); // Intercept key release to deactivate _LOWER
            update_tri_layer(_LOWER, _RAISE, _ADJUST); // Deactivate _ADJUST if necessary
          }
          return false;
          break;
        case RAISE:
          if (record->tap.count && record->event.pressed) {
            tap_code16(KC_ENT); // Intercept tap function to send Enter
          }
          else if (record->event.pressed) {
            layer_on(_RAISE); // Intercept hold function to activate _RAISE
            update_tri_layer(_LOWER, _RAISE, _ADJUST); // Activate _ADJUST if both RAISE and LOWER
          } else {
            layer_off(_RAISE); // Intercept key release to deactivate _RAISE
            update_tri_layer(_LOWER, _RAISE, _ADJUST); // Deactivate _ADJUST if necessary
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
