/*
 * ADC_register.h
 *
 *  Created on: Dec 11, 2024
 *      Author: Fc
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

/*$07 ($27) ADMUX REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0 214
$06 ($26) ADCSRA ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0 216
$05 ($25) ADCH ADC Data Register High Byte 217
$04 ($24) ADCL ADC Data Register Low Byte 217*/

#define ADMUX_REG         (*(volatile u8*)(0x27))
#define REFS1              7
#define REFS0              6
#define ADLAR              5
#define MUX4               4
#define MUX3               3
#define MUX2               2
#define MUX1               1
#define MUX0               0


#define ADCSRA_REG        (*(volatile u8*)(0x26))
#define ADEN               7
#define ADSC               6
#define ADATE              5
#define ADIF               4
#define ADIE               3
#define ADPS2              2
#define ADPS1              1
#define ADPS0              0

#define ADCH_REG          (*(volatile u8*)(0x25))

#define ADCL_REG          (*(volatile u8*)(0x24))

#define ADC_REG          (*(volatile u16*)(0x24))

#endif /* ADC_REGISTER_H_ */
