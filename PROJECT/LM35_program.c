/*
 * LM35_program.c
 *
 *  Created on: Dec 12, 2024
 *      Author: Fc
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LM35_interface.h"

void LM35_voidInit(u8 copy_u8ChannelId){
	DIO_voidSetPinDirection(DIO_PORTA,copy_u8ChannelId,DIO_PIN_INPUT);
	ADC_voidInit(ADC_REFERANCE_INTERNAL);
}
void LM35_voidGetTemprature(u8 copy_u8ChannelId,u16* copy_pu16Temprature){
	if(copy_pu16Temprature != NULL){
	u16 local_u16DigitalValue,local_u16AnalogValue;

	ADC_voidGetDigigtalValue(copy_u8ChannelId,&local_u16DigitalValue);

	local_u16AnalogValue=((u32)local_u16DigitalValue * 2560)/ 1024;

	*copy_pu16Temprature=local_u16AnalogValue/10;
	}
	else{
		//return error
	}
}
