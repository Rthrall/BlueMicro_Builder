/*
Copyright 2018-2021 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other material>

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior w>
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF >
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN >
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

// Initialize matrix with nothing...
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {{
        {LAYER_1,    KC_KP_SLASH,    KC_KP_ASTERISK,     KC_KP_MINUS,},    
        {KC_KP_7,       KC_KP_8,        KC_KP_9,            KC_KP_PLUS,},
        {KC_KP_4,       KC_KP_5,        KC_KP_6,            KC_NO,},  
        {KC_KP_4,       KC_KP_5,        KC_KP_6,            KC_NO,},
        {KC_DOT,        KC_KP_0,        KC_COLN,            KC_KP_ENTER}
    }};


void setupKeymap() {
    
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
            KEYMAP(
        PRINT_BATTERY,    RESET,    KC_NO,    KC_NO, 
        KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,   
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    
        KC_NO,    KC_NO,    KC_NO,    KC_NO );
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
        }
    }

}
