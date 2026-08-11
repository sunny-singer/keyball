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
  dvorak = 0,
  dvorak_mod,
  qwerty,
  qwerty_mod,
  aml,
  navigation,
  gaming,
  gaming_mod_1,
  gaming_mod_2
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default 

  [dvorak] = LAYOUT_universal(
    KC_TAB   , KC_SCLN  , KC_COMM  , KC_DOT   , KC_P     , KC_Y     ,                                        KC_F     , KC_G     , KC_C     , KC_R     , KC_L     , _______  ,
    KC_LSFT  , KC_A     , KC_O     , KC_E     , KC_U     , KC_I     ,                                        KC_D     , KC_H     , KC_T     , KC_N     , KC_S     , KC_MINS  ,
    KC_LCTL  , KC_QUOTE , KC_Q     , KC_J     , KC_K     , KC_X     ,                                        KC_B     , KC_M     , KC_W     , KC_V     , KC_Z     , KC_RSFT  ,
               _______  , _______  , MO(navigation) , KC_SPC , MO(dvorak_mod) ,                    KC_BSPC , KC_ENT              , _______  , _______  , _______
  ),

  [dvorak_mod] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
              _______ , _______           , _______ , _______  , _______ ,                 _______  , _______           , _______ , _______ , _______
  ),

  [qwerty] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , _______  ,
    KC_LSFT  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , _______  ,
    KC_LCTL  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , _______  ,
               _______  , _______  , MO(navigation)  , KC_SPC , MO(qwerty_mod) ,                   KC_BSPC , KC_ENT              , _______  , _______  , _______
  ),

  [qwerty_mod] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
              _______ , _______           , _______ , _______  , _______ ,                 _______  , _______           , _______ , _______ , _______
  ),

  [aml] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , KC_BTN1 , _______ , _______ , KC_BTN2 , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______           , _______ , _______ , _______ ,                  _______  , _______           , _______  , _______ , _______
  ),

  [navigation] = LAYOUT_universal(
    _______ , _______ , _______ , KC_UP , _______ , TO(dvorak) ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , TO(qwerty) ,                                    _______ , AML_TO  , _______ , _______ , _______ , _______ ,
    _______ , SSNP_FRE , SSNP_HOR , SSNP_VRT , _______ , TO(gaming) ,                                 _______ , _______ , _______ , _______ , _______ , _______ ,
                 _______ , _______           , _______ , _______ , _______ ,               C(KC_C)  , C(KC_V)           , _______ , _______ , _______
  ),

  [gaming] = LAYOUT_universal(
    _______  , KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     ,                                 KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , _______  ,
    _______  , KC_LSFT  , KC_A     , KC_S     , KC_D     , KC_F     ,                                 KC_H     , KC_BTN1  , KC_K     , KC_L     , KC_BTN2  , _______  ,
    _______  , KC_LCTL  , KC_Z     , KC_X     , KC_C     , KC_V     ,                                 KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , _______  ,
               _______  , _______  , MO(gaming_mod_2) , KC_SPC , MO(gaming_mod_1) ,         KC_BSPC , KC_ENT              , _______  , _______  , TO(navigation)
  ),

  [gaming_mod_1] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                       _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
              _______ , _______           , _______ , _______  , _______ ,                 _______  , _______           , _______ , _______ , _______
  ),

  [gaming_mod_2] = LAYOUT_universal(
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
      case navigation:
      case gaming_mod_2:
        keyball_set_scroll_mode(true);
        break;
      default:
        keyball_set_scroll_mode(false);
    }
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
