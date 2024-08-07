/*
 * SPI.c
 *
 *  Created on: ???/???/????
 *      Author: adel
 */
#include"SPI.h"
#include "Port.h"
#include "Dio.h"
void Spi_MasterInit()
{
	SET_BIT(SPCR ,SPIE);//SPI Interrupt Enable
	SET_BIT(SREG ,7);//global interrupt
	SET_BIT(SPCR ,SPE);//SPI Enable
	SET_BIT(SPCR ,MSTR);// Master/Slave Select

	//output
	Port_enuSetPinDirection(MOSI,1);
	Port_enuSetPinDirection(SCK,1);
	Port_enuSetPinDirection(SS,1);

	SET_BIT(SPCR,SPR0);//SPI Clock Rate--> 16
}
void Spi_SlaveInit()
{
	SET_BIT(SPCR ,SPIE);//SPI Interrupt Enable
	SET_BIT(SREG ,7);//global interrupt
	SET_BIT(SPCR ,SPE);//SPI Enable

	Port_enuSetPinDirection(MISO,1);//output

	SET_BIT(SPCR,SPR0);//SPI Clock Rate--> 16
}
void Spi_MasterTransData(u8 data)
{
	Dio_enuWriteChannel(SS,0);//ss is active with -->0
	SPDR = data;
	while(GET_BIT(SPSR,SPIF)==0);//SPI Interrupt Flag-->When a serial transfer is complete, the SPIF Flag is set
	u8 var = SPDR;//to make SPDR empty
}
/*void Spi_SlaveTransData(u8 data)
{
	SPDR = data;
	while(GET_BIT(SPSR,SPIF)==0);
	u8 var = SPDR;
}*/
/*void Spi_MasterSendData(up8 data)
{
	while(GET_BIT(SPSR,SPIF)==0);
	*data = SPDR;
}*/
void Spi_SlaveReciveData(up8 data)
{
	while(GET_BIT(SPSR,SPIF)==0);//SPI Interrupt Flag-->When a serial transfer is complete, the SPIF Flag is set
	*data = SPDR;
}
