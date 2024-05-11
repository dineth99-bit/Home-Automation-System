/*
 * DIO.c
 *
 * Created: 8/19/2023 11:46:42 PM
 *  Author: Dineth Jayakody
 */ 

#include <avr/io.h>
#include "std_macros.h"
#include "DIO.h"
void DIO_vsetPINDir(uint8 portname,uint8 pinnumber,uint8 direction)
{
	switch(portname)
	{
		
		
		case 'A':
		if(direction==1)
		{
			SET_BIT(DDRA,pinnumber);//Set the direction of the given pin in port A as output
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);//Set the direction of the given pin in port A as input
		}
		break;
		case 'B':
		if(direction==1)
		{
			SET_BIT(DDRB,pinnumber);//Set the direction of the given pin in port B as output
		}
		else
		{
			CLR_BIT(DDRB,pinnumber);//Set the direction of the given pin in port B as input
		}
		break;
		case 'C':
		if(direction==1)
		{
			SET_BIT(DDRC,pinnumber);//Set the direction of the given pin in port C as output
		}
		else
		{
			CLR_BIT(DDRC,pinnumber);//Set the direction of the given pin in port C as input
		}
		break;
		case 'D':
		if(direction==1)
		{
			SET_BIT(DDRD,pinnumber);//Set the direction of the given pin in port D as output
		}
		else
		{
			CLR_BIT(DDRD,pinnumber);//Set the direction of the given pin in port D as input
		}
		break;
		case 'K':
		if(direction==1)
		{
			SET_BIT(DDRK,pinnumber);//Set the direction of the given pin in port D as output
		}
		else
		{
			CLR_BIT(DDRK,pinnumber);//Set the direction of the given pin in port D as input
		}
		break;
		case 'F':
		if(direction==1)
		{
			SET_BIT(DDRF,pinnumber);//Set the direction of the given pin in port D as output
		}
		else
		{
			CLR_BIT(DDRF,pinnumber);//Set the direction of the given pin in port D as input
		}
		break;
		default: break;
	}
}


void DIO_write(uint8 portname,uint8 pinnumber,uint8 outputvalue)
{
	switch(portname)
	{
		case 'A' :
		
		if(outputvalue==1)
		{
			SET_BIT(PORTA,pinnumber);//Set the value of the given pin in port A as High
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);//Set the value of the given pin in port A as Low
		}
		break ;
		case 'B':
		
		if(outputvalue==1)
		{
			SET_BIT(PORTB,pinnumber);//Set the value of the given pin in port B as High
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);//Set the value of the given pin in port B as Low
		}
		break ;
		case 'C' :
		
		if(outputvalue==1)
		{
			SET_BIT(PORTC,pinnumber);//Set the value of the given pin in port C as High
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);//Set the value of the given pin in port C as Low
		}
		break ;
		case 'D':
		
		if(outputvalue==1)
		{
			SET_BIT(PORTD,pinnumber);//Set the value of the given pin in port D as High
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);//Set the value of the given pin in port D as Low
		}
		break ;
		case 'F':
		
		if(outputvalue==1)
		{
			SET_BIT(PORTF,pinnumber);//Set the value of the given pin in port D as High
		}
		else
		{
			CLR_BIT(PORTF,pinnumber);//Set the value of the given pin in port D as Low
		}
		break ;
		case 'K':
		
		if(outputvalue==1)
		{
			SET_BIT(PORTK,pinnumber);//Set the value of the given pin in port D as High
		}
		else
		{
			CLR_BIT(PORTK,pinnumber);//Set the value of the given pin in port D as Low
		}
		break ;
		default: break ;
	}
}


uint8 DIO_u8read(uint8 portname,uint8 pinnumber)
{
	uint8 return_value=0;
	switch(portname)
	{
		case 'A' :
		return_value=Read_bIT(PINA,pinnumber);//Read the value from the given pin in port A
		break;
		
		case 'B' :
		return_value=Read_bIT(PINB,pinnumber);//Read the value from the given pin in port B
		break;
		
		case 'C' :
		return_value=Read_bIT(PINC,pinnumber);//Read the value from the given pin in port C
		break;
		
		case 'D' :
		return_value=Read_bIT(PIND,pinnumber);//Read the value from the given pin in port D
		break;
		
		case 'F' :
		return_value=Read_bIT(PINF,pinnumber);//Read the value from the given pin in port A
		break;
		
		case 'K' :
		return_value=Read_bIT(PINK,pinnumber);//Read the value from the given pin in port A
		break;
		
		default: break;
	}
	return return_value ;
}

void DIO_toggle(uint8 portname,uint8 pinnumber)
{
	switch(portname)
	{
		case 'A':
		TOG_BIT(PORTA,pinnumber);//Toggle the value of the given pin in port A
		break;
		case 'B':
		TOG_BIT(PORTB,pinnumber);//Toggle the value of the given pin in port B
		break;
		case 'C':
		TOG_BIT(PORTC,pinnumber);//Toggle the value of the given pin in port C
		break;
		case 'D':
		TOG_BIT(PORTD,pinnumber);//Toggle the value of the given pin in port D
		break;
		case 'F':
		TOG_BIT(PORTF,pinnumber);//Toggle the value of the given pin in port F
		break;
		case 'K':
		TOG_BIT(PORTK,pinnumber);//Toggle the value of the given pin in port K
		break;
		default: break;
	}
}
void DIO_write_port(uint8 portname,uint8 portvalue)
{
	switch(portname)
	{
		case 'A' :
		PORTA=portvalue; //Write the given value to the port A
		break ;
		case 'B':
		PORTB=portvalue; //Write the given value to the port B
		break ;
		case 'C' :
		PORTC=portvalue; //Write the given value to the port C
		break ;
		case 'D':
		PORTD=portvalue; //Write the given value to the port D
		break ;
		case 'F':
		PORTF=portvalue; //Write the given value to the port F
		break ;
		case 'K':
		PORTK=portvalue; //Write the given value to the port K
		break ;
		
		default: break ;
	}
}
void dio_write_highnibble(uint8 portname,uint8 value)
{
	switch(portname)
	{
		case 'A' :
		PORTA|=(value&0xf0);//Set only the high nibble of the port A by the given value
		break ;
		case 'B':
		PORTB|=(value&0xf0);//Set only the high nibble of the port B by the given value
		break ;
		case 'C' :
		PORTC|=(value&0xf0);//Set only the high nibble of the port C by the given value
		break ;
		case 'D':
		PORTD|=(value&0xf0);//Set only the high nibble of the port D by the given value
		break ;
		case 'F':
		PORTF|=(value&0xf0);//Set only the high nibble of the port D by the given value
		break ;
		case 'K':
		PORTK|=(value&0xf0);//Set only the high nibble of the port D by the given value
		break ;
		default: break ;
		
	}
}

void clear_high_nibble(uint8 portname)
{
	switch(portname)
	{
		case 'A' :
		PORTA&=0x0f;//set the value of the high nibble of the port A as low
		break ;
		case 'B':
		PORTB&=0x0f;//set the value of the high nibble of the port B as low
		break ;
		case 'C' :
		PORTC&=0x0f;//set the value of the high nibble of the port C as low
		break ;
		case 'D':
		PORTD&=0x0f;//set the value of the high nibble of the port D as low
		break ;
		case 'F':
		PORTF&=0x0f;//set the value of the high nibble of the port D as low
		break ;
		case 'K':
		PORTK&=0x0f;//set the value of the high nibble of the port D as low
		break ;
		default: break ;
		
	}
}

void DIO_vconnectpullup(uint8 portname ,uint8 pinnumber, uint8 connect_pullup)
{
	switch(portname)
	{
		/* Connect or disconnect the pull up resistance to the given pin in port A */
		case 'A':
		if(connect_pullup==1)
		{
			CLR_BIT(MCUCR,PUD);
			CLR_BIT(DDRA,pinnumber);
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		/* Connect or disconnect the pull up resistance to the given pin in port B */
		case 'B':
		if(connect_pullup==1)
		{
			CLR_BIT(MCUCR,PUD);
			CLR_BIT(DDRB,pinnumber);
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		/* Connect or disconnect the pull up resistance to the given pin in port C */
		case 'C':
		if(connect_pullup==1)
		{
			CLR_BIT(MCUCR,PUD);
			CLR_BIT(DDRC,pinnumber);
			SET_BIT(PORTC,pinnumber);
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		/* Connect or disconnect the pull up resistance to the given pin in port D */
		case 'D':
		if(connect_pullup==1)
		{
			CLR_BIT(MCUCR,PUD);
			CLR_BIT(DDRD,pinnumber);
			SET_BIT(PORTD,pinnumber);
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		
		case 'F':
		if(connect_pullup==1)
		{
			CLR_BIT(MCUCR,PUD);
			CLR_BIT(DDRF,pinnumber);
			SET_BIT(PORTF,pinnumber);
		}
		else
		{
			CLR_BIT(PORTF,pinnumber);
		}
		break;
		
		case 'K':
		if(connect_pullup==1)
		{
			CLR_BIT(MCUCR,PUD);
			CLR_BIT(DDRK,pinnumber);
			SET_BIT(PORTK,pinnumber);
		}
		else
		{
			CLR_BIT(PORTK,pinnumber);
		}
		break;
		
	}
}