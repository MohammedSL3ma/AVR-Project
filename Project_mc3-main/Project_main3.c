/*
 * Project_main3.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"UART.h"
#include"Exti.h"
#include"Keypad.h"
#include"Lcd.h"
#include"Pwm2.h"
#include"Led.h"
#include"Port.h"
#include"Dio.h"
volatile u8 Counter=0;
volatile u8 Counter1=0;
int main()
{
	Lcd_Int();
	Uart_Init(9600);
    Pmw2_voidInit();
    Timer_Reg();
	Port_enuSetPinDirection(PORT_u8PIN31,PORT_u8OUTPUT);//motor2
	Port_enuSetPinDirection(PORT_u8PIN09,PORT_u8OUTPUT);//led
	Port_enuSetPinDirection(PORT_u8PIN27,PORT_u8INPUT);//button
    Dio_enuWriteChannel(DIO_CHANNEL09,DIO_u8LOW);//led off
	u8 button=0;
	u8 Resive_data1=0;
	u8 str1[]="LEVEL1";
	u8 str2[]="LEVEL2";
	u8 str3[]="LEVEL3";
	up8 ptr1= str1;
	up8 ptr2= str2;
	up8 ptr3= str3;
	while(1)
	{
		Uart_RcievedData(&Resive_data1);//uart
		if(Resive_data1!='z')
		{
			if((Resive_data1>1)&&(Resive_data1<=10))
			{
				switch (Resive_data1)
				{
				case 1:
					Lcd_vidGoTo(0,5);
					Lcd_vidDisplayString(ptr1);
					Lcd_vidGoTo(1,7);
					Lcd_vidDisplayCharacter('5');
					Lcd_vidDisplayCharacter('0');
					Pwm_enuSet_OCR2_Value(50);
					break;
				case 2:
					Lcd_vidGoTo(0,5);
					Lcd_vidDisplayString(ptr2);
					Lcd_vidGoTo(1,7);
					Lcd_vidDisplayCharacter('1');
					Lcd_vidDisplayCharacter('5');
					Lcd_vidDisplayCharacter('0');
					Pwm_enuSet_OCR2_Value(150);
					break;
				case 3:
					Lcd_vidGoTo(0,5);
					Lcd_vidDisplayString(ptr3);
					Lcd_vidGoTo(1,7);
					Lcd_vidDisplayCharacter('2');
					Lcd_vidDisplayCharacter('5');
					Lcd_vidDisplayCharacter('0');
					Pwm_enuSet_OCR2_Value(250);
					break;
				default:
					Lcd_vidGoTo(0,4);
					Lcd_vidDisplayCharacter(Resive_data1+48);
					Pwm_enuSet_OCR2_Value(0);
					break;
				}
				Lcd_vidClean();
				Resive_data1=0;
			}
		Resive_data1='z';
	    }
		Dio_enuReadChannel(DIO_CHANNEL27,&button);
		while(button==1)
		{
			Dio_enuWriteChannel(DIO_CHANNEL09,1);
			Counter=0;
			Counter1=0;
			button=0;
		}
		while((Counter>=62)&&(Counter1==1))
		{
			Dio_enuWriteChannel(DIO_CHANNEL09,DIO_u8LOW);
			Counter=0;
			Counter1=0;
		}
	}
	return 0;
}

ISR(TIMER0_OVF_vect)
{
	Counter++;
	if(Counter>=250)
	{
		Counter1=1;
		Counter=0;
	}
}
