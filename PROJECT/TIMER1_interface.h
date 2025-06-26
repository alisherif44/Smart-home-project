/*
 * TIMER1_interface.h
 *
 *  Created on: Dec 20, 2024
 *      Author: Fc
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_voidInit();
void TIMER1_voidStart();
void TIMER1_voidStop();
void TIMER1_voidSetDelay_msCompareMatchMode(u32 copy_u16Delay_ms);
void TIMER1_PWMGenerateChannel(u16 copy_u16Frequency_hz ,f32 copy_f32DutyCycley);
void TIMER1_voidSetCallBackOVF(void (* copy_pFunAction)(void));
void TIMER1_voidSetCallBackCTC(void (* copy_pFunAction)(void));

#define TIMER1_NORMAL_MODE0          1
#define TIMER1_CTCA_MODE4            2
#define TIMER1_FAST_PWM_MODE14       3

#endif /* TIMER1_INTERFACE_H_ */
