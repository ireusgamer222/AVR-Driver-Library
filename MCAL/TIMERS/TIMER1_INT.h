// TIMER1_INT.h

#ifndef MCAL_TIMERS_TIMER1_INT_H_
#define MCAL_TIMERS_TIMER1_INT_H_

#include "../../STD_TYPES.h"

void TIMER1_voidInit(void);
void TIMER1_voidEnable(void);
void TIMER1_voidDisable(void);

void TIMER1_voidSetCallBack(void (*Copy_pVoidCallBack)(void));


void TIMER1_voidCompAInterruptEnable(void);
void TIMER1_voidCompAInterruptDisable(void);
void TIMER1_voidSetCompareValueA(u16 Copy_u16Value);
void TIMER1_voidCompASetCallBack(void (*Copy_pVoidCallBack)(void));


void TIMER1_voidCompBInterruptEnable(void);
void TIMER1_voidCompBInterruptDisable(void);
void TIMER1_voidSetCompareValueB(u16 Copy_u16Value);
void TIMER1_voidCompBSetCallBack(void (*Copy_pVoidCallBack)(void));


void TIMER1_voidSetICR1Value(u16 Copy_u16Value);
u16 TIMER1_u16GetCounterValue(void);
u16 TIMER1_u16GetICR1Value(void);

void TIMER1_voidICUInterruptEnable(void);
void TIMER1_voidICUInterruptDisable(void);
void TIMER1_voidICUSetTrigger(uint8_t Copy_u8MODE);
void TIMER1_voidICUSetCallBack(void (*Copy_pVoidCallBack)(void));

#endif
