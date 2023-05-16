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
        KC_DOT,        KC_KP_0,        KC_COLN,            KC_KP_ENTER 
    )};


void setupKeymap() {

uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
  PRINT_BATTERY, RESET,   KC_NO,   KC_NO, \
  KC_NO,         KC_NO,   KC_NO,   KC_NO,  \
  KC_NO,         KC_NO,   KC_NO,   KC_NO,    \
  KC_NO,         KC_NO,   KC_NO,   KC_NO,    \
  KC_NO,         KC_NO,   KC_NO,   KC_NO   \
);

}
#endif
