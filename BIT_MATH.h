#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Set Bit */
#define SET_BIT(REG, BIT)      ((REG) |= (1U << (BIT)))

/* Clear Bit */
#define CLR_BIT(REG, BIT)      ((REG) &= ~(1U << (BIT)))

/* Toggle Bit */
#define TOG_BIT(REG, BIT)      ((REG) ^= (1U << (BIT)))

/* Get Bit */
#define GET_BIT(REG, BIT)      (((REG) >> (BIT)) & 0x01U)

#endif /* BIT_MATH_H */
