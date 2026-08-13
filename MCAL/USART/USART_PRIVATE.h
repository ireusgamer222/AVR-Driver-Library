/*
 * USART_PRIVATE.h
 *
 *  Created on: Aug 1, 2026
 *      Author: dell
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

/* UCSRA Bit Positions */
#define USART_RXC_BIT                   7
#define USART_TXC_BIT                   6
#define USART_UDRE_BIT                  5
#define USART_FE_BIT                    4
#define USART_DOR_BIT                   3
#define USART_PE_BIT                    2
#define USART_U2X_BIT                   1
#define USART_MPCM_BIT                  0

/* UCSRB Bit Positions */
#define USART_RXCIE_BIT                 7
#define USART_TXCIE_BIT                 6
#define USART_UDRIE_BIT                 5
#define USART_RXEN_BIT                  4
#define USART_TXEN_BIT                  3
#define USART_UCSZ2_BIT                 2
#define USART_RXB8_BIT                  1
#define USART_TXB8_BIT                  0

/* UCSRC Bit Positions */
#define USART_URSEL_BIT                 7
#define USART_UMSEL_BIT                 6
#define USART_UPM1_BIT                  5
#define USART_UPM0_BIT                  4
#define USART_USBS_BIT                  3
#define USART_UCSZ1_BIT                 2
#define USART_UCSZ0_BIT                 1
#define USART_UCPOL_BIT                 0



/* Baud Rate Calculation */
#if USART_MODE == USART_MODE_ASYNC
    #if USART_DOUBLE_SPEED == USART_DOUBLE_SPEED_ENABLE
        #define USART_UBRR_VALUE   (((USART_F_CPU) + (4UL * USART_BAUD_RATE)) / (8UL * USART_BAUD_RATE) - 1)
    #else
        #define USART_UBRR_VALUE   (((USART_F_CPU) + (8UL * USART_BAUD_RATE)) / (16UL * USART_BAUD_RATE) - 1)
    #endif
#elif USART_MODE == USART_MODE_SYNC
    #define USART_UBRR_VALUE   (((USART_F_CPU) + (1UL * USART_BAUD_RATE)) / (2UL * USART_BAUD_RATE) - 1)
#endif


#define USART_FLAG_TIMEOUT              	10000

#endif /* MCAL_USART_USART_PRIVATE_H_ */
