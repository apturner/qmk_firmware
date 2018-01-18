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

/* TO DO
 * Fix left shift and tap dancing
 * Add power button
 * Fix LED breathing
 */

// Treats CAPS_LOCK LED as backlight, comment to disable
#define BACKLIGHT_CAPS

// Layer declarations
enum satan_layers {
    _QWERTY,
    _FN1,
    _FN2,
    _ADJ,
};

// Keycode declarations
enum satan_keycodes {
    PLACEHOLDER = NEW_SAFE_RANGE,
};

// Tap Dance declarations
// enum {
//     TD_SHIFT,
// };

// Custom macros
#define FN1_SPC LT(_FN1, KC_SPC) // Tap for Space, hold for NUM layer
#define TAB_HYP ALL_T(KC_TAB)    // Tap for Tab, hold for Hyper

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _QWERTY: (Base Layer) Default Layer
     * ,-------------------------------------------------------------------------.
     * |ESC~| 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  | -  | =  | BACKSP |
     * |-------------------------------------------------------------------------|
     * |TABHYP| Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  | [  | ]  |  \   |
     * |-------------------------------------------------------------------------|
     * |  FN2  | A  | S  | D  | F  | G  | H  | J  | K  | L  | ;  | '  |  RETURN  |
     * |-------------------------------------------------------------------------|
     * | LSHIFT( | Z  | X  | C  | V  | B  | N  | M  | ,  | .  | /  |   RSHIFT)   |
     * |-------------------------------------------------------------------------|
     * |LCTRL|LALT |LGUI |          SPACE/FN1          | RGUI | RALT | FN2 |RCTRL|
     * `-------------------------------------------------------------------------'
     */
    [_QWERTY] = KEYMAP_ANSI(
         KC_GESC,    KC_1,    KC_2, KC_3, KC_4, KC_5,    KC_6, KC_7, KC_8,    KC_9,    KC_0,  KC_MINS,   KC_EQL,  KC_BSPC, \
         TAB_HYP,    KC_Q,    KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I,    KC_O,    KC_P,  KC_LBRC,  KC_RBRC,  KC_BSLS, \
        MO(_FN2),    KC_A,    KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K,    KC_L, KC_SCLN,  KC_QUOT,             KC_ENT, \
         KC_LSPO,             KC_Z, KC_X, KC_C, KC_V,    KC_B, KC_N, KC_M, KC_COMM,  KC_DOT,  KC_SLSH,            KC_RSPC, \
         KC_LCTL, KC_LALT, KC_LGUI,                   FN1_SPC,                      KC_RGUI,  KC_RALT, MO(_ADJ), KC_RCTL),

    /* Keymap _FN1: Function Layer
     *  -------------------------------------------------------------------------.
     * |    | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |  DEL   |
     * |-------------------------------------------------------------------------|
     * |      |    |WLDN|MSUP|WLUP|    |    |ACL1| UP |ACL0|ACL2|    |    |      |
     * |-------------------------------------------------------------------------|
     * |       |BTN2|MSLF|MSDN|MSRT|BTN1|BTN1|LEFT|DOWN|RGHT|    | `  |          |
     * |-------------------------------------------------------------------------|
     * |         |    |    |    |    |HOME|PGUP|PGDN|END |INS |    |             |
     * |-------------------------------------------------------------------------|
     * |     |     |     |                             |      |      |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_FN1] = KEYMAP_ANSI(
        ____,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL, \
        ____,    ____, KC_WH_D, KC_MS_U, KC_WH_U,    ____,    ____, KC_ACL1,   KC_UP, KC_ACL0, KC_ACL2,   ____,   ____,   ____, \
        ____, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN1, KC_LEFT, KC_DOWN, KC_RGHT,    ____, KC_GRV,           ____, \
        ____,             ____,    ____,    ____,    ____, KC_HOME, KC_PGUP, KC_PGDN,  KC_END,  KC_INS,   ____,           ____, \
        ____,    ____,    ____,                               ____,                               ____,   ____,   ____,  ____),

    /* Keymap _NUM: Keypad Layer
     *  -------------------------------------------------------------------------.
     * |    |    |    |    |    |    |    |EQLS|DIVD|TIMS|BACK|    |    |        |
     * |-------------------------------------------------------------------------|
     * |      |    |    |UNDO|REDO|    |    |NUM7|NUM8|NUM9|MINU|    |    |      |
     * |-------------------------------------------------------------------------|
     * |       |    |CUT |COPY|PSTE|    |    |NUM4|NUM5|NUM6|PLUS|    |          |
     * |-------------------------------------------------------------------------|
     * |         |    |    |SFUN|SFRE|    |    |NUM1|NUM2|NUM3|ENTR|             |
     * |-------------------------------------------------------------------------|
     * |     |     |     |            NUM0             | DOT  |COMMA |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_FN2] = KEYMAP_ANSI(
        ____, ____, ____, ____,    ____,    ____, ____, KC_PEQL, KC_PSLS, KC_PAST, KC_BSPC,    ____, ____,  ____, \
        ____, ____, ____, UNDO,    REDO,    ____, ____,   KC_P7,   KC_P8,   KC_P9, KC_PMNS,    ____, ____,  ____, \
        ____, ____,  CUT, COPY,   PASTE,    ____, ____,   KC_P4,   KC_P5,   KC_P6, KC_PPLS,    ____,        ____, \
        ____,       ____, ____, SOFT_UN, SOFT_RE, ____,    ____,   KC_P1,   KC_P2,   KC_P3, KC_PENT,        ____, \
        ____, ____, ____,                        KC_P0,                            KC_PDOT, KC_PCMM, ____, ____),

    /* Keymap _FN2: Function Layer
     *  -------------------------------------------------------------------------.
     * |MAKE|    |    |    |    |    |    |    |    |    |    |SWAP|NORM|        |
     * |-------------------------------------------------------------------------|
     * |RESET |    |    |    |    |    |    |    |    |    |BRTG|BL- |BL+ |BL_TOG|
     * |-------------------------------------------------------------------------|
     * |       |    |PREV| PP |NEXT|    |    |    |    |    |BDN |BUP |          |
     * |-------------------------------------------------------------------------|
     * |         |    |    |    |    |    |    |    |MUTE| V- | V+ |             |
     * |-------------------------------------------------------------------------|
     * |     |     |     |                             |      |      |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_ADJ] = KEYMAP_ANSI(
        KC_MAKE, ____, ____,    ____, ____, ____, ____, ____, ____, ____,    ____, AG_SWAP, AG_NORM,    ____, \
          RESET, ____, ____,    ____, ____, ____, ____, ____, ____, ____, BL_BRTG,  BL_DEC,  BL_INC, BL_TOGG, \
           ____, ____, PREV, KC_MPLY, NEXT, ____, ____, ____, ____, ____, MAC_DIM, MAC_BRI  ,             ____, \
           ____,       ____,    ____, ____, ____, ____, ____, ____, MUTE,    VOLD,    VOLU,             ____, \
           ____, ____, ____,                      ____,                      ____,    ____,    ____,   ____),
};

//Tap Dance definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     //Tap once for Shift, twice for Caps Lock
//     [TD_SHIFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LSPO, KC_CAPS),
// };

void matrix_init_keymap(void) {
    // OS conditioning setup
    if (keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
        osx = false;
    }

    // Backlight setup
    #ifdef BACKLIGHT_CAPS
        // register the required ISRs
        // #ifdef BACKLIGHT_BREATHING
        //     TIMSK1 |= _BV(OCIE1B);
        // #else
            TIMSK1 |= _BV(OCIE1B) | _BV(TOIE1);
        // #endif
        // TIMSK3 |= _BV(TOIE3);

        // #define TIMER_TOP 0xFFFFU // Copied this from quantum.c, magic number
        // TCCR3A = _BV(COM3B1) | _BV(WGM31); // = 0b00100010;
        // TCCR3B = _BV(WGM33) | _BV(WGM32) | _BV(CS30); // = 0b00011001;
        // // Use full 16-bit resolution. Counter counts to ICR1 before reset to 0.
        // ICR3 = TIMER_TOP;
    #endif
}

// Backlight setup
#ifdef BACKLIGHT_CAPS
    uint8_t backlight_on;

    ISR(TIMER1_COMPB_vect)
    {
        led_set_kb(~(1 << USB_LED_BL));
    }

    // #ifdef BACKLIGHT_BREATHING
    //     #define LED_INTERRUPT_USER
    //     void led_interrupt_keymap(void) {
    //         if (OCR1B != 0) {
    //             led_set_kb(1 << USB_LED_BL);
    //         }
    //     }
    // #else
        ISR(TIMER1_OVF_vect)
        {
            if (OCR1B != 0) {
                led_set_kb(1 << USB_LED_BL);
            }
        }
    // #endif
#endif

void led_set_keymap(uint8_t usb_led) {
    #ifndef BACKLIGHT_CAPS
        if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
            // Turn capslock on
            PORTB &= ~(1<<2);
        } else {
            // Turn capslock off
            PORTB |= (1<<2);
        }
    #endif
    #ifdef BACKLIGHT_CAPS
        if (usb_led & (1 << USB_LED_BL)) {
            // Turn capslock on
            PORTB &= ~(1<<2);
        } else {
            // Turn capslock off
            PORTB |= (1<<2);
        }
    #endif
}


