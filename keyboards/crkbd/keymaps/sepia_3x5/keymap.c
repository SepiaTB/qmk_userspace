#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
// https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_spanish.h#L78

enum custom_keycodes {
	CUT = SAFE_RANGE,
	COPY,
	PASTE,
	UNDO,
	LANG,
	HIRAGANA,
	KATAKANA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
			  KC_NO,      ES_Q,       ES_W,       ES_E,       ES_R,       ES_T,                            ES_Y,      ES_U,        ES_I,       ES_O,       ES_P,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,  LCTL_T(ES_A),LGUI_T(ES_S),LALT_T(ES_D),LSFT_T(ES_F),ES_G,                            ES_H,  RSFT_T(ES_J),LALT_T(ES_K),LGUI_T(ES_L),RCTL_T(ES_NTIL),KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,      ES_Z,       ES_X,       ES_C,       ES_V,       ES_B,                            ES_N,      ES_M,       ES_COMM,    ES_DOT,     ES_MINS,    KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
									LT(_MEDIA, KC_ESC), LT(_NAV, KC_SPC), LT(_NUM, KC_TAB),       LT(_SYM_1, KC_ENTER), LT(_SYM_2, KC_BSPC),LT(_FN, KC_DEL)
		//                                  '-------------------------------------'                    '-------------------------------------'
	),

	[_SYM_1] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
			  KC_NO,    ES_EXLM,     ES_QUES,    ES_LCBR,    ES_RCBR,    ES_PIPE,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,    ES_SLSH,     ES_DQUO,    ES_LPRN,    ES_RPRN,    ES_AMPR,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     ES_AT,      ES_TILD,    ES_LBRC,    ES_RBRC,    ES_CIRC,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
												ES_LABK,    ES_RABK,     ES_EQL,                           KC_NO,     KC_NO,       KC_NO
		//                                  '-------------------------------------'                    '-------------------------------------'
	),

	[_SYM_2] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
			  KC_NO,     ES_IEXL,    ES_IQUE,    ES_EURO,    ES_UNDS,    ES_FORD,                          KC_NO,     KC_HOME,     KC_UP,     KC_END,     KC_PGUP,     KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     ES_BSLS,    ES_QUOT,     ES_DLR,    ES_MINS,    ES_MORD,                          KC_NO,     KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_PGDN,     KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     ES_DIAE,    ES_NOT,     ES_BULT,    ES_HASH,     KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
												  KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO
		//                                  '-------------------------------------'                    '-------------------------------------'
	),
	
	[_FN] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
			  KC_NO,     KC_F1,       KC_F2,      KC_F3,      KC_F4,     KC_PSCR,                          KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     KC_F5,       KC_F6,      KC_F7,      KC_F8,     KC_INS,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     KC_F9,       KC_F10,    KC_F11,      KC_F12,     KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
												 KC_MENU,     KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO
		//                                  '-------------------------------------'                    '-------------------------------------'
	),

	[_NUM] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
			  KC_NO,    HIRAGANA,   KATAKANA,    KC_NO,       KC_NO,      KC_NO,                          ES_ASTR,     ES_7,       ES_8,       ES_9,      ES_PERC,     KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,    KC_CAPS,      LANG,       KC_NO,      KC_NO,      KC_NO,                          ES_SLSH,     ES_4,       ES_5,       ES_6,      ES_EQL,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,      UNDO,       CUT,        COPY,       PASTE,      KC_NO,                          ES_PLUS,     ES_1,       ES_2,       ES_3,      ES_HASH,     KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
												  KC_NO,      KC_NO,      KC_NO,                          ES_MINS,     ES_0,       ES_DOT
		//                                  '-------------------------------------'                    '-------------------------------------'
	),

	[_NAV] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
			  KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                          KC_NO,      KC_HOME,     KC_UP,     KC_END,     KC_PGUP,     KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                          KC_NO,      KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_PGDN,     KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                          KC_NO,      KC_NO,       KC_NO,     KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
												  KC_NO,      KC_NO,      KC_NO,                          KC_NO,      KC_NO,       KC_NO
		//                                  '-------------------------------------'                    '-------------------------------------'
	),
	
	[_MEDIA] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
			  KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,      KC_NO,    KC_VOLU,     KC_NO,      ES_GRV,     KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_MPRV,   KC_VOLD,    KC_MNXT,    KC_QUOT,     KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
			  KC_NO,     KC_NO,       KC_NO,     ES_CCED,     KC_NO,      KC_NO,                           KC_NO,      KC_NO,      KC_NO,     KC_NO,      KC_NO,      KC_NO,
		//|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
												  KC_NO,      KC_NO,      KC_NO,                          KC_MSTP,    KC_MPLY,    KC_MUTE
		//                                  '-------------------------------------'                    '-------------------------------------'
	),

};


//     [_EMPTY] = LAYOUT_split_3x6_3(
//         //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
//               KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
//         //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
//               KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
//         //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
//               KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO,      KC_NO,      KC_NO,      KC_NO,
//         //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
//                                                   KC_NO,      KC_NO,      KC_NO,                           KC_NO,     KC_NO,       KC_NO
//         //                                  '-------------------------------------'                    '-------------------------------------'
//     ),



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
