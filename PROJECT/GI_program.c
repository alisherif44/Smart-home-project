/*
 * GI_program.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Fc
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GI_interface.h"
#include "GI_register.h"

void GI_voidEnable(){
	SET_BIT(SREG_REG,I);

}
void GI_voidDisable(){
	CLR_BIT(SREG_REG,I);
}
