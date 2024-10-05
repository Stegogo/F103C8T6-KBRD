/*
 * keyboard_layout.c
 *
 *  Created on: Sep 27, 2024
 *      Author: maru
 */


#include "keyboard_layout.h"

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* VARIABLES                                                       			*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
const uint16_t KBRD[] = {
	KEY_NONE, KEY_NONE, KEY_LEFT, KEY_DOWN, KEY_RIGHT,
};

const LAYOUT KBRD_LAYOUT = {
    .keys = KBRD,
    .key_count = sizeof(KBRD) / sizeof(uint16_t)
};

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* INTERFACE                                                       			*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
uint16_t kbrd_mapKey(uint8_t current_layer, uint16_t key_position, uint16_t key_count) {
    for (uint8_t i = current_layer; i >= 0; i--) {
    	LAYOUT layout = KBRD_LAYOUT;
        if (key_position > layout.key_count - 1) {
            return KEY_NONE;
        }
        uint16_t key = layout.keys[key_position];
        if (key != KEY_NONE) {
            return key;
        }
    }
    return KEY_NONE;
}
