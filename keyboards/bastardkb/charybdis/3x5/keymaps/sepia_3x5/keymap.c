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
#include "keymap_spanish.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    _QWERTY = 0,
    _SYM_1,
    _SYM_2,
    _FN,
    _NUM,
    _NAV,
    _MEDIA,
    LAYER_POINTER,
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
    CUT = SAFE_RANGE,
    COPY,
    PASTE,
    UNDO,
    LANG,
    HIRAGANA,
    KATAKANA,
    ESC
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x5_3(
        //,---------------------------------------------------------.                    ,---------------------------------------------------------.
              ES_Q,       ES_W,       ES_E,       ES_R,       ES_T,                            ES_Y,      ES_U,        ES_I,       ES_O,       ES_P,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
          LCTL_T(ES_A),LGUI_T(ES_S),LALT_T(ES_D),LSFT_T(ES_F),ES_G,                            ES_H,  RSFT_T(ES_J),LALT_T(ES_K),LGUI_T(ES_L),RCTL_T(ES_NTIL),
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
              ES_Z,       ES_X,       ES_C,       ES_V,       ES_B,                            ES_N,      ES_M,       ES_COMM,    ES_DOT,     ES_MINS,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
                                  LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_NUM, KC_TAB),       LT(_SYM_1, KC_ENTER), LT(_SYM_2, KC_BSPC),LT(_FN, KC_DEL)
        //                                  '-------------------------------------'                    '-------------------------------------'
    ),

    [_SYM_1] = LAYOUT_split_3x5_3(
        //,---------------------------------------------------------.                    ,---------------------------------------------------------.
            ES_EXLM,     ES_QUES,    ES_LCBR,    ES_RCBR,    ES_PIPE,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
            ES_SLSH,     ES_DQUO,    ES_LPRN,    ES_RPRN,    ES_AMPR,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             ES_AT,      ES_TILD,    ES_LBRC,    ES_RBRC,    ES_CIRC,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
                                            ES_LABK,    ES_RABK,     ES_EQL,                           KC_NO,     KC_NO,       KC_NO
        //                                  '-------------------------------------'                    '-------------------------------------'
    ),

    [_SYM_2] = LAYOUT_split_3x5_3(
        //,---------------------------------------------------------.                    ,---------------------------------------------------------.
             ES_IEXL,    ES_IQUE,    ES_EURO,    ES_UNDS,    ES_FORD,                          KC_NO,     KC_HOME,     KC_UP,     KC_END,     KC_PGUP,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             ES_BSLS,    ES_QUOT,     ES_DLR,    ES_MINS,    ES_MORD,                          KC_NO,     KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_PGDN,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             ES_DIAE,    ES_NOT,     ES_BULT,    ES_HASH,     KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
                                              KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO
        //                                  '-------------------------------------'                    '-------------------------------------'
    ),
    
    [_FN] = LAYOUT_split_3x5_3(
        //,---------------------------------------------------------.                    ,---------------------------------------------------------.
             KC_F1,       KC_F2,      KC_F3,      KC_F4,     KC_PSCR,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             KC_F5,       KC_F6,      KC_F7,      KC_F8,     KC_INS,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             KC_F9,       KC_F10,    KC_F11,      KC_F12,     KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
                                             KC_MENU,     KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO
        //                                  '-------------------------------------'                    '-------------------------------------'
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        //,---------------------------------------------------------.                    ,---------------------------------------------------------.
            HIRAGANA,   KATAKANA,    KC_NO,       KC_NO,      KC_NO,                          ES_ASTR,     ES_7,       ES_8,       ES_9,      ES_PERC,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
            KC_CAPS,      LANG,       KC_NO,      KC_NO,      KC_NO,                          ES_SLSH,     ES_4,       ES_5,       ES_6,      ES_EQL,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
              UNDO,       CUT,        COPY,       PASTE,      KC_NO,                          ES_PLUS,     ES_1,       ES_2,       ES_3,      ES_HASH,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
                                              KC_NO,      KC_NO,      KC_NO,                          ES_MINS,     ES_0,       ES_DOT
        //                                  '-------------------------------------'                    '-------------------------------------'
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        //,---------------------------------------------------------.                    ,---------------------------------------------------------.
             KC_F1,       KC_F2,      KC_F3,      KC_F4,     KC_PSCR,                          KC_NO,      KC_HOME,     KC_UP,     KC_END,     KC_PGUP,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             KC_F5,       KC_F6,      KC_F7,      KC_F8,     KC_INS,                          KC_NO,      KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_PGDN,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             KC_F9,       KC_F10,    KC_F11,      KC_F12,     KC_NO,                          KC_NO,      KC_NO,       KC_NO,     KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
                                              KC_NO,      KC_NO,      KC_NO,                          KC_NO,     KC_DELETE,    KC_NO
        //                                  '-------------------------------------'                    '-------------------------------------'
    ),
    
    [_MEDIA] = LAYOUT_split_3x5_3(
        //,---------------------------------------------------------.                    ,---------------------------------------------------------.
             KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,      KC_NO,    KC_VOLU,     KC_NO,      ES_GRV,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_MPRV,   KC_VOLD,    KC_MNXT,    KC_QUOT,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
             KC_NO,       KC_NO,     ES_CCED,     KC_NO,      KC_NO,                           KC_NO,      KC_NO,      KC_NO,     KC_NO,      KC_NO,
        //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
                                              KC_NO,      KC_NO,      KC_NO,                          KC_MSTP,    KC_MPLY,    KC_MUTE
        //                                  '-------------------------------------'                    '-------------------------------------'
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
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(ES_A):
        case LGUI_T(ES_S):
        case LALT_T(ES_D):
        case LSFT_T(ES_F):
        case RSFT_T(ES_J):
        case LALT_T(ES_K):
        case LGUI_T(ES_L):
        case RCTL_T(ES_NTIL):
        case LT(_MEDIA, KC_ESC):
        case LT(_NAV, KC_SPC):
        case LT(_NUM, KC_TAB):
        case LT(_SYM_1, KC_ENTER):
        case LT(_SYM_2, KC_BSPC):
        case LT(_FN, KC_DEL):
            return 180;
        default:
            return 100;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC:
            if(get_highest_layer(layer_state) == LAYER_POINTER) {
                layer_off(LAYER_POINTER);
            } else {
                register_code(KC_ESC);
                unregister_code(KC_ESC);
            }
            return false;

        case CUT:
            if (record->event.pressed) {
                // Ctrl+X (Cut)
                register_code(KC_LCTL);
                register_code(KC_X);
                unregister_code(KC_X);
                unregister_code(KC_LCTL);
            }
            return false;

        case COPY:
            if (record->event.pressed) {
                // Ctrl+C (Copy)
                register_code(KC_LCTL);
                register_code(KC_C);
                unregister_code(KC_C);
                unregister_code(KC_LCTL);
            }
            return false;

        case PASTE:
            if (record->event.pressed) {
                // Ctrl+V (Paste)
                register_code(KC_LCTL);
                register_code(KC_V);
                unregister_code(KC_V);
                unregister_code(KC_LCTL);
            }
            return false;

        case UNDO:
            if (record->event.pressed) {
                // Ctrl+Z (Undo)
                register_code(KC_LCTL);
                register_code(KC_Z);
                unregister_code(KC_Z);
                unregister_code(KC_LCTL);
            }
            return false;

        case LANG:
            if (record->event.pressed) {
                // Alt + Shift
                register_code(KC_LALT);
                register_code(KC_LSFT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            return false;

        case HIRAGANA:
            if (record->event.pressed) {
                // Shift + Caps Lock
                register_code(KC_LSFT);
                register_code(KC_CAPS);
                unregister_code(KC_CAPS);
                unregister_code(KC_LSFT);
            }
            return false;

        case KATAKANA:
            if (record->event.pressed) {
                // Alt + Caps Lock
                register_code(KC_LALT);
                register_code(KC_CAPS);
                unregister_code(KC_CAPS);
                unregister_code(KC_LALT);
            }
            return false;

        default:
            return true; // Process other keys normally
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