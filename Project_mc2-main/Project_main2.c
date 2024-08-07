/*
 * Project_main2.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"UART.h"
#include"Exti.h"
#include"Keypad.h"
#include"Lcd.h"
#include"Pwm.h"
#include"Port.h"
#include"Dio.h"
volatile u8 Counter=0;
volatile u8 Counter1=0;
u8 encrypt(u8 data)
{
	u8 key;
	key=1;
	data=data+key;
	return data;
}
u8 decrypt(u8 data)
{
	u8 key;
	key=1;
	data=data-key;
	return data;
}
int main()
{
	Lcd_Int();
	Uart_Init(9600);//received
	Pmw_voidInit();
	Timer_Reg();
	Port_enuSetPinDirection(PORT_u8PIN11,PORT_u8OUTPUT);//motor
	Port_enuSetPinDirection(PORT_u8PIN09,PORT_u8OUTPUT);//led
	Port_enuSetPinDirection(PORT_u8PIN27,PORT_u8INPUT);//button
	Dio_enuWriteChannel(DIO_CHANNEL09,DIO_u8LOW);//led_off
    u8 Resive_data=0;//receive
    u8 button=0;
	u8 str1[]="LEVEL1";
	u8 str2[]="LEVEL2";
	u8 str3[]="LEVEL3";
	u8 str4[]="No";//r1
	u8 str5[]="Action";//r2
    up8 ptr1= str1;
    up8 ptr2= str2;
    up8 ptr3= str3;
    up8 ptr4= str4;
    up8 ptr5= str5;
	while(1)
	{
		Uart_RcievedData(&Resive_data);//uart
		if(Resive_data!='z')
		{
			if((Resive_data>1)&&(Resive_data<=10))//2-->10
			{
			Resive_data=decrypt(Resive_data);
			switch (Resive_data)
			{
			case 1:
				Lcd_vidGoTo(0,5);//row0,col5
				Lcd_vidDisplayString(ptr1);//level1
				Lcd_vidGoTo(1,7);//row1,col7
				Lcd_vidDisplayCharacter('5');
				Lcd_vidDisplayCharacter('0');//50
				Pwm_enuSet_OCR0_Value(50);//motor-->OCR0-->50
				break;
			case 2:
				Lcd_vidGoTo(0,5);
				Lcd_vidDisplayString(ptr2);
				Lcd_vidGoTo(1,7);
				Lcd_vidDisplayCharacter('1');
				Lcd_vidDisplayCharacter('5');
				Lcd_vidDisplayCharacter('0');
				Pwm_enuSet_OCR0_Value(150);
				break;
			case 3:
				Lcd_vidGoTo(0,5);
				Lcd_vidDisplayString(ptr3);
				Lcd_vidGoTo(1,7);
				Lcd_vidDisplayCharacter('2');
				Lcd_vidDisplayCharacter('5');
				Lcd_vidDisplayCharacter('0');
				Pwm_enuSet_OCR0_Value(250);
				break;
			default:
				Lcd_vidGoTo(0,7);
				Lcd_vidDisplayString(ptr4);//No
				Lcd_vidGoTo(1,5);
				Lcd_vidDisplayString(ptr5);//action
				Pwm_enuSet_OCR0_Value(0);
				break;
			}
			Lcd_vidClean();//clean
			Resive_data=0;
			}
			Resive_data='z';
		}

		Dio_enuReadChannel(DIO_CHANNEL27,&button);
		while(button==1)
		{
			Dio_enuWriteChannel(DIO_CHANNEL09,1);//led on
			Counter=0;
			Counter1=0;
			button=0;
		}
		while((Counter>=62)&&(Counter1==1))//10sec
		{
			Dio_enuWriteChannel(DIO_CHANNEL09,DIO_u8LOW);//led off
			Counter=0;
			Counter1=0;
		}

    }
	return 0;
}
ISR(TIMER0_OVF_vect)
{
	Counter++;
	if(Counter>=250)//8sec
	{
		Counter1=1;
		Counter=0;
	}
}
