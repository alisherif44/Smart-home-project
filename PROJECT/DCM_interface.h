/*
 * DCM_interface.h
 *
 *  Created on: Feb 23, 2025
 *      Author: Fc
 */

#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

void DCM_voidInit(u8 copy_u8MotorId);
void DCM_voidOn(u8 copy_u8MotorId,u8 copy_u8MotorDirection);
void DCM_voidOff(u8 copy_u8MotorId);
void DCM_voidInitWithCtrlSpeed(u8 copy_u8MotorId);
void DCM_voidOnwithCtrlSpeed(u8 copy_u8MotorId,u8 copy_u8MotorDirection,u8 copy_u8MotorSpeed);
void DCM_voidOffwithCtrlSpeed();

#define DCM_MOTORA                      0
#define DCM_MOTORB                      1

#define DCM_ROTATE_CLOCKWISE            0
#define DCM_ROTATE_COUNTERCLOCKWISE     1


#endif /* DCM_INTERFACE_H_ */
