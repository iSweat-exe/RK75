// RK R75 - Core functionality
// Optimized version without verbose debugging

#include "quantum.h"

#define LED_ENABLE_PIN A5

void keyboard_pre_init_kb(void) {
    // Enable RGB LEDs power
    gpio_set_pin_output(LED_ENABLE_PIN);
    gpio_write_pin_high(LED_ENABLE_PIN);

    // Initialize custom LED indicator pins (Caps Lock is handled by QMK via keyboard.json)
    gpio_set_pin_output(LED_WIN_LOCK_PIN);
    gpio_write_pin_high(LED_WIN_LOCK_PIN);

    gpio_set_pin_output(LED_MAC_PIN);
    gpio_write_pin_high(LED_MAC_PIN);

    keyboard_pre_init_user();
}

// Declare startup animation function
void keyboard_post_init_startup_animation(void);

void keyboard_post_init_kb(void) {
    // Enable RGB Matrix (settings will be loaded from EEPROM)
    rgb_matrix_enable();
    
    // Start boot animation
    keyboard_post_init_startup_animation();
    
    keyboard_post_init_user();
}

void suspend_power_down_kb(void) {
    // Turn off RGB LEDs on suspend
    gpio_write_pin_low(LED_ENABLE_PIN);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    // Turn on RGB LEDs on wake
    gpio_write_pin_high(LED_ENABLE_PIN);
    suspend_wakeup_init_user();
}
