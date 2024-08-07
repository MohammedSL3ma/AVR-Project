/*
 * Lcd2.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef LCDP_H_
#define LCDP_H_
#include"micro_config.h"

/*instruction port*/
#define RS2 8 //PD6
#define E2  10 //PD7

/*Data Port*/
#define LCD_u8DataPort2 PORTA

/*ROWS*/
#define ROW_ONE 0
#define ROW_TWO 1

#define Port_output 0xff

void Lcd2_Int();
void Lcd2_vidSendData(u8 Copy_u8Data);
void Lcd2_vidDisplayCharacter(u8 Copy_u8Character);
void Lcd2_vidDisplayString(up8 Add_up8String);
void Lcd2_vidSendCommand(u8 Copy_u8Command);
void Lcd2_vidGoTo(u8 Copy_u8Row , u8 Copy_u8Column);
void Lcd2_vidClean();

#endif /* LCDP_H_ */
