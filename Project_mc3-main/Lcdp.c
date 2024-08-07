/*
 * Lcd2.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#include "Lcdp.h"

#include"Port.h"
#include"Dio.h"

void Lcd2_Int()
{
	Lcd2_vidSendCommand(0x38);//mode 8
	_delay_ms(1);
	Lcd2_vidSendCommand(0x01);//clear+goto first cell
	_delay_ms(1);
	Lcd2_vidSendCommand(0x02);//return home
	_delay_ms(1);
	Lcd2_vidSendCommand(0x06);//entry mode
	_delay_ms(1);
	Lcd2_vidSendCommand(0x80);//first row
	_delay_ms(1);
	Lcd2_vidSendCommand(0x0C);//display on cursor off
	_delay_ms(1);
}

void Lcd2_vidSendData(u8 Copy_u8Data)
{
	Port_enuSetPinDirection(RS2,PORT_u8HIGH);
	Port_enuSetPinDirection(E2,PORT_u8HIGH);
	_delay_ms(3);
	ASSIGN_REG(LCD_u8DataPort2,Port_output);
	Dio_enuWriteChannel(RS2,1);
	Dio_enuWriteChannel(E2,1);
	_delay_ms(5);
	LCD_u8DataPort2 = Copy_u8Data;
	Dio_enuWriteChannel(E2,DIO_u8LOW);
	_delay_ms(1);
}
void Lcd2_vidDisplayCharacter(u8 Copy_u8Character)
{
	Lcd2_vidSendData(Copy_u8Character);
}
void Lcd2_vidDisplayString(up8 Add_up8String)
{
	while((*Add_up8String) != '\0')
	{
		Lcd2_vidSendData(*Add_up8String);
		Add_up8String++;
	}

}
void Lcd2_vidSendCommand(u8 Copy_u8Command)
{
	Port_enuSetPinDirection(RS2,PORT_u8HIGH);
	Port_enuSetPinDirection(E2,PORT_u8HIGH);
	_delay_ms(3);
	ASSIGN_REG(LCD_u8DataPort2,Port_output);
	Dio_enuWriteChannel(RS2,DIO_u8LOW);
	Dio_enuWriteChannel(E2,DIO_u8HIGH);
	_delay_ms(5);
	LCD_u8DataPort2 = Copy_u8Command;
	Dio_enuWriteChannel(E2,DIO_u8LOW);
	_delay_ms(1);
}
void Lcd2_vidGoTo(u8 Copy_u8Row , u8 Copy_u8Column)
{
   switch(Copy_u8Row)
   {
   case ROW_ONE:
	   Lcd2_vidSendCommand(0x80+Copy_u8Column-1);
	   break;
   case ROW_TWO:
	   Lcd2_vidSendCommand(0xC0+Copy_u8Column-1);
   	   break;
   }
}
void Lcd2_vidClean()
{
	Lcd2_vidSendCommand(0x0E);
	_delay_ms(1000);
   Lcd2_vidSendCommand(0x01);
}


