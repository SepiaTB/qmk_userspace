# Código común a todos los keymaps sepia_3x5 (Corne y Charybdis).
# Las capas compartidas (Corne y Charybdis 3x5) están en sepia_keymap.h, que solo incluyen esos
# dos keymaps desde keymap.c; el Charybdis 4x6 no lo usa, por eso no va nada de eso en sepia.c.
# QMK lo incluye automáticamente porque el keymap y esta carpeta se llaman igual.
OS_DETECTION_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

SRC += sepia.c
