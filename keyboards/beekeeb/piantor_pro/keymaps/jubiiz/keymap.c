// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_O LALT_T(KC_O)
#define SFT_E LSFT_T(KC_E)
#define CTL_U LCTL_T(KC_U)

// Right-hand home row mods
#define CTL_H RCTL_T(KC_H)
#define SHFT_T RSFT_T(KC_T)
#define ALT_N LALT_T(KC_N)
#define GUI_S RGUI_T(KC_S)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_SCLN,KC_COMMA,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   GUI_A,   ALT_O,   SFT_E,   CTL_U,    KC_I,                         KC_D,   CTL_H,  SHFT_T,   ALT_N,  GUI_S, KC_MINUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,   KC_Z,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC,   MO(2),  KC_SPC,     KC_ENT,   MO(1), KC_LSFT
                                      //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
        // todo add shift above tab
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                         KC_0,    KC_2,    KC_4,    KC_6,    KC_8, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN,  KC_EQL,               KC_KP_ASTERISK, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_AMPR, KC_PERC, KC_TILD, KC_DLR, XXXXXXX,                      XXXXXXX, KC_HASH, KC_COLN, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(3),  KC_TAB,     KC_ENT,   _______, KC_LSFT
                                      //`--------------------------'  `--------------------------'
  ),

// Right-hand home row mods
#define CTL_LT RCTL_T(KC_LT)
#define SHFT_GT RSFT_T(KC_GT)
#define ALT_AT LALT_T(KC_AT)

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, KC_COPY, KC_PASTE,  XXXXXXX, KC_BSPC,                   KC_PIPE, KC_QUES,  KC_GRV, KC_CIRC, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_DELETE,                     KC_BSLS, CTL_LT,  SHFT_GT,  ALT_AT, MOD_RGUI,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PSCR, KC_PGDN, KC_PGUP, KC_HOME,  KC_END, KC_LSFT,                       KC_DQUO, KC_UNDS, KC_MINUS, KC_SLASH, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, _______,  KC_SPC,     KC_LSFT,  MO(3), KC_LSFT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, TG(4), XXXXXXX,                      KC_VOLU,   KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX,     GUI_A,   ALT_O,   SFT_E,   CTL_U, XXXXXXX,                      KC_VOLD,    KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MUTE,   KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

   [4] = LAYOUT_split_3x6_3(  // numpad
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TG(4), KC_SLASH,   KC_7,    KC_8,    KC_9, KC_MINUS,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_SPC,KC_KP_ASTERISK,KC_4,    KC_5,    KC_6, KC_PLUS,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ENT, KC_COMMA,    KC_1,    KC_2,    KC_3,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,  KC_0,  KC_DOT,     KC_ENT, TG(4), KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
