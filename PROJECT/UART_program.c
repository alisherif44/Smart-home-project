/*
 * UART_program.c
 *
 *  Created on: Jan 21, 2025
 *      Author: Fc
 */

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "UART_interface.h"
#include "UART_register.h"

/*
#define F_OSC			        16000000UL
#define UART_BUAD_RATE			96000

#define UBRR_VALUE			    ((F_OSC/16/UART_BUAD_RATE)-1)
*/
void UART_voidInit(void)
{
	// Set Buad Rate = 9600 (f(osc) = 16MHZ, Double speed off)
	CLR_BIT(UCSRA_REG, U2X);
	UBRRL_REG = 103;

	// Disable UART Interrupts
	CLR_BIT(UCSRB_REG, RXCIE);
	CLR_BIT(UCSRB_REG, TXCIE);
	CLR_BIT(UCSRB_REG, UDRIE);

	/* // writing on UCSRC
	   // select UART MODE = Asynchronous
	   // configure no parity
	   // configure stop bits = 1
	   // configure data bits = 8
	   // configure no polarity
	*/
	UCSRC_REG = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); // UCSRC_REG = 0X86; //0b10000110
	CLR_BIT(UCSRB_REG, UCSZ2);

	// Enable UART Rx
	SET_BIT(UCSRB_REG, RXEN);

	// Enable UART Tx
	SET_BIT(UCSRB_REG, TXEN);
}


void UART_voidTxChar(u8 copy_u8TxData)
{
	// Busy Wait on Data Register empty flag
	while(0 == GET_BIT(UCSRA_REG, UDRE));

	UDR_REG = copy_u8TxData;
}


void UART_voidRxChar(u8* copy_pu8RxData)
{
	if(copy_pu8RxData != NULL)
	{
		// Busy Wait on Receive Complete flag
		while(0 == GET_BIT(UCSRA_REG, RXC));

		*copy_pu8RxData = UDR_REG;
	}
	else
	{
		//return Error State
	}
}


void UART_voidTxString(u8* copy_pu8TxString)
{
	if(copy_pu8TxString != NULL)
	{
		u8 local_u8Counter = 0;
		while(copy_pu8TxString[local_u8Counter] != '\0')
		{
			UART_voidTxChar(copy_pu8TxString[local_u8Counter]);
			local_u8Counter++;
		}
	}
	else
	{
		// return Error State
	}
}


void UART_voidRxString(u8* copy_pu8RxString)
{
	if(copy_pu8RxString != NULL)
	{
		u8 local_u8Counter = 0;
		do
		{

			UART_voidRxChar(&copy_pu8RxString[local_u8Counter]);
			local_u8Counter++;

		} while(copy_pu8RxString[local_u8Counter-1] != '#');

		copy_pu8RxString[local_u8Counter-1] = '\0';
	}
	else
	{
		// return Error State
	}
}
