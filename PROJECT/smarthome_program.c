/*
 * smarthome_program.c
 *
 *  Created on: Feb 27, 2025
 *      Author: Fc
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "UART_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "ADC_interface.h"
#include "TIMER0_interface.h"
#include "TIMER1_interface.h"
#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "smarthome_interface.h"
#include "LM35_interface.h"
#include "DCM_interface.h"
#include "smarthome_config.h"
#include "SERVO_interface.h"
#include "LED_interface.h"

BOOL SmartHome_voidCheckPassword(){

u32 local_u32realpass=SmartHome_u32WR_Rpassword();

	u8 local_u8val;
	u32 local_u8pass=0;
	u8 local_u8counter=0;

	LCD_voidInit();
	KPD_voidInit();

	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_OUTPUT);//buzzer

	LCD_voidGoToSpecificPosition(0,2);
	LCD_voidDisplayString((u8*)"welcome home");
	_delay_ms(1000);
	LCD_voidClear();
	LCD_voidDisplayString((u8*)"Enter The Pass");
	_delay_ms(1000);
	LCD_voidClear();

	while(local_u8counter<3){
		while(1){
	KPD_voidGetValue(&local_u8val);
	if(local_u8val !=KPD_NOT_PRESSED){

		if(local_u8val == '='){  //if user write the password
			if(local_u32realpass ==local_u8pass)
			{ //if the password is correct
				DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);  //Rx
				DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT); //Tx
				UART_voidInit();

				LCD_voidClear();
				LCD_voidDisplayString((u8*)"Right pass");
				UART_voidTxString((u8*)"Welcome to your sweet home <3 ");
				local_u8pass=0;
				_delay_ms(1000);
				LCD_voidClear();
				local_u8counter=3;
				//UART_voidTxString((u8*)"Welcome your sweet home ");
				return TRUE;
			}

			else
			{
				local_u8counter++;

				if(local_u8counter !=3)
				{   //if the password is wrong and he has a trial
				DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);  //Rx
				DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT); //Tx
				UART_voidInit();
				LCD_voidClear();
				LCD_voidDisplayString((u8*)"wrong pass");
				LCD_voidGoToSpecificPosition(1,0);
				LCD_voidDisplayString((u8*)"try again");
				_delay_ms(1000);
				LCD_voidClear();

				local_u8pass=0;  //clear the variable to write again the passwrod

				UART_voidTxString((u8*)"Someone try to log in ");
				}

				else{
					LCD_voidClear();
					LCD_voidDisplayString((u8*)"wrong pass");
					_delay_ms(1000);
					LCD_voidClear();
				   }

				if(local_u8counter ==3)
				{   //if the password is wrong and he has not any trial
					DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);  //Rx
					DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT); //Tx
					UART_voidInit();

					DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_PIN_HIGH);//buzzer
					LCD_voidDisplayString((u8*)"system blocked");
					_delay_ms(1000);
					LCD_voidClear();
					UART_voidTxString((u8*)"ALARM IS ON ! ");
					return FALSE;
				}
				break;

			}

		}
		else
		{   //to convert the string to number
		local_u8pass=(local_u8pass*10) + (local_u8val -'0');
		LCD_voidDisplayChar('*');
		}

      }
	}
}
}

void SmartHome_voidTempratureDCmotor(){

	u8 temprature;
	//ADC lm35(temp)
	LM35_voidInit(LM35_ADC_CHANNEL_3);
	DCM_voidInitWithCtrlSpeed(DCM_MOTORA);
	while(1){
		LCD_voidDisplayString((u8*)"Temp is:");
		LCD_voidDisplayNumber(temprature);
		LCD_voidDisplayChar('C');

		LM35_voidGetTemprature(LM35_ADC_CHANNEL_3,&temprature);

		if(temprature>=0 && temprature< 15){
			DCM_voidOffwithCtrlSpeed();
			LCD_voidGoToSpecificPosition(1,0);
			LCD_voidDisplayString((u8*)"AC SYSTEM OFF");
			//UART_voidTxString((u8*)"AC SYSTEM OFF ");
		}
		else if(temprature>=15 && temprature< 25){
			DCM_voidOnwithCtrlSpeed(DCM_MOTORA,DCM_ROTATE_CLOCKWISE,30);
			LCD_voidGoToSpecificPosition(1,0);
			LCD_voidDisplayString((u8*)"AC SYST ON 30%");
			//UART_voidTxString((u8*)"AC SYST ON 30% ");

		}
		else if(temprature>=25 && temprature< 35){
			DCM_voidOnwithCtrlSpeed(DCM_MOTORA,DCM_ROTATE_CLOCKWISE,75);
			LCD_voidGoToSpecificPosition(1,0);
			LCD_voidDisplayString((u8*)"AC SYST ON 75%");
			//UART_voidTxString((u8*)"AC SYST ON 75% ");

		}
		else if(temprature>=35 && temprature<= 50){
			DCM_voidOnwithCtrlSpeed(DCM_MOTORA,DCM_ROTATE_CLOCKWISE,100);
			LCD_voidGoToSpecificPosition(1,0);
			LCD_voidDisplayString((u8*)"AC SYST ON 100%");
			//UART_voidTxString((u8*)"AC SYST ON 100% ");
		}
		_delay_ms(500);
		LCD_voidClear();

	}

}

void SmartHome_voidOpenDoorservoCmotor(){
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);  //Rx
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT); //Tx
	UART_voidInit();

	SERVO_voidInit();
	SERVO_voidOn(90);  //duty cycle 10%
	LCD_voidDisplayString((u8*)"Door Is Opened ");
	UART_voidTxString((u8*)"Door Is Opened ");
	_delay_ms(800);
	LCD_voidClear();

}

u32  SmartHome_u32WR_Rpassword(){
	u8 i=0;
	u32 local_pass=0;
	u8 local_u8data1[]=SMART_HOME_PASS;
	u8 local_u8data2[10];
	EEPROM_voidInit();
	EEPROM_voidWritePage(8,7,local_u8data1);
	EEPROM_voidReadPage(8,7,local_u8data2);

	while(local_u8data2[i] != '\0'){  //to convert the string to number
		local_pass=(local_pass*10) + (local_u8data2[i] -'0');
		i++;
	}
	return 	local_pass;
}

void SmartHome_voidLedEnable()
{
DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);  //5 lamps
DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);        //5 lamps

DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_OUTPUT);  //dimmer lamp
DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);      //dimmer lamp
}

void SmartHome_voidLedDisable(){

	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW); //5 lamps
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_LOW); //dimmer lamp
}

