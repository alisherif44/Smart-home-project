/*
 * EXTI_interface.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Fc
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum{
	EXTI_INT0=0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_intSrc_t;

typedef enum{
	EXTI_RISING_EDGE=0,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_intSenceControl_t;

void EXTI_voidInit(EXTI_intSrc_t copy_tIntSource,EXTI_intSenceControl_t copy_tIntSenceControl);
void EXTI_voidEnable(EXTI_intSrc_t copy_tIntSource);
void EXTI_voidDisable(EXTI_intSrc_t copy_tIntSource);

void EXTI_voidSetCallBackINT0(void (* copy_pFunAction)(void)); //its function to have the adrress of function on the main of the ISR
void EXTI_voidSetCallBackINT1(void (* copy_pFunAction)(void));
void EXTI_voidSetCallBackINT2(void (* copy_pFunAction)(void));


#endif /* EXTI_INTERFACE_H_ */
