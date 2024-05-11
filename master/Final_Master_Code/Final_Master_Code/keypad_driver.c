/*
 * keypad_driver.c
 *
 * Created: 8/19/2023 11:53:26 PM
 *  Author: Dineth Jayakody
 */ 


#include "keypad_driver.h"
void keypad_vInit(void)
{
	/* Initialize first four bits in keypad as output pins */
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_FIRST_PIN,1);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_SECOND_PIN,1);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_THIRD_PIN,1);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_FOURTH_PIN,1);
	/******************************************************/
	/* initalize second four bits in keypad as input pins */
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_FIFTH_PIN,0);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_SIXTH_PIN,0);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_SEVENTH_PIN,0);
	DIO_vsetPINDir(KEYPAD_PORT,KEYPAD_EIGHTH_PIN,0);
	/*****************************************************/
	/*connect pull up resistance to the input pins*/
	DIO_vconnectpullup(KEYPAD_PORT,KEYPAD_FIFTH_PIN,1);
	DIO_vconnectpullup(KEYPAD_PORT,KEYPAD_SIXTH_PIN,1);
	DIO_vconnectpullup(KEYPAD_PORT,KEYPAD_SEVENTH_PIN,1);
	DIO_vconnectpullup(KEYPAD_PORT,KEYPAD_EIGHTH_PIN,1);
	/****************************************************/
}
uint8 keypad_u8check_press(void)
{
	uint8 arr[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}}; //keypad buttons
	//uint8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}}; //keypad buttons
	uint8 row; //which indicate the given output  pin
	uint8 coloumn; //which indicate the given input pin
	uint8 key_pressed_indicator; //the variable  which contain the key pressed
	
	uint8 returnval=NOT_PRESSED; //the variable contain the value which will be returned which will be key pressed or not pressed in case of no key pressed
	for(row=0;row<4;row++)
	{
		/*stop the work of keypad firstly*/
		DIO_write(KEYPAD_PORT,KEYPAD_FIRST_PIN,1);
		DIO_write(KEYPAD_PORT,KEYPAD_SECOND_PIN,1);
		DIO_write(KEYPAD_PORT,KEYPAD_THIRD_PIN,1);
		DIO_write(KEYPAD_PORT,KEYPAD_FOURTH_PIN,1);
		/*************************************/
		_delay_ms(20);
		DIO_write(KEYPAD_PORT,row,0);//write 0 to the first pin in keypad (output pin from MC)
		
		for(coloumn=0;coloumn<4;coloumn++)
		{
			key_pressed_indicator=DIO_u8read(KEYPAD_PORT,(coloumn+4)); // read the input pins of MC which connected to keypad
			if(key_pressed_indicator==0)// will be 0 only if any key pressed
			{
				returnval=arr[row][coloumn]; //put the selected pressed key to the retrurnval
				break; // break from the loop
			}
		}
	}
	return returnval ; //return the pressed key in case of key pressed or return 0xff in case of no key pressed
}