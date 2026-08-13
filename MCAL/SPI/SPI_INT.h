/*
 * SPI_INT.h
 *
 *  Created on: Aug 2, 2026
 *      Author: dell
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_


void SPI_voidInit(void);

void SPI_voidEnable(void);
void SPI_voidDisable(void);


uint8_t SPI_u8TransmitDataSync(uint8_t Copy_u8Data);
uint8_t SPI_u8ReadDataReg(void);
void SPI_vidWriteDataReg(uint8_t Copy_u8Data);


void SPI_voidInterruptEnable(void);
void SPI_voidInterruptDisable(void);


void SPI_voidSetCallBack(volatile void (*Copy_pVoidCallBack)(void));

#endif /* MCAL_SPI_SPI_INT_H_ */
