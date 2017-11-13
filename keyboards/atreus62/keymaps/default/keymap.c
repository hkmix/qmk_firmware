#include "atreus62.h"

#define _______ KC_TRNS
#define _x_x_x_ KC_TRNS
#define xxxxxxx KC_NO

#define _BL 0
#define _FL 1
#define _ML 2
#define _NL 3
#define _SL 4

#define G(kc) LGUI(KC_##kc)

enum macro_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  WHOAMI,
};

/*
  // Keymap _XL: (X Layer) Some Layer
  [_XL] = KEYMAP(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Keymap _BL: (Base Layer) Default Layer
  [_BL] = KEYMAP(
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MO(_NL), KC_GRV,  KC_INS,  KC_LALT, KC_LGUI, KC_BSPC, LT(_ML,KC_ESC),
                                                                   KC_ENT,  KC_SPC,  KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(_FL)),

  // Keymap _FL: (Function Layer) Default Function Layer
  [_FL] = KEYMAP(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______,                   _______, _______, _______, _______, _______, KC_F12,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,                   _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    _______, KC_F14,  KC_F15,  _______, _______, _______,                   _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,
    MO(_SL), _______, _______, _______, _______, KC_DEL,  _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _x_x_x_),

  // Keymap _ML: (Mouse Layer) Mouse Controls
  [_ML] = KEYMAP(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, G(LBRC), G(RBRC),                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_BTN4, KC_BTN5, _x_x_x_, KC_BTN2, KC_BTN1, KC_BTN3, _______, _______, _______, _______),

  // Keymap _NL: (Numpad Layer) Number Pad Layer
  [_NL] = KEYMAP(
    _______, _______, _______, _______, _______, _______,                   _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
    _x_x_x_, _______, _______, _______, _______, _______, KC_PEQL, KC_PENT, KC_P0,   KC_P4,   KC_P4,   KC_PDOT, KC_PENT, MO(_SL)),

  // Keymap _SL: (System Layer) System commands
  [_SL] = KEYMAP(
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, RESET,   xxxxxxx,                   xxxxxxx, xxxxxxx, xxxxxxx, WHOAMI,  xxxxxxx, xxxxxxx,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    _x_x_x_, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _x_x_x_),
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};

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
