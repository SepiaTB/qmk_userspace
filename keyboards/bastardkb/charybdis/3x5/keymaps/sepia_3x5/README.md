# Charybdis 3x5+3 Sepia Layout

A custom QMK keymap for the Charybdis 3x5+3 keyboard based on the sepia_3x5 layout originally designed for the Corne keyboard.

## Layout Features

- **3x5+3 Layout**: 3 rows × 5 columns + 3 thumb keys on each side (36 keys total)
- **Spanish Keymap**: Uses Spanish key codes for proper localization
- **Home Row Mods**: GACS (Gui, Alt, Ctrl, Shift) modifiers on home row
- **Layer Tap**: Thumb keys activate different layers when held
- **Trackball Support**: Full Charybdis trackball integration with automatic pointer layer
- **Custom Keycodes**: Cut, Copy, Paste, Undo, and language switching

## Layers

1. **QWERTY** (_QWERTY): Base layer with Spanish QWERTY layout
2. **SYM_1** (_SYM_1): Primary symbols layer
3. **SYM_2** (_SYM_2): Secondary symbols and navigation
4. **FN** (_FN): Function keys
5. **NUM** (_NUM): Number pad and utility functions
6. **NAV** (_NAV): Navigation and function keys
7. **MEDIA** (_MEDIA): Media controls
8. **POINTER** (LAYER_POINTER): Trackball and mouse functions

## Thumb Key Layout

Left hand (from left to right):
- **ESC**/Media: Escape key, Media layer when held
- **Space**/Nav: Space key, Navigation layer when held  
- **Tab**/Num: Tab key, Number layer when held

Right hand (from left to right):
- **Enter**/Sym1: Enter key, Primary symbols layer when held
- **Backspace**/Sym2: Backspace key, Secondary symbols layer when held
- **Delete**/Fn: Delete key, Function layer when held

## Trackball Features

- **Auto Pointer Layer**: Automatically activates pointer layer when trackball moves
- **Sniping Mode**: Precision mode for detailed work
- **Drag Scroll**: Scroll mode for document navigation
- **DPI Switching**: Multiple DPI levels for different use cases

## Building

This keymap is designed to work with the Charybdis 3x5+3 keyboard configuration. Make sure you have the appropriate keyboard definition that supports the `LAYOUT_split_3x5_3` macro.

## Customization

The keymap is organized for easy customization:
- Layer definitions are clearly separated
- Tapping terms are configurable per key
- Charybdis-specific features can be enabled/disabled
- VIA support for real-time customization

## Credits

Based on the original sepia_3x5 layout for Corne keyboard and adapted for Charybdis 3x5+3 with trackball support.