/*
 * TIMER1_register.h
 *
 *  Created on: Dec 20, 2024
 *      Author: Fc
 */

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

/*
 $2F ($4F) TCCR1A COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10 107
$2E ($4E) TCCR1B ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10 110
$2D ($4D) TCNT1H Timer/Counter1 – Counter Register High Byte 111
$2C ($4C) TCNT1L Timer/Counter1 – Counter Register Low Byte 111
$39 ($59) TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 82, 112, 130
$38 ($58) TIFR OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0
 */

// Timer/Counter1 Control Register A
#define TCCR1A_REG			(*(volatile u8*)0x4F)
#define WGM10               0
#define WGM11               1
#define FOC1B               2
#define FOC1A               3
#define COM1B0              4
#define COM1B1              5
#define COM1A0              6
#define COM1A1              7

// Timer/Counter1 Control Register B
#define TCCR1B_REG			(*(volatile u8*)0x4E)
#define CS10                0
#define CS11                1
#define CS12                2
#define WGM12               3
#define WGM13               4
#define ICES1               6
#define ICNC1               7

// Timer/Counter1 Registers
#define TCNT1_u16_REG       (*(volatile u16*)0x4C)
#define TCNT1L_REG			(*(volatile u8*)0x4C)
#define TCNT1H_REG			(*(volatile u8*)0x4D)

// Output Compare Registers 1 A
#define OCR1A_u16_REG       (*(volatile u16*)0x4A)
#define OCR1AL_REG			(*(volatile u8*)0x4A)
#define OCR1AH_REG			(*(volatile u8*)0x4B)

// Output Compare Registers 1 B
#define OCR1B_u16_REG       (*(volatile u16*)0x48)
#define OCR1BL_REG			(*(volatile u8*)0x48)
#define OCR1BH_REG			(*(volatile u8*)0x49)

// Input Capture Register 1
#define ICR1_u16_REG        (*(volatile u16*)0x46)
#define ICR1BL_REG			(*(volatile u8*)0x46)
#define ICR1BH_REG			(*(volatile u8*)0x47)

// Timer/Counter Interrupt Mask Register
#define TIMSK_REG          (*(volatile u8*)0x59)
#define TOIE1              2
#define OCIE1B             3
#define OCIE1A             4
#define TICIE1             5

// Timer/Counter Interrupt Flag Register
#define TIFR_REG           (*(volatile u8*)0x58)
#define TOV1               2
#define OCF1B              3
#define OCF1A              4
#define ICF1               5

#endif /* TIMER1_REGISTER_H_ */
