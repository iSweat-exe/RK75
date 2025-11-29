// RGB Startup Animation for RK R75
#include "quantum.h"
#include "color.h"

static bool startup_animation_done = false;
static uint16_t startup_timer = 0;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Skip if animation is done
    if (startup_animation_done) {
        return false;
    }
    
    // Run animation for 0.85 seconds after boot
    uint16_t elapsed = timer_elapsed(startup_timer);
    if (elapsed > 850) {
        startup_animation_done = true;
        return false;
    }
    
    // Rainbow wave animation from left to right
    uint8_t wave_pos = (elapsed / 10) % RGB_MATRIX_LED_COUNT;
    
    for (uint8_t i = led_min; i < led_max; i++) {
        int8_t distance = abs((int8_t)i - (int8_t)wave_pos);
        
        if (distance < 10) {
            uint8_t hue = (i * 255 / RGB_MATRIX_LED_COUNT) + (elapsed / 10);
            uint8_t val = 255 - (distance * 25);
            RGB rgb = hsv_to_rgb((HSV){hue, 255, val});
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    
    return false;
}

void keyboard_post_init_startup_animation(void) {
    startup_timer = timer_read();
    startup_animation_done = false;
}
