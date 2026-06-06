/*
This is the c configuration file for the keymap

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

#pragma once

#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
//#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE // 自動マウスレイヤー設定
#define AUTO_MOUSE_DEFAULT_LAYER 1 // 自動マウスレイヤーのレイヤー
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT // 左右判定
#define DYNAMIC_KEYMAP_LAYER_COUNT 6 // レイヤー数
#define KEYBALL_CPI_DEFAULT 1300 // マウス速度 (default: 500)
#define KEYBALL_SCROLL_DIV_DEFAULT 7 // スクロール速度 (default: 4)
#define OLED_TIMEOUT 25000 // ミリ秒 (default: 60000)

/* define OLED mirror */
#ifdef OLED_ENABLE
//#define SPLIT_TRANSPORT_MIRROR     //Slave側に同じ情報を表示
#define SPLIT_LAYER_STATE_ENABLE   //レイヤーごとに表示変更可能とする
#define SPLIT_LED_STATE_ENABLE     //ホストLEDの状態（Caps Lock、Num Lockなど）を同期
#endif

/* 他キーを押した瞬間にホールド確定 */
#define PERMISSIVE_HOLD
#define TAPPING_TERM 180

/* define OLED Scroll and timeout */
#ifdef OLED_ENABLE
#define OLED_SCROLL_TIMEOUT 5000      //5秒後にスクロール開始
#endif
