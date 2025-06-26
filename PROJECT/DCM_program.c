/*
 * DCM_program.c
 *
 *  Created on: Feb 23, 2025
 *      Author: Fc
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "DCM_interface.h"
#include "DCM_config.h"


void DCM_voidInit(u8 copy_u8MotorId){
	switch(copy_u8MotorId)
	{
	case DCM_MOTORA:
		DIO_voidSetPinDirection(DCM_MOTOR_A_PORT_IN1,DCM_MOTOR_A_PIN_IN1,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_PORT_IN2,DCM_MOTOR_A_PIN_IN2,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_PORT_EN1,DCM_MOTOR_A_PORT_EN1,DIO_PIN_OUTPUT);
		break;
	case DCM_MOTORB:
		DIO_voidSetPinDirection(DCM_MOTOR_B_PORT_IN3,DCM_MOTOR_B_PIN_IN3,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_PORT_IN4,DCM_MOTOR_B_PIN_IN4,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_PORT_EN2,DCM_MOTOR_B_PORT_EN2,DIO_PIN_OUTPUT);
		break;
	}
}

void DCM_voidOn(u8 copy_u8MotorId,u8 copy_u8MotorDirection){
	switch(copy_u8MotorId)
	{
	case DCM_MOTORA:

			switch(copy_u8MotorDirection){
			DIO_voidSetPinValue(DCM_MOTOR_A_PORT_EN1,DCM_MOTOR_A_PORT_EN1,DIO_PIN_HIGH);
				case DCM_ROTATE_CLOCKWISE:
					DIO_voidSetPinValue(DCM_MOTOR_A_PORT_IN1,DCM_MOTOR_A_PIN_IN1,DIO_PIN_HIGH);
					DIO_voidSetPinValue(DCM_MOTOR_A_PORT_IN2,DCM_MOTOR_A_PIN_IN2,DIO_PIN_LOW);
					break;
				case DCM_ROTATE_COUNTERCLOCKWISE:
					DIO_voidSetPinValue(DCM_MOTOR_A_PORT_IN1,DCM_MOTOR_A_PIN_IN1,DIO_PIN_LOW);
					DIO_voidSetPinValue(DCM_MOTOR_A_PORT_IN2,DCM_MOTOR_A_PIN_IN2,DIO_PIN_HIGH);
					break;
		}

			break;

	case DCM_MOTORB:

			switch(copy_u8MotorDirection){
			DIO_voidSetPinValue(DCM_MOTOR_B_PORT_EN2,DCM_MOTOR_B_PORT_EN2,DIO_PIN_HIGH);
				case DCM_ROTATE_CLOCKWISE:
					DIO_voidSetPinValue(DCM_MOTOR_B_PORT_IN3,DCM_MOTOR_B_PIN_IN3,DIO_PIN_HIGH);
					DIO_voidSetPinValue(DCM_MOTOR_B_PORT_IN4,DCM_MOTOR_B_PIN_IN4,DIO_PIN_LOW);
					break;
				case DCM_ROTATE_COUNTERCLOCKWISE:
					DIO_voidSetPinValue(DCM_MOTOR_B_PORT_IN3,DCM_MOTOR_B_PIN_IN3,DIO_PIN_LOW);
					DIO_voidSetPinValue(DCM_MOTOR_B_PORT_IN4,DCM_MOTOR_B_PIN_IN4,DIO_PIN_HIGH);
					break;
				}

				break;

	}
}

void DCM_voidOff(u8 copy_u8MotorId){
	switch(copy_u8MotorId)
	{
	case DCM_MOTORA:
			DIO_voidSetPinValue(DCM_MOTOR_A_PORT_EN1,DCM_MOTOR_A_PORT_EN1,DIO_PIN_LOW);
			break;

	 case DCM_MOTORB:
			DIO_voidSetPinValue(DCM_MOTOR_B_PORT_EN2,DCM_MOTOR_B_PORT_EN2,DIO_PIN_LOW);
			break;

	}
}

void DCM_voidInitWithCtrlSpeed(u8 copy_u8MotorId){
	switch(copy_u8MotorId)
	{
	case DCM_MOTORA:
		DIO_voidSetPinDirection(DCM_MOTOR_A_PORT_IN1,DCM_MOTOR_A_PIN_IN1,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_PORT_IN2,DCM_MOTOR_A_PIN_IN2,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_PORT_EN1,DCM_MOTOR_A_PORT_EN1,DIO_PIN_OUTPUT);
		break;
	case DCM_MOTORB:
		DIO_voidSetPinDirection(DCM_MOTOR_B_PORT_IN3,DCM_MOTOR_B_PIN_IN3,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_PORT_IN4,DCM_MOTOR_B_PIN_IN4,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_PORT_EN2,DCM_MOTOR_B_PORT_EN2,DIO_PIN_OUTPUT);
		break;
	}
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	TIMER0_voidInit();
}

void DCM_voidOnwithCtrlSpeed(u8 copy_u8MotorId,u8 copy_u8MotorDirection,u8 copy_u8MotorSpeed){
	 TIMER0_PWMGenerateChannel(copy_u8MotorSpeed);
	switch(copy_u8MotorId)
	{
	case DCM_MOTORA:

			switch(copy_u8MotorDirection){

				case DCM_ROTATE_CLOCKWISE:
					DIO_voidSetPinValue(DCM_MOTOR_A_PORT_IN1,DCM_MOTOR_A_PIN_IN1,DIO_PIN_HIGH);
					DIO_voidSetPinValue(DCM_MOTOR_A_PORT_IN2,DCM_MOTOR_A_PIN_IN2,DIO_PIN_LOW);
					break;
				case DCM_ROTATE_COUNTERCLOCKWISE:
					DIO_voidSetPinValue(DCM_MOTOR_A_PORT_IN1,DCM_MOTOR_A_PIN_IN1,DIO_PIN_LOW);
					DIO_voidSetPinValue(DCM_MOTOR_A_PORT_IN2,DCM_MOTOR_A_PIN_IN2,DIO_PIN_HIGH);
					break;
		}

			break;

	case DCM_MOTORB:

			switch(copy_u8MotorDirection){

				case DCM_ROTATE_CLOCKWISE:
					DIO_voidSetPinValue(DCM_MOTOR_B_PORT_IN3,DCM_MOTOR_B_PIN_IN3,DIO_PIN_HIGH);
					DIO_voidSetPinValue(DCM_MOTOR_B_PORT_IN4,DCM_MOTOR_B_PIN_IN4,DIO_PIN_LOW);
					break;
				case DCM_ROTATE_COUNTERCLOCKWISE:
					DIO_voidSetPinValue(DCM_MOTOR_B_PORT_IN3,DCM_MOTOR_B_PIN_IN3,DIO_PIN_LOW);
					DIO_voidSetPinValue(DCM_MOTOR_B_PORT_IN4,DCM_MOTOR_B_PIN_IN4,DIO_PIN_HIGH);
					break;
				}

				break;

	}
}

void DCM_voidOffwithCtrlSpeed(){
TIMER0_voidStop();
}
