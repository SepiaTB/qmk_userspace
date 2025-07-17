#include QMK_KEYBOARD_H
#include "sepia_3x5_common.h"

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

};
