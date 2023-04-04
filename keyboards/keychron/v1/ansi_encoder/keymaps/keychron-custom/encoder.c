#include QMK_KEYBOARD_H

// #include "dedm8.h"

static uint16_t key_timer;

void encoder_action_cursor(bool clockwise) {
    if (clockwise) {
        tap_code(KC_RGHT);
        if (timer_elapsed(key_timer) < 50) {
            tap_code(KC_RGHT); // if less than 50ms have passed, hit right twice.
            tap_code(KC_RGHT);
            key_timer = timer_read();
        } else {
            key_timer = timer_read();
            // do nothing if 50ms or more have passed
        }
    } else {
        tap_code(KC_LEFT);
        if (timer_elapsed(key_timer) < 50) {
            tap_code(KC_LEFT); // if less than 50ms have passed, hit left twice.
            tap_code(KC_LEFT);
            key_timer = timer_read();
        } else {
            key_timer = timer_read();
            // do nothing if 50ms or more have passed
        }
    }
}

void encoder_action_mediatrack(bool clockwise) {
    if (clockwise)
        tap_code(KC_MEDIA_NEXT_TRACK);
    else
        tap_code(KC_MEDIA_PREV_TRACK);
}

void encoder_action_navword(bool clockwise) {
    if (clockwise)
        tap_code16(LCTL(KC_RGHT));
    else
        tap_code16(LCTL(KC_LEFT));
}

void encoder_action_desktop(bool clockwise) {
    if (clockwise)
        tap_code16(LCTL(LGUI(KC_RGHT)));
    else
        tap_code16(LCTL(LGUI(KC_LEFT)));
}

void encoder_action_zoom(bool clockwise) {
    if (clockwise)
        tap_code16(LCTL(KC_EQL));
    else
        tap_code16(LCTL(KC_MINS));
}

#    ifdef RGB_MATRIX_ENABLE
void encoder_action_rgb_speed(bool clockwise) {
    if (clockwise)
        rgb_matrix_increase_speed_noeeprom();
    else
        rgb_matrix_decrease_speed_noeeprom();
}
void encoder_action_rgb_hue(bool clockwise) {
    if (clockwise)
        rgb_matrix_increase_hue_noeeprom();
    else
        rgb_matrix_decrease_hue_noeeprom();
}
void encoder_action_rgb_saturation(bool clockwise) {
    if (clockwise)
        rgb_matrix_increase_sat_noeeprom();
    else
        rgb_matrix_decrease_sat_noeeprom();
}
void encoder_action_rgb_brightness(bool clockwise) {
    if (clockwise)
        rgb_matrix_increase_val_noeeprom();
    else
        rgb_matrix_decrease_val_noeeprom();
}
void encoder_action_rgb_mode(bool clockwise) {
    if (clockwise)
        rgb_matrix_step_noeeprom();
    else
        rgb_matrix_step_reverse_noeeprom();
}
#    endif // RGB_MATRIX_ENABLE