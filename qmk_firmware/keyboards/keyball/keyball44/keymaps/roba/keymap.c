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

enum custom_keycodes {
    MAIL1 = SAFE_RANGE,
    MAIL2,
    MAIL3,
    MAIL4,
    PASS1,
    PASS2,
    PASS3,
    PASS4,
    PASS5,
    PASS6,
    PASS7,
    WIN_SHFT_S,
    OLED_IN,  // OLED ページ変更
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E         , KC_R          , KC_T        ,                                      KC_Y        , KC_U     , KC_I     , KC_O     , KC_P          , KC_DEL        ,
    KC_TAB   , KC_A     , KC_S     , KC_D         , KC_F          , KC_G        ,                                      KC_H        , KC_J     , KC_K     , KC_L     , KC_SCLN       , KC_MINS       ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C         , KC_V          , KC_B        ,                                      KC_N        , KC_M     , KC_COMM  , KC_DOT   , LT(1,KC_SLSH) , LT(5,KC_INT1) ,
                         KC_LALT   , KC_LGUI      ,LCTL_T(KC_GRV) , LT(1,KC_SPC), LT(3,KC_DEL),       LT(4,KC_BSPC)  , LT(2,KC_ENT), _______  , _______  , LT(3,KC_LBRC)
  ),

  [1] = LAYOUT_universal(
    _______  ,  KC_F1   , KC_F2      , KC_F3      , KC_F4      , KC_F5    ,                                             KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , _______  ,
  	_______  ,  SCRL_TO , C(KC_PGUP) , _______    , C(KC_PGDN) , KC_HOME  ,                                             KC_BTN4  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_BTN3  , KC_F11   ,
    _______  ,  SCRL_MO , KC_PGUP    , S(KC_LCTL) , KC_PGDN    , KC_END   ,                                             KC_BTN5  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , KC_F12   ,
                            _______  , _______    , _______    , _______  , _______  ,                       _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  ,S(KC_QUOT) , KC_7     , KC_8    , KC_9     , S(KC_8)   ,                                                 S(KC_9)   , S(KC_1)    , S(KC_6)  , KC_LBRC   , S(KC_4)    , _______   ,
    _______  ,S(KC_SCLN) , KC_4     , KC_5    , KC_6     , KC_RBRC   ,                                                 KC_NUHS   , KC_MINS    , S(KC_EQL), S(KC_3)   , KC_QUOT    , S(KC_2)   ,
    _______  ,S(KC_MINS) , KC_1     , KC_2    , KC_3     , S(KC_RBRC),                                                 S(KC_NUHS), S(KC_INT1) , KC_EQL   , S(KC_7)   , S(KC_SLSH) , S(KC_INT3),
                           KC_0     , KC_DOT  , _______  , _______   , _______  ,                            _______  , _______  , _______    , _______  , S(KC_5)
  ),

  [3] = LAYOUT_universal(
    _______   , _______  , AML_I50  , AML_D50  , AML_TO   , SCRL_DVI ,                                                  SSNP_VRT , SSNP_HOR , SSNP_FRE , _______  , _______   , _______  ,
    _______   , _______  , _______  , _______  , _______  , SCRL_DVD ,                                                  XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______   , _______  ,
  S(KC_LCTL)  , CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  ,                                                  _______  , _______  , _______  , _______  , QK_REBOOT , KBC_SAVE ,
                           QK_BOOT  , KBC_RST  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                                   KC_CALC      , KC_SCRL     , KC_VOLU  , KC_NUM   , _______  , _______  ,
    PASS7    , PASS5    , PASS3    , PASS1    , MAIL3    , MAIL1    ,                                                   RALT(KC_PSCR), S(KC_CAPS)  , KC_VOLD  , _______  , _______  , _______  ,
    _______  , PASS6    , PASS4    , PASS2    , MAIL4    , MAIL2    ,                                                   KC_PSCR      , WIN_SHFT_S  , KC_MUTE  , _______  , _______  , _______  ,
                          _______  , _______  , _______  , _______  , _______  ,                             _______  , _______      , _______     , _______  , _______
  ),

  [5] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                                   _______  , KC_MS_ACCEL0  , KC_MS_ACCEL1  , KC_MS_ACCEL2  , _______  , _______  ,
    _______  , _______  , _______  , KC_MS_U  , _______  , _______  ,                                                   _______  , _______  , KC_WH_U  , _______  , _______  , _______  ,
    _______  , _______  , KC_MS_L  , KC_MS_D  , KC_MS_R  , OLED_IN  ,                                                   _______  , KC_WH_L  , KC_WH_D  , KC_WH_R  , _______  , _______  ,
                          _______  , _______  , KC_GRV   , _______  , KC_GRV   ,                             _______  , _______  , _______  , _______  , _______
  ),

};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"
#    include "custom_oled.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return rotation;
    } else {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oledkit_render_info_user(void) {
    keyball_oled_render_mymain();
}

// サブ側OLEDの表示処理
void oledkit_render_logo_user(void) {
    keyball_oled_render_mysub();
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {

         case MAIL1:
            // arai_akira@nec.com
            SEND_STRING("arai");
            tap_code16(S(KC_INT1));  // "_"
            SEND_STRING("akira");
            tap_code16(KC_LBRC);     // "@"
            SEND_STRING("nec.com");
            return false;

         case MAIL2:
            // akira-arai@nec.com
            SEND_STRING("akira-arai");
            tap_code16(KC_LBRC);     // "@"
            SEND_STRING("nec.com");
            return false;

        case MAIL3:
            // volvo_v70_1999@yahoo.co.jp
            SEND_STRING("volvo");
            tap_code16(S(KC_INT1));  // "_"
            SEND_STRING("v70");
            tap_code16(S(KC_INT1));  // "_"
            SEND_STRING("1999");
            tap_code16(KC_LBRC);     // "@"
            SEND_STRING("yahoo.co.jp");
            return false;

        case MAIL4:
            // volvo.v70.1999@gmail.com
            SEND_STRING("volvo.v70.1999");
            tap_code16(KC_LBRC);       // "@"
            SEND_STRING("gmail.com");
            return false;

       case PASS1:
            // Ep0s6_zip
            SEND_STRING("Ep0s6");
            tap_code16(S(KC_INT1));  // "_"
            SEND_STRING("zip");
            return false;

       case PASS2:
            // Ep0s6_zip
            SEND_STRING("Ep0s7");
            tap_code16(S(KC_INT1));  // "_"
            SEND_STRING("zip");
            return false;

        case PASS3:
            // v0is4!_ZIP
            SEND_STRING("v0is4!");
            tap_code16(S(KC_INT1));    // "_"
            SEND_STRING("ZIP");
            return false;

        case PASS4:
            // aakira05q
            SEND_STRING("aakira05q");
            return false;

        case PASS5:
            // Aakira0502@
            SEND_STRING("Aakira0502");
            tap_code16(KC_LBRC);       // "@"
            return false;

        case PASS6:
            // Aakira05@
            SEND_STRING("Aakira05");
            tap_code16(KC_LBRC);       // "@"
            return false;

        case PASS7:
            // Estima0502@
            SEND_STRING("Estima0502");
            tap_code16(KC_LBRC);       // "@"
            return false;

        case WIN_SHFT_S:
            if (record->event.pressed) {
                // Shift + Win + S を一発送信
                tap_code16(S(G(KC_S)));
            }

            return false; // 通常処理をスキップ
        case OLED_IN:
            change_page(record->event.pressed);
            return true;
    }

    return true;
}

