#include "rev2.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { 0, 1, 2 },
    { 3, 4, 5 },
    { 6, 7, 8 }
}, {
    // LED Index to Physical Position
    { 0, 0 }, { 112, 0 }, { 224, 0 },
    { 0, 32 }, { 112, 32 }, { 224, 32 },
    { 0, 64 }, { 112, 64 }, { 224, 64 },
    { 56, 64 }, { 168, 64 },
}, {
    // LED Index to Flag
    4, 4, 4,
    4, 4, 4,
    4, 4, 4,
    2, 2
} };
#endif

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
    rgb_matrix_set_speed(RGB_MATRIX_STARTUP_SPD);
    rgb_matrix_sethsv(0, 255, RGB_MATRIX_STARTUP_VAL);
}

void eeconfig_init_kb(void) {
    eeconfig_update_kb(0);
    eeconfig_init_user();
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}
