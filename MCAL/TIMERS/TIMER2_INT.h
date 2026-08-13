/*
 * TIMER2_INT.h
 *
 * Created on: Jul 30, 2026
 * Author: dell
 */

#ifndef MCAL_TIMERS_TIMER2_INT_H_
#define MCAL_TIMERS_TIMER2_INT_H_

#include "../../STD_TYPES.h"

void TIMER2_voidInit(void);
void TIMER2_voidEnable(void);
void TIMER2_voidDisable(void);

void TIMER2_voidSetCallBack(void (*Copy_pVoidCallBack)(void));

void TIMER2_voidCompareInterruptEnable(void);
void TIMER2_voidCompareInterruptDisable(void);
void TIMER2_voidSetCompareValue(uint8_t Copy_u8Value);
void TIMER2_voidCompareSetCallBack(void (*Copy_pVoidCallBack)(void));



uint8_t TIMER2_u8GetCounterValue(void);
void TIMER2_voidSetCounterValue(uint8_t Copy_u8Value);



uint8_t TIMER2_u8IsAsyncBusy(void);

#endif /* MCAL_TIMERS_TIMER2_INT_H_ */
