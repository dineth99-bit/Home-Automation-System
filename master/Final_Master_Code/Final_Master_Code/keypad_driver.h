/*
 * keypad_driver.h
 *
 * Created: 8/19/2023 11:55:02 PM
 *  Author: Dineth Jayakody
 */ 

#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_
#define NOT_PRESSED 0xff
#include "DIO.h"

/*
	Function Name        : keypad_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize the keypad.
*/
void keypad_vInit(void);

/*
	Function Name        : keypad_u8check_press
	Function Returns     : uint8
	Function Arguments   : void
	Function Description : Returns the pressed key or return NOT_PRESSED if no keys are pressed.
*/
uint8 keypad_u8check_press(void);

#endif /* KEYPAD_DRIVER_H_ */