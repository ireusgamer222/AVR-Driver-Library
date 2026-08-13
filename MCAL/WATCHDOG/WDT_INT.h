/*
 * WDT_INT.h
 *
 *  Created on: Jul 30, 2026
 *      Author: dell
 */

#ifndef MCAL_WATCHDOG_WDT_INT_H_
#define MCAL_WATCHDOG_WDT_INT_H_

#include "../../STD_TYPES.h"


void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidClearResetFlag(void);

#endif /* MCAL_WATCHDOG_WDT_INT_H_ */
