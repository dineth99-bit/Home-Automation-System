/*
 * menu.h
 *
 * Created: 8/20/2023 12:00:22 AM
 *  Author: Dineth Jayakody
 */ 

#ifndef MENU_H_
#define MENU_H_

#include "main_config.h"
#include "STD_MESSAGES.h"
#include "STD_Types.h"
#include "keypad_driver.h"
#include "SPI.h"
#include "LCD.h"

/*
	Function Name        : ui8ComparePass
	Function Returns     : uint8
	Function Arguments   : const uint8* pass1,const uint8* pass2,const uint8 size
	Function Description : Compare two arrays of bytes and return True in case they are identical and return false in case they are different .
*/
uint8 ui8ComparePass(const uint8* pass1,const uint8* pass2,const uint8 size);

/*
	Function Name        : vMenuOption
	Function Returns     : void
	Function Arguments   : const uint8 u8SelectedRoom,const uint8 u8LoginMode
	Function Description : Show the sub menus of room 1 ,room 2 ,room 3,room 4 , tv
*/
void vMenuOption(const uint8 u8SelectedRoom,const uint8 u8LoginMode);

/*
	Function Name        : u8GetKeyPressed
	Function Returns     : uint8
	Function Arguments   : const uint8 u8LoginMode
	Function Description : Wait the user to press key then return the key pressed or return (NOT_PRESSED = 0xFF) in case of timeout.
*/
uint8 u8GetKeyPressed(const uint8 u8LoginMode);

#endif /* MENU_H_ */