/*
 * TWI_register.h
 *
 *  Created on: Feb 2, 2025
 *      Author: Fc
 */

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

// TWI Bit Rate Register
#define TWBR_REG			(*(volatile u8*)0x20)

// TWI Control Register
#define TWCR_REG            (*(volatile u8*)0x56)
#define TWIE                0
#define TWEN                2
#define TWWC                3
#define TWSTO               4
#define TWSTA               5
#define TWEA                6
#define TWINT               7

// TWI Status Register
#define TWSR_REG            (*(volatile u8*)0x21)
#define TWPS0               0
#define TWPS1               1

// TWI Data Register
#define TWDR_REG            (*(volatile u8*)0x23)

// TWI (Slave) Address Register
#define TWAR_REG            (*(volatile u8*)0x22)
#define TWGCE               0

#endif /* TWI_REGISTER_H_ */
