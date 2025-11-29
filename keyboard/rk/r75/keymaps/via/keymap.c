#include QMK_KEYBOARD_H
#include "keymap_french.h"

// --- Custom Keycodes ---
enum custom_keycodes {
    WIN_LOCK = QK_KB_0,
    MAC_MODE = QK_KB_1
};

enum layer_names {
    _BASE,
    _FN,
    _LAYER2,
    _LAYER3
};

// --- LED State Variables ---
static bool win_lock_enabled = false;
static bool mac_mode_enabled = false;

// --- Layouts ---
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MUTE,
  FR_SUP2, FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL,  KC_BSPC, KC_INS,
  KC_TAB,  FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    FR_CIRC, FR_DLR,  KC_ENT,  KC_PGUP,
  KC_CAPS, FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    FR_UGRV, _______, KC_NUHS, KC_PGDN,
  KC_LSFT, FR_LABK, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, KC_RSFT, KC_UP,
  KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
),

// VIA LAYOUT 1 :
// RM_TOGG = 0x7842
// RM_NEXT = 0x7843
// RM_PREV = 0x7844
// RM_HUEU = 0x7845
// RM_HUED = 0x7846
// RM_SATU = 0x7847
// RM_SATD = 0x7848
// RM_VALU = 0x7849
// RM_VALD = 0x784a
// RM_SPDU = 0x784b
// RM_SPDD = 0x784c

[_FN] = LAYOUT(
  RM_TOGG, _______, _______, _______, _______, KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, QK_BOOT,
  _______, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, RM_PREV, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
  _______, MAC_MODE,RM_HUED, RM_SATD, RM_VALD, RM_SPDD, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, WIN_LOCK,_______,                   EE_CLR,                             _______, _______, _______, _______, _______
),

[_LAYER2] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______
),

[_LAYER3] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______
)
};

// --- Custom Keycode Processing ---
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WIN_LOCK:
            if (record->event.pressed) {
                // Toggle Win Lock
                win_lock_enabled = !win_lock_enabled;
                // Active LOW - invert logic
                gpio_write_pin(LED_WIN_LOCK_PIN, !win_lock_enabled);
            }
            return false;
        
        case MAC_MODE:
            if (record->event.pressed) {
                // Toggle Mac Mode
                mac_mode_enabled = !mac_mode_enabled;
                // Active LOW - invert logic
                gpio_write_pin(LED_MAC_PIN, !mac_mode_enabled);
            }
            return false;
        
        case KC_LGUI:
        case KC_RGUI:
            // Block Windows key if Win Lock is enabled
            if (win_lock_enabled) {
                return false;
            }
            return true;
        
        default:
            return true;
    }
}
