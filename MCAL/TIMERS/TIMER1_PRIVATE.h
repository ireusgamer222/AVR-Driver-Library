#ifndef MCAL_TIMERS_TIMER1_PRIVATE_H_
#define MCAL_TIMERS_TIMER1_PRIVATE_H_

/* TCCR1A Register Bits */
#define COM1A1_BIT     7
#define COM1A0_BIT     6
#define COM1B1_BIT     5
#define COM1B0_BIT     4
#define WGM11_BIT      1
#define WGM10_BIT      0

/* TCCR1B Register Bits */
#define ICNC1_BIT      7
#define ICES1_BIT      6
#define WGM13_BIT      4
#define WGM12_BIT      3
#define CS12_BIT       2
#define CS11_BIT       1
#define CS10_BIT       0

/* TIMSK Register Bits */
#define TICIE1_BIT     5
#define OCIE1A_BIT     4
#define OCIE1B_BIT     3
#define TOIE1_BIT      2

/* Masks */
#define WGM_MASK_LOW   0b00000011
#define WGM_MASK_HIGH  0b00000011
#define COM_MASK       0b00000011
#define CS_MASK        0b00000111

#endif /* MCAL_TIMERS_TIMER1_PRIVATE_H_ */
