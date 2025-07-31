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

/* Pointing device configuration. */

// Enable use of pointing device on slave split.
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define POINTING_DEVICE_ROTATION_90

// Cirque trackpad driver configuration.
#define CIRQUE_PINNACLE_X_LOWER 127
#define CIRQUE_PINNACLE_X_UPPER 1919
#define CIRQUE_PINNACLE_Y_LOWER 63
#define CIRQUE_PINNACLE_Y_UPPER 1471
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define CIRQUE_PINNACLE_TAP_ENABLE

/* RGB Matrix. */
#ifdef RGB_MATRIX_ENABLE
// Limit maximum brightness to keep power consumption reasonable, and avoid
// disconnects.
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64

// Rainbow swirl as startup mode.
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

// Slow swirl at startup.
#    define RGB_MATRIX_DEFAULT_SPD 32

// Startup values.
#    define RGB_MATRIX_DEFAULT_HUE 0
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif // RGB_MATRIX_ENABLE