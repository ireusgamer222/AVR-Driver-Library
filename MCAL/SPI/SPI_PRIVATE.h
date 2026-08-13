/*
 * SPI_PRIVATE.h
 *
 *  Created on: Aug 2, 2026
 *      Author: dell
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

/* SPCR Bit Positions */
#define SPI_SPIE_BIT                    7
#define SPI_SPE_BIT                     6
#define SPI_DORD_BIT                    5
#define SPI_MSTR_BIT                    4
#define SPI_CPOL_BIT                    3
#define SPI_CPHA_BIT                    2
#define SPI_SPR1_BIT                    1
#define SPI_SPR0_BIT                    0


/* SPSR Bit Positions */
#define SPI_SPIF_BIT                    7
#define SPI_WCOL_BIT                    6
#define SPI_SPI2X_BIT                   0

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
