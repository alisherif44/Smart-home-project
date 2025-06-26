/*
 * UART_interface.h
 *
 *  Created on: Jan 21, 2025
 *      Author: Fc
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit    (void);
void UART_voidTxChar  (u8  copy_u8TxData);
void UART_voidRxChar  (u8* copy_pu8RxData);
void UART_voidTxString(u8* copy_pu8TxString);
void UART_voidRxString(u8* copy_pu8RxString);
#endif /* UART_INTERFACE_H_ */
