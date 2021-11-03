/* Copyright 2020 tominabox1
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
#include "keymap_spanish.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM
};

#define LOWER LT(_LOWER, KC_BSPC)
#define RAISE LT(_RAISE, KC_ENT)
#define TABNUM LT(_NUM, KC_TAB)
#define BKSPNUM LT(_NUM, KC_BSPC)

// Tap Dance declarations
enum {
    TD_PASTE_UNDO,
    TD_SAVE,
    TD_COPY_CUT
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for COPY, twice for CUT
    [TD_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(C(KC_C), C(KC_X)),
    [TD_PASTE_UNDO] = ACTION_TAP_DANCE_DOUBLE(C(KC_V), C(KC_Z)),
    [TD_SAVE] = ACTION_TAP_DANCE_DOUBLE(KC_Q, C(KC_S))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab* |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl*|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ñ  |  ´   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | COPY | PASTE|  Alt | GUI  |Lower*|    Space    |Raise*| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 * - Tap dance NUM/Tab
 * - Tap dance Ctrl/Esc
 * - Tap dance MOV/Space
 * - Tap dance NUM/Tab
 * - Tap dance Raise/Enter
 * - Tap dance Lower/Backspace 
 * TODO: Check the arrow keys + COPY/PASTE. KC_CAPS lighting.
 */
[_QWERTY] = LAYOUT_planck_mit(
    TABNUM,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    ES_NTIL, ES_ACUT,
    LSFT_T(KC_CAPS),        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    ES_COMM, ES_DOT,  ES_MINS, RSFT_T(KC_ENT),
    TD(TD_COPY_CUT), TD(TD_PASTE_UNDO),KC_LALT,KC_LGUI, MO(_LOWER),    KC_SPC       ,   RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   \  |   ~  |   @  |   #  |   $  |   %  |   ^  |   &  |   |  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   `  |      |   €  |      |      |   ¿  |   ?  |   =  |   {  |   }  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   <  |   >  |      |      |      |   ¡  |   !  |   /  |   *  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | Pg Dn| Pg Up|  End |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    ES_BSLS, ES_TILD,   ES_AT, ES_HASH,  ES_DLR, ES_PERC, ES_CIRC,   ES_AMPR,    ES_PIPE,    ES_LPRN, ES_RPRN, KC_BSPC,
    KC_DEL,  ES_GRV, XXXXXXX, ES_EURO , XXXXXXX, XXXXXXX, ES_IQUE,  ES_QUES,     ES_EQL,    ES_LCBR, ES_RCBR, ES_DQUO,
    _______, ES_LABK, ES_RABK, XXXXXXX,  XXXXXXX, XXXXXXX, ES_IEXL,  ES_EXLM,    ES_SLSH,    ES_ASTR, ES_PLUS, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_HOME, KC_PGDN,   KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   /  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |   [  |   ]  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |   <  |   >  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |SHome |SPg Dn|SPg Up| SEnd |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    ES_SLSH, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX,  ES_LBRC, ES_RBRC, ES_QUOT,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,  ES_LABK, ES_RABK, _______,
    _______, _______, _______, _______, _______, _______, _______, S(KC_HOME), S(KC_PGDN),   S(KC_PGUP), S(KC_END)
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | C+A+D|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    C(A(KC_DEL)), _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* NUM
  * ,-----------------------------------------------------------------------------------.
  * |      |  Next| Vol- | Vol+ | Play |      |      |   7  |   8  |   9  |   *  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |SPrtSc| PrtSc|  Ins |      |      | Bksp |   4  |   5  |   6  |   +  |  Del |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      | Desk1| Desk2|      |      |      | Enter|   1  |   2  |   3  |   -  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | RCtl | RAlt |      |      |      |             |   0  |   .  |   ,  |   /  |  =   |
  * `-----------------------------------------------------------------------------------'
  */
[_NUM] = LAYOUT_planck_mit(
        _______ , KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  , XXXXXXX   , XXXXXXX,  KC_P7,   KC_P8, KC_P9,   KC_PAST, KC_BSPC,
        _______ , G(S(KC_S))   , KC_PSCR   , KC_INS   , XXXXXXX   , XXXXXXX , KC_BSPC, KC_P4, KC_P5, KC_P6,   KC_PPLS, KC_DEL,
        _______ , C(G(KC_LEFT))   , C(G(KC_RGHT))  , XXXXXXX  , XXXXXXX  , XXXXXXX , KC_PENT, KC_P1, KC_P2, KC_P3,   KC_PMNS, KC_PENT,
        KC_RCTRL , KC_RALT , _______ , _______ , _______ ,      XXXXXXX     , KC_P0, KC_PDOT, ES_COMM, KC_PSLS, ES_EQL
        )

};

void matrix_init_user() {
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Runs constantly in the background, in a loop.
// void matrix_scan_user(void) {
//   rgb_matrix_set_color(4, RGB_WHITE);
//   rgb_matrix_set_color(7, RGB_WHITE);

//   rgb_matrix_set_color(16, RGB_WHITE);
//   rgb_matrix_set_color(19, RGB_WHITE);

//   rgb_matrix_set_color(28, RGB_WHITE);
//   rgb_matrix_set_color(31, RGB_WHITE);

//   rgb_matrix_set_color(40, RGB_WHITE);
//   rgb_matrix_set_color(42, RGB_WHITE);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  static bool caps_active = false;

  switch (keycode) {
    case LSFT_T(KC_CAPS):
      
      if (record->tap.count && record->event.pressed) {
        register_code(KC_CAPS);
        caps_active = !caps_active;

        if(caps_active) {
          rgblight_enable();
          rgblight_mode(0);
          rgblight_sethsv(HSV_WHITE);
        } else {
          rgblight_disable();
        }

        return false;
      }

      return true;

    default:
      return true; //Process all other keycodes normally
  }
}