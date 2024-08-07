/*
 * Pwm2.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef PWM2_H_
#define PWM2_H_


#include"micro_config.h"

typedef enum
{
	Pwm2_enuOk = 0 ,
    Pwm2_enuValueError
}Pwm2_tenuErrorStatus;

/*TCCR0_reg*/
#define FOC2  7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22  2
#define CS21  1
#define CS20  0

void Pmw2_voidInit();
Pwm2_tenuErrorStatus Pwm_enuSet_OCR2_Value(u8 value);


#endif /* PWM2_H_ */
