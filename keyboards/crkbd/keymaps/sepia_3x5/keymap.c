#include "sepia_3x5.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x5_3( SEPIA_LAYOUT_QWERTY() ),
    [_SYM_1] = LAYOUT_split_3x5_3( SEPIA_LAYOUT_SYM_1() ),
    [_SYM_2] = LAYOUT_split_3x5_3( SEPIA_LAYOUT_SYM_2() ),
    [_FN] = LAYOUT_split_3x5_3( SEPIA_LAYOUT_FN() ),
    [_NUM] = LAYOUT_split_3x5_3( SEPIA_LAYOUT_NUM() ),
    [_NAV] = LAYOUT_split_3x5_3( SEPIA_LAYOUT_NAV() ),
    [_MEDIA] = LAYOUT_split_3x5_3( SEPIA_LAYOUT_MEDIA() ),
};


