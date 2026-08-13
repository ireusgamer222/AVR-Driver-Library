/*
 * KEYPAD_INIT.h
 *
 *  Created on: Jul 21, 2026
 *      Author: dell
 */

#ifndef HAL_KEYPAD_INIT_H_
#define HAL_KEYPAD_INIT_H_
#include "../../STD_TYPES.h"
#include "../../MCAL/DIO_INIT.h"
#include "KEYPAD_CONFIG.h"

#define KEYPAD_NOT_PRESSED      0xFF



void KEYPAD_voidInit(void);
uint8_t KEYPAD_getPressedKey(void);


#endif /* HAL_KEYPAD_INIT_H_ */
