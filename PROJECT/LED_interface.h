/*
 * LED.interface.h
 *
 *  Created on: Nov 19, 2024
 *      Author: Fc
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_FORWARD_CONNECTION  0
#define LED_REVERSED_CONNECTION  1

void LED_voidInit(u8 copy_u8LedPort,u8 copy_u8LedPin);
void LED_voidOn(u8 copy_u8LedPort,u8 copy_u8LedPin,u8 copy_LedConnectionType);
void LED_voidOff(u8 copy_u8LedPort,u8 copy_u8LedPin,u8 copy_LedConnectionType);
void LED_voidToggle(u8 copy_u8LedPort,u8 copy_u8LedPin);

#endif /* LED_INTERFACE_H_ */
