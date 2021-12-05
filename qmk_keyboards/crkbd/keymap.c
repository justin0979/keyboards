/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

compile: qmk compile -kb crkbd -km justin0979  (can just run `qmk compile`)
flash:   qmk flash -kb crkbd -km justin0979    (can just run `qmk flash`)
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

#define _CMK 0  // line 51
#define _QWE 1  // line 64
#define _RS 2   // line 76
#define _LS 3   // line 88
#define _LLS 4  // line 100
#define _FNUM 5 // line 112
#define _MCR 6  // line 124
#define _MCRR 7 // line 136
#define _NP 8   // line 148
#define _DB 9   // line 160

enum custom_keycodes {
  CMK,
  QWE,
  RS,
  LS,
  LLS,
  FNUM,
  MCR,
  MCRR,
  NP,
  DB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CMK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_RALT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LCTL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        A(KC_LEFT), MO(_LS), KC_LSFT,   KC_SPC,  MO(_RS),  TO(_NP) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS, KC_TRNS \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_QUOT, KC_TILD, KC_RALT, KC_TAB,  KC_ESC,                      KC_BSLS,KC_MINUS,  KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, C(KC_Z) , KC_GRV, C(KC_C), KC_DEL, C(A(KC_V)),                    C(KC_T), C(KC_W), KC_TRNS, KC_DOT, KC_QUOT, KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, MO(_FNUM),  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,  C(S(KC_E)),C(S(KC_P)), KC_PGDN, C(S(KC_I)), KC_M,                 C(S(KC_6)),C(KC_MINUS), C(KC_PLUS),C(KC_Y),  KC_RPRN,    KC_BSPC,\
  //|--------+----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, MO(_LLS),  C(KC_PLUS), KC_DOWN, LCA(KC_T),  C(S(KC_D)),           KC_LEFT,   KC_DOWN,     KC_UP,     KC_RIGHT, C(S(KC_0)), KC_GRV,\
  //|--------+----------+--------+--------+--------+--------|                    |--------+--------+-   -------+--------+--------+--------|
     KC_LSFT, C(KC_Z),   C(KC_Y),    C(KC_C), C(KC_E),    C(S(KC_J)),           KC_HOME,   KC_END,      KC_LBRC,   KC_RBRC,  KC_QUOT,    KC_TILD,\
  //|--------+----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   KC_TRNS,  KC_SPC,     KC_RGUI,   MO(_FNUM),XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LLS] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP,   KC_F5,   KC_H,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,C(KC_MINUS), KC_UP, XXXXXXX,C(S(KC_D)),                    KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,S(KC_QUOT),XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RS,  KC_SPC,     KC_ENT,   LS, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_FNUM] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TO(_MCR), RGB_HUI, C(KC_TAB), KC_LCTL, KC_TAB, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(_DB), RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RS,  KC_SPC,     KC_ENT,   LS, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MCR] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F5,     KC_LSFT,   KC_A,    KC_W,    KC_D,    KC_E,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, TO(_CMK),\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_Q,       KC_Z,    KC_D,    KC_S,    KC_F,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+-----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(_MCRR), KC_LCTL,  KC_SPC,     KC_ENT,  KC_SPC,  RS \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MCRR] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F5,     KC_LSFT,   KC_A,    KC_W,    KC_D,    KC_E,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, TO(_CMK),\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_Q,       KC_Z,    KC_D,    KC_S,    KC_F,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+-----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LCTL,  KC_SPC,     KC_ENT,  KC_SPC,  RS \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NP] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,      KC_Q,    KC_W,   KC_F,    KC_P,    KC_G,                         KC_Y,   KC_KP_7,  KC_KP_8,  KC_KP_9, KC_KP_0, KC_BSPC,\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_BSPC,      KC_A,    KC_R,   KC_S,    KC_T,    KC_D,                         KC_M,   KC_KP_4,  KC_KP_5,  KC_KP_6, KC_KP_0, KC_ENT,\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TO(_CMK), KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,                         KC_L,   KC_KP_1,  KC_KP_2,  KC_KP_3, KC_SLSH, KC_RSFT,\
  //|--------+-----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_SPC,  KC_F5,     KC_E,  KC_N,  TO(_CMK) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_DB] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,   KC_F1, KC_F2,     KC_F3,  KC_F4,   KC_F5,                        KC_F10,  KC_F9,   KC_U,    KC_Y,    KC_SCLN, KC_RALT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,   KC_1,  KC_2,      KC_3,   KC_4,    KC_I,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_R,     KC_A,  S(KC_GRV), KC_Q,   KC_F6,   KC_T,                         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_SPC,  KC_LSFT, KC_LALT,   TO(_CMK), MO(_RS), TO(_NP) \
                                      //`--------------------------'  `--------------------------'
  )

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
