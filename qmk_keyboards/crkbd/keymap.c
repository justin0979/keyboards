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

Compile: qmk compile -kb crkbd -km justin0979
Flash  : qmk flash -kb crkbd -km justin0979
*/

#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 1      // line 70
#define _COLEMAK 0     // line 63
#define _RSIDE 2       // line 96
#define _LSIDE 3       // line 108
#define _LLS 4        // line 113
#define _THIRD 5      // line 120
#define _MCR 6         // line 136
#define _MCRR 7
#define _NP 8         // line 149
#define _DB 9         // line 180

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  RSIDE,
  LSIDE,
  THIRD,
  BACKLIT,
  RGBRST,
  MCR,
  MCRR,
  NP,
  DB
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_RALT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LCTL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        A(KC_LEFT), MO(_LSIDE), KC_LSFT,   KC_SPC,  MO(_RSIDE),  TO(_NP) \
                                      //`--------------------------'  `--------------------------'

  ),

  [_QWERTY] = LAYOUT_split_3x6_3( \
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

  [_RSIDE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_QUOT, KC_TILD, KC_RALT, KC_TAB,  KC_ESC,                      KC_BSLS,KC_MINUS,  KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, C(KC_Z) , KC_GRV, C(KC_C), KC_DEL, C(A(KC_V)),                    C(KC_T), C(KC_W), KC_TRNS, KC_DOT, KC_QUOT, KC_TRNS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, MO(_THIRD),  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS \
                                      //`--------------------------'  `--------------------------'
    ),

  [_LSIDE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,  C(S(KC_E)),C(S(KC_P)), KC_PGDN, C(S(KC_I)), KC_M,                 C(S(KC_6)),C(KC_MINUS), C(KC_PLUS),C(KC_Y),  KC_RPRN,    KC_BSPC,\
  //|--------+----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, MO(_LLS),  C(KC_PLUS), KC_DOWN, LCA(KC_T),  C(S(KC_D)),           KC_LEFT,   KC_DOWN,     KC_UP,     KC_RIGHT, C(S(KC_0)), KC_GRV,\
  //|--------+----------+--------+--------+--------+--------|                    |--------+--------+-   -------+--------+--------+--------|
     KC_LSFT, C(KC_Z),   C(KC_Y),    C(KC_C), C(KC_E),    C(S(KC_J)),           KC_HOME,   KC_END,      KC_LBRC,   KC_RBRC,  KC_QUOT,    KC_TILD,\
  //|--------+----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   KC_TRNS,  KC_SPC,     KC_RGUI,   MO(_THIRD),XXXXXXX \
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
                                          KC_LGUI,   RSIDE,  KC_SPC,     KC_ENT,   LSIDE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_THIRD] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TO(_MCR), RGB_HUI, C(KC_TAB), KC_LCTL, KC_TAB, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(_DB), RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RSIDE,  KC_SPC,     KC_ENT,   LSIDE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MCR] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F5,     KC_LSFT,   KC_A,    KC_W,    KC_D,    KC_E,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, TO(_COLEMAK),\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_Q,       KC_Z,    KC_D,    KC_S,    KC_F,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+-----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(_MCRR), KC_LCTL,  KC_SPC,     KC_ENT,  KC_SPC,  RSIDE \
                                      //`--------------------------'  `--------------------------'

  ),

  [_MCRR] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F5,     KC_LSFT,   KC_A,    KC_W,    KC_D,    KC_E,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, TO(_COLEMAK),\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_Q,       KC_Z,    KC_D,    KC_S,    KC_F,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
  //|--------+-----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LCTL,  KC_SPC,     KC_ENT,  KC_SPC,  RSIDE \
                                      //`--------------------------'  `--------------------------'

  ),

  [_NP] = LAYOUT_split_3x6_3( \
  //,--------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,      KC_Q,    KC_W,   KC_F,    KC_P,    KC_G,                         KC_Y,   KC_KP_7,  KC_KP_8,  KC_KP_9, KC_KP_0, KC_BSPC,\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_BSPC,      KC_A,    KC_R,   KC_S,    KC_T,    KC_D,                         KC_M,   KC_KP_4,  KC_KP_5,  KC_KP_6, KC_KP_0, KC_ENT,\
  //|--------+-----------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TO(_COLEMAK), KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,                         KC_L,   KC_KP_1,  KC_KP_2,  KC_KP_3, KC_SLSH, KC_RSFT,\
  //|--------+-----------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_SPC,  KC_F5,     KC_E,  KC_N,  TO(_COLEMAK) \
                                      //`--------------------------'  `--------------------------'
     
  ),

  [_DB] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,   KC_F1,  KC_F2,   KC_F3,   KC_F4,    KC_F5,                         KC_F10,    KC_F9,    KC_U,    KC_Y, KC_SCLN,  KC_RALT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_I,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    S(KC_GRV),  KC_A,    KC_R,    KC_H,    KC_Q,    KC_T,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LCTL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_SPC, KC_LALT, KC_LSFT,   TO(_COLEMAK),  MO(_RSIDE),  TO(_NP) \
                                      //`--------------------------'  `--------------------------'

  )

};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting THIRD layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_on(_QWERTY);
      } else {
        layer_off(_QWERTY);
      }
      return false;
    case RSIDE:
      if (record->event.pressed) {
        layer_on(_RSIDE);
        update_tri_layer_RGB(_RSIDE, _LSIDE, _THIRD);
      } else {
        layer_off(_RSIDE);
        update_tri_layer_RGB(_RSIDE, _LSIDE, _THIRD);
      }
      return false;
    case LSIDE:
      if (record->event.pressed) {
        layer_on(_LSIDE);
        update_tri_layer_RGB(_RSIDE, _LSIDE, _THIRD);
      } else {
        layer_off(_LSIDE);
        update_tri_layer_RGB(_RSIDE, _LSIDE, _THIRD);
      }
      return false;
    case THIRD:
        if (record->event.pressed) {
          layer_on(_THIRD);
        } else {
          layer_off(_THIRD);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
