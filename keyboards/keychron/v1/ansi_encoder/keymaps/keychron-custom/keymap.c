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

#include "keychron_common.h"
#include "os_detection.h"

#include "dedm8.h"

#include "print.h"

os_variant_t os_type;

// clang-format off

// Layers
enum layers{
    WIN,
    WIN_FN,
    LNX,
    LNX_FN
};

// Macro keycodes
enum my_keycodes {
    DSKTP_LFT = SAFE_RANGE,
    DSKTP_RHT,
    CTRL_1,
    GBAR_REC,
    ZOOM_OUT,
    ZOOM_IN,
    SWCH_KMP
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
    [WIN] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   TD(TD_DEL_PRNT),    TO(LNX),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             TD(TD_HOME_END),
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        _______,  _______,  _______,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,             _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            QK_LOCK,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                CTRL_1,   _______,    GBAR_REC, _______,  _______,  _______),

    [LNX] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   TD(TD_DEL_PRNT),    TO(WIN),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             TD(TD_HOME_END),
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(LNX_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [LNX_FN] = LAYOUT_ansi_82(
        QK_BOOT,  _______,  _______,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,             EE_CLR,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                CTRL_1,   _______,    _______,  _______,  _______,  _______),
};

// clang-format on
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();
    if (mods_state & MOD_BIT(KC_LSFT)) { // If you are holding L shift, encoder changes layers
        encoder_action_desktop(clockwise); // navigate next/prev word
    } else if (mods_state & MOD_BIT(KC_RSFT)) { // If you are holding R shift, Page up/dn
        encoder_action_rgb_hue(clockwise);
    } else if (mods_state & MOD_BIT(KC_LCTL)) { // if holding Left Ctrl, navigate next/prev word
        encoder_action_cursor(clockwise);
    } else if (mods_state & MOD_BIT(KC_RCTL)) { // if holding Right Ctrl, change rgb hue/colour
        encoder_action_rgb_saturation(clockwise);
    } else if (mods_state & MOD_BIT(KC_LALT)) { // if holding Left Alt, change media next/prev track
        encoder_action_rgb_brightness(clockwise);
    } else {
        encoder_action_zoom(clockwise);
    }
    return false;
}

// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [WIN] = {ENCODER_CCW_CW(DSKTP_LFT, DSKTP_RHT)},
    [WIN_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [LNX] = {ENCODER_CCW_CW(ZOOM_OUT, ZOOM_IN)},
    [LNX_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
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
                print("Test console");
                SEND_STRING(SS_LCTL(SS_TAP(X_1)));
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
        case SWCH_KMP:
            if (record->event.pressed) {
                if (get_highest_layer(layer_state) == WIN_FN) {
                    layer_move(LNX);
                    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CANDY_RAIN);
                } else {
                    layer_move(WIN);
                    rgb_matrix_mode(RGB_MATRIX_CUSTOM_CANDY_SPLASH);
                }
            }
            break;
    }
    return true;
}

#ifdef ENABLE_RGB_DEBUG
bool rgb_matrix_indicators_user(void) {
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL:
            switch (get_highest_layer(layer_state)) {
                case LNX:
                    rgb_matrix_set_color_all(255, 255, 255);
                    return true;
                    break;
                case WIN:
                    rgb_matrix_set_color_all(255, 0, 0);
                    return true;
                    break;
                case WIN_FN:
                    rgb_matrix_set_color_all(0, 255, 0);
                    return true;
                    break;
                case LNX_FN:
                    rgb_matrix_set_color_all(0, 0, 255);
                    return true;
                    break;
                default:
                    return false;
                    break;
            }
            break;
        case LED_FLAG_NONE:
            return true;
            break;
        default:
            return true;
            break;
    }
}
#endif // ENABLE_RGB_DEBUG
