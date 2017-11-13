#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _______ KC_TRNS
#define xxxxxxx KC_NO

#define _BL 0
#define _TL 1
#define _FL 2
#define _ML 3

/* Keymap _XL: (Template Layer) Does something
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/*
[_XL] = KEYMAP(
  // Left
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // Right
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _BL: (Base Layer) Default Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |  1   |  2   |  3   |  4   |  5   |C-Left|           |C-Rght|  6   |  7   |  8   |  9   |  0   |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  Q   |  W   |  E   |  R   |  T   | S-Gui|           | Gui  |  Y   |  U   |  I   |  O   |  P   |   \    |
 * |--------+------+------+------+------+------| Tab  |           | Tab  |------+------+------+------+------+--------|
 * | LCtrl  |  A   |  S   |  D   |  F   |  G   |------|           |------|  H   |  J   |  K   |  L   |  ;   |   '    |
 * |--------+------+------+------+------+------| Gui  |           | Gui  |------+------+------+------+------+--------|
 * | LShift |  Z   |  X   |  C   |  V   |  B   | Shift|           | Shift|  N   |  M   |  ,   |  .   |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | FL   |   `  | Ins  | Left | Right|                                       |  Up  | Down |   [  |   ]  |  FL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | LAlt |       | RCtrl| RGui |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Del  |       | TL   |      |      |
 *                                 | Bspc | Esc  |------|       |------| Enter| Space|
 *                                 |      |      | ML   |       |  _   |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_BL] = KEYMAP(
  // Left
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    LCTL(KC_LEFT),
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    LSFT(LGUI(KC_TAB)),
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LSFT(KC_LGUI),
  MO(_FL), KC_GRV,  KC_INS,  KC_LEFT, KC_RGHT,
                                               KC_LGUI, KC_LALT,
                                                        KC_DEL,
                                      KC_BSPC, KC_ESC,  MO(_ML),
  // Right
  LCTL(KC_RGHT),
           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  LGUI(KC_TAB),
           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  LSFT(KC_RGUI),
           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(_FL),
  KC_RCTL, KC_RGUI,
  TG(_TL),
  KC_UNDS, KC_ENT,  KC_SPC),

/* Keymap _TL: (Traditional Layer) Adapts modifiers for windows use
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | A-S  |           | A    |      |      |      |      |      |        |
 * |--------+------+------+------+------+------| Tab  |           | Tab  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
<<<<<<< HEAD:keyboards/ergodox/keymaps/default/keymap.c
[_TL] = KEYMAP(
  // Left
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, LSFT(LALT(KC_TAB)),
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // Right
  _______, _______, _______, _______, _______, _______, _______,
  LALT(KC_TAB),
           _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* Keymap _FL: (Function Layer)
=======
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
>>>>>>> upstream/master:keyboards/ergodox_infinity/keymaps/default/keymap.c
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         | F1   | F2   | F3   | F4   | F5   | NumLk|           | VolM |  F6  | F7   | F8   | F9   | F10  |  F11   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      | F15  |           | Vol+ | ---- |  7   |  8   |  9   |  /   |  F12   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------| ---- |  4   |  5   |  6   |  *   |   -    |
 * |---------+------+------+------+------+------| F14  |           | Vol- |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | ---- |  1   |  2   |  3   | Enter|   +    |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |  0   |  0   |  .   | Enter|      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Prev | Next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Play |      |      |
 *                                 |      |      |------|       |------| Enter|  0   |
 *                                 |      |      |      |       | Stop |      |      |
 *                                 `--------------------'       `--------------------'
 */
<<<<<<< HEAD:keyboards/ergodox/keymaps/default/keymap.c
[_FL] = KEYMAP(
  // Left
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NLCK,
  _______, _______, _______, _______, _______, _______, KC_F15,
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_F14,
  _______, _______, _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // Right
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, xxxxxxx, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_F12,
           xxxxxxx, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PMNS,
  _______, xxxxxxx, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_PPLS,
                    KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______,
  KC_MPRV, KC_MNXT,
  KC_MPLY,
  KC_MSTP, KC_PENT, KC_P0),

/* Keymap _ML: (Mouse Layer) Mouse movement and commands
=======
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
>>>>>>> upstream/master:keyboards/ergodox_infinity/keymaps/default/keymap.c
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Gui  |           | MW^  |      |      |  M^  |      |      |        |
 * |--------+------+------+------+------+------| [    |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| ---- |  M<  |  Mv  |  M>  |      |        |
 * |--------+------+------+------+------+------| Gui  |           | MWv  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      | ]    |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | MB3  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | MW<  | MW>  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | MB4  | MB5  |------|       |------| MB2  | MB1  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
<<<<<<< HEAD:keyboards/ergodox/keymaps/default/keymap.c
[_ML] = KEYMAP(
  // Left
  _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, LGUI(KC_LBRC),
  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, LGUI(KC_RBRC),
  _______, _______, _______, _______, _______,
                                      _______, _______,
                                               _______,
                             KC_BTN4, KC_BTN5, _______,
  // Right
  _______, _______, _______, _______, _______, _______, _______,
  KC_WH_U, _______, _______, KC_MS_U, _______, _______, _______,
           xxxxxxx, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  KC_WH_D, _______, _______, _______, _______, _______, _______,
                    KC_BTN3, _______, _______, _______, _______,
  KC_WH_L, KC_WH_R,
  _______,
  _______, KC_BTN2, KC_BTN1),
=======
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
>>>>>>> upstream/master:keyboards/ergodox_infinity/keymaps/default/keymap.c
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t* record, uint8_t id, uint8_t opt) {
  // Unused
  (void) record;
  (void) id;
  (void) opt;

  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  // Unused
  (void) keycode;
  (void) record;

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
  case _FL:
    ergodox_right_led_1_on();
    break;

  case _ML:
    ergodox_right_led_2_on();
    break;

  default:
    break;
  }
};
