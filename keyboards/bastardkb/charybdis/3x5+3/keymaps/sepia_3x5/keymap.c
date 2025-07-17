/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include "sepia_3x5_common.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_POINTER = 7,  // Continue from where common layers end
};

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 700
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#    define SNP_TOG KC_NO
#endif // !POINTING_DEVICE_ENABLE

enum custom_keycodes {
    ESC = KEYMAP_SAFE_RANGE,  // Charybdis-specific custom keycode
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x5_3(
        LAYOUT_sepia_qwerty()
    ),

    [_SYM_1] = LAYOUT_split_3x5_3(
        LAYOUT_sepia_sym1()
    ),

    [_SYM_2] = LAYOUT_split_3x5_3(
        LAYOUT_sepia_sym2()
    ),
    
    [_FN] = LAYOUT_split_3x5_3(
        LAYOUT_sepia_fn()
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        LAYOUT_sepia_num()
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        LAYOUT_sepia_nav()
    ),
    
    [_MEDIA] = LAYOUT_split_3x5_3(
        LAYOUT_sepia_media()
    ),

    [LAYER_POINTER] = LAYOUT_split_3x5_3(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
             QK_BOOT,  EE_CLR, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX,  EE_CLR, QK_BOOT,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
             KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
             _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______,
        // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                        KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1, KC_BTN2
        //                            ╰───────────────────────────╯ ╰──────────────────╯
        ),
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC:
            if(get_highest_layer(layer_state) == LAYER_POINTER) {
                layer_off(LAYER_POINTER);
            } else {
                register_code(KC_ESC);
                unregister_code(KC_ESC);
            }
            return false;

        default:
            return true; // Continue to process other keys normally
    }
    return true;
}

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif