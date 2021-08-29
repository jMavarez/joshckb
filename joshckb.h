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
    // Os based combinations
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

