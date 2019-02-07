/* Copyright 2017 Baris Tosun
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

#define _______ KC_TRNS
#define _x_x_x_ KC_TRNS
#define xxxxxxx KC_NO

// Layers.
#define BL 0
#define AL 1
#define FL 2
#define NL 3
#define SL 4

enum macro_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    WHOAMI,
};


/*
// Something layer.
[XL] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer.
    [BL] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  TG(AL),  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    LCTL(KC_INS), LSFT(KC_INS),KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
 LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT, MO(AL),  KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        MO(NL),  KC_LCTL, KC_LALT, KC_LGUI,                   KC_BSPC, KC_ENT,  LT(FL,KC_SPC),    KC_ENT,  KC_UP,   KC_DOWN, KC_RGHT, MO(FL)),

    // Arrow layer.
    [AL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______,
        _______, _______, _______, _______,                   _______, KC_BTN3, KC_BTN1,          KC_BTN2, KC_LEFT, KC_DOWN, KC_RGHT, _______),

    // Function layer.
    [FL] = LAYOUT(
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, _______,          _______, _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_INS,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______,          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_ENT,
        _______, KC_F14,  KC_F15,  _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        MO(SL),  _______, _______, _______,                   KC_DEL,  _______, _x_x_x_,          KC_PSCR, KC_SLCK, KC_PAUS, _______, _x_x_x_),

    // Numpad layer.
    [NL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
        _x_x_x_, _______, _______, _______,                   _______, _______, MO(SL),           KC_P0,   KC_P0,   KC_PDOT, KC_PENT, MO(SL)),

    // Numpad layer.
    [SL] = LAYOUT(
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, WHOAMI,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, RESET,   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        _x_x_x_, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx, xxxxxxx, _x_x_x_,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _x_x_x_),
};


const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
    case 0:
        if (record->event.pressed) {
            register_code(KC_RSFT);
        } else {
            unregister_code(KC_RSFT);
        }
        break;
    }
    return MACRO_NONE;
};


void matrix_init_user(void) {}
void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
    case WHOAMI:
        if (record->event.pressed) {
          SEND_STRING("Property of Jack Zhou (@hkmix)");
        }

        return false;
    }

    return true;
}

void led_set_user(uint8_t usb_led) {}
