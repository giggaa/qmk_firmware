/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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

// Define tap toggle as 2 taps.
#define TAPPING_TOGGLE 2

// Define MOD-Tap key, LCTRL when held or Capslock when tap
#define CTLCAPS MT(MOD_LCTL, KC_CAPS)

/*
 * Mac OS
 */
// Define MOD-Tap key Mac OS, LGUI (Command) when held or Capslock when tap
#define CMDCAPS LCMD_T(KC_CAPS)
// Define L_CMD Mac OS, KC_LCMD (Command)
#define L_CMD KC_LCMD
// Define R_CMD Mac OS, KC_RCMD (Command)
#define R_CMD KC_RCMD
// Define Left Option Mac OS, Left Alt
#define L_OPT KC_LALT
// Define Right Option Mac OS, Right Alt
#define R_OPT KC_RALT

// Define WIN lock
#define WIN_LOCK MAGIC_NO_GUI
// Define WIN unlock
#define WIN_UNLOCK MAGIC_UNNO_GUI
// Define treat capslock as control
#define CAPS2CTRL MAGIC_CAPSLOCK_TO_CONTROL
// Define Stop treating Caps Lock as Control
#define STOPCAPS2CTRL MAGIC_UNCAPSLOCK_TO_CONTROL


/* Each layer gets a name for readability, which is then used in the keymap matrix below.
 * The underscores don't mean anything - you can have a layer called STUFF or any other name.
 * Layer names don't all need to be of the same length, obviously, and you can also skip them
 * entirely and just use numbers.
 */

// Layer declarations
enum my_layers {
  _FIRST_LAYER,
  _SECOND_LAYER,
  _THIRD_LAYER,
  _FOURTH_LAYER,
  _FIFTH_LAYER, // Mac OS layer
  _SIXTH_LAYER
};

// Tap dance declarations
enum tap_dance {
  // a or Select All
  CT_CTL_A = 0,
  // c or Copy
  CT_CTL_C,
  // f or find
  CT_CTL_F,
  // h or replace
  CT_CTL_H,
  // n or new
  CT_CTL_N,
  // r or refresh
  CT_CTL_R,
  // s or save
  CT_CTL_S,
  // t or new tab
  CT_CTL_T,
  // v or Paste
  CT_CTL_V,
  // x or cut
  CT_CTL_X,
  // Z or Undo
  CT_CTL_Z,
  // Home or Ctl+Home
  CT_CTL_HOME,
  // End or Ctl+End
  CT_CTL_END
};
// Define tap dance shortcut
#define TD_A TD(CT_CTL_A)
#define TD_C TD(CT_CTL_C)
#define TD_F TD(CT_CTL_F)
#define TD_H TD(CT_CTL_H)
#define TD_N TD(CT_CTL_N)
#define TD_R TD(CT_CTL_R)
#define TD_S TD(CT_CTL_S)
#define TD_T TD(CT_CTL_T)
#define TD_V TD(CT_CTL_V)
#define TD_X TD(CT_CTL_X)
#define TD_Z TD(CT_CTL_Z)
#define TD_HOME TD(CT_CTL_HOME)
#define TD_END TD(CT_CTL_END)

// Define toggle FIRST layer shortcut
#define TO_FIRST_LAYER TO(_FIRST_LAYER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_FIRST_LAYER] = LAYOUT_tkl_ansi(
        /*
         * Modded Windows layer
         */
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, KC_BRK,  \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_INS,  TD_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_DEL,  TD_END,  KC_PGDN, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                  \
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,               KC_UP,            \
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             KC_RCTL, MO(_SECOND_LAYER),_______ , KC_CAPS,      KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_SECOND_LAYER] = LAYOUT_tkl_ansi(
      /*
       * Windows function layer
       */
        RESET,            KC_BRID, KC_BRIU, _______, _______, _______, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,    WIN_UNLOCK, WIN_LOCK, TO_FIRST_LAYER, \
        _______,   TO_FIRST_LAYER, _______, TG(_THIRD_LAYER), _______, TG(_FIFTH_LAYER), _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                                 \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,               _______,          \
        _______, _______, _______,                            _______,                            _______, KC_TRNS, _______, _______,      _______, _______, _______  \
    ),
    [_THIRD_LAYER] = LAYOUT_tkl_ansi(
        /*
         * Default Windows layer
         */
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, TO_FIRST_LAYER,  \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                  \
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,               KC_UP,            \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RCTL, MO(_FOURTH_LAYER), KC_RGUI, KC_RALT,      KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_FOURTH_LAYER] = LAYOUT_tkl_ansi(
        RESET,            KC_BRID, KC_BRIU, _______, _______, _______, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,    WIN_UNLOCK, WIN_LOCK, TO_FIRST_LAYER, \
        _______,   TO_FIRST_LAYER, _______, _______, _______, TG(_FIFTH_LAYER), _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                                 \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,               _______,          \
        _______, _______, _______,                            _______,                            _______, KC_TRNS, _______, _______,      _______, _______, _______  \
    ),
    [_FIFTH_LAYER] = LAYOUT_tkl_ansi(
      /*
       * Mac OS layer
       */
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, TO_FIRST_LAYER,  \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                              \
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,               KC_UP,            \
        KC_LCTL, L_OPT,  L_CMD,                              KC_SPC,                             KC_RCTL, MO(_SIXTH_LAYER), R_OPT, R_CMD,      KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_SIXTH_LAYER] = LAYOUT_tkl_ansi(
      /*
       * Mac OS function layer
       */
        RESET,            KC_BRMD, KC_BRMU, _______, _______, _______, KC_MSTP, KC_MRWD, KC_MPLY, KC_MFFD, KC__MUTE, KC__VOLDOWN, KC__VOLUP,_______, _______, TO_FIRST_LAYER, \
        _______,   TO_FIRST_LAYER, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                                 \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,               _______,          \
        _______, _______, _______,                            _______,                            _______, KC_TRNS, _______, _______,      _______, _______, _______  \
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {
}

/*
 * Send L Ctrl + A (select all) on triple tap else send "a".
 */
void dance_a_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_A);
      break;
    case 2:
      register_code (KC_A);
      unregister_code (KC_A);
      register_code (KC_A);
      break;
    default:
      register_code (KC_A);
      break;
  }

  // if (state->count == 3) {
    // register_code (KC_LCTL);
    // register_code (KC_A);
  // } else if (state->count == 2) {
    // register_code (KC_LCTL);
    // register_code (KC_A);
  // } else {
    // register_code (KC_A);
  // }
}

/*
 * Reset "a" or L Ctrl + c.
 */
void dance_a_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_A);
      break;
    default:
      unregister_code (KC_A);
      break;
  }
  // if (state->count == 3) {
    // unregister_code (KC_LCTL);
    // unregister_code (KC_A);
  // } else {
    // unregister_code (KC_A);
  // }
}

/*
 * Send L Ctrl + c (copy) on triple tap else send "c".
 */
void dance_c_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_C);
  } else {
    register_code (KC_C);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_C);
      break;
    case 2:
      register_code (KC_C);
      unregister_code (KC_C);
      register_code (KC_C);
      break;
    default:
      register_code (KC_C);
      break;
  }
}

/*
 * Reset "c" on single tap or L Ctrl + c (copy).
 */
void dance_c_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_C);
  } else {
    unregister_code (KC_C);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_C);
      break;
    default:
      unregister_code (KC_C);
      break;
  }
}

/*
 * Send L Ctrl + f (find) on triple tap else send "f".
 */
void dance_f_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_F);
  } else {
    register_code (KC_F);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_F);
      break;
    case 2:
      register_code (KC_F);
      unregister_code (KC_F);
      register_code (KC_F);
      break;
    default:
      register_code (KC_F);
      break;
  }
}

/*
 * Reset "f" on single tap or L Ctrl + f (find).
 */
void dance_f_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_F);
  } else {
    unregister_code (KC_F);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_F);
      break;
    default:
      unregister_code (KC_F);
      break;
  }
}

/*
 * Send L Ctrl + h (replace) on triple tap else send "h".
 */
void dance_h_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_H);
  } else {
    register_code (KC_H);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_H);
      break;
    case 2:
      register_code (KC_H);
      unregister_code (KC_H);
      register_code (KC_H);
      break;
    default:
      register_code (KC_H);
      break;
  }
}

/*
 * Reset "h" on single tap or L Ctrl + h (replace).
 */
void dance_h_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_H);
  } else {
    unregister_code (KC_H);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_H);
      break;
    default:
      unregister_code (KC_H);
      break;
  }
}

/*
 * Send L Ctrl + n (new) on triple tap else send "n".
 */
void dance_n_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_N);
  } else {
    register_code (KC_N);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_N);
      break;
    case 2:
      register_code (KC_N);
      unregister_code (KC_N);
      register_code (KC_N);
      break;
    default:
      register_code (KC_N);
      break;
  }
}

/*
 * Reset "n" on single tap or L Ctrl + n (new).
 */
void dance_n_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_N);
  } else {
    unregister_code (KC_N);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_N);
      break;
    default:
      unregister_code (KC_N);
      break;
  }
}

/*
 * Send L Ctrl + r (refresh) on triple tap else send "r".
 */
void dance_r_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_R);
  } else {
    register_code (KC_R);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_R);
      break;
    case 2:
      register_code (KC_R);
      unregister_code (KC_R);
      register_code (KC_R);
      break;
    default:
      register_code (KC_R);
      break;
  }
}

/*
 * Reset "r"  or L Ctrl + r (refresh).
 */
void dance_r_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_R);
  } else {
    unregister_code (KC_R);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_R);
      break;
    default:
      unregister_code (KC_R);
      break;
  }
}

/*
 * Send L Ctrl + s (save) on triple tap else send "s".
 */
void dance_s_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_S);
  } else {
    register_code (KC_S);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_S);
      break;
    case 2:
      register_code (KC_S);
      unregister_code (KC_S);
      register_code (KC_S);
      break;
    default:
      register_code (KC_S);
      break;
  }
}

/*
 * Reset "s" on single tap or L Ctrl + s (save).
 */
void dance_s_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_S);
  } else {
    unregister_code (KC_S);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_S);
      break;
    default:
      unregister_code (KC_S);
      break;
  }
}

/*
 * Send L Ctrl + t (new tab) on triple tap else send "t".
 */
void dance_t_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_T);
  } else {
    register_code (KC_T);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_T);
      break;
    case 2:
      register_code (KC_T);
      unregister_code (KC_T);
      register_code (KC_T);
      break;
    default:
      register_code (KC_T);
      break;
  }
}

/*
 * Reset "t" on single tap or L Ctrl + t (new tab).
 */
void dance_t_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_T);
  } else {
    unregister_code (KC_T);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_T);
      break;
    default:
      unregister_code (KC_T);
      break;
  }
}

/*
 * Send L Ctrl + v (paste) on triple tap else send "v".
 */
void dance_v_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_V);
  } else {
    register_code (KC_V);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_V);
      break;
    case 2:
      register_code (KC_V);
      unregister_code (KC_V);
      register_code (KC_V);
      break;
    default:
      register_code (KC_V);
      break;
  }
}

/*
 * Reset "v" on single tap or L Ctrl + v (paste).
 */
void dance_v_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_V);
  } else {
    unregister_code (KC_V);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_V);
      break;
    default:
      unregister_code (KC_V);
      break;
  }
}

/*
 * Send L Ctrl + x (cut) on triple tap else send "x".
 */
void dance_x_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_X);
  } else {
    register_code (KC_X);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_X);
      break;
    case 2:
      register_code (KC_X);
      unregister_code (KC_X);
      register_code (KC_X);
      break;
    default:
      register_code (KC_X);
      break;
  }
}

/*
 * Reset "x" on single tap or L Ctrl + z (cut).
 */
void dance_x_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    unregister_code (KC_LCTL);
    unregister_code (KC_X);
  } else {
    unregister_code (KC_X);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_X);
      break;
    default:
      unregister_code (KC_X);
      break;
  }
}

/*
 * Send L Ctrl + z (undo) on triple tap else send "z".
 */
void dance_z_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_Z);
  } else {
    register_code (KC_Z);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_Z);
      break;
    case 2:
      register_code (KC_Z);
      unregister_code (KC_Z);
      register_code (KC_Z);
      break;
    default:
      register_code (KC_Z);
      break;
  }
}

/*
 * Reset "z" on single tap or L Ctrl + z (undo) .
 */
void dance_z_reset (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 13) {
    unregister_code (KC_LCTL);
    unregister_code (KC_Z);
  } else {
    unregister_code (KC_Z);
  } */
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_Z);
      break;
    default:
      unregister_code (KC_Z);
      break;
  }
}

/*
 * Send L Ctrl + Home on triple tap else send Home.
 */
void dance_home_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_HOME);
  } else {
    register_code (KC_HOME);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_HOME);
      break;
    case 2:
      register_code (KC_HOME);
      unregister_code (KC_HOME);
      register_code (KC_HOME);
      break;
    default:
      register_code (KC_HOME);
      break;
  }
}

/*
 * Reset Home or L Ctrl + Home.
 */
void dance_home_reset (qk_tap_dance_state_t *state, void *user_data) {
  /*if (state->count == 13) {
    unregister_code (KC_LCTL);
    unregister_code (KC_HOME);
  } else {
    unregister_code (KC_HOME);
  }*/
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_HOME);
      break;
    default:
      unregister_code (KC_HOME);
      break;
  }
}

/*
 * Send L Ctrl + End on triple tap else send End.
 */
void dance_end_finished (qk_tap_dance_state_t *state, void *user_data) {
/*  if (state->count == 3) {
    register_code (KC_LCTL);
    register_code (KC_END);
  } else {
    register_code (KC_END);
  } */
  switch (state->count) {
    case 3:
      register_code (KC_LCTL);
      register_code (KC_END);
      break;
    case 2:
      register_code (KC_END);
      unregister_code (KC_END);
      register_code (KC_END);
      break;
    default:
      register_code (KC_END);
      break;
  }
}

/*
 * Reset End or L Ctrl + End.
 */
void dance_end_reset (qk_tap_dance_state_t *state, void *user_data) {
  /*if (state->count == 13) {
    unregister_code (KC_LCTL);
    unregister_code (KC_END);
  } else {
    unregister_code (KC_END);
  }*/
  switch (state->count) {
    case 3:
      unregister_code (KC_LCTL);
      unregister_code (KC_END);
      break;
    default:
      unregister_code (KC_END);
      break;
  }
}

// All tap dance functions would go here.
qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_CTL_A] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_a_finished, dance_a_reset),
  [CT_CTL_C] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_c_finished, dance_c_reset),
  [CT_CTL_F] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_f_finished, dance_f_reset),
  [CT_CTL_H] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_h_finished, dance_h_reset),
  [CT_CTL_N] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_n_finished, dance_n_reset),
  [CT_CTL_R] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_r_finished, dance_r_reset),
  [CT_CTL_S] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_s_finished, dance_s_reset),
  [CT_CTL_T] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_t_finished, dance_t_reset),
  [CT_CTL_V] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_v_finished, dance_v_reset),
  [CT_CTL_X] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_x_finished, dance_x_reset),
  [CT_CTL_Z] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_z_finished, dance_z_reset),
  [CT_CTL_HOME] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_home_finished, dance_home_reset),
  [CT_CTL_END] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_end_finished, dance_end_reset)
};

