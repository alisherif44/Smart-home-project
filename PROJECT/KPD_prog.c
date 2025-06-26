/*
 * KPD_program.c
 *
 *  Created on: Nov 27, 2024
 *      Author: Fc
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"KPD_interface.h"
#include"KPD_config.h"


void KPD_voidInit(){
	//ROW INPUT
	DIO_voidSetPinDirection(KPD_ROW0_PORT,KPD_ROW0_PIN,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW1_PORT,KPD_ROW1_PIN,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW2_PORT,KPD_ROW2_PIN,DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW3_PORT,KPD_ROW3_PIN,DIO_PIN_INPUT);

	//active internal pull up resistor
	DIO_voidActivePinInPllUpResistor(KPD_ROW0_PORT,KPD_ROW0_PIN);
	DIO_voidActivePinInPllUpResistor(KPD_ROW1_PORT,KPD_ROW1_PIN);
	DIO_voidActivePinInPllUpResistor(KPD_ROW2_PORT,KPD_ROW2_PIN);
	DIO_voidActivePinInPllUpResistor(KPD_ROW3_PORT,KPD_ROW3_PIN);

	//COLUMN OUTPUT
	DIO_voidSetPinDirection(KPD_COL0_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL1_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL2_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL3_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);

	//COLUMN HIGH
	DIO_voidSetPinValue(KPD_COL0_PORT,KPD_COL0_PIN,DIO_PIN_HIGH);
	DIO_voidSetPinValue(KPD_COL1_PORT,KPD_COL1_PIN,DIO_PIN_HIGH);
	DIO_voidSetPinValue(KPD_COL2_PORT,KPD_COL2_PIN,DIO_PIN_HIGH);
	DIO_voidSetPinValue(KPD_COL3_PORT,KPD_COL3_PIN,DIO_PIN_HIGH);

}
void KPD_voidGetValue(u8* copy_Pu8ReturnedValue){
	if(copy_Pu8ReturnedValue != NULL){
		* copy_Pu8ReturnedValue=KPD_NOT_PRESSED;//keypad nor pressed

		u8 local_u8ColsCounter;
		u8 local_u8RowsCounter;
		u8 local_u8PinState;

		u8 local_u8ColsPorts[4] ={KPD_COL0_PORT ,KPD_COL1_PORT ,KPD_COL2_PORT ,KPD_COL3_PORT};
		u8 local_u8ColsPins[4] ={KPD_COL0_PIN ,KPD_COL1_PIN ,KPD_COL2_PIN ,KPD_COL3_PIN};
		u8 local_u8RowsPorts[4] ={KPD_ROW0_PORT ,KPD_ROW1_PORT ,KPD_ROW2_PORT ,KPD_ROW3_PORT};
		u8 local_u8RowsPins[4] ={KPD_ROW0_PIN ,KPD_ROW1_PIN ,KPD_ROW2_PIN ,KPD_ROW3_PIN};
		u8 local_u8KpdChars[4][4]=KPD_KEYS;

		for(local_u8ColsCounter=0 ; local_u8ColsCounter<4 ;local_u8ColsCounter++)
		{
			DIO_voidSetPinValue(local_u8ColsPorts[local_u8ColsCounter],local_u8ColsPins[local_u8ColsCounter],DIO_PIN_LOW);

			for(local_u8RowsCounter=0 ; local_u8RowsCounter<4 ;local_u8RowsCounter++){

				DIO_voidGetPinValue(local_u8RowsPorts[local_u8RowsCounter],local_u8RowsPins[local_u8RowsCounter],&local_u8PinState);

				if(local_u8PinState==0){

					while(local_u8PinState==0){
					DIO_voidGetPinValue(local_u8RowsPorts[local_u8RowsCounter],local_u8RowsPins[local_u8RowsCounter],&local_u8PinState);
							 }

						*copy_Pu8ReturnedValue=local_u8KpdChars[local_u8RowsCounter][local_u8ColsCounter];
							break;
					}
				}

			if(local_u8RowsCounter<4)  //34an atl3 mn al loop al kebera fe 7alh al break al ola
			{
				break;
			}
			DIO_voidSetPinValue(local_u8ColsPorts[local_u8ColsCounter],local_u8ColsPins[local_u8ColsCounter],DIO_PIN_HIGH);
			}

	}
	else{
		//return error
	}

}
