/*
 * SPI_REG.h
 *
 *  Created on: Aug 2, 2026
 *      Author: dell
 */

#ifndef MCAL_SPI_SPI_REG_H_
#define MCAL_SPI_SPI_REG_H_

/* SPI Control Register */
#define SPI_SPCR_REG                    *((volatile uint8_t*)0x2D)

/* SPI Status Register */
#define SPI_SPSR_REG                    *((volatile uint8_t*)0x2E)

/* SPI Data Register */
#define SPI_SPDR_REG                    *((volatile uint8_t*)0x2F)


#endif /* MCAL_SPI_SPI_REG_H_ */
