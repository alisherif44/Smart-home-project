#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "LED_interface.h"

void LED_voidInit(u8 copy_u8LedPort,u8 copy_u8LedPin){
	DIO_voidSetPinDirection(copy_u8LedPort,copy_u8LedPin,DIO_PIN_OUTPUT);
}
void LED_voidOn(u8 copy_u8LedPort,u8 copy_u8LedPin,u8 copy_LedConnectionType){
	switch(copy_LedConnectionType){
	case LED_FORWARD_CONNECTION:
		DIO_voidSetPinValue(copy_u8LedPort,copy_u8LedPin,DIO_PIN_HIGH);
		break;
	case LED_REVERSED_CONNECTION:
		DIO_voidSetPinValue(copy_u8LedPort,copy_u8LedPin,DIO_PIN_LOW);
		break;

	}

}
void LED_voidOff(u8 copy_u8LedPort,u8 copy_u8LedPin,u8 copy_LedConnectionType){
	switch(copy_LedConnectionType){
	case LED_FORWARD_CONNECTION:
		DIO_voidSetPinValue(copy_u8LedPort,copy_u8LedPin,DIO_PIN_LOW);
		break;
	case LED_REVERSED_CONNECTION:
		DIO_voidSetPinValue(copy_u8LedPort,copy_u8LedPin,DIO_PIN_HIGH);
		break;

	}
}
void LED_voidToggle(u8 copy_u8LedPort,u8 copy_u8LedPin){
	 DIO_voidTogglePinValue(copy_u8LedPort,copy_u8LedPin);
}

