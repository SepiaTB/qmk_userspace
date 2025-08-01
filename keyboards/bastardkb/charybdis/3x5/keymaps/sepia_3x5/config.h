/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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
 #pragma once

 #define MASTER_LEFT
 
 #define _QWERTY 0
 #define _SYM_1 1
 #define _SYM_2 2
 #define _FN 3
 #define _NUM 4
 #define _NAV 5
 #define _MEDIA 6
 #define LAYER_POINTER 7
 
 #define TAPPING_TOGGLE 2
 #define TAPPING_FORCE_HOLD_PER_KEY
 #define TAPPING_TERM_PER_KEY
 #define TAPPING_TERM 100
 #undef PERMISSIVE_HOLD
 
 #ifdef VIA_ENABLE
 /* VIA configuration. */
 #    define DYNAMIC_KEYMAP_LAYER_COUNT 7
 #endif // VIA_ENABLE
 
 #ifndef __arm__
 /* Disable unused features. */
 #    define NO_ACTION_ONESHOT
 #endif // __arm__
 
 /* Charybdis-specific features. */
 
 #ifdef POINTING_DEVICE_ENABLE
 // Automatically enable the pointer layer when moving the trackball.  See also:
 // - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
 // - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
 #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
 #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 1
 #endif // POINTING_DEVICE_ENABLE
 