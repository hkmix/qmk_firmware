#include "satan.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL1 1
#define _FL2 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ` |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Bksp |
   * |-----------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |FN1|
   * |-----------------------------------------------------------|
   * |FN2 |Alt |Gui |      Space            |Gui |Alt |FN2 |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_HHKB(
  F(0),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_GRV, KC_BSLS, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSPC, \
  KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,MO(_FL1), \
  MO(_FL2),KC_LALT,KC_LGUI,                KC_SPC,                                 KC_RGUI,KC_RALT,MO(_FL2),KC_RCTL),

  /* Keymap _FL1: (Function Layer 1) Default Function Layer
   * ,-----------------------------------------------------------.
   * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Ins|Del|
   * |-----------------------------------------------------------|
   * |Caps |Prv|Ply|Nxt|Stp|   |   |   |Psc|SLk|Pus|Up |   |     |
   * |-----------------------------------------------------------|
   * |       |V- |V+ |Vm |   |   | * | / |Hme|PgU|Lft|Rgt|       |
   * |-----------------------------------------------------------|
   * |        |F14|F15|   |   |   | + | - |End|PgD|Dwn|      |   |
   * |-----------------------------------------------------------|
   * |    |    |    |                       |    |    |    |     |
   * `-----------------------------------------------------------'
   */
[_FL1] = KEYMAP_HHKB(
  KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,  \
  KC_CAPS,KC_MPRV,KC_MPLY,KC_MNXT,KC_MSTP,_______,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,KC_UP  ,_______,_______, \
  _______,KC_VOLD,KC_VOLU,KC_MUTE,_______,_______,KC_PAST,KC_PSLS,KC_HOME,KC_PGUP,KC_LEFT,KC_RGHT,_______, \
  _______,KC_F14 ,KC_F15 ,_______,_______,_______,KC_PPLS,KC_PMNS,KC_END ,KC_PGDN,KC_DOWN,_______,_______, \
  _______,_______,_______,                _______,                        _______,_______,_______,_______),

  /* Keymap _FL2: (Function Layer 2) Basic Vim mappings + Numpad
   * ,-----------------------------------------------------------.
   * |   |   |   |   | / |   |   |   |   |   |   |   |   |   |   |
   * |-----------------------------------------------------------|
   * |     |Kp7|Kp8|Kp9| * |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |KpEnter|Kp4|Kp5|Kp6| - |   |Lft|Dwn|Up |Rgt|   |   |       |
   * |-----------------------------------------------------------|
   * |        |Kp1|Kp2|Kp3| + |   |   |   |   |   |   |      |   |
   * |-----------------------------------------------------------|
   * |    |    |Kp0 |                       |    |    |    |     |
   * `-----------------------------------------------------------'
   */
[_FL2] = KEYMAP_HHKB(
  _______,_______,_______,_______,KC_PSLS,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  \
  _______,KC_P7  ,KC_P8  ,KC_P9  ,KC_PAST,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  KC_PENT,KC_P4  ,KC_P5  ,KC_P6  ,KC_PMNS,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,_______, \
  _______,KC_P1  ,KC_P2  ,KC_P3  ,KC_PPLS,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,_______,KC_P0  ,                _______,                        _______,_______,_______,_______),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
