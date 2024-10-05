/*
 * keyboard_action.c
 *
 *  Created on: Sep 28, 2024
 *      Author: maru
 */
#include "main.h"
#include "keyboard_action.h"
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
uint8_t read_keyboard()
{
	HAL_GPIO_WritePin (ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_RESET); 	 //Pull the R1 low
	HAL_GPIO_WritePin (ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_SET);  	// Pull the R2 High

	if (!(HAL_GPIO_ReadPin (COL2_GPIO_Port, COL2_Pin))) {
		while (!HAL_GPIO_ReadPin (COL2_GPIO_Port, COL2_Pin));   // wait till the button is pressed
		return 1;
	}

	HAL_GPIO_WritePin (ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_SET);  //Pull the R1 low
	HAL_GPIO_WritePin (ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_RESET);  // Pull the R2 High

	if (!(HAL_GPIO_ReadPin (COL1_GPIO_Port, COL1_Pin))) {
		while (!HAL_GPIO_ReadPin (COL1_GPIO_Port, COL1_Pin));   // wait till the button is pressed
		return 2;
	}

	if (!(HAL_GPIO_ReadPin (COL2_GPIO_Port, COL2_Pin))) {
		while (!HAL_GPIO_ReadPin (COL2_GPIO_Port, COL2_Pin));   // wait till the button is pressed
		return 3;
	}

	if (!(HAL_GPIO_ReadPin (COL3_GPIO_Port, COL3_Pin))) {
		while (!HAL_GPIO_ReadPin (COL3_GPIO_Port, COL3_Pin));   // wait till the button is pressed
		return 4;
	}
	return 0;
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void poll_keyboard()
{
	/*
	 *  79:	Keyboard Right Arrow : 	0x4F
	 *  80:	Keyboard Left Arrow : 	0x50
	 *  81:	Keyboard Down Arrow : 	0x51
	 *  82:	Keyboard Up Arrow : 	0x52
	 */


	uint8_t key = read_keyboard();
	//HIDkeyboard.KEYCODE1 = key;
	if (key == 0)  HIDkeyboard.KEYCODE1 = 0x01; // no key pressed
	if (key == 1)  HIDkeyboard.KEYCODE1 = 0x1E;
	if (key == 2)  HIDkeyboard.KEYCODE1 = 0x1F;
	if (key == 3)  HIDkeyboard.KEYCODE1 = 0x20;
	if (key == 4)  HIDkeyboard.KEYCODE1 = 0x21;
	USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *)&HIDkeyboard, sizeof (HIDkeyboard));
	HAL_Delay (20);
	HIDkeyboard.KEYCODE1 = 0x00;  // release key
	USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *)&HIDkeyboard, sizeof (HIDkeyboard));
}
