/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        LAYER_1,       KC_KP_SLASH,    KC_KP_ASTERISK,     KC_KP_MINUS,  
        KC_KP_7,       KC_KP_8,        KC_KP_9,            KC_KP_PLUS,  
        KC_KP_4,       KC_KP_5,        KC_KP_6,            KC_NO,  
        KC_KP_1,       KC_KP_2,        KC_KP_3,            KC_NO,  
        KC_COLN,       KC_KP_0,        KC_DOT,             KC_KP_ENTER 
    )};


void setupKeymap() {

    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    KC_NO,            RESET,    KC_NO,    KC_NO,  \
    PRINT_BATTERY,    KC_NO,    KC_NO,    KC_NO,  \
    KC_NO,            KC_NO,    KC_NO,    KC_NO,  \ 
    KC_NO,            KC_UP,    KC_NO,    KC_NO,  \
    KC_LEFT,          KC_DOWN,  KC_RIGHT, KC_NO   \
    );
    ADDLAYER(_L1, Method::PRESS , layer1);
    #ifdef BLUEMICRO_CONFIGURED_DISPLAY
        OLED.setStatusDisplayCallback(updateDisplay);
    #endif
}

void updateDisplay(PersistentState* cfg, DynamicState* stat)
{
    #ifdef BLUEMICRO_CONFIGURED_DISPLAY
    u8g2.setFontMode(1);    // Transparent
    u8g2.setFontDirection(0);
    battery(22,19,stat->vbat_per);
    printline(0,28,stat->peer_name_prph);

    char buffer [50];
    u8g2.setFont(u8g2_font_helvB12_tf); // choose a suitable font
    switch(stat->layer)
    {
        case _QWERTY:     u8g2.drawStr(0,128,""); break;
        case _LOWER:      u8g2.drawStr(0,128,"L");break;
        case _RAISE:     u8g2.drawStr(0,128,"R");break;
        case _ADJUST:     u8g2.drawStr(0,128,"A");break;
        case _EXTRAL:     u8g2.drawStr(0,128,"EL");break;
        case _EXTRAR:     u8g2.drawStr(0,128,"ER");break; 
        case _MACROL:     u8g2.drawStr(0,128,"ML");break;
        case _MACROR:     u8g2.drawStr(0,128,"MR");break; 
        case _MACRO:     u8g2.drawStr(0,128,"M");break;    
    }
    #endif
}



#endif
