#include "os_mode_utils.h"

void os_mode_init(void) {
    // TODO: Maybe store current mode on the EEPROM 
    // so we are consistent with how we store the default layer.
    current_os_mode = PC_MODE;
}

void set_os_mode(os_mode_t mode) {
    current_os_mode = mode;
}

os_mode_t get_os_mode() {
    return current_os_mode;
}

