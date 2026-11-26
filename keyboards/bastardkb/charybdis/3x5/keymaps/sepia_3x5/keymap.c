#include QMK_KEYBOARD_H
#include "sepia.h"
#include "sepia_key_overrides.h"
#include "sepia_keymap.h"

// 36 teclas sobre la matriz 8x5 de bastardkb/charybdis/3x5 (mismo orden que LAYOUT_split_3x5_3).
// El pulgar central derecho es [7][3], posicion que el LAYOUT oficial deja en KC_NO
// y que la flex de pulgares del Skeletyl cablea en la mitad derecha.
#define LAYOUT_charybdis_3x5_3(                          \
    k00, k01, k02, k03, k04,   k44, k43, k42, k41, k40,  \
    k10, k11, k12, k13, k14,   k54, k53, k52, k51, k50,  \
    k20, k21, k22, k23, k24,   k64, k63, k62, k61, k60,  \
              k32, k33, k30,   k70, k73, k72             \
) {                                                      \
    { k00, k01,   k02, k03, k04   },                     \
    { k10, k11,   k12, k13, k14   },                     \
    { k20, k21,   k22, k23, k24   },                     \
    { k30, KC_NO, k32, k33, KC_NO },                     \
    { k40, k41,   k42, k43, k44   },                     \
    { k50, k51,   k52, k53, k54   },                     \
    { k60, k61,   k62, k63, k64   },                     \
    { k70, KC_NO, k72, k73, KC_NO }                      \
}

// Las capas (SEPIA_*) y get_tapping_term() estan en users/sepia_3x5/sepia_keymap.h.
// El wrapper variadico fuerza a expandir la macro de la capa antes de contar los argumentos.
#define LAYOUT_sepia(...) LAYOUT_charybdis_3x5_3(__VA_ARGS__)

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/** \brief Automatically enable sniping-mode on the pointer layer. */
// #define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

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
#endif // !POINTING_DEVICE_ENABLE





// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_sepia(SEPIA_QWERTY),

    [_SYM_1] = LAYOUT_sepia(SEPIA_SYM_1),

    [_SYM_2] = LAYOUT_sepia(SEPIA_SYM_2),

    [_FN] = LAYOUT_sepia(SEPIA_FN),

    [_NUM] = LAYOUT_sepia(SEPIA_NUM),

    [_NAV] = LAYOUT_sepia(SEPIA_NAV),

    [_MEDIA] = LAYOUT_sepia(SEPIA_MEDIA),

    [LAYER_POINTER] = LAYOUT_charybdis_3x5_3(
        // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
             QK_BOOT,  EE_CLR, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX,  EE_CLR, QK_BOOT,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
             KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL,
        // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
             _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______,
        // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                        MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN3, MS_BTN1, MS_BTN2
        //                            ╰───────────────────────────╯ ╰──────────────────╯
        ),
};
// clang-format on

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
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
