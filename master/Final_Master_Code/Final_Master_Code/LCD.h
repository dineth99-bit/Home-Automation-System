/*
 * LCD.h
 *
 * Created: 8/19/2023 11:56:33 PM
 *  Author: Dineth Jayakody
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_config.h"
#define CLR_SCREEN           0X01
#define DISPLAY_ON_CURSOR_ON 0X0E
#define EIGHT_BIT_MODE       0X38
#define FOUR_BIT_MODE_I      0X02
#define FOUR_BIT_MODE_II     0X28

/*
	Function Name        : LCD_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize the LCD screen to be ready for use.
*/
void LCD_vInit(void);

/*
	Function Name        : LCD_vSend_cmd
	Function Returns     : void
	Function Arguments   : uint8 cmd
	Function Description : Send the given command to be executed by the LCD.
*/
void LCD_vSend_cmd(uint8 cmd);

/*
	Function Name        : LCD_vSend_char
	Function Returns     : void
	Function Arguments   : uint8 data
	Function Description : Print the given character on the LCD screen at the current cursor location.
*/
void LCD_vSend_char(uint8 data);

/*
	Function Name        : LCD_vSend_string
	Function Returns     : void
	Function Arguments   : char *data
	Function Description : Print the given string at the current cursor location.
*/
void LCD_vSend_string(char *data);

/*
	Function Name        : LCD_clearscreen
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear all printed characters and move the cursor to the first location at the first line
*/
void LCD_clearscreen(void);

/*
	Function Name        : LCD_movecursor
	Function Returns     : void
	Function Arguments   : uint8 row ,uint8 column
	Function Description : Move the cursor at the given row and column (Rows 1:2 , Cols 1:16)
*/
void LCD_movecursor(uint8 row,uint8 column);

#endif /* LCD_H_ */