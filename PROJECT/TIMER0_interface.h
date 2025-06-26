/*
 * TIMER0_interface.h
 *
 *  Created on: Dec 16, 2024
 *      Author: Fc
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit();
void TIMER0_voidStart();
void TIMER0_voidStop();
void TIMER0_voidSetDelay_msCompareMatchMode(u16 copy_u16Delay_ms);
void TIMER0_PWMGenerateChannel(u8 copy_u8DutyCycle);
void TIMER0_voidSetCallBackOVF(void (* copy_pFunAction)(void));
void TIMER0_voidSetCallBackCTC(void (* copy_pFunAction)(void));

#define TIMER0_NORMAL_MODE             1
#define TIMER0_CTC_MODE                2
#define TIMER0_FAST_PWM_MODE           3
#endif /* TIMER0_INTERFACE_H_ */
