/*
 * EEPROM_program.c
 *
 *  Created on: Feb 3, 2025
 *      Author: Fc
 */

#include <util/delay.h>
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TWI_interface.h"

/* HAL */
#include "EEPROM_interface.h"
#include "EEPROM_private.h"


void EEPROM_voidInit(void)
{
	TWI_voidInitMaster();
}


void EEPROM_voidWriteByte(u16 copy_u16WordAdd, u8 copy_u8Data)
{
	u8 local_u8DeviceAdd = (copy_u16WordAdd >> 8) | EEPROM_FIXED_ADDRESS;

	// Send start condition
	TWI_voidSendStartCondition();

	// Send slave address with write operation (device address)
	TWI_voidSendSlaveAddWithWrite(local_u8DeviceAdd);

	// Send word address
	TWI_voidTransmitMasterDataByte((u8)copy_u16WordAdd);

	// Send byte data
	TWI_voidTransmitMasterDataByte(copy_u8Data);

	// Send stop condition
	TWI_voidSendStopCondition();

	// Self-timed Write Cycle delay
	_delay_ms(5);
}


void EEPROM_voidReadByte(u16 copy_u16WordAdd, u8* copy_pu8Data)
{
	if(copy_pu8Data != NULL)
	{
		u8 local_u8DeviceAdd = (copy_u16WordAdd >> 8) | EEPROM_FIXED_ADDRESS;

		// Send start condition
		TWI_voidSendStartCondition();

		// Send slave address with write operation (device address)
		TWI_voidSendSlaveAddWithWrite(local_u8DeviceAdd);

		// Send word address
		TWI_voidTransmitMasterDataByte((u8)copy_u16WordAdd);

		// Send repeated start condition in order to switch i2c operation (W >> R)
		TWI_voidSendRepStartCondition();

		// Send slave address with read operation (device address)
		TWI_voidSendSlaveAddWithRead(local_u8DeviceAdd);

		// Read byte data and respond without ACK
		TWI_voidReceiveMasterDataByteWithoutACK(copy_pu8Data);

		// Send stop condition
		TWI_voidSendStopCondition();

		// Self-timed Write Cycle delay
		_delay_ms(5);
	}
	else
	{
		//return Error State
	}
}

void EEPROM_voidWritePage(u16 copy_u16BaseAdd, u8 copy_u8DataLength,u8 *copy_pu8DataArray){

	if((copy_pu8DataArray != NULL) && (copy_u8DataLength <= 16))
		{
			u8 local_u8Counter;
			u8 local_u8DeviceAdd = (copy_u16BaseAdd >> 8) | EEPROM_FIXED_ADDRESS;

			// Send start condition
			TWI_voidSendStartCondition();

			// Send slave address with write operation (device address)
			TWI_voidSendSlaveAddWithWrite(local_u8DeviceAdd);

			// Send word address
			TWI_voidTransmitMasterDataByte((u8)copy_u16BaseAdd);

			for(local_u8Counter=0 ; local_u8Counter<copy_u8DataLength ; local_u8Counter++)
			{
				// Send byte data
				TWI_voidTransmitMasterDataByte(copy_pu8DataArray[local_u8Counter]);
			}

			// Send stop condition
			TWI_voidSendStopCondition();

			// Self-timed Write Cycle delay
			_delay_ms(5);
		}
		else
		{
			//return Error State
		}
}

void EEPROM_voidReadPage (u16 copy_u16BaseAdd, u8 copy_u8DataLength,u8 *copy_pu8DataPassOutArray){
	if((copy_pu8DataPassOutArray != NULL) && (copy_u8DataLength <= 16))
		{
			u8 local_u8Counter;
			u8 local_u8DeviceAdd = (copy_u16BaseAdd >> 8) | EEPROM_FIXED_ADDRESS;

			// Send start condition
			TWI_voidSendStartCondition();

			// Send slave address with write operation (device address)
			TWI_voidSendSlaveAddWithWrite(local_u8DeviceAdd);

			// Send word address
			TWI_voidTransmitMasterDataByte((u8)copy_u16BaseAdd);

			// Send repeated start condition in order to switch i2c operation (W >> R)
			TWI_voidSendRepStartCondition();

			// Send slave address with read operation (device address)
			TWI_voidSendSlaveAddWithRead(local_u8DeviceAdd);

			for(local_u8Counter=0 ; local_u8Counter<(copy_u8DataLength-1) ; local_u8Counter++)
			{
				// Read byte data and respond with ACK
				TWI_voidReceiveMasterDataByteWithACK(&copy_pu8DataPassOutArray[local_u8Counter]);
			}

			// Read byte data and respond without ACK
			TWI_voidReceiveMasterDataByteWithoutACK(&copy_pu8DataPassOutArray[local_u8Counter]);

			// Send stop condition
			TWI_voidSendStopCondition();

			// Self-timed Write Cycle delay
			_delay_ms(5);
		}
		else
		{
			//return Error States
		}
}
