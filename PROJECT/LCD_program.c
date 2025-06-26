/*
 * LCD_program.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Fc
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>
#include"DIO_interface.h"
#include"LCD_interface.h"
#include"LCD_config.h"
#include"LCD_private.h"

void LCD_voidInit(){
	DIO_voidSetPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);

	_delay_ms(40);
	//function set
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN ,DIO_PIN_LOW);
	PRV_voidWriteHalfPort(0b0010);
	PRV_voidEnableTriggerWrite();

	LCD_voidSendCommand(0b00101000);


	_delay_ms(45);
	//display on off
	LCD_voidSendCommand(0b00001111);

	_delay_ms(45);
	//display clear
	LCD_voidSendCommand(0b00000001);

	_delay_ms(2);
	//entery mode set
	LCD_voidSendCommand(0b00000110);

}

static void PRV_voidEnableTriggerWrite(){
	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);

}

static void PRV_voidWriteHalfPort(u8 copy_u8Value){

	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Value,0));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Value,1));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Value,2));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Value,3));
}

void LCD_voidDisplayChar(u8 copy_u8Data){
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);

	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);

	PRV_voidWriteHalfPort(copy_u8Data>>4);
	PRV_voidEnableTriggerWrite();

	PRV_voidWriteHalfPort(copy_u8Data);
	PRV_voidEnableTriggerWrite();

}

void LCD_voidSendCommand(u8 copy_u8Cmnd){
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);

	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN ,DIO_PIN_LOW);

	PRV_voidWriteHalfPort(copy_u8Cmnd>>4);
	PRV_voidEnableTriggerWrite();

	PRV_voidWriteHalfPort(copy_u8Cmnd);
	PRV_voidEnableTriggerWrite();

}

void LCD_voidDisplayString(u8* copy_Pu8String){
	if (copy_Pu8String != NULL){
		u8 local_u8counter=0;
		while(copy_Pu8String[local_u8counter] != '\0'){
			LCD_voidDisplayChar(copy_Pu8String[local_u8counter]);
			local_u8counter++;
		}
	}
	else{
		//return error
	}
}
void LCD_voidClear(){
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
}

void LCD_voidShift(u8 copy_u8ShifttingDirection){
	switch(copy_u8ShifttingDirection)
	{
	case SHIFT_CURSOR_LEFT:
		LCD_voidSendCommand(0b00010000);
		break;
	case SHIFT_CURSOR_RIGHT:
		LCD_voidSendCommand(0b00010100);
		break;
	case SHIFT_DISPLAY_LEFT:
		LCD_voidSendCommand(0b00011000);
		break;
	case SHIFT__DISPLAY_RIGHT:
		LCD_voidSendCommand(0b00011100);
		break;
	}
}

void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber,u8 copy_u8Position){
	u8 local_u8address=copy_u8Position+copy_u8LineNumber * 0x40;
	SET_BIT(local_u8address,7);
	LCD_voidSendCommand(local_u8address);

}

void LCD_voidDisplayNumber(u32 copy_u32Number){
 u32 local_u32ReversedNumber=1;
 	 if(copy_u32Number ==0){
 		 LCD_voidDisplayChar('0');
 	 }
 	 else{
 		 while(copy_u32Number !=0){
 			local_u32ReversedNumber= (local_u32ReversedNumber * 10) + (copy_u32Number % 10);
 			copy_u32Number/=10;
 		 }

 	 do{
 		LCD_voidDisplayChar((local_u32ReversedNumber%10) +'0');
 		local_u32ReversedNumber/=10;
 	 }
 	 while(local_u32ReversedNumber !=1);

 	 }
}
