/*
 * Final_Slave_Code.c
 *
 * Created: 8/19/2023 11:16:25 PM
 * Author : Dineth Jayakody
 */ 

#include "SPI.h"
#include "STD_MESSAGES.h"
#include "DIO.h"
#include "LED.h"
#include "APP_slave_Macros.h"


int main(void)
{

	SPI_vInitSlave();//initialize the SPI as a slave
	
	/* initialization of output pins of connected leds or devices */
	LED_vInit(FAN_PORT,FAN_PIN);
	LED_vInit(ROOM1_PORT,ROOM1_PIN);
	LED_vInit(ROOM2_PORT,ROOM2_PIN);
	LED_vInit(ROOM3_PORT,ROOM3_PIN);
	LED_vInit(ROOM4_PORT,ROOM4_PIN);
	
	uint8 request = DEFAULT_ACK;//the value that is received from the master
	uint8 response = DEFAULT_ACK;//the values that is sent back to the master
	
	while(1)
	{
		request = SPI_ui8TransmitRecive(DEFAULT_ACK);//wait for the master to start the transmitting
		//ALL Messages are defined in STD_messages.h
		
		switch (request)
		{
			
			
			/*********************************   STATUS COMMANDS ********************************/
			//commands related to send the current status back to the master
			case ROOM1_STATUS:
			if (LED_u8ReadStatus(ROOM1_PORT,ROOM1_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(ROOM1_PORT,ROOM1_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			case ROOM2_STATUS:
			if (LED_u8ReadStatus(ROOM2_PORT,ROOM2_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(ROOM2_PORT,ROOM2_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			case ROOM3_STATUS:
			if (LED_u8ReadStatus(ROOM3_PORT,ROOM3_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(ROOM3_PORT,ROOM3_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			case ROOM4_STATUS:
			if (LED_u8ReadStatus(ROOM4_PORT,ROOM4_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(ROOM4_PORT,ROOM4_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			
			case FAN_STATUS:
			if (LED_u8ReadStatus(FAN_PORT,FAN_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(FAN_PORT,FAN_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			
			
			
			/*********************************   TURN ON COMMANDS ********************************/
			case ROOM1_TURN_ON:
			LED_vTurnOn(ROOM1_PORT,ROOM1_PIN);//turn on the led of room 1
			break;//break the switch case
			
			case ROOM2_TURN_ON:
			LED_vTurnOn(ROOM1_PORT,ROOM2_PIN);//turn on the led of room 2
			break;//break the switch case
			
			case ROOM3_TURN_ON:
			LED_vTurnOn(ROOM3_PORT,ROOM3_PIN);//turn on the led of room 3
			break;//break the switch case
			
			case ROOM4_TURN_ON:
			LED_vTurnOn(ROOM4_PORT,ROOM4_PIN);//turn on the led of room 4
			break;//break the switch case
			
			case FAN_TURN_ON:
			LED_vTurnOn(FAN_PORT,FAN_PIN);//turn on the led of the TV
			break;//break the switch case
			
			
			
			/*********************************   TURN OFF COMMANDS ********************************/
			
			case ROOM1_TURN_OFF:
			LED_vTurnOff(ROOM1_PORT,ROOM1_PIN);//turn off the led of room 1
			break;//break the switch case
			
			case ROOM2_TURN_OFF:
			LED_vTurnOff(ROOM2_PORT,ROOM2_PIN);//turn off the led of room 2
			break;//break the switch case
			
			case ROOM3_TURN_OFF:
			LED_vTurnOff(ROOM3_PORT,ROOM3_PIN);//turn off the led of room 3
			break;//break the switch case
			
			case ROOM4_TURN_OFF:
			LED_vTurnOff(ROOM4_PORT,ROOM4_PIN);//turn off the led of room 4
			break;//break the switch case
			
			case FAN_TURN_OFF:
			LED_vTurnOff(FAN_PORT,FAN_PIN);//turn off the led of the TV
			break;//break the switch case
			
		}
	}
}


