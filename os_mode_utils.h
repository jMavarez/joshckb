#pragma once

typedef enum {
    PC_MODE = 0,
    MAC_MODE = 1,
} os_mode_t;

os_mode_t current_os_mode;

void os_mode_init(void);
void set_os_mode(os_mode_t mode);
os_mode_t get_os_mode(void);

