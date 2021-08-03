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
    C(KC_C), C(KC_V),KC_LALT,KC_LGUI,   LOWER,    KC_SPC       ,   RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   \  |   ~  |   @  |   #  |   $  |   %  |   ^  |   &  |   |  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   ¡  |   !  |   ¿  |   ?  |   €  |      |      |   =  |   {  |   }  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   <  |   >  |   `  |      |      |      |      |   /  |   *  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    ES_BSLS, ES_TILD,   ES_AT, ES_HASH,  ES_DLR, ES_PERC, ES_CIRC,   ES_AMPR,    ES_PIPE,    ES_LPRN, ES_RPRN, KC_BSPC,
    KC_DEL,  ES_IEXL, ES_EXLM, ES_IQUE, ES_QUES, ES_EURO, XXXXXXX,   XXXXXXX,     ES_EQL,    ES_LCBR, ES_RCBR, ES_QUOT,
    _______, ES_LABK, ES_RABK, ES_GRV,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    ES_SLSH,    ES_ASTR, ES_PLUS, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   /  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Ins  | Impr |   [  |   ]  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home | End | Pg Up | Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    ES_SLSH,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_INS,  KC_PSCR,  ES_LBRC, ES_RBRC, ES_DQUO,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END,   KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* NUM
  * ,-----------------------------------------------------------------------------------.
  * | **** |  F1  |  F2  |  F3  |  F4  |  F5  |      |   7  |   8  |   9  |   *  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |  F5  |  F6  |  F7  |  F8  |      | Bksp |   4  |   5  |   6  |   +  |  Del |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |  F9  |  F10 |  F11 |  F12 |      | Enter|   1  |   2  |   3  |   -  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |   0  |   ,  |   .  |   /  |  =   |
  * `-----------------------------------------------------------------------------------'
  */
[_NUM] = LAYOUT_planck_mit(
        _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , XXXXXXX, KC_P7, KC_P8, KC_P9,   KC_PAST, KC_BSPC,
        XXXXXXX , KC_F5   , KC_F6   , KC_F7   , KC_F8   , XXXXXXX , KC_BSPC, KC_P4, KC_P5, KC_P6,   KC_PPLS, KC_DEL,
        XXXXXXX , KC_F9   , KC_F10  , KC_F11  , KC_F12  , XXXXXXX , KC_PENT, KC_P1, KC_P2, KC_P3,   KC_PMNS, KC_PENT,
        XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX     , KC_P0,KC_PCMM,KC_PDOT, KC_PSLS, KC_PEQL
        )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  rgb_matrix_set_color(4, RGB_WHITE);
  rgb_matrix_set_color(7, RGB_WHITE);

  rgb_matrix_set_color(16, RGB_WHITE);
  rgb_matrix_set_color(19, RGB_WHITE);

  rgb_matrix_set_color(28, RGB_WHITE);
  rgb_matrix_set_color(31, RGB_WHITE);

  rgb_matrix_set_color(40, RGB_WHITE);
  rgb_matrix_set_color(42, RGB_WHITE);
}