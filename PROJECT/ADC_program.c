#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_register.h"
#include "ADC_interface.h"

void ADC_voidInit(u8 copy_u8RefrenceVoltage){
	//TO CHOOSE THE REFRENCE VOLTAGE
	switch(copy_u8RefrenceVoltage){
	case ADC_REFERANCE_AVCC:
		CLR_BIT(ADMUX_REG,REFS1);
		SET_BIT(ADMUX_REG,REFS0);
		break;
	case ADC_REFERANCE_AREF:
		CLR_BIT(ADMUX_REG,REFS1);
		CLR_BIT(ADMUX_REG,REFS0);
		break;
	case ADC_REFERANCE_INTERNAL:
		SET_BIT(ADMUX_REG,REFS1);
		SET_BIT(ADMUX_REG,REFS0);
		break;

	}
	//RIGHT ADJUSTMENT
	CLR_BIT(ADMUX_REG,ADLAR);

	//SINGLE CONVERSION MODE
	CLR_BIT(ADCSRA_REG,ADATE);

	//CLR INTERUPT OF ADC
	CLR_BIT(ADCSRA_REG,ADIE);

	//PRESCALER
	SET_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);

	//ADC ENABLE
	SET_BIT(ADCSRA_REG,ADEN);
}
void ADC_voidGetDigigtalValue(u8 copy_u8ChannelId,u16* copy_pu16DigitalValue){
	if(copy_pu16DigitalValue !=NULL && copy_u8ChannelId<32){
		//CHANNEL
		ADMUX_REG &=0b11100000;
		ADMUX_REG |=copy_u8ChannelId;

		//START CONVERSION
		SET_BIT(ADCSRA_REG,ADSC);

		//BUSY WAIT FOR ADC FLAG
		while(GET_BIT(ADCSRA_REG,ADIF) == 0);

		//CLR FLAG
		SET_BIT(ADCSRA_REG,ADIF);

		//pass out adc data
		*copy_pu16DigitalValue=ADC_REG;


	}
	else{
		//return error
	}

}
