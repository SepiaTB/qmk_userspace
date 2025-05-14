###### v3
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no

LTO_ENABLE = yes
EXTRAKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = no

VIA_ENABLE = yes

# START - OLED Enable
OLED_ENABLE = yes
WPM_ENABLE = yes
BONGO_ENABLED = yes 
OPT_DEFS += -DBONGO_ENABLED
SRC += bongo.c
SRC += ./lib/layer_state_reader.c
SRC += ./lib/keylogger.c 
# END - OLED Enable

BOOTLOADER = atmel-dfu
ifeq ($(PROMICRO), yes)
    BOOTLOADER = caterina
endif
