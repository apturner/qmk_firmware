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

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "apturner.h"

// Layer declarations
enum satan_layers {
	_QWERTY,
	_FN1,
	_NUM,
	_ADJ,
	_GAME,
};

enum ergodox_ez_keycodes {
	PLACEHOLDER = NEW_SAFE_RANGE, // can always be here
	RGB_SLD,
	GAME,
    EXT_GAME
};

#define FN1_ENT LT(_FN1, KC_ENT) // Tap for Enter, hold for FN1 layer
#define HYP_T   HYPR(KC_T)      // Hyper + T
#define HYP_Y   HYPR(KC_Y)      // Hyper + Y

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Keymap _QWERTY: Default layer
	 *
	 * .--------------------------------------------------.           .--------------------------------------------------.
	 * |   `    |  1   |  2   |  3   |  4   |  5   | ESC  |           | CAG  |  6   |  7   |  8   |  9   |  0   |  DEL   |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |  TAB   |  Q   |  W   |  E   |  R   |  T   | REDO |           | COPY |  Y   |  U   |  I   |  O   |  P   |   \    |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |  NUM   |  A   |  S   |  D   |  F   |  G   |------|           |------|  H   |  J   |  K   |  L   |  ;   |   '    |
	 * |--------+------+------+------+------+------| UNDO |           |PASTE |------+------+------+------+------+--------|
	 * |LSHIFT( |  Z   |  X   |  C   |  V   |  B   |      |           |      |  N   |  M   |  ,   |  .   |  /   |RSHIFT) |
	 * '--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
	 *   | VOLD | VOLU | LCTL | LALT | LGUI |                                       |  [   |  ]   |  -   |  =   | ADJ  |
	 *   '----------------------------------'                                       '----------------------------------'
	 *                                        .-------------.       .-------------.
	 *                                        | HOME | END  |       | RCTL | MEH  |
	 *                                 .------|------|------|       |------+------+------.
	 *                                 |      |      | PGUP |       | RALT |      |      |
	 *                                 |SPACE |HYPER |------|       |------|BACKSP|ENTER |
	 *                                 |      |      | PGDN |       | RGUI |      | /FN1 |
	 *                                 '--------------------'       '--------------------'
	 */
	[_QWERTY] = LAYOUT_ergodox(
		// left hand
		  KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_ESC,
		  KC_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    REDO,
		MO(_NUM), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
		 KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    UNDO,
		    VOLD, VOLU, KC_LCTL, KC_LALT, KC_LGUI,
		                                           KC_HOME,  KC_END,
		                                                    KC_PGUP,
		                                   KC_SPC, KC_HYPR, KC_PGDN,
		// right hand
		    CAG,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,   KC_DEL,
		   COPY,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
		            KC_H,     KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
		  PASTE,    KC_N,     KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSPC,
		                   KC_LBRC, KC_RBRC, KC_MINS,  KC_EQL, MO(_ADJ),
		KC_RCTL,  KC_MEH,
		KC_RALT,
		KC_RGUI, KC_BSPC, FN1_ENT),

	/* Keymap _FN1: Function Layer
	 *
	 * .--------------------------------------------------.           .--------------------------------------------------.
	 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |        | WLLF | WLDN | MSUP | WLUP | WLRT |      |           |      | PGUP | ACL1 |  UP  | ACL0 | ACL2 |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        | BTN2 | MSLF | MSDN | MSRT | BTN1 |------|           |------| PGDN | LEFT | DOWN | RGHT |      |   `    |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |      |           |      |      | BTN1 | HOME | END  | INS  |        |
	 * '--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
	 *   |      |      |      | BTN2 | BTN1 |                                       |      |      |      |      |      |
	 *   '----------------------------------'                                       '----------------------------------'
	 *                                        .-------------.       .-------------.
	 *                                        |      |      |       |      |      |
	 *                                 .------|------|------|       |------+------+------.
	 *                                 |      |      |      |       |      |      |      |
	 *                                 | BTN1 | BTN2 |------|       |------|      |      |
	 *                                 |      |      |      |       |      |      |      |
	 *                                 '--------------------'       '--------------------'
	 */
	[_FN1] = LAYOUT_ergodox(
		// left hand
		____,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,
		____, KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R,  ____,
		____, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
		____,    ____,    ____,    ____,    ____,    ____,  ____,
		____,    ____,    ____, KC_BTN2, KC_BTN1,
		                                             ____,  ____,
		                                                    ____,
		                                 KC_BTN1, KC_BTN2,  ____,
		// right hand
		KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   ____,
		 ____, KC_PGUP, KC_ACL1,   KC_UP, KC_ACL0, KC_ACL2,   ____,
		       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,    ____, KC_GRV,
		 ____,    ____, KC_BTN1, KC_HOME,  KC_END,  KC_INS,   ____,
		                   ____,    ____,    ____,    ____,   ____,
		 ____,    ____,
		 ____,
		 ____,    ____,   ____),

	/* Keymap _NUM: Numpad layer
	 *
	 * .--------------------------------------------------.           .--------------------------------------------------.
	 * |        |      |      |      |      |      |      |           |      |      |EQUALS|DIVIDE|TIMES |BACKSP|        |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |        |      |      | UNDO | REDO |      |      |           |      |      | NUM7 | NUM8 | NUM9 |MINUS |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      | CUT  | COPY |PASTE |      |------|           |------|      | NUM4 | NUM5 | NUM6 | PLUS |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      |      | SFUN | SFRE |      |      |           |      |      | NUM1 | NUM2 | NUM3 |ENTER |        |
	 * '--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
	 *   |      |      |      |      |      |                                       | NUM0 | NUM0 | DOT  |COMMA |      |
	 *   '----------------------------------'                                       '----------------------------------'
	 *                                        .-------------.       .-------------.
	 *                                        |      |      |       |      |      |
	 *                                 .------|------|------|       |------+------+------.
	 *                                 |      |      |      |       |      |      |      |
	 *                                 |      |      |------|       |------|      |      |
	 *                                 |      |      |      |       |      |      |      |
	 *                                 '--------------------'       '--------------------'
	 */
	[_NUM] = LAYOUT_ergodox(
		// left hand
		____, ____, ____,    ____,    ____, ____, ____,
		____, ____, ____,    UNDO,    REDO, ____, ____,
		____, ____,  CUT,    COPY,   PASTE, ____,
		____, ____, ____, SOFT_UN, SOFT_RE, ____, ____,
		____, ____, ____,    ____,    ____,
		                                    ____, ____,
		                                          ____,
		                              ____, ____, ____,
		// right hand
		____, ____, KC_PEQL, KC_PSLS, KC_PAST, KC_BSPC, ____,
		____, ____,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, ____,
		      ____,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, ____,
		____, ____,   KC_P1,   KC_P2,   KC_P3, KC_PENT, ____,
		              KC_P0,   KC_P0, KC_PDOT, KC_PCMM, ____,
		____, ____,
		____,
		____, ____,   ____),

	/* Keymap _ADJ: Adjust layer
	 *
	 * .--------------------------------------------------.           .--------------------------------------------------.
	 * |  MAKE  |      |      |      |      |      |      |           |      |      |      |      | SWAP | NORM | SLEEP  |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      | PREV |  PP  | NEXT |      |------|           |------|      |      |      | BDN  | BUP  |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      |      |      |      |      |      |           |      |      |      | MUTE | VOLD | VOLU |  GAME  |
	 * '--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
	 *   |      |      |      |      |      |                                       |      |      |      |      |      |
	 *   '----------------------------------'                                       '----------------------------------'
	 *                                        .-------------.       .-------------.
	 *                                        |ANIMAT|      |       | TOGG |SOLID |
	 *                                 .------|------|------|       |------+------+------.
	 *                                 |      |      |      |       |      |      |      |
	 *                                 |BRITE-|BRITE+|------|       |------| HUE- | HUE+ |
	 *                                 |      |      |      |       |      |      |      |
	 *                                 '--------------------'       '--------------------'
	 */
	[_ADJ] = LAYOUT_ergodox(
		// left hand
		KC_MAKE, ____, ____,    ____,    ____,    ____, ____,
		  RESET, ____, ____,    ____,    ____,    ____, ____,
		   ____, ____, PREV, KC_MPLY,    NEXT,    ____,
		   ____, ____, ____,    ____,    ____,    ____, ____,
		   ____, ____, ____,    ____,    ____,
		                                       RGB_MOD, ____,
		                                                ____,
		                              RGB_VAD, RGB_VAI, ____,
		// right hand
		   ____,    ____,     ____, ____, AG_SWAP, AG_NORM, KC_SLEP,
		   ____,    ____,     ____, ____,    ____,    ____,    ____,
		            ____,     ____, ____, MAC_DIM, MAC_BRI,    ____,
		   ____,    ____,     ____, MUTE,    VOLD,    VOLU,    GAME,
		            ____,     ____, ____,    ____,    ____,
		RGB_TOG, RGB_SLD,
		   ____,
		   ____, RGB_HUD, RGB_HUI),

	/* Keymap _GAME: Gaming layer
	 *
	 * .--------------------------------------------------.           .--------------------------------------------------.
	 * |   `    |  1   |  2   |  3   |  4   |  5   |  =   |           | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |   F6   |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |  TAB   |  Q   |  W   |  E   |  R   |  T   | PGUP |           | XXXX |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |ALT+BTN3|  A   |  S   |  D   |  F   |  G   |------|           |------| XXXX | XXXX | XXXX |  UP  | XXXX |  XXXX  |
	 * |--------+------+------+------+------+------| PGDN |           | XXXX |------+------+------+------+------+--------|
	 * | LSHIFT |  Z   |  X   |  C   |  V   |  B   |      |           |      | XXXX | XXXX | LEFT | DOWN | RGHT |  XXXX  |
	 * '--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
	 *   | LCTL |  M   |  X   | LGUI |SPACE |                                       | ENTR | XXXX | XXXX | XXXX | EXIT |
	 *   '----------------------------------'                                       '----------------------------------'
	 *                                        .-------------.       .-------------.
	 *                                        | INS  | DEL  |       | XXXX | XXXX |
	 *                                 .------|------|------|       |------+------+------.
	 *                                 |      |      |  7   |       | XXXX |      |      |
	 *                                 |  9   |  0   |------|       |------| VOLD | VOLU |
	 *                                 |      |      |  8   |       | XXXX |      |      |
	 *                                 '--------------------'       '--------------------'
	 */
	[_GAME] = LAYOUT_ergodox(
		// left hand
		       KC_GRV,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,  KC_EQL,
		       KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T, KC_PGUP,
		LALT(KC_BTN3),    KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
		      KC_LSFT,    KC_Z,    KC_X,    KC_C,   KC_V,   KC_B, KC_PGDN,
		      KC_LCTL,    KC_M,    KC_X, KC_LGUI, KC_SPC,
		                                                  KC_INS,  KC_DEL,
		                                                             KC_7,
		                                            KC_9,   KC_0,    KC_8,
		// right hand
		KC_ESC, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,
		  XXXX, KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,
		         XXXX,   XXXX,    XXXX,   KC_UP,    XXXX,     XXXX,
		  XXXX,  XXXX,   XXXX, KC_LEFT, KC_DOWN, KC_RGHT,     XXXX,
		               KC_ENT,    XXXX,    XXXX,    XXXX, EXT_GAME,
		  XXXX,  XXXX,
		  XXXX,
		  XXXX,  VOLD,  VOLU),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GAME:
            if (record->event.pressed) {
                layer_off(_FN1);
                layer_off(_NUM);
                layer_off(_ADJ);
                layer_on(_GAME);
                rgblight_enable();
                rgblight_mode(1); // Solid
                rgblight_setrgb(0, 255, 0);
                if (!eeconfig_is_enabled()) {
                        eeconfig_init();
                }
                keymap_config.raw = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);

            }
            return false;
            break;
        case EXT_GAME:
            if (record->event.pressed) {
                layer_off(_GAME);
                rgblight_mode(8); // Fast rainbow cycle
                rgblight_disable();
            }
            return false;
            break;
		case RGB_SLD:
			if (record->event.pressed) {
				#ifdef RGBLIGHT_ENABLE
					rgblight_mode(1);
				#endif
			}
			return false;
			break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_keymap(void) {
	// OS conditioning setup
	if (!eeconfig_is_enabled()) {
            eeconfig_init();
    }
    keymap_config.raw = eeconfig_read_keymap();
    if (keymap_config.swap_lalt_lgui && keymap_config.swap_ralt_rgui) {
        osx = false;
    }
};

// Runs constantly in the background, in a loop.
void matrix_scan_keymap(void) {

	uint8_t layer = biton32(layer_state);

	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	switch (layer) {
		case _FN1:
			ergodox_right_led_1_on();
			break;
		case _NUM:
			ergodox_right_led_2_on();
			break;
		case _ADJ:
			ergodox_right_led_3_on();
			break;
		default:
			break;
	}

};
