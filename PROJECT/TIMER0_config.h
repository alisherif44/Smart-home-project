/*
 * TIMER0_config.h
 *
 *  Created on: Dec 16, 2024
 *      Author: Fc
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#define TIMER0_PRELOAD_VALUE                        113
#define TIMER0_OVERFLOW_COUNTER                     977

#define TIMER0_OUTPUT_COMPARE_VALUE                 249
#define TIMER0_OUTPUT_COMPARE_COUNTER               1500 // we didnt use it bec of delay func of ctc

#define TIMER0_FAST_PWM_DUTY_CYCLE                  80

#define TIMER0_MODE                  TIMER0_FAST_PWM_MODE

#endif /* TIMER0_CONFIG_H_ */
