/*
 * TIMER2_PROG.c
 *
 * Created on: Jul 30, 2026
 * Author: dell
 */

#include "TIMER2_INT.h"
#include "TIMER2_CONFIG.h"
#include "TIMER2_PRIVATE.h"
#include "TIMERS_REG.h"
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

static void (*TIMER2_OVF_CallBack)(void)  = NULL;
static void (*TIMER2_COMP_CallBack)(void) = NULL;

void TIMER2_voidInit(void) {
    // TIMER2 MODE SELECTION
    #if TIMER2_MODE == TIMER2_MODE_NORMAL
        CLR_BIT(TIMERS_TCCR2_REG, WGM20_BIT);
        CLR_BIT(TIMERS_TCCR2_REG, WGM21_BIT);
    #elif TIMER2_MODE == TIMER2_MODE_PWM_PHASE_CORRECT
        SET_BIT(TIMERS_TCCR2_REG, WGM20_BIT);
        CLR_BIT(TIMERS_TCCR2_REG, WGM21_BIT);
    #elif TIMER2_MODE == TIMER2_MODE_CTC
        CLR_BIT(TIMERS_TCCR2_REG, WGM20_BIT);
        SET_BIT(TIMERS_TCCR2_REG, WGM21_BIT);
    #elif TIMER2_MODE == TIMER2_MODE_FAST_PWM
        SET_BIT(TIMERS_TCCR2_REG, WGM20_BIT);
        SET_BIT(TIMERS_TCCR2_REG, WGM21_BIT);
    #endif

    // Configure CTC Compare Match Output Mode
    #if TIMER2_COM_MODE == TIMER2_COM_DISCONNECTED
        CLR_BIT(TIMERS_TCCR2_REG, COM20_BIT);
        CLR_BIT(TIMERS_TCCR2_REG, COM21_BIT);
    #elif TIMER2_COM_MODE == TIMER2_COM_TOGGLE
        #if (TIMER2_MODE == TIMER2_MODE_PWM_PHASE_CORRECT) || (TIMER2_MODE == TIMER2_MODE_FAST_PWM)
            #error "TIMER2: COM_TOGGLE is reserved in PWM modes - use NON_INVERTING or INVERTING"
        #endif
        SET_BIT(TIMERS_TCCR2_REG, COM20_BIT);
        CLR_BIT(TIMERS_TCCR2_REG, COM21_BIT);
    #elif TIMER2_COM_MODE == TIMER2_COM_NON_INVERTING
        CLR_BIT(TIMERS_TCCR2_REG, COM20_BIT);
        SET_BIT(TIMERS_TCCR2_REG, COM21_BIT);
    #elif TIMER2_COM_MODE == TIMER2_COM_INVERTING
        SET_BIT(TIMERS_TCCR2_REG, COM20_BIT);
        SET_BIT(TIMERS_TCCR2_REG, COM21_BIT);
    #endif

    // Clocl soucre
    #if TIMER2_CLOCK_SOURCE == TIMER2_CLOCK_ASYNCHRONOUS
        SET_BIT(TIMERS_ASSR_REG, AS2_BIT);
    #elif TIMER2_CLOCK_SOURCE == TIMER2_CLOCK_SYNCHRONOUS
        CLR_BIT(TIMERS_ASSR_REG, AS2_BIT);
    #endif

    // Configure Overflow Interrupt Enable
    #if TIMER2_OVF_INTERRUPT == TIMER2_INTERRUPT_ENABLE
        SET_BIT(TIMERS_TIMSK_REG, TOIE2_BIT);
    #elif TIMER2_OVF_INTERRUPT == TIMER2_INTERRUPT_DISABLE
        CLR_BIT(TIMERS_TIMSK_REG, TOIE2_BIT);
    #endif

    // Configure Compare Match Interrupt Enable
    #if TIMER2_COMPARE_INTERRUPT == TIMER2_INTERRUPT_ENABLE
        SET_BIT(TIMERS_TIMSK_REG, OCIE2_BIT);
    #elif TIMER2_COMPARE_INTERRUPT == TIMER2_INTERRUPT_DISABLE
        CLR_BIT(TIMERS_TIMSK_REG, OCIE2_BIT);
    #endif

    // Load Initial Counter and Compare Values
    TIMERS_TCNT2_REG = TIMER2_INITIAL_VALUE;
    TIMERS_OCR2_REG  = TIMER2_COMPARE_VALUE;
}

void TIMER2_voidEnable(void) {
    // Prescaler selection
    TIMERS_TCCR2_REG &= ~CS_MASK;
    TIMERS_TCCR2_REG |= TIMER2_PRESCALER;
}

void TIMER2_voidDisable(void) {
    // Disable timer clock
    TIMERS_TCCR2_REG &= ~CS_MASK;
}


void TIMER2_voidSetCallBack(void (*Copy_pVoidCallBack)(void)) {
    if (Copy_pVoidCallBack != NULL) {
        TIMER2_OVF_CallBack = Copy_pVoidCallBack;
    }
}

void TIMER2_voidCompareInterruptEnable(void) {
    SET_BIT(TIMERS_TIMSK_REG, OCIE2_BIT);
}

void TIMER2_voidCompareInterruptDisable(void) {
    CLR_BIT(TIMERS_TIMSK_REG, OCIE2_BIT);
}

void TIMER2_voidSetCompareValue(uint8_t Copy_u8Value) {
    TIMERS_OCR2_REG = Copy_u8Value;
}

void TIMER2_voidCompareSetCallBack(void (*Copy_pVoidCallBack)(void)) {
    if (Copy_pVoidCallBack != NULL) {
        TIMER2_COMP_CallBack = Copy_pVoidCallBack;
    }
}

uint8_t TIMER2_u8GetCounterValue(void) {
    return TIMERS_TCNT2_REG;
}

void TIMER2_voidSetCounterValue(uint8_t Copy_u8Value) {
    TIMERS_TCNT2_REG = Copy_u8Value;
}



uint8_t TIMER2_u8IsAsyncBusy(void) {
    // Return flag status
    return (GET_BIT(TIMERS_ASSR_REG, TCN2UB_BIT) || GET_BIT(TIMERS_ASSR_REG, OCR2UB_BIT) || GET_BIT(TIMERS_ASSR_REG, TCR2UB_BIT));
}


// ISR FUNCTIONS
// Timer2 CTC Compare Match ISR FUNCTION
void __vector_4(void) __attribute__((signal));
void __vector_4(void) {
    if (TIMER2_COMP_CallBack != NULL) {
        TIMER2_COMP_CallBack();
    }
}

// Timer2 Overflow ISR FUNCTION
void __vector_5(void) __attribute__((signal));
void __vector_5(void) {
    if (TIMER2_OVF_CallBack != NULL) {
        TIMER2_OVF_CallBack();
    }
}
