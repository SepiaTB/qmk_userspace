/*
 * Copyright 2024 SepiaTB
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

#pragma once

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// Common layer definitions for both charybdis 3x5 and corne 3x5
enum sepia_3x5_layers {
    _QWERTY = 0,
    _SYM_1,
    _SYM_2,
    _FN,
    _NUM,
    _NAV,
    _MEDIA,
};

// Common custom keycodes
enum custom_keycodes {
    CUT = SAFE_RANGE,
    COPY,
    PASTE,
    UNDO,
    LANG,
    HIRAGANA,
    KATAKANA,
    ESC,
    // Add any keyboard-specific keycodes after this
    KEYMAP_SAFE_RANGE
};

// Common layer layouts
#define LAYOUT_sepia_qwerty() \
    ES_Q,       ES_W,       ES_E,       ES_R,       ES_T,                            ES_Y,      ES_U,        ES_I,       ES_O,       ES_P, \
    LCTL_T(ES_A),LGUI_T(ES_S),LALT_T(ES_D),LSFT_T(ES_F),ES_G,                            ES_H,  RSFT_T(ES_J),LALT_T(ES_K),LGUI_T(ES_L),RCTL_T(ES_NTIL), \
    ES_Z,       ES_X,       ES_C,       ES_V,       ES_B,                            ES_N,      ES_M,       ES_COMM,    ES_DOT,     ES_MINS, \
                            LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_NUM, KC_TAB),       LT(_SYM_1, KC_ENTER), LT(_SYM_2, KC_BSPC),LT(_FN, KC_DEL)

#define LAYOUT_sepia_sym1() \
    ES_EXLM,     ES_QUES,    ES_LCBR,    ES_RCBR,    ES_PIPE,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO, \
    ES_SLSH,     ES_DQUO,    ES_LPRN,    ES_RPRN,    ES_AMPR,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO, \
    ES_AT,      ES_TILD,    ES_LBRC,    ES_RBRC,    ES_CIRC,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO, \
                            ES_LABK,    ES_RABK,     ES_EQL,                           KC_NO,     KC_NO,       KC_NO

#define LAYOUT_sepia_sym2() \
    ES_IEXL,    ES_IQUE,    ES_EURO,    ES_UNDS,    ES_FORD,                          KC_NO,     KC_HOME,     KC_UP,     KC_END,     KC_PGUP, \
    ES_BSLS,    ES_QUOT,     ES_DLR,    ES_MINS,    ES_MORD,                          KC_NO,     KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_PGDN, \
    ES_DIAE,    ES_NOT,     ES_BULT,    ES_HASH,     KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO, \
                              KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO

#define LAYOUT_sepia_fn() \
    KC_F1,       KC_F2,      KC_F3,      KC_F4,     KC_PSCR,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO, \
    KC_F5,       KC_F6,      KC_F7,      KC_F8,     KC_INS,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO, \
    KC_F9,       KC_F10,    KC_F11,      KC_F12,     KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO, \
                             KC_MENU,     KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO

#define LAYOUT_sepia_num() \
    HIRAGANA,   KATAKANA,    KC_NO,       KC_NO,      KC_NO,                          ES_ASTR,     ES_7,       ES_8,       ES_9,      ES_PERC, \
    KC_CAPS,      LANG,       KC_NO,      KC_NO,      KC_NO,                          ES_SLSH,     ES_4,       ES_5,       ES_6,      ES_EQL, \
    UNDO,       CUT,        COPY,       PASTE,      KC_NO,                          ES_PLUS,     ES_1,       ES_2,       ES_3,      ES_HASH, \
                              KC_NO,      KC_NO,      KC_NO,                          ES_MINS,     ES_0,       ES_DOT

#define LAYOUT_sepia_nav() \
    KC_F1,       KC_F2,      KC_F3,      KC_F4,     KC_PSCR,                          KC_NO,      KC_HOME,     KC_UP,     KC_END,     KC_PGUP, \
    KC_F5,       KC_F6,      KC_F7,      KC_F8,     KC_INS,                          KC_NO,      KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_PGDN, \
    KC_F9,       KC_F10,    KC_F11,      KC_F12,     KC_NO,                          KC_NO,      KC_NO,       KC_NO,     KC_NO,      KC_NO, \
                              KC_NO,      KC_NO,      KC_NO,                          KC_NO,     KC_DELETE,    KC_NO

#define LAYOUT_sepia_media() \
    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,      KC_NO,    KC_VOLU,     KC_NO,      ES_GRV, \
    KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_MPRV,   KC_VOLD,    KC_MNXT,    KC_QUOT, \
    KC_NO,       KC_NO,     ES_CCED,     KC_NO,      KC_NO,                           KC_NO,      KC_NO,      KC_NO,     KC_NO,      KC_NO, \
                              KC_NO,      KC_NO,      KC_NO,                          KC_MSTP,    KC_MPLY,    KC_MUTE

// Function declarations
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);
bool process_record_user(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);