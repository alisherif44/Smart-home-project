/*
 * EXTI_register.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Fc
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/*$35 ($55) MCUCR SE SM2 SM1 SM0 ISC11 ISC10 ISC01 ISC00 32, 66
$34 ($54) MCUCSR JTD ISC2 – JTRF WDRF BORF EXTRF PORF 40, 67, 228
$3B ($5B) GICR INT1 INT0 INT2 – – – IVSEL IVCE 47, 67
$3A ($5A) GIFR INTF1 INTF0 INTF2 – – – – – 68
*/

#define MCUCR_REG        (*(volatile u8*)(0x55))
#define ISC00                  0
#define ISC01                  1
#define ISC10                  2
#define ISC11                  3

#define MCUCSR_REG       (*(volatile u8*)(0x54))
#define ISC2                   6

#define GICR_REG         (*(volatile u8*)(0x5B))
#define INT2                   5
#define INT0                   6
#define INT1                   7

#define GIFR_REG         (*(volatile u8*)(0x5A))
#define INTF2                  5
#define INTF0                  6
#define INTF1                  7


#endif /* EXTI_REGISTER_H_ */
