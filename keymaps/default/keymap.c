#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "process_combo.h"
#include "process_tap_dance.h"

// --- Tap Dance Configuration ---
enum tap_dance_keys {
    TD_RESET,
};

// Définition d'abord
void safe_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        reset_keyboard(); // bootloader
        reset_tap_dance(state);
    }
}

// Puis le tableau d’actions
tap_dance_action_t tap_dance_actions[] = {
    [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset),
};


// --- Custom Keycodes ---
enum custom_keycodes {
    WIN_LOCK = SAFE_RANGE,
    MAC_MODE
};

// --- Déclaration du combo Fn + Mute = RESET ---
enum combo_events {
    FN_MUTE_RESET,
    COMBO_LENGTH
};

enum layer_names {
    _BASE,
    _FN
};

// --- LED State Variables ---
static bool win_lock_enabled = false;
static bool mac_mode_enabled = false;

const uint16_t PROGMEM fn_mute_combo[] = {MO(_FN), KC_MUTE, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [FN_MUTE_RESET] = COMBO(fn_mute_combo, RESET),
};

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

[_FN] = LAYOUT(
  _______, _______, _______, _______, _______, KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, TD(TD_RESET),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
  _______, MAC_MODE,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, WIN_LOCK,_______,                   _______,                            _______, _______, _______, _______, _______
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
                writePin(LED_WIN_LOCK_PIN, !win_lock_enabled);
            }
            return false;
        
        case MAC_MODE:
            if (record->event.pressed) {
                // Toggle Mac Mode
                mac_mode_enabled = !mac_mode_enabled;
                // Active LOW - invert logic
                writePin(LED_MAC_PIN, !mac_mode_enabled);
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
