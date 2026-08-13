/*
 * TWI_REG.h
 *
 *  Created on: Aug 3, 2026
 *      Author: dell
 */

#ifndef MCAL_TWI_TWI_REG_H_
#define MCAL_TWI_TWI_REG_H_

/* TWI Bit Rate Register */
#define TWI_TWBR_REG        *((volatile uint8_t*)0x20)

/* TWI Status Register */
#define TWI_TWSR_REG         *((volatile uint8_t*)0x21)

/* TWI Slave Address Register */
#define TWI_TWAR_REG         *((volatile uint8_t*)0x22)

/* TWI Data Register */
#define TWI_TWDR_REG         *((volatile uint8_t*)0x23)

/* TWI Control Register */
#define TWI_TWCR_REG         *((volatile uint8_t*)0x56)

#endif /* MCAL_TWI_TWI_REG_H_ */
