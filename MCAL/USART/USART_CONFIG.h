/*
 * USART_CONFIG.h
 *
 *  Created on: Aug 1, 2026
 *      Author: dell
 */

#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

// CPU Clock  System Frequency
#define USART_F_CPU             8000000UL


// Baud Rate Selection
#define USART_BAUD_RATE         9600


// Clock Mode Selection Options
#define USART_MODE_ASYNC        0
#define USART_MODE_SYNC         1

// MODE SELECTION
#define USART_MODE              USART_MODE_ASYNC

// Double Speed Mode Options
#define USART_DOUBLE_SPEED_DISABLE      0
#define USART_DOUBLE_SPEED_ENABLE       1

// Double Speed MODE SELECTION
#define USART_DOUBLE_SPEED              USART_DOUBLE_SPEED_DISABLE


/* Parity Options */
#define USART_PARITY_DISABLE    0
#define USART_PARITY_EVEN       2
#define USART_PARITY_ODD        3

//Parity MODE SELECTION
#define USART_PARITY            USART_PARITY_DISABLE


// INTERRUPT OR FLAG ENABLE OPTIONS
#define USART_INTERRUPT_DISABLE                  0
#define USART_INTERRUPT_ENABLE                   1

// TX Interrupt
#define USART_TX_INTERRUPT      USART_INTERRUPT_ENABLE

// RX Interrupt
#define USART_RX_INTERRUPT      USART_INTERRUPT_ENABLE

// UDR Empty Interrupt
#define USART_UDRE_INTERRUPT    USART_INTERRUPT_DISABLE

// Stop Bit Options */
#define USART_STOP_1_BIT        0
#define USART_STOP_2_BIT        1

// Stop Bits MODE SELECTION
#define USART_STOP_BITS         USART_STOP_1_BIT


// Data Bits Options
#define USART_DATA_5_BIT        0
#define USART_DATA_6_BIT        1
#define USART_DATA_7_BIT        2
#define USART_DATA_8_BIT        3
#define USART_DATA_9_BIT        7

// Data Bits MODE SELECTION
#define USART_DATA_BITS         USART_DATA_8_BIT

#endif /* MCAL_USART_USART_CONFIG_H_ */
