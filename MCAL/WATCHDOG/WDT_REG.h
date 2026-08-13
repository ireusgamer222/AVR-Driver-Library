/*
 * WDT_REG.h
 *
 *  Created on: Jul 30, 2026
 *      Author: dell
 */

#ifndef MCAL_WATCHDOG_WDT_REG_H_
#define MCAL_WATCHDOG_WDT_REG_H_

#include "../../STD_TYPES.h"

// Watchdog Timer Control Register
#define WDT_WDTCR_REG       *((volatile uint8_t*)0x41)

// MCU Control and Status Register
#define WDT_MCUCSR_REG       *((volatile uint8_t*)0x54)

#endif /* MCAL_WATCHDOG_WDT_REG_H_ */
