# Charybdis 3x5+3 Custom Keyboard Definition

## Overview

This is a custom QMK keyboard definition for the **Charybdis 3x5+3** - a modified Charybdis keyboard with an additional thumb key per side (36 keys total instead of the standard 35).

### Hardware Specifications
- **Layout**: 3x5+3 (3 rows × 5 columns + 3 thumb keys per side)
- **Total Keys**: 36 keys
- **Trackball**: Cirque Pinnacle (right side)
- **MCU**: RP2040 (modern ARM processor)
- **Features**: Split keyboard, RGB matrix, pointing device
- **Connectivity**: USB-C, TRRS for split communication

## The Problem

The standard QMK repository contains two relevant keyboards, but neither matches this hardware exactly:

| Keyboard | Layout | Trackball | Keys | Issue |
|----------|--------|-----------|------|-------|
| `bastardkb/skeletyl` | 3x5+3 ✅ | No ❌ | 36 | Missing trackball support |
| `bastardkb/charybdis/3x5` | 3x5+2 ❌ | Yes ✅ | 35 | Wrong key count |

### Compilation Error
When trying to use `bastardkb/charybdis/3x5` with a 36-key keymap:

```
error: macro "LAYOUT" passed 36 arguments, but takes just 35
```

## The Solution

Create a **hybrid keyboard definition** that combines:
- **Layout structure** from Skeletyl (3x5+3, 36 keys)
- **Trackball features** from Charybdis (pointing device, RGB, etc.)
- **Modern hardware support** (RP2040 processor)

## Architecture

```
┌─────────────────────┐    ┌──────────────────────┐    ┌─────────────────────────┐
│   Skeletyl 3x5+3    │    │   Charybdis 3x5+2    │    │   Custom 3x5+3         │
│                     │    │                      │    │                         │
│ • 36 keys           │ +  │ • Trackball          │ =  │ • 36 keys               │
│ • LAYOUT_split_3x5_3│    │ • RGB Matrix         │    │ • LAYOUT_split_3x5_3    │
│ • Split keyboard    │    │ • Pointing device    │    │ • Trackball             │
│ • No trackball      │    │ • 35 keys only       │    │ • RGB Matrix            │
└─────────────────────┘    └──────────────────────┘    └─────────────────────────┘
```

## File Structure

```
keyboards/bastardkb/charybdis/3x5_3/
├── keyboard.json          # Hardware definition & layout
├── config.h              # Trackball & RGB configuration  
├── rules.mk              # Feature enablement
└── keymaps/
    └── sepia_3x5/         # Example keymap
        ├── keymap.c       # Key layout definition
        ├── config.h       # Keymap-specific settings
        └── rules.mk       # Keymap build options
```

## Key Implementation Details

### 1. Layout Definition (keyboard.json)

The core innovation is defining a native `LAYOUT_split_3x5_3` macro with 36 key positions:

```json
"layouts": {
    "LAYOUT_split_3x5_3": {
        "layout": [
            // Main keys: 3 rows × 5 columns per side (30 keys)
            {"matrix": [0, 0], "x": 0, "y": 0},  // Q
            {"matrix": [0, 1], "x": 1, "y": 0},  // W
            // ... (30 main keys)
            
            // Thumb cluster: 3 keys per side (6 keys)
            {"matrix": [3, 2], "x": 3, "y": 3},  // Left thumb 1
            {"matrix": [3, 3], "x": 4, "y": 3},  // Left thumb 2  
            {"matrix": [3, 4], "x": 5, "y": 3},  // Left thumb 3
            {"matrix": [7, 4], "x": 7, "y": 3},  // Right thumb 1
            {"matrix": [7, 3], "x": 8, "y": 3},  // Right thumb 2
            {"matrix": [7, 2], "x": 9, "y": 3}   // Right thumb 3
        ]
    }
}
```

### 2. Hardware Configuration (config.h)

Trackball and pointing device settings from Charybdis:

```c
// Split pointing device on right side
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define POINTING_DEVICE_ROTATION_90

// Cirque trackpad calibration
#define CIRQUE_PINNACLE_X_LOWER 127
#define CIRQUE_PINNACLE_X_UPPER 1919
#define CIRQUE_PINNACLE_Y_LOWER 63
#define CIRQUE_PINNACLE_Y_UPPER 1471

// RGB Matrix configuration
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
```

### 3. Feature Enablement (rules.mk)

```makefile
# Core features
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
RGB_MATRIX_ENABLE = yes
SERIAL_DRIVER = vendor

# Optimizations  
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
```

## Usage

### 1. QMK Userspace Setup

Add to your `qmk.json`:

```json
{
    "userspace_version": "1.0",
    "build_targets": [
        [
            "bastardkb/charybdis/3x5_3",
            "your_keymap_name"
        ]
    ]
}
```

### 2. Compilation

```bash
# Compile all userspace keyboards
qmk userspace-compile

# Or compile specific keyboard
qmk compile -kb bastardkb/charybdis/3x5_3 -km your_keymap_name
```

### 3. Keymap Development

Your keymaps can use `LAYOUT_split_3x5_3` natively:

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        // Row 1: 10 keys
        KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P,
        // Row 2: 10 keys  
        KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        // Row 3: 10 keys
        KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        // Thumb cluster: 6 keys (3 per side)
                KC_ESC, KC_SPC, KC_TAB,    KC_ENT, KC_BSPC, KC_DEL
    ),
};
```

## Trackball Features

All Charybdis trackball features are supported:

- **Auto Pointer Layer**: Automatically activates when trackball moves
- **Sniping Mode**: Precision mode for detailed work  
- **Drag Scroll**: Scroll mode for document navigation
- **DPI Switching**: Multiple sensitivity levels
- **Custom Keycodes**: `DPI_MOD`, `SNIPING`, `DRGSCRL`, etc.

## Compatibility

### Hardware Requirements
- Charybdis 3x5 PCB with 3+3 thumb key modification
- RP2040-based controller (Splinky, Elite-Pi, etc.)
- Cirque Pinnacle trackball module
- Compatible with standard Charybdis cases and plates

### Software Requirements  
- QMK Userspace (recommended) or QMK firmware with custom keyboard
- ARM toolchain for RP2040 compilation

## Troubleshooting

### Common Issues

**"Invalid keyboard" error**:
- Ensure you're using QMK userspace, not standard QMK
- Verify the keyboard files are in the correct directory

**"macro passed 36 arguments, but takes just 35"**:
- You're using the wrong keyboard target  
- Use `bastardkb/charybdis/3x5_3` not `bastardkb/charybdis/3x5`

**Trackball not working**:
- Check `POINTING_DEVICE_ENABLE = yes` in rules.mk
- Verify trackball wiring and driver configuration
- Ensure `SPLIT_POINTING_ENABLE` is defined

## Credits

- **Original Charybdis design**: [Bastard Keyboards](https://bastardkb.com/)
- **QMK Firmware**: [QMK Community](https://qmk.fm/)
- **QMK Firmware Skeletyl**: [Keyboard definition](https://github.com/qmk/qmk_firmware/tree/master/keyboards/bastardkb/skeletyl)
- **QMK Firmware Charybdis**: [Keyboard definition](https://github.com/qmk/qmk_firmware/tree/master/keyboards/bastardkb/charybdis/3x5)
- **Inspiration**: BastardKB documentation suggesting to "base firmware off charybdis/3x5 and copy keymap from Skeletyl for third thumb key"

## License

This keyboard definition follows the same GPL v2+ license as QMK firmware.

---

**Note**: This is a custom keyboard definition for specific hardware. If you have standard Charybdis 3x5 hardware (35 keys), use the official `bastardkb/charybdis/3x5` definition instead.