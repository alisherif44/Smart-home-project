/*
 * TWI_interface.h
 *
 *  Created on: Feb 2, 2025
 *      Author: Fc
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidInitMaster                     (void);
void TWI_voidSendStartCondition             (void);
void TWI_voidSendRepStartCondition          (void);
void TWI_voidSendStopCondition              (void);
void TWI_voidSendSlaveAddWithWrite          (u8  copy_u8SlaveAdd);
void TWI_voidSendSlaveAddWithRead           (u8  copy_u8SlaveAdd);
void TWI_voidTransmitMasterDataByte         (u8  copy_u8TxData);
void TWI_voidReceiveMasterDataByteWithACK   (u8* copy_pu8RxData);
void TWI_voidReceiveMasterDataByteWithoutACK(u8* copy_pu8RxData);

#endif /* TWI_INTERFACE_H_ */
