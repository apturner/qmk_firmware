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
#include "quantum.h"
#include "action.h"
#include "version.h"

// Add reconfigurable functions here, for keymap customization.
// This allows for global userspace functions and continued
// customization of the keymap. Use _keymap instead of _user
// functions in the keymaps.
__attribute__ ((weak))
void matrix_init_keymap(void) {}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	return true; // Process all other keycodes normally
}
__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
	return state;
}
__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}

__attribute__ ((weak))
void led_interrupt_keymap(void) {}

// Call user matrix init, then call the keymap's init function
void matrix_init_user(void) {
	osx = true;
	matrix_init_keymap();
}

// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {
	matrix_scan_keymap();
}

// For conditioning on which OS
void conditional_key(bool condition, uint16_t keycode_true, uint16_t keycode_false, keyrecord_t *record) {
	if (record->event.pressed) {
		if (condition) {
			register_code16(keycode_true);
		} else {
			register_code16(keycode_false);
		}
	} else {
		if (condition) {
			unregister_code16(keycode_true);
		} else {
			unregister_code16(keycode_false);
		}
	}
}

// Defines actions for global custom keycodes. Defined in apturner.h file
// Then runs the _keymap's record handier if not processed here,
// And use "NEW_SAFE_RANGE" for new safe range
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case KC_MAKE:
			if (!record->event.pressed) {
				SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
					#if  (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
						":dfu"
					#elif defined(BOOTLOADER_HALFKAY)
						":teensy"
					#elif defined(BOOTLOADER_CATERINA)
						":avrdude"
					#endif
					SS_TAP(X_ENTER));
				reset_keyboard();
			}
			return false;
			break;
		case TOGG_OS:
			if (record->event.pressed) {
				// if (osx) {
				// 	osx = false;
				// } else{
				// 	osx = true;
				// }
				osx = !osx;
			}
			return false; // Skip all further processing of this key
			break; // Exit switch
		case AG_NORM:
			if (record->event.pressed) {
				osx = true;
			}
			return true; // Let QMK send the press/release events
			break; // Exit switch
		case AG_SWAP:
			if (record->event.pressed) {
				osx = false;
			}
			return true; // Let QMK send the press/release events
			break; // Exit switch
		case NEXT:
			conditional_key(osx, KC_MFFD, KC_MNXT, record);
			return false; // Skip all further processing of this key
			break; // Exit switch
		case PREV:
			conditional_key(osx, KC_MRWD, KC_MPRV, record);
			return false; // Skip all further processing of this key
			break; // Exit switch
		case MUTE:
			conditional_key(osx, KC__MUTE, KC_MUTE, record);
			return false; // Skip all further processing of this key
			break; // Exit switch
		case VOLD:
			conditional_key(osx, KC__VOLDOWN, KC_VOLD, record);
			return false; // Skip all further processing of this key
			break; // Exit switch
		case VOLU:
			conditional_key(osx, KC__VOLUP, KC_VOLU, record);
			return false; // Skip all further processing of this key
			break; // Exit switch
		case UNDO:
			conditional_key(osx, LGUI(KC_Z), LCTL(KC_Z), record); // KC_UNDO
			return false; // Skip all further processing of this key
			break; // Exit switch
		case REDO:
			conditional_key(osx, SCMD(KC_Z), LSFT(LCTL(KC_Z)), record); // KC_AGAIN
			return false; // Skip all further processing of this key
			break; // Exit switch
		case CUT:
			conditional_key(osx, LGUI(KC_X), LCTL(KC_X), record); // KC_CUT
			return false; // Skip all further processing of this key
			break; // Exit switch
		case COPY:
			conditional_key(osx, LGUI(KC_C), LCTL(KC_C), record); // KC_COPY
			return false; // Skip all further processing of this key
			break; // Exit switch
		case PASTE:
			conditional_key(osx, LGUI(KC_V), LCTL(KC_V), record); // KC_PASTE
			return false; // Skip all further processing of this key
			break; // Exit switch

	}
	return process_record_keymap(keycode, record);
}

// Run user layer change check, then runs keymap's layer change check
uint32_t layer_state_set_user(uint32_t state) {
	return layer_state_set_keymap (state);
}

void led_set_user(uint8_t usb_led) {
	led_set_keymap(usb_led);
}

void led_interrupt_user(void) {
	led_interrupt_keymap();
}
