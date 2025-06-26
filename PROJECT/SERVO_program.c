/*
 * SERVO_program.c
 *
 *  Created on: Feb 25, 2025
 *      Author: Fc
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER1_interface.h"
#include "SERVO_interface.h"


void SERVO_voidInit(){
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	TIMER1_voidInit();

}
void SERVO_voidOn(f32 copy_f32Angle){
	f32 cpoy_f32DutyCycleRatio;
	if(copy_f32Angle>=-90 && copy_f32Angle <=90){
		cpoy_f32DutyCycleRatio=( copy_f32Angle/36 )+7.5;
	}
	else{
		//return error
	}

	TIMER1_PWMGenerateChannel(50 ,cpoy_f32DutyCycleRatio);
}
