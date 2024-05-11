/*
 * DIO.h
 *
 * Created: 8/19/2023 11:47:08 PM
 *  Author: Dineth Jayakody
 */ 

#ifndef DIO_H_
#define DIO_H_
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_config_master.h"
#include "STD_Types.h"

/*
	Function Name        : DIO_vsetPINDir
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber,uint8 direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_vsetPINDir(uint8 portname,uint8 pinnumber,uint8 direction);

/*
	Function Name        : DIO_write
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber,uint8 outputvalue
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
*/
void DIO_write(uint8 portname,uint8 pinnumber,uint8 outputvalue);

/*
	Function Name        : DIO_u8read
	Function Returns     : uint8
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value was low
*/
uint8 DIO_u8read(uint8 portname,uint8 pinnumber);

/*
	Function Name        : DIO_toggle
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 pinnumber
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_toggle(uint8 portname,uint8 pinnumber);

/*
	Function Name        : DIO_write_port
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 portvalue
	Function Description : Write the value to all port pins.
*/
void DIO_write_port(uint8 portname,uint8 portvalue);

/*
	Function Name        : clear_high_nibble
	Function Returns     : void
	Function Arguments   : uint8 portname
	Function Description : Clear the value of the high nibble of the given port.
*/
void clear_high_nibble(uint8 portname) ;

/*
	Function Name        : dio_write_highnibble
	Function Returns     : void
	Function Arguments   : uint8 portname,uint8 value
	Function Description : Write the high bits of the value given to the high nibble pins of the given port
*/
void dio_write_highnibble(uint8 portname,uint8 value);

/*
	Function Name        : DIO_vconnectpullup
	Function Returns     : void
	Function Arguments   : uint8 portname ,uint8 pinnumber, uint8 connect_pullup
	Function Description : Connect and disconnect pull up resistor to the given pin at the given port 
*/
void DIO_vconnectpullup(uint8 portname ,uint8 pinnumber, uint8 connect_pullup);

#endif /* DIO_H_ */