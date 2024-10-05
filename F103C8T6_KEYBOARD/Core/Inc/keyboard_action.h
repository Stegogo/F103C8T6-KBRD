/*
 * keyboard_action.h
 *
 *  Created on: Sep 28, 2024
 *      Author: maru
 */

#ifndef INC_KEYBOARD_ACTION_H_
#define INC_KEYBOARD_ACTION_H_

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* INCLUDES                                                                  */
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#include "usb_device.h"
#include "usbd_hid.h"

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* VARIABLES                                                                */
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
extern USBD_HandleTypeDef hUsbDeviceFS;
typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
}keyboardReportDesc;

extern keyboardReportDesc HIDkeyboard;
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* FUNCTION PROTOTYPES                                                      */
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
uint8_t read_keyboard();
void poll_keyboard();

#endif /* INC_KEYBOARD_ACTION_H_ */
