#include QMK_KEYBOARD_H
#include "sepia.h"
#include "sepia_key_overrides.h"
#include "sepia_keymap.h"

// Las capas (SEPIA_*) y get_tapping_term() estan en users/sepia_3x5/sepia_keymap.h.
// El wrapper variadico fuerza a expandir la macro de la capa antes de contar los argumentos.
#define LAYOUT_sepia(...) LAYOUT_split_3x5_3(__VA_ARGS__)
// https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_spanish.h#L78


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_sepia(SEPIA_QWERTY),

	[_SYM_1] = LAYOUT_sepia(SEPIA_SYM_1),

	[_SYM_2] = LAYOUT_sepia(SEPIA_SYM_2),
	
	[_FN] = LAYOUT_sepia(SEPIA_FN),

	[_NUM] = LAYOUT_sepia(SEPIA_NUM),

	[_NAV] = LAYOUT_sepia(SEPIA_NAV),
	
	[_MEDIA] = LAYOUT_sepia(SEPIA_MEDIA),

};


//     [_EMPTY] = LAYOUT_split_3x5_3(
//         //,---------------------------------------------------------.                    ,---------------------------------------------------------.
//               KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
//         //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
//               KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
//         //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
//               KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,
//         //|-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------|
//                                                   KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO
//         //                                  '-------------------------------------'                    '-------------------------------------'
//     ),
