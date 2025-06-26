/*
 * UART_register.h
 *
 *  Created on: Jan 21, 2025
 *      Author: Fc
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

/*
 $0C ($2C) UDR USART I/O Data Register 159
$0B ($2B) UCSRA RXC TXC UDRE FE DOR PE U2X MPCM 160
$0A ($2A) UCSRB RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8 161
$09 ($29) UBRRL USART Baud Rate Register Low Byte 164
$20(2) ($40)(2) UBRRH URSEL � � � UBRR[11:8] 164
UCSRC URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL
 */

// USART I/O Data Register
#define UDR_REG             (*(volatile u8*)0x2C)

// USART Control and Status Register A
#define UCSRA_REG           (*(volatile u8*)0x2B)
#define MPCM                0
#define U2X                 1
#define PE                  2
#define DOR                 3
#define FE                  4
#define UDRE                5
#define TXC                 6
#define RXC                 7

// USART Control and Status Register B
#define UCSRB_REG           (*(volatile u8*)0x2A)
#define TXB8                0
#define RXB8                1
#define UCSZ2               2
#define TXEN                3
#define RXEN                4
#define UDRIE               5
#define TXCIE               6
#define RXCIE               7

// USART Control and Status Register C
#define UCSRC_REG           (*(volatile u8*)0x40)
#define UCPOL               0
#define UCSZ0               1
#define UCSZ1               2
#define USBS                3
#define UPM0                4
#define UPM1                5
#define UMSEL               6
#define URSEL               7

// USART Baud Rate Registers
#define UBRRL_REG           (*(volatile u8*)0x29)
#define UBRRH_REG           (*(volatile u8*)0x40)

#endif /* UART_REGISTER_H_ */
