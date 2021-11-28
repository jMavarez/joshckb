#pragma once
#include QMK_KEYBOARD_H

enum layer_number {
  _QW = 0,
  _DV,
  _LW,
  _RS,
  _AD,
};

enum custom_keycode {
    // OS based combinations
    ALT_TAB = SAFE_RANGE,
    CTL_TAB,
    COPY,
    PASTE,
    CUT,
    // Base layouts
    QWERTY,
    DVORAK,
    // Keyboard OS mode
    OS_PC,
    OS_MAC,
    // Reset
    KC_RESET,
};

// Home rows definitions
// QWERTY
// Left-hand
#define HOME_A    LSFT_T(KC_A)
#define HOME_S    LCTL_T(KC_S)
#define HOME_D    LGUI_T(KC_D)
#define HOME_F    LALT_T(KC_F)

// Right-hand
#define HOME_J    LALT_T(KC_J)
#define HOME_K    RGUI_T(KC_K)
#define HOME_L    RCTL_T(KC_L)
#define HOME_SCLN RSFT_T(KC_SCLN)
 
// DVORAK
// Left-hand
#define HOME_A    LSFT_T(KC_A)
#define HOME_O    LCTL_T(KC_O)
#define HOME_E    LGUI_T(KC_E)
#define HOME_U    LALT_T(KC_U)

// Right-hand
#define HOME_H    LALT_T(KC_H)
#define HOME_T    RGUI_T(KC_T)
#define HOME_N    RCTL_T(KC_N)
#define HOME_SS   RSFT_T(KC_S)
