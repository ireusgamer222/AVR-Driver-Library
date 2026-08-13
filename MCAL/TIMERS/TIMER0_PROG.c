#include "TIMER0_INT.h"
#include "TIMER0_CONFIG.h"
#include "TIMER0_PRIVATE.h"
#include "TIMERS_REG.h"
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

static void (*TIMER0_CallBack)(void)     = NULL;
static void (*TIMER0_CTC_CallBack)(void) = NULL;

void TIMER0_voidInit(void) {
    /* TIMER0 Mode SELECTION */
    #if TIMER0_MODE == TIMER0_MODE_NORMAL
        CLR_BIT(TIMERS_TCCR0_REG, WGM00_BIT);
        CLR_BIT(TIMERS_TCCR0_REG, WGM01_BIT);
    #elif TIMER0_MODE == TIMER0_MODE_PWM_PHASE_CORRECT
        SET_BIT(TIMERS_TCCR0_REG, WGM00_BIT);
        CLR_BIT(TIMERS_TCCR0_REG, WGM01_BIT);
    #elif TIMER0_MODE == TIMER0_MODE_CTC
        CLR_BIT(TIMERS_TCCR0_REG, WGM00_BIT);
        SET_BIT(TIMERS_TCCR0_REG, WGM01_BIT);
    #elif TIMER0_MODE == TIMER0_MODE_FAST_PWM
        SET_BIT(TIMERS_TCCR0_REG, WGM00_BIT);
        SET_BIT(TIMERS_TCCR0_REG, WGM01_BIT);
    #endif

    /* CTC Compare Match Output Mode */
    #if TIMER0_COMP_OUT_MODE == TIMER0_COMP_OUT_DISCONNECTED
        CLR_BIT(TIMERS_TCCR0_REG, COM00_BIT);
        CLR_BIT(TIMERS_TCCR0_REG, COM01_BIT);
    #elif TIMER0_COMP_OUT_MODE == TIMER0_COMP_OUT_TOGGLE
        SET_BIT(TIMERS_TCCR0_REG, COM00_BIT);
        CLR_BIT(TIMERS_TCCR0_REG, COM01_BIT);
    #elif TIMER0_COMP_OUT_MODE == TIMER0_COMP_OUT_CLEAR
        CLR_BIT(TIMERS_TCCR0_REG, COM00_BIT);
        SET_BIT(TIMERS_TCCR0_REG, COM01_BIT);
    #elif TIMER0_COMP_OUT_MODE == TIMER0_COMP_OUT_SET
        SET_BIT(TIMERS_TCCR0_REG, COM00_BIT);
        SET_BIT(TIMERS_TCCR0_REG, COM01_BIT);
    #endif

    /* Overflow Interrupt Enable */
    #if TIMER0_OVF_INTERRUPT == TIMER0_INTERRUPT_ENABLE
        SET_BIT(TIMERS_TIMSK_REG, TOIE0_BIT);
    #elif TIMER0_OVF_INTERRUPT == TIMER0_INTERRUPT_DISABLE
        CLR_BIT(TIMERS_TIMSK_REG, TOIE0_BIT);
    #endif

    /* Compare Match Interrupt Enable */
    #if TIMER0_COMPARE_INTERRUPT == TIMER0_INTERRUPT_ENABLE
        SET_BIT(TIMERS_TIMSK_REG, OCIE0_BIT);
    #elif TIMER0_COMPARE_INTERRUPT == TIMER0_INTERRUPT_DISABLE
        CLR_BIT(TIMERS_TIMSK_REG, OCIE0_BIT);
    #endif

    /* Load Initial Counter and Compare Values */
    TIMERS_TCNT0_REG = TIMER0_INITIAL_VALUE;
    TIMERS_OCR0_REG  = TIMER0_COMPARE_VALUE;
}

void TIMER0_voidEnable(void) {
    /* Mask out CS00-CS02 bits and write configured prescaler */
    TIMERS_TCCR0_REG &= ~CS_MASK;
    TIMERS_TCCR0_REG |= TIMER0_PRESCALER;
}

void TIMER0_voidDisable(void) {
    /* Stop clock source to disable Timer0 */
    TIMERS_TCCR0_REG &= ~CS_MASK;
}

void TIMER0_voidSetCallBack(void (*Copy_pVoidCallBack)(void)) {
    if (Copy_pVoidCallBack != NULL) {
        TIMER0_CallBack = Copy_pVoidCallBack;
    }
}

void TIMER0_voidCTCInterruptEnable(void) {
    SET_BIT(TIMERS_TIMSK_REG, OCIE0_BIT);
}

void TIMER0_voidCTCInterruptDisable(void) {
    CLR_BIT(TIMERS_TIMSK_REG, OCIE0_BIT);
}

void TIMER0_voidSetCompareValue(uint8_t Copy_u8Value) {
    TIMERS_OCR0_REG = Copy_u8Value;
}

void TIMER0_voidCTCSetCallBack(void (*Copy_pVoidCallBack)(void)) {
    if (Copy_pVoidCallBack != NULL) {
        TIMER0_CTC_CallBack = Copy_pVoidCallBack;
    }
}

uint8_t TIMER0_u8GetCounterValue(void) {
    return TIMERS_TCNT0_REG;
}





/* Timer0 Overflow ISR */
void __vector_11(void) __attribute__((signal));
void __vector_11(void) {
    if (TIMER0_CallBack != NULL) {
        TIMER0_CallBack();
    }
}

/* Timer0 Compare Match (CTC) ISR */
void __vector_10(void) __attribute__((signal));
void __vector_10(void) {
    if (TIMER0_CTC_CallBack != NULL) {
        TIMER0_CTC_CallBack();
    }
}
