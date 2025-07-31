# Custom QMK Keyboard Development Guide

## Overview

This guide covers creating a QMK firmware fork for custom keyboard development, managing multiple QMK repositories, and setting up automated builds.

## Table of Contents

1. [Phase 1: QMK Firmware Fork Setup](#phase-1-qmk-firmware-fork-setup)
2. [Phase 2: Custom Keyboard Implementation](#phase-2-custom-keyboard-implementation)
3. [Phase 3: GitHub Actions Setup](#phase-3-github-actions-setup)
4. [Phase 4: Local Development Workflow](#phase-4-local-development-workflow)
5. [Future Plans: Integration Strategies](#future-plans-integration-strategies)

---

## Phase 1: QMK Firmware Fork Setup

### Step 1: Fork QMK Firmware Repository

1. **Navigate to QMK Firmware**
   ```bash
   # Visit: https://github.com/qmk/qmk_firmware
   # Click "Fork" button
   ```

2. **Clone your fork locally**
   ```bash
   git clone https://github.com/YOUR_USERNAME/qmk_firmware.git
   cd qmk_firmware
   ```

3. **Add upstream remote**
   ```bash
   git remote add upstream https://github.com/qmk/qmk_firmware.git
   git fetch upstream
   ```

### Step 2: Setup QMK Development Environment

1. **Install QMK CLI** (if not already installed)
   ```bash
   # Windows (QMK MSYS)
   # Download from: https://github.com/qmk/qmk_distro_msys/releases
   
   # Or via pip
   pip install qmk
   ```

2. **Configure QMK**
   ```bash
   qmk setup
   # Point to your fork: /path/to/your/qmk_firmware
   ```

3. **Verify setup**
   ```bash
   qmk doctor
   ```

---

## Phase 2: Custom Keyboard Implementation

### Step 1: Create Custom Keyboard Directory Structure

```bash
# In your qmk_firmware fork
mkdir -p keyboards/bastardkb/charybdis/3x5_3
cd keyboards/bastardkb/charybdis/3x5_3
```

### Step 2: Create Keyboard Definition Files

1. **Create `keyboard.json`**
   ```json
   {
       "keyboard_name": "Charybdis 3x5+3",
       "manufacturer": "Bastard Keyboards",
       "url": "https://bastardkb.com/",
       "maintainer": "Charly Delay",
       "usb": {
           "vid": "0xA8F8",
           "pid": "0x1832",
           "device_version": "0.0.1"
       },
       "features": {
           "bootmagic": true,
           "command": false,
           "console": false,
           "extrakey": true,
           "mousekey": true,
           "nkro": true,
           "rgb_matrix": true,
           "pointing_device": true
       },
       "mouse_key": {
           "enabled": true
       },
       "pointing_device": {
           "driver": "cirque_pinnacle_spi"
       },
       "rgb_matrix": {
           "driver": "ws2812"
       },
       "matrix_pins": {
           "cols": [
               "GP28", "GP21", "GP22", "GP26", "GP27"
           ],
           "rows": [
               "GP4", "GP5", "GP6", "GP7"
           ]
       },
       "diode_direction": "COL2ROW",
       "split": {
           "enabled": true,
           "matrix_pins": {
               "right": {
                   "cols": [
                       "GP28", "GP21", "GP22", "GP26", "GP27"
                   ],
                   "rows": [
                       "GP4", "GP5", "GP6", "GP7"
                   ]
               }
           },
           "transport": {
               "protocol": "serial",
               "pin": "GP1"
           }
       },
       "processor": "RP2040",
       "bootloader": "rp2040",
       "layouts": {
           "LAYOUT_split_3x5_3": {
               "layout": [
                   {"matrix": [0, 0], "x": 0, "y": 0}, {"matrix": [0, 1], "x": 1, "y": 0}, {"matrix": [0, 2], "x": 2, "y": 0}, {"matrix": [0, 3], "x": 3, "y": 0}, {"matrix": [0, 4], "x": 4, "y": 0},
                   {"matrix": [4, 4], "x": 8, "y": 0}, {"matrix": [4, 3], "x": 9, "y": 0}, {"matrix": [4, 2], "x": 10, "y": 0}, {"matrix": [4, 1], "x": 11, "y": 0}, {"matrix": [4, 0], "x": 12, "y": 0},
                   {"matrix": [1, 0], "x": 0, "y": 1}, {"matrix": [1, 1], "x": 1, "y": 1}, {"matrix": [1, 2], "x": 2, "y": 1}, {"matrix": [1, 3], "x": 3, "y": 1}, {"matrix": [1, 4], "x": 4, "y": 1},
                   {"matrix": [5, 4], "x": 8, "y": 1}, {"matrix": [5, 3], "x": 9, "y": 1}, {"matrix": [5, 2], "x": 10, "y": 1}, {"matrix": [5, 1], "x": 11, "y": 1}, {"matrix": [5, 0], "x": 12, "y": 1},
                   {"matrix": [2, 0], "x": 0, "y": 2}, {"matrix": [2, 1], "x": 1, "y": 2}, {"matrix": [2, 2], "x": 2, "y": 2}, {"matrix": [2, 3], "x": 3, "y": 2}, {"matrix": [2, 4], "x": 4, "y": 2},
                   {"matrix": [6, 4], "x": 8, "y": 2}, {"matrix": [6, 3], "x": 9, "y": 2}, {"matrix": [6, 2], "x": 10, "y": 2}, {"matrix": [6, 1], "x": 11, "y": 2}, {"matrix": [6, 0], "x": 12, "y": 2},
                   {"matrix": [3, 2], "x": 3, "y": 3}, {"matrix": [3, 3], "x": 4, "y": 3}, {"matrix": [3, 4], "x": 5, "y": 3},
                   {"matrix": [7, 4], "x": 7, "y": 3}, {"matrix": [7, 3], "x": 8, "y": 3}, {"matrix": [7, 2], "x": 9, "y": 3}
               ]
           }
       }
   }
   ```

2. **Create `config.h`**
   ```c
   #pragma once
   #define MASTER_LEFT
   #define SPLIT_POINTING_ENABLE
   #define POINTING_DEVICE_RIGHT
   #define POINTING_DEVICE_TASK_THROTTLE_MS 1
   #define POINTING_DEVICE_ROTATION_90
   #define CIRQUE_PINNACLE_X_LOWER 127
   #define CIRQUE_PINNACLE_X_UPPER 1919
   #define CIRQUE_PINNACLE_Y_LOWER 63
   #define CIRQUE_PINNACLE_Y_UPPER 1471
   #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64
   #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
   #define TAPPING_TOGGLE 2
   #define TAPPING_FORCE_HOLD_PER_KEY
   #define TAPPING_TERM_PER_KEY
   #define TAPPING_TERM 100
   #undef PERMISSIVE_HOLD
   #ifdef VIA_ENABLE
   #    define DYNAMIC_KEYMAP_LAYER_COUNT 8
   #endif // VIA_ENABLE
   #ifndef __arm__
   #    define NO_ACTION_ONESHOT
   #endif // __arm__
   #ifdef POINTING_DEVICE_ENABLE
   #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
   #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 1
   #endif // POINTING_DEVICE_ENABLE
   ```

3. **Create `rules.mk`**
   ```makefile
   POINTING_DEVICE_ENABLE = yes
   POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
   RGB_MATRIX_ENABLE = yes
   SERIAL_DRIVER = vendor
   COMMAND_ENABLE = no
   CONSOLE_ENABLE = no
   ```

### Step 3: Create Keymap

1. **Create keymap directory**
   ```bash
   mkdir -p keyboards/bastardkb/charybdis/3x5_3/keymaps/sepia_3x5
   cd keyboards/bastardkb/charybdis/3x5_3/keymaps/sepia_3x5
   ```

2. **Copy your existing keymap files**
   ```bash
   # Copy from your userspace
   cp /path/to/qmk_userspace/keyboards/bastardkb/charybdis/3x5_3/keymaps/sepia_3x5/* .
   ```

3. **Update keymap.c to use correct layout**
   ```c
   // In keymap.c, ensure all layers use:
   LAYOUT_split_3x5_3(
       // Your key definitions here
   )
   ```

---

## Phase 3: GitHub Actions Setup

### Step 1: Create GitHub Actions Workflow

Create `.github/workflows/build.yml`:

```yaml
name: Build QMK Firmware

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]
  workflow_dispatch:

jobs:
  build:
    runs-on: ubuntu-latest
    strategy:
      fail-fast: false
      matrix:
        keyboard:
          - bastardkb/charybdis/3x5_3
        keymap:
          - sepia_3x5

    steps:
    - name: Checkout QMK Firmware
      uses: actions/checkout@v4
      with:
        submodules: true

    - name: Setup QMK Environment
      uses: qmk/setup-qmk@v1
      with:
        platform: linux

    - name: Build Firmware
      run: |
        qmk compile -kb ${{ matrix.keyboard }} -km ${{ matrix.keymap }}

    - name: Upload Firmware
      uses: actions/upload-artifact@v4
      with:
        name: ${{ matrix.keyboard }}_${{ matrix.keymap }}
        path: |
          *.hex
          *.bin
          *.uf2
        retention-days: 30
```

### Step 2: Test Local Build

```bash
# Test your custom keyboard
qmk compile -kb bastardkb/charybdis/3x5_3 -km sepia_3x5

# Should create firmware files
```

---

## Phase 4: Local Development Workflow

### Daily Development Workflow

1. **Sync with upstream**
   ```bash
   git fetch upstream
   git checkout main
   git merge upstream/main
   ```

2. **Make changes**
   ```bash
   git checkout -b feature/new-keyboard
   # Edit files
   git add .
   git commit -m "Add new keyboard feature"
   ```

3. **Test locally**
   ```bash
   qmk compile -kb bastardkb/charybdis/3x5_3 -km sepia_3x5
   ```

4. **Push and create PR**
   ```bash
   git push origin feature/new-keyboard
   # Create PR on GitHub
   ```

### Adding New Custom Keyboards

1. **Create new keyboard directory**
   ```bash
   mkdir -p keyboards/manufacturer/keyboard_name
   ```

2. **Add keyboard definition files**
   - `keyboard.json`
   - `config.h`
   - `rules.mk`

3. **Add keymap**
   ```bash
   mkdir -p keyboards/manufacturer/keyboard_name/keymaps/sepia_3x5
   # Copy keymap files
   ```

4. **Update GitHub Actions matrix**
   ```yaml
   matrix:
     keyboard:
       - bastardkb/charybdis/3x5_3
       - manufacturer/keyboard_name  # Add new keyboard
     keymap:
       - sepia_3x5
   ```

---

## Future Plans: Integration Strategies

### Current State (Separated)
```
qmk_userspace/          # Community keyboards
├── keyboards/bastardkb/charybdis/4x6/keymaps/sepia_3x5/
├── keyboards/crkbd/keymaps/sepia_3x5/
└── .github/workflows/build_binaries.yaml

qmk_firmware/           # Custom keyboards
├── keyboards/bastardkb/charybdis/3x5_3/
└── .github/workflows/build.yml
```

### Future State (Integrated)

#### Option A: Single QMK Fork with Multiple Actions

```yaml
# .github/workflows/build_standard.yml
jobs:
  build:
    uses: qmk/.github/.github/workflows/qmk_userspace_build.yml@main
    with:
      qmk_repo: qmk/qmk_firmware
      qmk_ref: master

# .github/workflows/build_bastardkb.yml  
jobs:
  build:
    uses: qmk/.github/.github/workflows/qmk_userspace_build.yml@main
    with:
      qmk_repo: bastardkb/bastardkb-qmk
      qmk_ref: bkb-master

# .github/workflows/build_custom.yml
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - uses: qmk/setup-qmk@v1
      - run: qmk compile -kb bastardkb/charybdis/3x5_3 -km sepia_3x5
```

#### Option B: Submodule Approach

```bash
# In single QMK fork
git submodule add https://github.com/bastardkb/bastardkb-qmk.git keyboards/bastardkb
git submodule add https://github.com/qmk/qmk_firmware.git keyboards/standard
```

#### Option C: Unified Repository Structure

```
unified-qmk/
├── keyboards/
│   ├── custom/
│   │   └── bastardkb/charybdis/3x5_3/
│   ├── community/
│   │   ├── bastardkb/charybdis/4x6/keymaps/sepia_3x5/
│   │   └── crkbd/keymaps/sepia_3x5/
│   └── external/
│       └── [submodules for different QMK forks]
├── .github/workflows/
│   ├── build_custom.yml
│   ├── build_community.yml
│   └── build_external.yml
└── README.md
```

### Migration Steps (Future)

1. **Phase 1**: Keep current separated setup
2. **Phase 2**: Create unified repository structure
3. **Phase 3**: Migrate community keyboards to unified repo
4. **Phase 4**: Set up multiple GitHub Actions workflows
5. **Phase 5**: Archive old repositories

---

## Troubleshooting

### Common Issues

1. **Build fails with "Invalid keyboard"**
   - Ensure keyboard path matches directory structure
   - Check `keyboard.json` syntax

2. **GitHub Actions fails**
   - Verify workflow syntax
   - Check matrix configuration
   - Ensure all required files exist

3. **Local build fails**
   - Run `qmk doctor` to check environment
   - Verify QMK CLI setup points to correct repository

### Getting Help

- **QMK Documentation**: https://docs.qmk.fm/
- **QMK Discord**: https://discord.gg/qmk
- **GitHub Issues**: Create issues in your fork for tracking

---

## Summary

This guide provides a complete workflow for:
- ✅ Creating custom QMK keyboards
- ✅ Managing multiple QMK repositories
- ✅ Setting up automated builds
- ✅ Planning future integration

Start with Phase 1-4 for immediate implementation, then use the Future Plans section when ready to consolidate your workflow. 


---

## References

- **QMK Firmware Skeletyl**: [Keyboard definition](https://github.com/qmk/qmk_firmware/tree/master/keyboards/bastardkb/skeletyl)
- **QMK Firmware Charybdis**: [Keyboard definition](https://github.com/qmk/qmk_firmware/tree/master/keyboards/bastardkb/charybdis/3x5)