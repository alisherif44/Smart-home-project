/*
 * TIMER1_program.c
 *
 *  Created on: Dec 20, 2024
 *      Author: Fc
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_interface.h"
#include "TIMER1_config.h"
#include "TIMER1_register.h"

static void (*PRV_pFunCallBackOVF)(void) = NULL;
static void (*PRV_pFunCallBackCTC)(void) = NULL;
static u16 PRV_u16CTC_counter;

void TIMER1_voidInit(){
#if TIMER1_MODE ==TIMER1_NORMAL_MODE0
		//select normal mode
		CLR_BIT(TCCR1A_REG,WGM10);
		CLR_BIT(TCCR1A_REG,WGM11);
		CLR_BIT(TCCR1B_REG,WGM12);
		CLR_BIT(TCCR1B_REG,WGM13);

		//set preload value
		TCNT1_u16_REG=TIMER1_PRELOAD_VALUE;

		//select overflow interupt enable
		SET_BIT(TIMSK_REG,TOIE1);

#elif TIMER1_MODE ==TIMER1_CTCA_MODE4
		//select CTC mode4
		CLR_BIT(TCCR1A_REG,WGM10);
		CLR_BIT(TCCR1A_REG,WGM11);
		SET_BIT(TCCR1B_REG,WGM12);
		CLR_BIT(TCCR1B_REG,WGM13);

		//set OCR value
		OCR1A_u16_REG=TIMER1_OUTPUT_COMPARE_VALUE_A;

		//select ctc interupt enable
		SET_BIT(TIMSK_REG,OCIE1A);
#elif TIMER1_MODE ==TIMER1_FAST_PWM_MODE14
		//select fast pwm mode14
		CLR_BIT(TCCR1A_REG,WGM10);
		SET_BIT(TCCR1A_REG,WGM11);
		SET_BIT(TCCR1B_REG,WGM12);
		SET_BIT(TCCR1B_REG,WGM13);

		//non inverting
		CLR_BIT(TCCR1A_REG,COM1A0);
		SET_BIT(TCCR1A_REG,COM1A1);

#endif

}
void TIMER1_PWMGenerateChannel(u16 copy_u16Frequency_hz ,f32 copy_f32DutyCycley){
	if(copy_f32DutyCycley<=100){
		ICR1_u16_REG=((1000000UL/copy_u16Frequency_hz)/4)-1;
		OCR1A_u16_REG=((copy_f32DutyCycley * (ICR1_u16_REG+1))/100)-1;


		//select PRESCALER 64
		SET_BIT(TCCR1B_REG,CS10);
		SET_BIT(TCCR1B_REG,CS11);
		CLR_BIT(TCCR1B_REG,CS12);
	}
	else{
		//return error
	}


}
void TIMER1_voidStart(){
	//select PRESCALER 64
	SET_BIT(TCCR1B_REG,CS10);
	SET_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);

}
void TIMER1_voidStop(){
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
}

void TIMER1_voidSetDelay_msCompareMatchMode(u32 copy_u16Delay_ms){
	//Under Condition Tick Time = 4Ms, OCR0 = 62499
	OCR1A_u16_REG = 62499;
	PRV_u16CTC_counter = (copy_u16Delay_ms * 1000) / (62500 * 4);
}

void TIMER1_voidSetCallBackOVF(void (* copy_pFunAction)(void)){
	if (copy_pFunAction !=NULL){
		PRV_pFunCallBackOVF=copy_pFunAction;
	}
	else
	{
		//error
	}

}

void TIMER1_voidSetCallBackCTC(void (* copy_pFunAction)(void)){
	if (copy_pFunAction !=NULL){
		PRV_pFunCallBackCTC=copy_pFunAction;
	}
	else
	{
		//error
	}

}

void __vector_9(void) __attribute((signal));
void __vector_9(void){

	static u16 local_u16Counter;
	local_u16Counter++;

	if(TIMER1_OVERFLOW_COUNTER ==local_u16Counter){
		TCNT1_u16_REG=TIMER1_PRELOAD_VALUE;
		local_u16Counter=0;

		if(PRV_pFunCallBackOVF !=NULL){
			PRV_pFunCallBackOVF();
		}
	}

}

void __vector_7(void) __attribute((signal));
void __vector_7(void){

	static u16 local_u16Counter;
	local_u16Counter++;

	if(PRV_u16CTC_counter ==local_u16Counter){

		local_u16Counter=0;

		if(PRV_pFunCallBackCTC !=NULL){
			PRV_pFunCallBackCTC();
		}
	}

}


