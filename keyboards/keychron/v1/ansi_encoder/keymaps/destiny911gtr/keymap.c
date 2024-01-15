/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keychron_common.h"

// clang-format off

enum layers{
    LNX_BASE,
    LNX_FN,
    WIN_BASE,
    WIN_FN
};

// Macro keycodes
enum my_keycodes {
    DSKTP_LFT = SAFE_RANGE,
    DSKTP_RHT,
    CTRL_1,
    CTRL_2,
    GBAR_REC,
    ZOOM_OUT,
    ZOOM_IN,
    PRINT_HSV
};

// Tap Dance declarations
enum {
    TD_HOME_END,
    TD_DEL_PRNT
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END), // Tap once for Home, twice for End
    [TD_DEL_PRNT] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, KC_PSCR)  // Tap once for Delete, twice for Print Screen
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LNX_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   TD(TD_DEL_PRNT),    KC_MPLY,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             TD(TD_HOME_END),
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(LNX_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LNX_FN] = LAYOUT_ansi_82(
        QK_BOOT,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            EE_CLR,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                CTRL_1,   _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   TD(TD_DEL_PRNT),    PRINT_HSV,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             TD(TD_HOME_END),
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            QK_LOCK,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                CTRL_1,   _______,    GBAR_REC, _______,  _______,  _______),
};

// clang-format off

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [WIN_BASE] = {ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
    [WIN_FN] = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
    [LNX_BASE] = {ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [LNX_FN] = {ENCODER_CCW_CW(ZOOM_OUT, ZOOM_IN)}
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case DSKTP_LFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_LEFT))));
            }
            break;
        case DSKTP_RHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_RGHT))));
            }
            break;
        case CTRL_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_1)));
            }
            break;
        case CTRL_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_2)));
            }
            break;
        case GBAR_REC:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_G))));
            }
            break;
        case ZOOM_OUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("-"));
            }
            break;
        case ZOOM_IN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("="));
            }
            break;
        case PRINT_HSV:
            if (record->event.pressed) {
                char h[5];
                char s[5];
                char v[5];
                char spd[4];
                sprintf(h, "%d ", rgb_matrix_get_hue());
                sprintf(s, "%d ", rgb_matrix_get_sat());
                sprintf(v, "%d ", rgb_matrix_get_val());
                sprintf(spd, "%d", rgb_matrix_get_speed());
                send_string(h);
                send_string(s);
                send_string(v);
                send_string(spd);
            }
            break;
    }
    return true;
}