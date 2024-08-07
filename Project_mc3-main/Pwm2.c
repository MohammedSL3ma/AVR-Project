/*
 * Pwm2.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"Pwm2.h"
#include"Port.h"

void Pmw2_voidInit()
{
	SET_BIT(TCCR2,WGM20);//Pwm_fast
	SET_BIT(TCCR2,WGM21);//Pwm_fast
	SET_BIT(TCCR2,COM21);//NonInvator
	SET_BIT(TCCR2,CS21);//prescaler
	SET_BIT(TCCR2,CS20);//prescaler_64
	Port_enuSetPinDirection(PORT_u8PIN11,PORT_u8OUTPUT);
}
Pwm2_tenuErrorStatus Pwm_enuSet_OCR2_Value(u8 value)
{
	Pwm2_tenuErrorStatus Loc_enuReturnStatus = Pwm2_enuOk ;
	if((value<0)||(value>255))
	{
		Loc_enuReturnStatus=Pwm2_enuValueError;
	}
	else
	{
		ASSIGN_REG(OCR2,value);
	}
	return Loc_enuReturnStatus;
}
