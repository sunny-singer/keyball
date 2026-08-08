/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// DEVNOTE https://keymapdb.com/keymaps/jwon/
// https://pseudocc.github.io/real-prog-dvorak/
// https://docs.qmk.fm/keycodes_basic

enum my_layers {
  navigation = 0,
  navigation_mod,
  dvorak,
  dvorak_mod,
  qwerty,
  qwerty_mod,
  gaming,
  gaming_mod,
};

enum my_keycodes {
  KC_CONFIG_NAVIGATION = SAFE_RANGE,
  KC_CONFIG_DVORAK,
  KC_CONFIG_QWERTY,
  KC_CONFIG_GAMING,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default 
  // TODO set up navigation
  [navigation] = LAYOUT_universal(
    KC_CONFIG_DVORAK , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    KC_CONFIG_QWERTY , _______ , _______ , _______ , _______ , _______ ,                                       _______ , KC_BTN1 , KC_BTN3 , _______ , KC_BTN2 , _______ ,
    KC_CONFIG_GAMING , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
             _______ , _______          , MO(navigation_mod) , _______ , _______ ,                  _______  , _______ , _______           , _______ , _______
  ),

  [navigation_mod] = LAYOUT_universal(
    SSNP_FRE , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    SSNP_VRT , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    SSNP_VRT , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
               _______ , _______           , _______ , _______  , _______ ,                 _______  , _______           , _______ , _______ , _______
  ),

  [dvorak] = LAYOUT_universal(
    KC_ESC   , KC_SCLN  , KC_COMM  , KC_DOT   , KC_P     , KC_Y     ,                                        KC_F     , KC_G     , KC_C     , KC_R     , KC_L     , _______  ,
    KC_TAB   , KC_A     , KC_O     , KC_E     , KC_U     , KC_I     ,                                        KC_D     , KC_H     , KC_T     , KC_N     , KC_S     , KC_MINS  ,
    KC_LSFT  , KC_QUOTE , KC_Q     , KC_J     , KC_K     , KC_X     ,                                        KC_B     , KC_M     , KC_W     , KC_V     , KC_Z     , KC_RSFT  ,
               _______  , _______  , MO(programmer_dvorak_mod) , KC_SPC , _______ ,               KC_BSPC  , KC_ENT   , _______  , _______  , KC_CONFIG_NAVIGATION
  ),

  [dvorak_mod] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______           , _______ , _______  , _______ ,                 _______  , _______           , _______ , _______ , _______
  ),

  [qwerty] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , _______  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , _______  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , _______  ,
               _______  , _______  , MO(qwerty_mod)  , KC_SPC , _______ ,                          KC_BSPC , KC_ENT   , _______  , _______  , KC_CONFIG_NAVIGATION
  ),

  [qwerty_mod] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______           , _______ , _______  , _______ ,                 _______  , _______           , _______ , _______ , _______
  ),

  [gaming] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , _______  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_BTN1  , KC_BTN3  , KC_BTN4  , KC_BTN2  , _______  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , _______  ,
               _______  , _______  , MO(qwerty_mod)  , KC_SPC , _______ ,                          KC_BSPC , KC_ENT   , _______  , _______  , KC_CONFIG_NAVIGATION
  ),

  [gaming_mod] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______           , _______ , _______  , _______ ,                 _______  , _______           , _______ , _______ , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state))
    {
      case navigation_mod:
      case dvorak_mod:
      case qwerty_mod:
      case gaming_mod:
        keyball_set_scroll_mode(true);
        break;
      default:
        keyball_set_scroll_mode(false);
    }
    return state;
}

// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CONFIG_NAVIGATION:
    case KC_CONFIG_DVORAK:
    case KC_CONFIG_QWERTY:
    case KC_CONFIG_GAMING:
      // Our logic will happen on presses, nothing is done on releases
      if (!record->event.pressed) {
        // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
        return false;
      }
      layer_move(keycode << 1);
      return false;

    // Process other keycodes normally
    default:
      return true;
  }
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
