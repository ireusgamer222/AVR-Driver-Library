/*
 * TIMER2_PRIVATE.h
 *
 * Created on: Jul 30, 2026
 * Author: dell
 */

#ifndef MCAL_TIMERS_TIMER2_PRIVATE_H_
#define MCAL_TIMERS_TIMER2_PRIVATE_H_

/* TCCR2 Bit Positions */
#define FOC2_BIT     7
#define WGM20_BIT    6
#define COM21_BIT    5
#define COM20_BIT    4
#define WGM21_BIT    3
#define CS22_BIT     2
#define CS21_BIT     1
#define CS20_BIT     0

/* ASSR Bit Positions */
#define AS2_BIT      3
#define TCN2UB_BIT   2
#define OCR2UB_BIT   1
#define TCR2UB_BIT   0

/* TIMSK Bit Positions */
#define OCIE2_BIT    7
#define TOIE2_BIT    6

/* TIFR Bit Positions */
#define OCF2_BIT     7
#define TOV2_BIT     6

/* Masks */
#define CS_MASK      0b00000111

#endif /* MCAL_TIMERS_TIMER2_PRIVATE_H_ */
