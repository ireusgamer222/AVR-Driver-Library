#ifndef MCAL_TIMERS_TIMER0_PRIVATE_H_
#define MCAL_TIMERS_TIMER0_PRIVATE_H_

/* TCCR0 Register Bits */
#define FOC0_BIT       7
#define WGM00_BIT      6
#define COM01_BIT      5
#define COM00_BIT      4
#define WGM01_BIT      3
#define CS02_BIT       2
#define CS01_BIT       1
#define CS00_BIT       0

/* TIMSK / TIFR Register Bits */
#define TOIE0_BIT      0
#define OCIE0_BIT      1
#define TOV0_BIT       0
#define OCF0_BIT       1

/* Masks */
#define COM_MASK       0b00000011
#define CS_MASK        0b00000111

#endif /* MCAL_TIMERS_TIMER0_PRIVATE_H_ */
