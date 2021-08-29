#include "joshckb.h"
#include "os_mode_utils.h"

uint16_t reset_timer = 0;

bool is_alt_tab_active = false;
bool is_clt_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(_LW):
            if (!record->event.pressed) {
                if (is_alt_tab_active) {
                    switch (get_os_mode()) {
                        case PC_MODE:
                            unregister_code(KC_LALT);
                        break;
                        case MAC_MODE:
                            unregister_code(KC_LGUI);
                        break;
                    }

                    is_alt_tab_active = false;
                }

                if (is_clt_tab_active) {
                    unregister_code(KC_LCTL);
                    is_clt_tab_active = false;
                }
            }

            return true;
            break;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    
                    switch (get_os_mode()) {
                        case PC_MODE:
                            register_code(KC_LALT);
                        break;
                        case MAC_MODE:
                            register_code(KC_LGUI);
                        break;
                    }
                }

                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }

            return false;
            break;
        case CTL_TAB:
            if (record->event.pressed) {
                if (!is_clt_tab_active) {
                    is_clt_tab_active = true;
                    register_code(KC_LCTL);
                }

                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }

            return false;
            break;
        case COPY:
            if (record->event.pressed) {
                switch (get_os_mode()) {
                    case PC_MODE:
                        tap_code16(LCTL(KC_C));
                    break;
                    case MAC_MODE:
                        tap_code16(LGUI(KC_C));
                    break;
                }
            }
            return false;
            break;
        case PASTE:
            if (record->event.pressed) {
                switch (get_os_mode()) {
                    case PC_MODE:
                        tap_code16(LCTL(KC_V));
                    break;
                    case MAC_MODE:
                        tap_code16(LGUI(KC_V));
                    break;
                }
            }
            return false;
            break;
        case CUT:
            if (record->event.pressed) {
                switch (get_os_mode()) {
                    case PC_MODE:
                        tap_code16(LCTL(KC_X));
                    break;
                    case MAC_MODE:
                        tap_code16(LGUI(KC_X));
                    break;
                }
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QW);
                layer_off(_AD);
            }

            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DV);
                layer_off(_AD);
            }

            return false;
            break;
        case OS_PC:
            if (record->event.pressed) {
                set_os_mode(PC_MODE);
                layer_off(_AD);
            }

            return false;
            break;
        case OS_MAC:
            if (record->event.pressed) {
                set_os_mode(MAC_MODE);
                layer_off(_AD);
            }

            return false;
            break;
        case KC_RESET:
            if (record->event.pressed) {
                reset_timer = timer_read();
            } else if (timer_elapsed(reset_timer) >= RESET_THRESHOLD) {
                reset_keyboard();
            }

            return false;
            break;
        default:
            return true;
    }
}

void matrix_init_user(void) {
    os_mode_init();
}

