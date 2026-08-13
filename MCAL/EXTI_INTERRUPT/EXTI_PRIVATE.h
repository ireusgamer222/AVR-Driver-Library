#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

/* MCUCR Register Bit Positions (INT0 & INT1 Sense Control) */
#define ISC00_BIT   0
#define ISC01_BIT   1
#define ISC10_BIT   2
#define ISC11_BIT   3

/* MCUCSR Register Bit Positions (INT2 Sense Control) */
#define ISC2_BIT    6

/* GICR Register Bit Positions (Interrupt Enable) */
#define INT1_BIT    7
#define INT0_BIT    6
#define INT2_BIT    5

/* GIFR Register Bit Positions (Interrupt Flags) */
#define INTF1_BIT   7
#define INTF0_BIT   6
#define INTF2_BIT   5

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
