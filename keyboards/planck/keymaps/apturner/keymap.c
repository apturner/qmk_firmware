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

#include "planck.h"
#include "action_layer.h"
#include "apturner.h"

extern keymap_config_t keymap_config;

// layer declarations
enum planck_layers {
	_QWERTY,
	_FUNC,
	_LOWER,
	_RAISE,
	_ADJUST,
	_PLOVER
};

enum planck_keycodes {
	PLACEHOLDER = NEW_SAFE_RANGE, // can always be here
	QWERTY,
	FUNC,
	LOWER,
	RAISE,
	PLOVER,
	EXT_PLV,
	POLY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Qwerty
	 * ,-----------------------------------------------------------------------------------.
	 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | Bksp |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |Hyper |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  "   |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |Shift |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |Sh/Ent|
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Esc  | Ctrl | Alt  | GUI  |Lower |Space | Func |Raise | Undo | Redo | Copy |Paste |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_QWERTY] = {
		{KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC       },
		{KC_HYPR, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT       },
		{KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT)},
		{KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, FUNC, RAISE, UNDO,    REDO,    COPY,    PASTE         }
	},

	/* Function
	 * ,-----------------------------------------------------------------------------------.
	 * |      |WheelL|WheelD|MouseU|WheelU|WheelR|PageUp|Accel1|  Up  |Accel0|Accel2|      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |Mouse2|MouseL|MouseD|MouseR|Mouse1|PageDn| Left | Down |Right |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |Mouse1| Home | End  |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_FUNC] = {
		{____, KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R, KC_PGUP, KC_ACL1, KC_UP,   KC_ACL0, KC_ACL2, ____},
		{____, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, ____,    ____},
		{____, ____,    ____,    ____,    ____,    ____,    ____,    KC_BTN1, KC_HOME, KC_END,  ____,    ____},
		{____, ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____}
	},

	/* Lower
	 * ,-----------------------------------------------------------------------------------.
	 * |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | Bksp |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | CAG  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  -   |  =   |  [   |  ]   |  \   |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Del  |      |      |      |      |      |      |      | Mute | Prev | Next | Play |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_LOWER] = {
		{KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,   KC_5,   KC_6,   KC_7,    KC_8,   KC_9,    KC_0,    KC_BSPC},
		{CAG,    KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,  KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS},
		{____,   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____,    ____,   ____,    ____,       ____},
		{KC_DEL, ____,  ____,  ____,  ____,   ____,   ____,   ____,    MUTE,   PREV,    NEXT,    KC_MPLY}
	},

	/* Raise
	 * ,-----------------------------------------------------------------------------------.
	 * |  ~   |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   | Bksp |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Meh  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  _   |  +   |  {   |  }   |  |   |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Del  |      |      |      |      |      |      |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_RAISE] = {
		{KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
		{KC_MEH,  KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
		{____,    KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  ____,    ____,    ____,    ____,       ____},
		{KC_DEL,  ____,    ____,  ____,    ____,   ____,    ____,    ____,    ____,    ____,    ____,       ____}
	},

	/* Adjust (Lower + Raise)
	 * ,-----------------------------------------------------------------------------------.
	 * | Make |      |      |      |      |      |      |      |      |      |      |Sleep |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | SAG  | Poly |MusMod|AudOn |AudOff|      |      |      |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |Voice-|Voice+|MusTog|      |      |      |      |      |      |      |QWERTY|
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |ToggOS|      |      |      |      |      |      |      | Vol- | Vol+ |Brite-|Brite+|
	 * `-----------------------------------------------------------------------------------'
	 */
	[_ADJUST] = {
		{KC_MAKE, ____,   ____,   ____,   ____,   ____, ____, ____, ____, ____, ____,    KC_SLEP},
		{SAG,     POLY,   MU_MOD, AU_ON,  AU_OFF, ____, ____, ____, ____, ____, ____,       ____},
		{____,    MUV_DE, MUV_IN, MU_TOG, ____,   ____, ____, ____, ____, ____, ____,    QWERTY },
		{TOGG_OS, ____,   ____,   ____,   ____,   ____, ____, ____, VOLD, VOLU, MAC_DIM, MAC_BRI}
	},

	/* Plover layer (http://opensteno.org)
	 * ,-----------------------------------------------------------------------------------.
	 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Exit |      |      |   A  |   O  |      |      |   E  |   U  |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */

	[_PLOVER] = {
		{KC_1,    KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,    KC_1},
		{XXXX,    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,    KC_LBRC},
		{XXXX,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
		{EXT_PLV, XXXX, XXXX, KC_C, KC_V, XXXX, XXXX, KC_N, KC_M, XXXX, XXXX,    XXXX}
	}
};

#ifdef AUDIO_ENABLE
	float plover_song[][2]    = SONG(PLOVER_SOUND);
	float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
	bool polyphony_on;
#endif

void matrix_init_keymap(void) {
	set_polyphony_rate(5);
	polyphony_on = true;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case POLY:
			if (polyphony_on) {
				set_polyphony_rate(0);
				polyphony_on = false;
			} else {
				set_polyphony_rate(20);
				polyphony_on = true;
			}
			return false;
			break;
		case QWERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
			}
			return false;
			break;
		case FUNC:
			if (record->event.pressed) {
				layer_on(_FUNC);
			} else {
				layer_off(_FUNC);
			}
			return false;
			break;
		case LOWER:
			if (record->event.pressed) {
				layer_on(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case RAISE:
			if (record->event.pressed) {
				layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case PLOVER:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					stop_all_notes();
					PLAY_SONG(plover_song);
				#endif
				layer_off(_RAISE);
				layer_off(_LOWER);
				layer_off(_ADJUST);
				layer_on(_PLOVER);
				if (!eeconfig_is_enabled()) {
						eeconfig_init();
				}
				keymap_config.raw = eeconfig_read_keymap();
				keymap_config.nkro = 1;
				eeconfig_update_keymap(keymap_config.raw);
			}
			return false;
			break;
		case EXT_PLV:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_SONG(plover_gb_song);
				#endif
				layer_off(_PLOVER);
			}
			return false;
			break;
	}
	return true;
}
