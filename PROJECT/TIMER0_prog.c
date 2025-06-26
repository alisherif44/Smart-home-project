/*
 * TIMER0_prog.c
 *
 *  Created on: Dec 16, 2024
 *      Author: Fc
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMER0_register.h"

static void (*PRV_pFunCallBackOVF)(void) = NULL;
static void (*PRV_pFunCallBackCTC)(void) = NULL;
static u16 PRV_u16CTC_counter;

void TIMER0_voidInit(){
#if TIMER0_MODE ==TIMER0_NORMAL_MODE

		//select normal mode
		CLR_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);

		//set preload value
		TCNT0_REG=TIMER0_PRELOAD_VALUE;

		//select overflow interupt enable
		SET_BIT(TIMSK_REG,TOIE0);

#elif TIMER0_MODE ==TIMER0_CTC_MODE
		//select CTC mode
		CLR_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);

		//set OCR value
		OCR0_REG=TIMER0_OUTPUT_COMPARE_VALUE ;

		//select output compare interupt enable
		SET_BIT(TIMSK_REG,OCIE0);

#elif TIMER0_MODE ==TIMER0_FAST_PWM_MODE
		//select fast pwm mode mode
		SET_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);


		//select non inverting mode
		CLR_BIT(TCCR0_REG,COM00);
		SET_BIT(TCCR0_REG,COM01);


#endif

}

void TIMER0_PWMGenerateChannel(u8 copy_u8DutyCycle){
	if(copy_u8DutyCycle <=100){
		//set OCR value
		OCR0_REG= ((copy_u8DutyCycle *256)/100)-1 ;

		//select PRESCALER 64
		SET_BIT(TCCR0_REG,CS00);
		SET_BIT(TCCR0_REG,CS01);
		CLR_BIT(TCCR0_REG,CS02);
	}
	else{
		//return error
	}
}

void TIMER0_voidStart(){
	//start for normal mode and ctc mode only
	//select PRESCALER 64
	SET_BIT(TCCR0_REG,CS00);
	SET_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);

}

void TIMER0_voidStop(){
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);
}

void TIMER0_voidSetDelay_msCompareMatchMode(u16 copy_u16Delay_ms){
	//Under Condition Tick Time = 4Ms, OCR0 = 249
	OCR0_REG = TIMER0_OUTPUT_COMPARE_VALUE; // we may not write it
	PRV_u16CTC_counter = copy_u16Delay_ms;

}
void TIMER0_voidSetCallBackOVF(void (* copy_pFunAction)(void)){
	if (copy_pFunAction !=NULL){
		PRV_pFunCallBackOVF=copy_pFunAction;
	}
	else
	{
		//error
	}

}

void TIMER0_voidSetCallBackCTC(void (* copy_pFunAction)(void)){
	if (copy_pFunAction !=NULL){
		PRV_pFunCallBackCTC=copy_pFunAction;
	}
	else
	{
		//error
	}

}


void __vector_11(void) __attribute((signal));
void __vector_11(void){

	static u16 local_u16Counter;
	local_u16Counter++;

	if(TIMER0_OVERFLOW_COUNTER ==local_u16Counter){
		TCNT0_REG=TIMER0_PRELOAD_VALUE;
		local_u16Counter=0;

		if(PRV_pFunCallBackOVF !=NULL){
			PRV_pFunCallBackOVF();
		}
	}

}

void __vector_10(void) __attribute((signal));
void __vector_10(void){

	static u16 local_u16Counter;
	local_u16Counter++;

	if(PRV_u16CTC_counter ==local_u16Counter){
		local_u16Counter=0;

		if(PRV_pFunCallBackCTC !=NULL){
			PRV_pFunCallBackCTC();
		}
	}

}
