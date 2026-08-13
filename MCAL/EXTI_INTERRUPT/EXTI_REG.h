/*
 * EXTI_REG.h
 *
 *  Created on: Jul 26, 2026
 *      Author: dell
 */

#ifndef MCAL_EXTI_REG_H_
#define MCAL_EXTI_REG_H_

#include "../../STD_TYPES.h"

/* MCU Control Register - for the INT0 and INT1 */
#define EXTI_MCUCR_REG      				*((volatile uint8_t*) 0x55)

/* MCU Control and Status Register - for the INT2 */
#define EXTI_MCUCSR_REG     				*((volatile uint8_t*) 0x54)

/* General Interrupt Control Register - the enable bits for the INT0, INT1, INT2 */
#define EXTI_GICR_REG       				*((volatile uint8_t*) 0x5B)

/* General Interrupt Flag Register - the interrupt Flags for the INT0, INT1, INT2 **/
#define EXTI_GIFR_REG       				*((volatile uint8_t*) 0x5A)

#endif /* MCAL_EXTI_REG_H_ */
