#pragma once

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// Teclas propias compartidas por todos los keymaps.
enum sepia_keycodes {
    CUT = SAFE_RANGE,
    COPY,
    PASTE,
    UNDO,
    LANG,
    HIRAGANA,
    KATAKANA,
    MAC_WIN, // Alterna a mano entre modo Mac y modo Windows
    KEYMAP_SAFE_RANGE,
};

// Modo Mac activo. Lo fija la detección de sistema al conectar el USB o la tecla MAC_WIN.
// En modo Mac se intercambian Ctrl <-> Cmd para que los atajos se hagan con los mismos dedos que en Windows.
extern bool sepia_mac_mode;

static inline bool is_mac(void) {
    return sepia_mac_mode;
}

void set_mac_mode(bool mac);

// Cada keymap puede definir esta función para gestionar sus propias teclas.
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
