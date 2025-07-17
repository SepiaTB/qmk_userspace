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

#include "sepia_3x5_common.h"

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

// Weak function to allow keyboard-specific overrides
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // First try keyboard-specific processing
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

    // Then handle common keycodes
    switch (keycode) {
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