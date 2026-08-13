#ifndef MCAL_TIMERS_TIMER0_INT_H_
#define MCAL_TIMERS_TIMER0_INT_H_

#include "../../STD_TYPES.h"

void TIMER0_voidInit(void);
void TIMER0_voidEnable(void);
void TIMER0_voidDisable(void);

void TIMER0_voidSetCallBack(void (*Copy_pVoidCallBack)(void));

void TIMER0_voidCTCInterruptEnable(void);
void TIMER0_voidCTCInterruptDisable(void);
void TIMER0_voidSetCompareValue(uint8_t Copy_u8Value);
void TIMER0_voidCTCSetCallBack(void (*Copy_pVoidCallBack)(void));

uint8_t TIMER0_u8GetCounterValue(void);

#endif /* MCAL_TIMERS_TIMER0_INT_H_ */
