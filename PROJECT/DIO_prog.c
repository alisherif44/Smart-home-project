/*
 * DIO_prog.c

 *
 *  Created on: Nov 19, 2024
 *      Author: Fc
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_register.h"
#include "DIO_interface.h"


//pin
void DIO_voidSetPinDirection(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinDirection)
{
if(copy_u8PortId <=3 && copy_u8PinId<=7){
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
				CLR_BIT(DDRA_REG,copy_u8PinId);
				break;
			case DIO_PIN_OUTPUT:
				SET_BIT(DDRA_REG,copy_u8PinId);
				break;
		}
		break;
		case DIO_PORTB:
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
				CLR_BIT(DDRB_REG,copy_u8PinId);
				break;
			case DIO_PIN_OUTPUT:
				SET_BIT(DDRB_REG,copy_u8PinId);
				break;
		}
		break;
		case DIO_PORTC:
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
				CLR_BIT(DDRC_REG,copy_u8PinId);
				break;
			case DIO_PIN_OUTPUT:
				SET_BIT(DDRC_REG,copy_u8PinId);
				break;
		}
		break;
		case DIO_PORTD:
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
				CLR_BIT(DDRD_REG,copy_u8PinId);
				break;
			case DIO_PIN_OUTPUT:
				SET_BIT(DDRD_REG,copy_u8PinId);
				break;
		}
		break;
	}
}
else
{
	//return error
}

}

void DIO_voidSetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue){
	if(copy_u8PortId <=3 && copy_u8PinId<=7){
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
				CLR_BIT(PORTA_REG,copy_u8PinId);
				break;
			case DIO_PIN_HIGH:
				SET_BIT(PORTA_REG,copy_u8PinId);
				break;
		}
		break;
		case DIO_PORTB:
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
				CLR_BIT(PORTB_REG,copy_u8PinId);
				break;
			case DIO_PIN_HIGH:
				SET_BIT(PORTB_REG,copy_u8PinId);
				break;
		}
		break;
		case DIO_PORTC:
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
				CLR_BIT(PORTC_REG,copy_u8PinId);
				break;
			case DIO_PIN_HIGH:
				SET_BIT(PORTC_REG,copy_u8PinId);
				break;
		}
		break;
		case DIO_PORTD:
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
				CLR_BIT(PORTD_REG,copy_u8PinId);
				break;
			case DIO_PIN_HIGH:
				SET_BIT(PORTD_REG,copy_u8PinId);
				break;
		}
		break;
	}
}
else
{
	//return error
}
}

void DIO_voidGetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8* copy_pu8PinValue){
if(copy_u8PortId <=3 && copy_u8PinId<=7 && copy_pu8PinValue!=NULL){
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			* copy_pu8PinValue=GET_BIT(PINA_REG,copy_u8PinId);
		break;
		case DIO_PORTB:
			* copy_pu8PinValue=GET_BIT(PINB_REG,copy_u8PinId);
		break;
		case DIO_PORTC:
			* copy_pu8PinValue=GET_BIT(PINC_REG,copy_u8PinId);
		break;
		case DIO_PORTD:
			* copy_pu8PinValue=GET_BIT(PIND_REG,copy_u8PinId);
		break;
	}
}
else
{
//return error
}

}

void DIO_voidTogglePinValue(u8 copy_u8PortId,u8 copy_u8PinId){
if(copy_u8PortId <=3 && copy_u8PinId<=7){
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
			TOG_BIT(PORTA_REG,copy_u8PinId);
		break;
		case DIO_PORTB:
			TOG_BIT(PORTB_REG,copy_u8PinId);
		break;
		case DIO_PORTC:
			TOG_BIT(PORTC_REG,copy_u8PinId);
		break;
		case DIO_PORTD:
			TOG_BIT(PORTD_REG,copy_u8PinId);
		break;
	}

}
else
{
//return error
}
}
//port
void DIO_voidSetPortDirection(u8 copy_u8PortId,u8 copy_u8PortDirection){
if(copy_u8PortId <=3){
	switch(copy_u8PortId){
	case DIO_PORTA:
		DDRA_REG=copy_u8PortDirection;
	break;
	case DIO_PORTB:
		DDRB_REG=copy_u8PortDirection;
	break;
	case DIO_PORTC:
		DDRC_REG=copy_u8PortDirection;
	break;
	break;
	case DIO_PORTD:
		DDRD_REG=copy_u8PortDirection;
	break;
	}

}
else
{
	//return false
}
}
void DIO_voidSetPortValue(u8 copy_u8PortId,u8 copy_u8PortValue){
if(copy_u8PortId <=3){
	switch(copy_u8PortId){
		case DIO_PORTA:
			PORTA_REG=copy_u8PortValue;
		break;
		case DIO_PORTB:
			PORTB_REG=copy_u8PortValue;
		break;
		case DIO_PORTC:
			PORTC_REG=copy_u8PortValue;
		break;
		break;
		case DIO_PORTD:
			PORTD_REG=copy_u8PortValue;
		break;
		}

}
else
{
		//return false
}
}
void DIO_voidGetPortValue(u8 copy_u8PortId,u8* copy_pu8PortValue){
if(copy_u8PortId <=3){
		switch(copy_u8PortId){
			case DIO_PORTA:
				*copy_pu8PortValue=PINA_REG;
			break;
			case DIO_PORTB:
				*copy_pu8PortValue=PINB_REG;

			break;
			case DIO_PORTC:
				*copy_pu8PortValue=PINC_REG;

			break;
			break;
			case DIO_PORTD:
				*copy_pu8PortValue=PIND_REG;

			break;
			}

}
else
{
		//return false
}

}
void DIO_voidTogglePortValue(u8 copy_u8PortId){
if(copy_u8PortId <=3){
		switch(copy_u8PortId){
				case DIO_PORTA:
					PORTA_REG= ~(PORTA_REG);
				break;
				case DIO_PORTB:
					PORTB_REG= ~(PORTB_REG);

				break;
				case DIO_PORTC:
					PORTC_REG= ~(PORTC_REG);

				break;
				break;
				case DIO_PORTD:
					PORTD_REG= ~(PORTD_REG);

				break;
				}

}
else
{
		//return false
}

}
void DIO_voidActivePinInPllUpResistor(u8 copy_u8PortId,u8 copy_u8PinId){
	if(copy_u8PortId<=3 && copy_u8PinId<=7)
	{
		switch(copy_u8PortId)
		{
		case DIO_PORTA:SET_BIT(PORTA_REG,copy_u8PinId);
			break;
		case DIO_PORTB:SET_BIT(PORTB_REG,copy_u8PinId);
			break;
		case DIO_PORTC:SET_BIT(PORTC_REG,copy_u8PinId);
			break;
		case DIO_PORTD:SET_BIT(PORTD_REG,copy_u8PinId);
			break;


		}
	}
	else
	{
		//return false
	}
}

void DIO_voidActivePortInPllUpResistor(u8 copy_u8PortId){
	if(copy_u8PortId <=3){
		switch(copy_u8PortId){
			case DIO_PORTA:
				PORTA_REG=DIO_PORT_HIGH;
			break;
			case DIO_PORTB:
				PORTB_REG=DIO_PORT_HIGH;
			break;
			case DIO_PORTC:
				PORTC_REG=DIO_PORT_HIGH;
			break;
			break;
			case DIO_PORTD:
				PORTD_REG=DIO_PORT_HIGH;
			break;
			}

	}
	else
	{
			//return false
	}
}
