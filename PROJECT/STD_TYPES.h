/*
 * STD_TYPES.h
 *
 *  Created on: Nov 19, 2024
 *      Author: Fc
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char        u8;
typedef signed char          s8;

typedef unsigned short int   u16;
typedef signed short int     s16;

typedef unsigned long int   u32;
typedef signed long int     s32;

typedef float               f32;
typedef double              f64;

typedef enum bolean
{
FALSE,
TRUE
}BOOL;

#define NULL  (void*)0           //address zero

#endif /* STD_TYPES_H_ */
