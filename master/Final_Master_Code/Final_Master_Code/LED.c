/*
 * LED.c
 *
 * Created: 8/19/2023 11:58:51 PM
 *  Author: Dineth Jayakody
 */ 

#include "LED.h"
void LED_vInit(uint8 portname,uint8 pinnumber)
{
	DIO_vsetPINDir(portname,pinnumber,1);//Set the given pin in the given port as an output
}
void LED_vTurnOn(uint8 portname,uint8 pinnumber)
{
	DIO_write(portname,pinnumber,1);//Set the given pin in the given port to one(on)
}
void LED_vTurnOff(uint8 portname,uint8 pinnumber)
{
	DIO_write(portname,pinnumber,0);//Set the given pin in the given port to zero(off)
}
void LED_vToggle(uint8 portname,uint8 pinnumber)
{
	DIO_toggle(portname,pinnumber);//Set the given pin in the given port to zero if it is one or set it to one if it is zero
}
uint8 LED_u8ReadStatus(uint8 portname,uint8 pinnumber)
{
	return DIO_u8read(portname,pinnumber);//return the current status of the given pin
}
