// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// from https://docs.qmk.fm/features/tap_dance#introduction
// Tap Dance keycodes
enum td_keycodes {
    CTL_LT // Our example key: `CTRL` when held, `<` when tapped. Add additional keycodes for each tapdance.
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void altlp_finished(tap_dance_state_t *state, void *user_data);
void altlp_reset(tap_dance_state_t *state, void *user_data);


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
      KC_LSFT, KC_AMPR, KC_PERC, KC_TILD, KC_DLR, XXXXXXX,                      XXXXXXX, KC_HASH, XXXXXXX, KC_COLN, XXXXXXX, XXXXXXX,
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
       KC_TAB, KC_PSCR, KC_COPY, KC_PASTE, KC_MPLY, KC_BSPC,                   KC_PIPE, KC_QUES,  KC_GRV, KC_CIRC, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_DELETE,                   KC_BSLS, TD(CTL_LT), SHFT_GT,  ALT_AT, MOD_RGUI,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PSCR, KC_PGUP, KC_PGDN, KC_HOME,  KC_END, KC_LSFT,                       KC_DQUO, KC_UNDS, KC_MINUS, KC_SLASH, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, _______,  KC_SPC,     KC_LSFT,  MO(3), KC_LSFT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, TG(4),     TG(5),                      KC_VOLU,   KC_F1, KC_F2, KC_F3, KC_F4,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    XXXXXXX,     GUI_A,   ALT_O,   SFT_E,   CTL_U, XXXXXXX,                      KC_VOLD,    KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,                      KC_MUTE,   KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

   [4] = LAYOUT_split_3x6_3(  // numpad
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TG(4), KC_SLASH,   KC_7,    KC_8,    KC_9, KC_MINUS,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_SPC,KC_KP_ASTERISK,KC_4,    KC_5,    KC_6, KC_PLUS,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ENT, KC_COMMA,    KC_1,    KC_2,    KC_3,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,  KC_0,  KC_DOT,     KC_ENT, TG(4), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

   [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MINUS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,   KC_K,    KC_L,  KC_SCLN, KC_DQUO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,KC_COMMA,  KC_DOT,KC_SLASH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LCTL, KC_SPC,KC_LALT,     KC_ENT,  KC_SPC, KC_RCBR
                                      //`--------------------------'  `--------------------------'
  ),
};

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void ctllt_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LT);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

void ctllt_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LT);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [CTL_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctllt_finished, ctllt_reset)
};