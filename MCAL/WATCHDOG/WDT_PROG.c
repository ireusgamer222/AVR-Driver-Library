/*
 * WDT_PROG.c
 *
 *  Created on: Jul 30, 2026
 *      Author: dell
 */

#include "WDT_INT.h"
#include "WDT_PRIVATE.h"
#include "WDT_REG.h"
#include "WDT_CONFIG.h"

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"


void WDT_voidEnable(){
	WDT_WDTCR_REG = (1 << WDT_WDE_BIT);
	WDT_WDTCR_REG |= (WDT_TIMEOUT_SELECT & 0x07);
}


void WDT_voidDisable(void){
    WDT_WDTCR_REG = (1 << WDT_WDTOE_BIT) | (1 << WDT_WDE_BIT);
    WDT_WDTCR_REG = 0x00;
}

void WDT_voidClearResetFlag(void){
	CLR_BIT(WDT_MCUCSR_REG, WDT_WDRF_BIT);
}
