/*
 * keyboard_layout.h
 *
 *  Created on: Sep 27, 2024
 *      Author: maru
 */

#ifndef INC_KEYBOARD_LAYOUT_H_
#define INC_KEYBOARD_LAYOUT_H_

#include "stdint.h"

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* STRUCTS                                                                  */
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
typedef struct {
    const uint16_t * keys;
    const uint16_t key_count;
} LAYOUT;

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* VARIABLES                                                                */
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
const uint16_t KEY_NONE = 0x00; 	// Key not pressed
const uint16_t KEY_RIGHT = 0x04; 	// Keyboard Right Arrow
const uint16_t KEY_LEFT = 0x05; 	// Keyboard Left Arrow
const uint16_t KEY_DOWN = 0x06; 	// Keyboard Down Arrow
const uint16_t KEY_UP = 0x07; 		// Keyboard Up Arrow

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* FUNCTION PROTOTYPES                                                      */
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
uint16_t kbrd_mapKey(uint8_t current_layer, uint16_t key_position, uint16_t key_count);

#endif /* INC_KEYBOARD_LAYOUT_H_ */
