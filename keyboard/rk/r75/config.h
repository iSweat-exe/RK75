#pragma once

#define MATRIX_ROWS 6
#define MATRIX_COLS 15
#define DEBOUNCE 5
#define COMBO_TERM 200
#define COMBO_ALLOW_ACTION_KEYS

// LED Indicator Pins
// #define LED_CAPS_LOCK_PIN C4 // defined in keyboard.json
#define LED_WIN_LOCK_PIN B9
#define LED_MAC_PIN B8

// RGB Matrix Configuration (most settings are in keyboard.json)
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

// SPI 
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN B3
#define SPI_MOSI_PIN B5
#define SPI_MISO_PIN B4

// RGB Matrix 
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

// WS2812
#define WS2812_SPI_DRIVER SPIDM2
#define WS2812_SPI_DIVISOR 32

// Set defaults for LED matrix
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
