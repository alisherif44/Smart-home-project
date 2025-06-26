/*
 * main.c
 *
 *  Created on: Feb 27, 2025
 *      Author: Fc
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "smarthome_interface.h"
#include "GI_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "UART_interface.h"

void EXTI1_action(void){
	//for flame sensor
	u8 local_u8pinvalu;
	DIO_voidGetPinValue(DIO_PORTD,DIO_PIN3,&local_u8pinvalu);

	if(local_u8pinvalu){
		//if flame sensor is on

		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);  //Rx
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT); //Tx
		UART_voidInit();

	DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);//PUMP
	DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_PIN_HIGH); //BUZZER
	UART_voidTxString((u8*)"THERE IS A FIRE!! ");

	}
	else
	{
		//if flame sensor is off
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT);  //Rx
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT); //Tx
		UART_voidInit();

		DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);//PUMP
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_PIN_LOW);//BUZZER
		UART_voidTxString((u8*)"THE FIRE IS GONE ");
	}

}


int main(){
	GI_voidEnable();
	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN7, DIO_PIN_OUTPUT); //PUMP
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT); //INT1
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_OUTPUT); //buzzer
	EXTI_voidInit(EXTI_INT1,EXTI_ANY_LOGICAL_CHANGE);

	EXTI_voidSetCallBackINT1(&EXTI1_action);
	EXTI_voidEnable(EXTI_INT1);



	if(SmartHome_voidCheckPassword()== TRUE){


		SmartHome_voidOpenDoorservoCmotor();
		SmartHome_voidLedEnable();

		SmartHome_voidTempratureDCmotor();
	}

	else{
		SmartHome_voidLedDisable();

	}
	while(1){
		DIO_voidSetPinValue(DIO_PORTD,DIO_PIN6,DIO_PIN_HIGH); //buzzer

	}
}


