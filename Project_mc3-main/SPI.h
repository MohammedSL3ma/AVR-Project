/*
 * SPI.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef SPI_H_
#define SPI_H_

#include"micro_config.h"

/*SPCR*/
#define SPIE  7
#define SPE   6
#define DORD  5
#define MSTR  4
#define CPOL  3
#define CPHA  2
#define SPR1  1
#define SPR0  0

#define SPIF  7//interrupt flag
#define WCOL  6
#define SPI2X 0//with SPR0 and SPR1 to select SPI Clock Rate

/*pins_in_PORTB*/
#define SS    12
#define MOSI  13
#define MISO  14
#define SCK   15


void Spi_MasterInit();
void Spi_SlaveInit();
void Spi_MasterTransData(u8 data);
//void Spi_SlaveTransData(u8 data);
//void Spi_MasterSendData(up8 data);
void Spi_SlaveReciveData(up8 data);

#endif /* SPI_H_ */
