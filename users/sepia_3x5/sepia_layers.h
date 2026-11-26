#pragma once

// Numeros de capa de los keymaps sepia_3x5 del Corne y del Charybdis 3x5+3.
// Solo defines: se puede incluir desde cualquier .c (oled, rgb_layers, bongo...).
// NO incluir desde el Charybdis 4x6, que tiene su propia numeracion (sin _FN).
// Las capas extra de cada teclado (p. ej. LAYER_POINTER = 7 en el Charybdis) van en su config.h.
#define _QWERTY 0
#define _SYM_1 1
#define _SYM_2 2
#define _FN 3
#define _NUM 4
#define _NAV 5
#define _MEDIA 6
