/*
 * STEPPERMOTOR_init.h
 *
 *  Created on: Jul 23, 2026
 *      Author: dell
 */
#ifndef HAL_STEPPERMOTOR_INIT_H_
#define HAL_STEPPERMOTOR_INIT_H_

#include <util/delay.h>
#include "../../STD_TYPES.h"
#include "../../MCAL/DIO_INIT.h"


#define STEPPER_CW      0
#define STEPPER_CCW     1

void STEPPER_voidInit(void);
void STEPPER_voidRotate(uint32_t Copy_u8Steps, uint8_t Copy_u8Direction);
void STEPPER_voidStop(void);

#endif /* HAL_STEPPERMOTOR_INIT_H_ */
