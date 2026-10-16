#pragma once

// Incluir solo desde keymap.c: QMK busca el array key_overrides en ese fichero.
#include "sepia.h"

// Igual que ko_make_with_layers_and_negmods, pero solo activo en modo Mac.
#define MAC_OVERRIDE(trigger_mods_, trigger_key, replacement_key, negative_mask) \
    ((const key_override_t){                                                     \
        .trigger_mods      = (trigger_mods_),                                    \
        .layers            = ~0,                                                 \
        .suppressed_mods   = (trigger_mods_),                                    \
        .options           = ko_options_default,                                 \
        .negative_mod_mask = (negative_mask),                                    \
        .custom_action     = NULL,                                               \
        .context           = NULL,                                               \
        .trigger           = (trigger_key),                                      \
        .replacement       = (replacement_key),                                  \
        .enabled           = &sepia_mac_mode,                                    \
    })

// En modo Mac la tecla de Ctrl envía Cmd, por eso los atajos de Windows con Ctrl llegan aquí como Cmd (GUI).
static const key_override_t mac_word_left  = MAC_OVERRIDE(MOD_MASK_GUI, KC_LEFT, A(KC_LEFT), 0);  // Ctrl+← -> Option+←
static const key_override_t mac_word_right = MAC_OVERRIDE(MOD_MASK_GUI, KC_RGHT, A(KC_RGHT), 0);  // Ctrl+→ -> Option+→
static const key_override_t mac_word_bspc  = MAC_OVERRIDE(MOD_MASK_GUI, KC_BSPC, A(KC_BSPC), 0);  // Ctrl+Retroceso -> Option+Retroceso
static const key_override_t mac_word_del   = MAC_OVERRIDE(MOD_MASK_GUI, KC_DEL, A(KC_DEL), 0);    // Ctrl+Supr -> Option+Supr
static const key_override_t mac_doc_start  = MAC_OVERRIDE(MOD_MASK_GUI, KC_HOME, G(KC_UP), 0);    // Ctrl+Inicio -> Cmd+↑
static const key_override_t mac_doc_end    = MAC_OVERRIDE(MOD_MASK_GUI, KC_END, G(KC_DOWN), 0);   // Ctrl+Fin -> Cmd+↓
static const key_override_t mac_line_start = MAC_OVERRIDE(0, KC_HOME, G(KC_LEFT), MOD_MASK_GUI);  // Inicio -> Cmd+←
static const key_override_t mac_line_end   = MAC_OVERRIDE(0, KC_END, G(KC_RGHT), MOD_MASK_GUI);   // Fin -> Cmd+→
static const key_override_t mac_screenshot = MAC_OVERRIDE(0, KC_PSCR, G(S(KC_4)), 0);             // ImprPant -> Cmd+Shift+4

const key_override_t *key_overrides[] = {
    &mac_word_left,
    &mac_word_right,
    &mac_word_bspc,
    &mac_word_del,
    &mac_doc_start,
    &mac_doc_end,
    &mac_line_start,
    &mac_line_end,
    &mac_screenshot,
};
