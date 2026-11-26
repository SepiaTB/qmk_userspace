#pragma once

// Capas compartidas entre los keymaps sepia_3x5 del Corne y del Charybdis 3x5+3.
// Incluir solo desde keymap.c (define get_tapping_term). NO lo usa el Charybdis 4x6.
// Los otros .c que solo necesiten los numeros de capa deben incluir "sepia_layers.h".
#include "sepia.h"
#include "sepia_layers.h"

// Dentro de las macros los comentarios son /* */: un // seguido de barra invertida se comeria la linea siguiente.
// Cada macro SEPIA_<CAPA> se expande a las 36 teclas en el orden de LAYOUT_split_3x5_3
// (5 izquierda + 5 derecha por fila, luego 3+3 pulgares). Cada keymap las pasa a su LAYOUT
// a traves de un wrapper variadico, p. ej.:
//   #define LAYOUT_sepia(...) LAYOUT_split_3x5_3(__VA_ARGS__)
//   [_QWERTY] = LAYOUT_sepia(SEPIA_QWERTY),
// (el wrapper obliga a expandir la macro antes de que LAYOUT cuente los argumentos).

// Capa base QWERTY (hold-taps de mods en la fila central, LT de capas en los pulgares)
#define SEPIA_QWERTY \
    /*,---------------------------------------------------------.                    ,---------------------------------------------------------. */            \
              ES_Q,       ES_W,       ES_E,       ES_R,       ES_T,                            ES_Y,      ES_U,        ES_I,       ES_O,       ES_P,           \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */        \
          LCTL_T(ES_A),LGUI_T(ES_S),LALT_T(ES_D),LSFT_T(ES_F),ES_G,                            ES_H,  RSFT_T(ES_J),LALT_T(ES_K),LGUI_T(ES_L),RCTL_T(ES_NTIL),  \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */        \
              ES_Z,       ES_X,       ES_C,       ES_V,       ES_B,                            ES_N,      ES_M,       ES_COMM,    ES_DOT,     ES_MINS,         \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */        \
                                LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_NUM, KC_TAB),       LT(_SYM_1, KC_ENTER), LT(_SYM_2, KC_BSPC),LT(_FN, KC_DEL)        \
    /*                                  '-------------------------------------'                    '-------------------------------------' */

// Simbolos a la izquierda (se activa con el pulgar derecho Enter)
#define SEPIA_SYM_1 \
    /*,---------------------------------------------------------.                    ,---------------------------------------------------------. */      \
            ES_EXLM,     ES_QUES,    ES_LCBR,    ES_RCBR,    ES_PIPE,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
            ES_SLSH,     ES_DQUO,    ES_LPRN,    ES_RPRN,    ES_AMPR,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             ES_AT,      ES_TILD,    ES_LBRC,    ES_RBRC,    ES_CIRC,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
                                            ES_LABK,    ES_RABK,     ES_EQL,                           KC_NO,     KC_NO,       KC_NO                     \
    /*                                  '-------------------------------------'                    '-------------------------------------' */

// Simbolos a la izquierda + navegacion a la derecha (pulgar derecho Bspc)
#define SEPIA_SYM_2 \
    /*,---------------------------------------------------------.                    ,---------------------------------------------------------. */      \
             ES_IEXL,    ES_IQUE,    ES_EURO,    ES_UNDS,    ES_FORD,                          KC_NO,     KC_HOME,     KC_UP,     KC_END,     KC_PGUP,   \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             ES_BSLS,    ES_QUOT,     ES_DLR,    ES_MINS,    ES_MORD,                          KC_NO,     KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_PGDN,   \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             ES_DIAE,    ES_NOT,     ES_BULT,    ES_HASH,     KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
                                              KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO                     \
    /*                                  '-------------------------------------'                    '-------------------------------------' */

// Teclas de funcion (pulgar derecho Del)
#define SEPIA_FN \
    /*,---------------------------------------------------------.                    ,---------------------------------------------------------. */      \
             KC_F1,       KC_F2,      KC_F3,      KC_F4,     KC_PSCR,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             KC_F5,       KC_F6,      KC_F7,      KC_F8,     KC_INS,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             KC_F9,       KC_F10,    KC_F11,      KC_F12,     KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
                                             KC_MENU,     KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO                     \
    /*                                  '-------------------------------------'                    '-------------------------------------' */

// Utilidades a la izquierda y teclado numerico a la derecha (pulgar izquierdo Tab)
#define SEPIA_NUM \
    /*,---------------------------------------------------------.                    ,---------------------------------------------------------. */      \
            HIRAGANA,   KATAKANA,    KC_NO,       KC_NO,      KC_NO,                          ES_ASTR,     ES_7,       ES_8,       ES_9,      ES_PERC,   \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
            KC_CAPS,      LANG,       MAC_WIN,    KC_NO,      KC_NO,                          ES_SLSH,     ES_4,       ES_5,       ES_6,      ES_EQL,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
              UNDO,       CUT,        COPY,       PASTE,      KC_NO,                          ES_PLUS,     ES_1,       ES_2,       ES_3,      ES_HASH,   \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
                                              KC_NO,      KC_NO,      KC_NO,                          ES_MINS,     ES_0,       ES_DOT                    \
    /*                                  '-------------------------------------'                    '-------------------------------------' */

// Funciones a la izquierda y navegacion a la derecha (pulgar izquierdo Space)
#define SEPIA_NAV \
    /*,---------------------------------------------------------.                    ,---------------------------------------------------------. */      \
             KC_F1,       KC_F2,      KC_F3,      KC_F4,     KC_PSCR,                         KC_NO,      KC_HOME,     KC_UP,     KC_END,     KC_PGUP,   \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             KC_F5,       KC_F6,      KC_F7,      KC_F8,     KC_INS,                          KC_NO,      KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_PGDN,   \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             KC_F9,       KC_F10,    KC_F11,      KC_F12,     KC_NO,                          KC_NO,      KC_NO,       KC_NO,     KC_NO,      KC_NO,     \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
                                              KC_NO,      KC_NO,      KC_NO,                          KC_NO,     KC_DELETE,    KC_NO                     \
    /*                                  '-------------------------------------'                    '-------------------------------------' */

// Multimedia (pulgar izquierdo Esc)
#define SEPIA_MEDIA \
    /*,---------------------------------------------------------.                    ,---------------------------------------------------------. */      \
             KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,      KC_NO,    KC_VOLU,     KC_NO,      ES_GRV,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_MPRV,   KC_VOLD,    KC_MNXT,    KC_QUOT,    \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
             KC_NO,       KC_NO,     ES_CCED,     KC_NO,      KC_NO,                           KC_NO,      KC_NO,      KC_NO,     KC_NO,      KC_NO,     \
    /*|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------| */  \
                                              KC_NO,      KC_NO,      KC_NO,                          KC_MSTP,    KC_MPLY,    KC_MUTE                    \
    /*                                  '-------------------------------------'                    '-------------------------------------' */

// Tiempo de tap/hold por tecla: 180 ms en los hold-taps de mods y en los LT de los pulgares,
// 100 ms (TAPPING_TERM) en el resto. TAPPING_TERM_PER_KEY y TAPPING_TERM siguen en config.h.
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
