/* 
 * Spanglish layout for KPRepublic BM40 Hotswap RGB keyboard.
 * In order to work as intended, you need to select the english layout in your OS. 
 */
#include QMK_KEYBOARD_H
//#include "keymap_spanish.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM
};

#define LOWER LT(_LOWER, KC_BSPC)
#define LOWER2 MO(_LOWER)
#define RAISE LT(_RAISE, KC_ENT)
#define TABNUM LT(_NUM, KC_TAB)
#define BKSPNUM LT(_NUM, KC_BSPC)

// Tap Dance declarations
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    TD_PASTE_UNDO,
    TD_SAVE,
    TD_COPY_CUT,
    TD_CAPSLOCK
};

td_state_t cur_dance(qk_tap_dance_state_t *state);
void dance_copy_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_copy_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_paste_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_paste_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_caps_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_caps_reset(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for COPY, twice for CUT
    [TD_COPY_CUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_copy_finished, dance_copy_reset),
    [TD_PASTE_UNDO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_paste_finished, dance_paste_reset),
    [TD_SAVE] = ACTION_TAP_DANCE_DOUBLE(KC_Q, C(KC_S)), 
    [TD_CAPSLOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_caps_finished, dance_caps_reset)
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
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    TD(TD_CAPSLOCK),        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    TD(TD_COPY_CUT), TD(TD_PASTE_UNDO),KC_LALT,KC_LGUI, LOWER2,    KC_SPC       ,   RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
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
    A(KC_LABK), KC_TILD,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,   KC_AMPR,    KC_PIPE,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_GRV, XXXXXXX, A(KC_E) , XXXXXXX, XXXXXXX,  A(KC_SLASH),   KC_QUES,     KC_EQL,    KC_LCBR, KC_RCBR, KC_DQUO,
    _______, KC_GRV, S(KC_GRV), XXXXXXX,  XXXXXXX, XXXXXXX, A(KC_1),  KC_EXLM,    KC_SLSH,    KC_ASTR, KC_PLUS, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_HOME, KC_PGDN,   KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   /  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |   ¿  |   [  |   ]  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   ¡  |   <  |   >  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |SHome |SPg Dn|SPg Up| SEnd |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    KC_SLSH, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   A(KC_SLASH), KC_QUES,  KC_LBRC, KC_RBRC, KC_QUOT,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  A(KC_1), KC_EXLM,  KC_GRV, S(KC_GRV), _______,
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
    C(A(KC_DEL)), KC_SLEP, KC_WAKE , KC_PWR, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* NUM
  * ,-----------------------------------------------------------------------------------.
  * |      |  Mute| Vol- | Vol+ | Next |  Play|      |   7  |   8  |   9  |   *  | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |SPrtSc| PrtSc|      |      |      | Bksp |   4  |   5  |   6  |   +  |  Del |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      | Desk1| Desk2|Desk3 |Desk4 |      | Ins  |   1  |   2  |   3  |   -  |Enter |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | RCtl | RAlt |      |      |      |             |   0  |   .  |   ,  |   /  |  =   |
  * `-----------------------------------------------------------------------------------'
  */
[_NUM] = LAYOUT_planck_mit(
        _______ , KC_MUTE, KC_VOLD, KC_VOLU, KC_MFFD  , KC_MPLY   , XXXXXXX,  KC_P7,   KC_P8, KC_P9,   KC_PAST, KC_BSPC,
        _______ , C(S(G(KC_4))), C(S(G(KC_3))), S(G(KC_4)), S(G(KC_3))   , XXXXXXX, KC_BSPC, KC_P4, KC_P5, KC_P6,   KC_PPLS, KC_DEL,
        _______ , C(KC_1)   , C(KC_2)  , C(KC_3)  , C(KC_4)  , XXXXXXX , KC_INS, KC_P1, KC_P2, KC_P3,   KC_PMNS, KC_PENT,
        KC_RCTRL , KC_RALT , _______ , _______ , _______ ,      XXXXXXX     , KC_P0, KC_DOT, KC_COMM, KC_PSLS, KC_EQL
        )

};

void matrix_init_user() {
  rgblight_disable();
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
//  }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {

//   static bool caps_active = false;

//   switch (keycode) {
//     case TD(TD_CAPSLOCK):
      
//       if (record->tap.count && record->event.pressed) {
        
//         caps_active = !caps_active;
        
//         if(caps_active) {
//           rgblight_enable();
//           rgblight_mode(0);
//           rgblight_sethsv(HSV_WHITE);
//         } else {
//           rgblight_disable();
//         }
//       }

//       return true;

//     default:
//       return true; //Process all other keycodes normally
//   }
// }


// TAP DANCE METHODS
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}
// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void dance_copy_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LCTL); register_code(KC_C); break;
        case TD_SINGLE_HOLD: //register_code16(KC_HYPR /*KC_F13*/); break;
            register_code(KC_LSFT); register_code(KC_LCTL); register_code(KC_LALT); register_code(KC_LGUI); break;
        case TD_DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_X); break;
        case TD_DOUBLE_HOLD: register_code(KC_RALT); break;
        default: break;
    }
}

void dance_copy_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_C); unregister_code(KC_LCTL); break;
        case TD_SINGLE_HOLD: // unregister_code16(KC_HYPR /*KC_F13*/); break;
            unregister_code(KC_LCTL); unregister_code(KC_LALT); unregister_code(KC_LCTL); unregister_code(KC_LSFT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_X); unregister_code(KC_LCTL); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_RALT);break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void dance_paste_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LCTL); register_code(KC_V); break;
        case TD_SINGLE_HOLD: //register_code16(KC_HYPR /*KC_F13*/); break;
            register_code(KC_LCTL); register_code(KC_LALT); break;
        case TD_DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_Z); break;
        case TD_DOUBLE_HOLD: register_code(KC_RALT); break;
        default: break;
    }
}

void dance_paste_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_V); unregister_code(KC_LCTL); break;
        case TD_SINGLE_HOLD: // unregister_code16(KC_HYPR /*KC_F13*/); break;
            unregister_code(KC_LALT); unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_Z); unregister_code(KC_LCTL); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_RALT);break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void dance_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    static bool caps_active = false;

    if (state->count == 2) {
      caps_active = !caps_active;
      register_code(KC_CAPSLOCK);

      if(caps_active) {
        rgblight_enable();
        rgblight_mode(0);
        rgblight_sethsv(HSV_WHITE);
      } else {
        rgblight_disable();
      }
    } else {
      register_code(KC_LSFT);
    }
}

void dance_caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        wait_ms(80); // Wait for the caps lock to be released MacOs
        unregister_code(KC_CAPSLOCK);
    } else {
        unregister_code(KC_LSFT);
    }
}
