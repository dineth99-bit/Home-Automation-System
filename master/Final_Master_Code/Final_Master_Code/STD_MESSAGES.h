/*
 * STD_MESSAGES.h
 *
 * Created: 8/20/2023 12:01:47 AM
 *  Author: Dineth Jayakody
 */ 

#ifndef STD_MESSAGES_H_
#define STD_MESSAGES_H_

#define ROOM1_STATUS    0x11
#define ROOM2_STATUS    0x12
#define ROOM3_STATUS    0x13
#define ROOM4_STATUS    0x14
#define FAN_STATUS 		0x15


#define ROOM1_TURN_ON    0x21
#define ROOM2_TURN_ON    0x22
#define ROOM3_TURN_ON    0x23
#define ROOM4_TURN_ON    0x24
#define FAN_TURN_ON      0x25

#define ROOM1_TURN_OFF    0x31
#define ROOM2_TURN_OFF    0x32
#define ROOM3_TURN_OFF    0x33
#define ROOM4_TURN_OFF    0x34
#define FAN_TURN_OFF 	  0x35

#define DEFAULT_ACK    0xFF
#define DEMAND_RESPONSE 0xFF

#define ON_STATUS   0x01
#define OFF_STATUS  0x00

#endif