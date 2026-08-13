/*
 * WDT_CONFIG.h
 *
 *  Created on: Jul 30, 2026
 *      Author: dell
 */

#ifndef MCAL_WATCHDOG_WDT_CONFIG_H_
#define MCAL_WATCHDOG_WDT_CONFIG_H_



// Available timeout options
#define WDT_TIMEOUT_16_MS   0b000
#define WDT_TIMEOUT_32_MS   0b001
#define WDT_TIMEOUT_65_MS   0b010
#define WDT_TIMEOUT_130_MS  0b011
#define WDT_TIMEOUT_260_MS  0b100
#define WDT_TIMEOUT_520_MS  0b101
#define WDT_TIMEOUT_1_S     0b110
#define WDT_TIMEOUT_2_1_S   0b111

// timeout selection
#define WDT_TIMEOUT_SELECT      WDT_TIMEOUT_2_1_S


#endif /* MCAL_WATCHDOG_WDT_CONFIG_H_ */
