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

 // El cable USB va a la mitad DERECHA (la del trackball): el config.h del teclado ya define MASTER_RIGHT.
 // Para usar la mitad izquierda como master, descomentar:
 // #undef MASTER_RIGHT

 // Orientacion del trackball. El teclado ya define POINTING_DEVICE_INVERT_X y
 // ROTATIONAL_TRANSFORM_ANGLE -25 (igual que el 4x6). Si el cursor se mueve mal con
 // el montaje actual, sobrescribir aqui (este config.h se incluye despues del del teclado):
 // #define POINTING_DEVICE_ROTATION_90   // o _180 / _270
 // #define POINTING_DEVICE_INVERT_Y      // o #undef POINTING_DEVICE_INVERT_X
 // #undef ROTATIONAL_TRANSFORM_ANGLE
 // #define ROTATIONAL_TRANSFORM_ANGLE -25  // ajustar el angulo
 
 // Capas 0-6 en users/sepia_3x5/sepia_layers.h
 #define LAYER_POINTER 7
 
 #define TAPPING_TOGGLE 2
 #define TAPPING_FORCE_HOLD_PER_KEY
 #define TAPPING_TERM_PER_KEY
 #define TAPPING_TERM 100
 #undef PERMISSIVE_HOLD
 
 #ifdef VIA_ENABLE
 /* VIA configuration. */
 #    define DYNAMIC_KEYMAP_LAYER_COUNT 8
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
 