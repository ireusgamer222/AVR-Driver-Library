/*
 * USART_REG.h
 *
 *  Created on: Aug 1, 2026
 *      Author: dell
 */

#ifndef MCAL_USART_USART_REG_H_
#define MCAL_USART_USART_REG_H_

/* USART Data Register */
#define USART_UDR_REG                   *((volatile uint8_t*)0x2C)

/* USART Control and Status Register A */
#define USART_UCSRA_REG                 *((volatile uint8_t*)0x2B)

/* USART Control and Status Register B */
#define USART_UCSRB_REG                 *((volatile uint8_t*)0x2A)

/* USART Baud Rate Register (Low Byte) */
#define USART_UBRRL_REG                 *((volatile uint8_t*)0x29)

/* USART Baud Rate Register (High Byte) / UCSRC Register */
#define USART_UBRRH_REG                 *((volatile uint8_t*)0x40)
#define USART_UCSRC_REG                 *((volatile uint8_t*)0x40)

#endif /* MCAL_USART_USART_REG_H_ */
