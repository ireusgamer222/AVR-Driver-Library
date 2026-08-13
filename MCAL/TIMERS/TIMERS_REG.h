/*
 * TIMER0_REG.h
 *
 *  Created on: Jul 28, 2026
 *      Author: dell
 */

#ifndef MCAL_TIMERS_TIMERS_REG_H_
#define MCAL_TIMERS_TIMERS_REG_H_
#include "../../STD_TYPES.h"

/* TIMER0 REGISTERS - 8 BIT TIMER */
#define TIMERS_TCNT0_REG            *((volatile uint8_t*)0x52)
#define TIMERS_TCCR0_REG            *((volatile uint8_t*)0x53)
#define TIMERS_OCR0_REG             *((volatile uint8_t*)0x5C)

/* TIMER1 REGISTERS - 16 BIT TIMER */
#define TIMERS_TCCR1A_REG           *((volatile uint8_t*)0x4F)
#define TIMERS_TCCR1B_REG           *((volatile uint8_t*)0x4E)
#define TIMERS_TCNT1_REG            *((volatile u16*)0x4C)
#define TIMERS_OCR1A_REG            *((volatile u16*)0x4A)
#define TIMERS_OCR1B_REG            *((volatile u16*)0x48)
#define TIMERS_ICR1_REG             *((volatile u16*)0x46)

/* TIMER2 REGISTERS - 8 BIT TIMER */
#define TIMERS_ASSR_REG             *((volatile uint8_t*)0x42)
#define TIMERS_OCR2_REG             *((volatile uint8_t*)0x43)
#define TIMERS_TCNT2_REG            *((volatile uint8_t*)0x44)
#define TIMERS_TCCR2_REG            *((volatile uint8_t*)0x45)

/* SHARED INTERRUPT REGISTERS */
#define TIMERS_TIMSK_REG            *((volatile uint8_t*)0x59)
#define TIMERS_TIFR_REG             *((volatile uint8_t*)0x58)



#endif /* MCAL_TIMERS_TIMERS_REG_H_ */
