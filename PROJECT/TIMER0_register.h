/*
 * TIMER0_register.h
 *
 *  Created on: Dec 16, 2024
 *      Author: Fc
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

/*
$33 ($53) TCCR0 FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00 80
$32 ($52) TCNT0 Timer/Counter0 (8 Bits) 82
$3C ($5C) OCR0 Timer/Counter0 Output Compare Register 82
$39 ($59) TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 82, 112, 130
$38 ($58) TIFR OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 83, 112, 130
 */

#define TCCR0_REG  	(*(volatile u8*)(0x53))
#define CS00              0
#define CS01              1
#define CS02              2
#define WGM01             3
#define COM00             4
#define COM01             5
#define WGM00             6
#define FOC0              7

#define TCNT0_REG  	(*(volatile u8*)(0x52))

#define OCR0_REG  	(*(volatile u8*)(0x5C))

#define TIMSK_REG  	(*(volatile u8*)(0x59))
#define TOIE0              0
#define OCIE0              1
//#define TOIE1            2
//#define OCIE1B           3
//#define OCIE1A           4
//#define TICIE1           5
//#define TOIE2            6
//#define OCIE2            7

#define TIFR_REG 	(*(volatile u8*)(0x58))
#define TOV0              0
#define OCF0              1
//#define TOV1            2
//#define OCF1B           3
//#define OCF1A           4
//#define ICF1            5
//#define TOV2            6
//#define OCF2            7

#endif /* TIMER0_REGISTER_H_ */
