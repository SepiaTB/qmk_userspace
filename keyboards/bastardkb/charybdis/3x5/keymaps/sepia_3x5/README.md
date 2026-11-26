# Charybdis 3x5+3 Sepia

Keymap sepia_3x5 de 36 teclas para un Charybdis 3x5+3 propio, montado con PCBs Skeletyl
(flex 3x5 rev 2.3 + flex de 3 pulgares TBK-Mini en ambas mitades), controladores Splinky (RP2040)
y el sensor PMW3360 de BastardKB (trackball en la mitad derecha).

## Firmware

- Se compila contra el teclado existente `bastardkb/charybdis/3x5` (matriz 8x5, LAYOUT oficial de 35 teclas).
- La tecla 36 (pulgar central derecho) es la posicion de matriz [7,3], que el LAYOUT oficial deja
  en KC_NO pero que la flex de pulgares del Skeletyl cablea. Por eso `keymap.c` define su propia
  macro `LAYOUT_charybdis_3x5_3` (mismo orden que `LAYOUT_split_3x5_3`).
- Capas: QWERTY, SYM_1, SYM_2, FN, NUM, NAV, MEDIA y POINTER (trackball, se activa al mover la bola).

## Notas

- El cable USB va en la mitad derecha (la del trackball). Para usar la izquierda como master,
  descomentar `#undef MASTER_RIGHT` en `config.h`.
- La orientacion del trackball puede necesitar calibracion segun como este montado; ver los
  comentarios en `config.h` (rotacion, inversion de ejes, angulo).
- VIA reconoce la placa como un Charybdis Nano de 35 teclas: la tecla 36 funciona con el keycode
  compilado, pero VIA no puede editarla sin una definicion propia.
- Los LEDs RGB de los pulgares pueden encenderse en un orden distinto al fisico (solo estetico).

## Compilar

    qmk compile -kb bastardkb/charybdis/3x5 -km sepia_3x5

El codigo comun esta en `users/sepia_3x5` (sepia.c, overrides de teclas, deteccion de sistema).
