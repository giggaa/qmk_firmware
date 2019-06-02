/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
#   include "rgblight.h"
extern rgblight_config_t rgblight_config;
#endif


// One shot tap toggle 2
#define ONESHOT_TAP_TOGGLE 2

// Define L GUI when held, capslock when tapped
#define WIN_CAPS LWIN_T(KC_CAPS)
// Define L_CMD Mac OS, KC_LCMD (Command)
#define L_CMD KC_LCMD
// Define R_CMD Mac OS, KC_RCMD (Command)
#define R_CMD KC_RCMD
// Define Left Option Mac OS, Left Alt
#define L_OPT KC_LALT
// Define left ctrl when held, capslock when tapped
#define CTL_CAP MT(MOD_LCTL, KC_CAPS)

#define SWAP_RGUI MAGIC_SWAP_RALT_RGUI
#define SWAP_LGUI MAGIC_SWAP_LALT_LGUI
#define USWAP_RGUI MAGIC_UNSWAP_RALT_RGUI
#define USWAP_LGUI MAGIC_UNSWAP_LALT_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Windows)
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬────┐
   * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ BSPC  │ Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────|────┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │LCtCps│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │LShiftFn│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RShift│FnL│
   * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┘
   *       │LAt│LCtr │           Space           │RAlGu│RCt│
   *       └───┴─────┴───────────────────────────┴─────┴───┘
   */
  [0] = LAYOUT(
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      WIN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, TT(1),
      XXXXXXX, KC_LALT, KC_LCTL,                   KC_SPACE,                 KC_RCTL, TO(2), XXXXXXX
      ),

  [1] = LAYOUT(
  /* Function layer (Windows)
   * arrow keys: Fn + ( ' - ↑, > - ←, Rshft - →, / - ↓ )
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│HME│DWN│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │Hom│ ↑ │End│PgU│   │   │   │   │   │   │INS│PGU│ PGD │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │ ← │ ↓ │ → │PgD│   │   │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │Mut│Vo-│Vo+│Ply│Prv│Nxt│MW←│   │   │   │      │   │
   * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┘
   *       │DPR│DstNA│            MW↓            │MAcl2│   │
   *       └───┴─────┴───────────────────────────┴─────┴───┘
   */
        RESET, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_HOME, KC_END,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_INS , KC_PGUP, KC_PGDN,
      KC_TRNS, RGB_TOG, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
      XXXXXXX, KC_LALT, KC_LCTL,                   KC_TRNS,                   KC_TRNS, KC_TRNS, XXXXXXX
      ),
  [2] = LAYOUT(
  /* Mac OS layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│PSc│Ins│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │Hom│ ↑ │End│PgU│   │   │   │   │M1 │M↑ │M2 │M3 │ Del │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │ ← │ ↓ │ → │PgD│   │   │   │MW↑│M← │M↓ │M→ │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │Mut│Vo-│Vo+│Ply│Prv│Nxt│MW←│MW→│M4 │M5 │      │   │
   * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┘
   *       │DPR│DstNA│            MW↓            │MAcl2│   │
   *       └───┴─────┴───────────────────────────┴─────┴───┘
   */
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS ,
      CTL_CAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, TT(3),
      XXXXXXX, L_OPT, L_CMD,                   KC_SPACE,                  R_CMD,  TO(0), XXXXXXX
      ),
[3] = LAYOUT(
  /* Function layer (Mac OS)
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│PSc│Ins│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │Hom│ ↑ │End│PgU│   │   │   │   │M1 │M↑ │M2 │M3 │ Del │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │ ← │ ↓ │ → │PgD│   │   │   │MW↑│M← │M↓ │M→ │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │Mut│Vo-│Vo+│Ply│Prv│Nxt│MW←│MW→│M4 │M5 │      │   │
   * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┘
   *       │DPR│DstNA│            MW↓            │MAcl2│   │
   *       └───┴─────┴───────────────────────────┴─────┴───┘
   */
        RESET, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_HOME, KC_END,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_INS , KC_PGUP, KC_PGDN,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_MSTP, KC_MRWD, KC_MPLY, KC_MFFD, KC__MUTE, KC__VOLDOWN, KC__VOLUP, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
      ),
[4] = LAYOUT(
  /* Not In USE at the moment
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│PSc│Ins│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │     │Hom│ ↑ │End│PgU│   │   │   │   │M1 │M↑ │M2 │M3 │ Del │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │ ← │ ↓ │ → │PgD│   │   │   │MW↑│M← │M↓ │M→ │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │Mut│Vo-│Vo+│Ply│Prv│Nxt│MW←│MW→│M4 │M5 │      │   │
   * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┘
   *       │DPR│DstNA│            MW↓            │MAcl2│   │
   *       └───┴─────┴───────────────────────────┴─────┴───┘
   */
        RESET,   KC_BRID,   KC_BRIU,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_MSTP,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS, RESET,
      KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_UP , KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_RGHT, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
      ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

#ifdef RGBLIGHT_ENABLE
  uint8_t layer = biton32(layer_state);
  switch (layer) {
    case 0:
      // Default layer, red
      rgblight_setrgb(255, 0, 0);
      if (rgblight_config.enable) {
        /**
         * host_keyboard_leds() gets the host's LED status
         * (1<<USB_LED_CAPS_LOCK) looks at only the caps lock LED
         */
        if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
          //Set color to purple.
          rgblight_setrgb(153, 51, 255);
        } else {
          rgblight_disable();
        }
      }
      break;
    case 1:
      // Function layer, blue
      rgblight_setrgb(0, 0, 255);
      if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        //Set color to purple.
        rgblight_setrgb(153, 51, 255);
      }
      if (!rgblight_config.enable) {
        rgblight_enable();
      }
      break;
    case 2:
      // Mac layer, green
      rgblight_setrgb(0, 255, 0);
      if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        //Set color to purple.
        rgblight_setrgb(153, 51, 255);
      }
      if (!rgblight_config.enable) {
        rgblight_enable();
      }
      break;
    case 3:
      // function Mac layer, yellow
      rgblight_setrgb(255, 255, 0);
      if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        //Set color to purple.
        rgblight_setrgb(153, 51, 255);
      }
      if (!rgblight_config.enable) {
        rgblight_enable();
      }
      break;
  }
#endif

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
#ifdef RGBLIGHT_ENABLE
  switch (keycode) {
    case WIN_CAPS:
      // If capslock is pressed then turn on the rgb else turn off rgb.
      if(record->event.pressed) {
        // (1<<USB_LED_CAPS_LOCK) looks at only the caps lock LED
        if (1<<USB_LED_CAPS_LOCK) {
          if (rgblight_config.enable) {
           rgblight_disable();
          } else {
            rgblight_enable();
          }
        }
      }
     break;
  }
#endif */
  return true; // We didn't handle other keypresses
}
