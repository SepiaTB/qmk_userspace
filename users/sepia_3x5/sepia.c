#include "sepia.h"

bool sepia_mac_mode = false;

// Cmd+Tab abierto desde un Alt+Tab de Windows; se cierra al soltar Alt.
static bool app_switcher_active = false;

void set_mac_mode(bool mac) {
    // Suelta todo lo pulsado para no dejar Ctrl o Cmd enganchados al cambiar el intercambio.
    clear_keyboard();
    sepia_mac_mode               = mac;
    keymap_config.swap_lctl_lgui = mac;
    keymap_config.swap_rctl_rgui = mac;
}

void keyboard_post_init_user(void) {
    // El intercambio Ctrl/Cmd puede venir guardado en la EEPROM; arrancamos en Windows hasta detectar el sistema.
    set_mac_mode(false);
}

// Se llama al conectar el USB. Linux y "no sé" se tratan como Windows.
bool process_detected_host_os_user(os_variant_t os) {
    if (os != OS_UNSURE) {
        set_mac_mode(os == OS_MACOS || os == OS_IOS);
    }
    return true;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// Cmd+<tecla> en macOS, Ctrl+<tecla> en Windows.
static void tap_shortcut(uint16_t kc) {
    tap_code16(is_mac() ? G(kc) : C(kc));
}

// Envía otra combinación en lugar de la tecla, respetando pulsar y soltar.
static bool send_instead(uint16_t kc, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code16(kc);
    } else {
        unregister_code16(kc);
    }
    return false;
}

// Keycode que envía la tecla: en LT() y MT() solo cuenta la pulsación corta.
static uint16_t tapped_keycode(uint16_t keycode, keyrecord_t *record) {
    if (IS_QK_LAYER_TAP(keycode) || IS_QK_MOD_TAP(keycode)) {
        return record->tap.count > 0 ? (keycode & 0xFF) : KC_NO;
    }
    return keycode;
}

static bool is_alt_key(uint16_t keycode) {
    if (IS_QK_MOD_TAP(keycode)) {
        return ((keycode >> 8) & MOD_LALT) != 0;
    }
    return keycode == KC_LALT || keycode == KC_RALT;
}

// Tab en modo Mac, para que los atajos de Windows hagan lo mismo:
// - Alt+Tab -> Cmd+Tab. Cmd sigue pulsado hasta soltar Alt, así se pueden recorrer las apps.
// - Ctrl+Tab (que en Mac llega como Cmd) -> Ctrl+Tab real, para cambiar de pestaña.
static bool process_mac_tab(void) {
    uint8_t mods = get_mods();
    if (app_switcher_active || (mods & MOD_MASK_ALT)) {
        if (!app_switcher_active) {
            app_switcher_active = true;
            del_mods(MOD_MASK_ALT);
            register_code(KC_LGUI);
        }
        tap_code(KC_TAB);
        return false;
    }
    if (mods & MOD_MASK_GUI) {
        del_mods(MOD_MASK_GUI);
        tap_code16(C(KC_TAB));
        set_mods(mods);
        return false;
    }
    return true;
}

// Ctrl+Retroceso/Supr de Windows (Cmd en Mac) -> Option+Retroceso/Supr para borrar palabras.
// Solo para las teclas de pulgar con LT(); las normales las cubren los key overrides.
static bool process_mac_word_delete(uint16_t kc) {
    uint8_t mods = get_mods();
    if (!(mods & MOD_MASK_GUI)) {
        return true;
    }
    del_mods(MOD_MASK_GUI);
    tap_code16(A(kc));
    set_mods(mods);
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

    if (app_switcher_active && !record->event.pressed && is_alt_key(keycode)) {
        unregister_code(KC_LGUI);
        app_switcher_active = false;
    }

    switch (keycode) {
        case OS_TOGG:
            if (record->event.pressed) {
                set_mac_mode(!is_mac());
            }
            return false;

        case CUT:
            if (record->event.pressed) tap_shortcut(KC_X);
            return false;

        case COPY:
            if (record->event.pressed) tap_shortcut(KC_C);
            return false;

        case PASTE:
            if (record->event.pressed) tap_shortcut(KC_V);
            return false;

        case UNDO:
            if (record->event.pressed) tap_shortcut(KC_Z);
            return false;

        case LANG:
            if (record->event.pressed) {
                // Cambiar fuente de entrada: Ctrl+Space en macOS, Alt+Shift en Windows
                tap_code16(is_mac() ? C(KC_SPC) : A(KC_LSFT));
            }
            return false;

        case HIRAGANA:
            if (record->event.pressed) {
                // Hiragana: Ctrl+Shift+J en macOS, Shift+Caps Lock en Windows
                tap_code16(is_mac() ? C(S(KC_J)) : S(KC_CAPS));
            }
            return false;

        case KATAKANA:
            if (record->event.pressed) {
                // Katakana: Ctrl+Shift+K en macOS, Alt+Caps Lock en Windows
                tap_code16(is_mac() ? C(S(KC_K)) : A(KC_CAPS));
            }
            return false;

        // Símbolos que en el layout "Spanish - ISO" de macOS están en otra tecla
        case ES_TILD: // Windows AltGr+4, Mac Option+ñ
            return is_mac() ? send_instead(RALT(ES_NTIL), record) : true;

        case ES_EURO: // Windows AltGr+5, Mac Option+E
            return is_mac() ? send_instead(RALT(KC_E), record) : true;
    }

    if (is_mac() && record->event.pressed) {
        switch (tapped_keycode(keycode, record)) {
            case KC_TAB:
                return process_mac_tab();

            case KC_BSPC:
            case KC_DEL:
                if (IS_QK_LAYER_TAP(keycode)) {
                    return process_mac_word_delete(keycode & 0xFF);
                }
                break;
        }
    }

    return true;
}
