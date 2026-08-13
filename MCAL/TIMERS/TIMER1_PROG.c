#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "TIMER1_CONFIG.h"
#include "TIMER1_PRIVATE.h"
#include "TIMERS_REG.h"
#include "TIMER1_INT.h"




static  void (*TIMER1_OVF_CallBack)(void)   = NULL;
static  void (*TIMER1_COMPA_CallBack)(void) = NULL;
static  void (*TIMER1_COMPB_CallBack)(void) = NULL;
static  void (*TIMER1_ICU_CallBack)(void)   = NULL;

void TIMER1_voidInit(void){
    // TIMER1 MODE Selection
    #if TIMER1_MODE == TIMER1_MODE_NORMAL
        CLR_BIT(TIMERS_TCCR1A_REG, WGM10_BIT);
        CLR_BIT(TIMERS_TCCR1A_REG, WGM11_BIT);
        CLR_BIT(TIMERS_TCCR1B_REG, WGM12_BIT);
        CLR_BIT(TIMERS_TCCR1B_REG, WGM13_BIT);
    #elif TIMER1_MODE == TIMER1_MODE_CTC_OCR1A
        CLR_BIT(TIMERS_TCCR1A_REG, WGM10_BIT);
        CLR_BIT(TIMERS_TCCR1A_REG, WGM11_BIT);
        SET_BIT(TIMERS_TCCR1B_REG, WGM12_BIT);
        CLR_BIT(TIMERS_TCCR1B_REG, WGM13_BIT);
    #elif TIMER1_MODE == TIMER1_MODE_CTC_ICR1
        CLR_BIT(TIMERS_TCCR1A_REG, WGM10_BIT);
        CLR_BIT(TIMERS_TCCR1A_REG, WGM11_BIT);
        SET_BIT(TIMERS_TCCR1B_REG, WGM12_BIT);
        SET_BIT(TIMERS_TCCR1B_REG, WGM13_BIT);
    #elif TIMER1_MODE == TIMER1_MODE_FAST_PWM_ICR1
        CLR_BIT(TIMERS_TCCR1A_REG, WGM10_BIT);
        SET_BIT(TIMERS_TCCR1A_REG, WGM11_BIT);
        SET_BIT(TIMERS_TCCR1B_REG, WGM12_BIT);
        SET_BIT(TIMERS_TCCR1B_REG, WGM13_BIT);
    #endif



    // Configure CTC Compare Match Output Mode A
    #if TIMER1_COMP_OUT_MODE_A == TIMER1_COMP_OUT_DISCONNECTED
        CLR_BIT(TIMERS_TCCR1A_REG, COM1A0_BIT);
        CLR_BIT(TIMERS_TCCR1A_REG, COM1A1_BIT);
    #elif TIMER1_COMP_OUT_MODE_A == TIMER1_COMP_OUT_TOGGLE
        SET_BIT(TIMERS_TCCR1A_REG, COM1A0_BIT);
        CLR_BIT(TIMERS_TCCR1A_REG, COM1A1_BIT);
    #elif TIMER1_COMP_OUT_MODE_A == TIMER1_COMP_OUT_CLEAR
        CLR_BIT(TIMERS_TCCR1A_REG, COM1A0_BIT);
        SET_BIT(TIMERS_TCCR1A_REG, COM1A1_BIT);
    #elif TIMER1_COMP_OUT_MODE_A == TIMER1_COMP_OUT_SET
        SET_BIT(TIMERS_TCCR1A_REG, COM1A0_BIT);
        SET_BIT(TIMERS_TCCR1A_REG, COM1A1_BIT);
    #endif



    // Configure CTC Compare Match Output Mode B
    #if TIMER1_COMP_OUT_MODE_B == TIMER1_COMP_OUT_DISCONNECTED
        CLR_BIT(TIMERS_TCCR1A_REG, COM1B0_BIT);
        CLR_BIT(TIMERS_TCCR1A_REG, COM1B1_BIT);
    #elif TIMER1_COMP_OUT_MODE_B == TIMER1_COMP_OUT_TOGGLE
        SET_BIT(TIMERS_TCCR1A_REG, COM1B0_BIT);
        CLR_BIT(TIMERS_TCCR1A_REG, COM1B1_BIT);
    #elif TIMER1_COMP_OUT_MODE_B == TIMER1_COMP_OUT_CLEAR
        CLR_BIT(TIMERS_TCCR1A_REG, COM1B0_BIT);
        SET_BIT(TIMERS_TCCR1A_REG, COM1B1_BIT);
    #elif TIMER1_COMP_OUT_MODE_B == TIMER1_COMP_OUT_SET
        SET_BIT(TIMERS_TCCR1A_REG, COM1B0_BIT);
        SET_BIT(TIMERS_TCCR1A_REG, COM1B1_BIT);
    #endif



    // Configure Overflow Interrupt Enable
    #if TIMER1_OVF_INTERRUPT == TIMER1_INTERRUPT_ENABLE
        SET_BIT(TIMERS_TIMSK_REG, TOIE1_BIT);
    #elif TIMER1_OVF_INTERRUPT == TIMER1_INTERRUPT_DISABLE
        CLR_BIT(TIMERS_TIMSK_REG, TOIE1_BIT);
    #endif



    // CTC Configure Compare Match A Interrupt Enable
    #if TIMER1_COMPA_INTERRUPT == TIMER1_INTERRUPT_ENABLE
        SET_BIT(TIMERS_TIMSK_REG, OCIE1A_BIT);
    #elif TIMER1_COMPA_INTERRUPT == TIMER1_INTERRUPT_DISABLE
        CLR_BIT(TIMERS_TIMSK_REG, OCIE1A_BIT);
    #endif



    // Configure CTC Compare Match B Interrupt Enable
    #if TIMER1_COMPB_INTERRUPT == TIMER1_INTERRUPT_ENABLE
        SET_BIT(TIMERS_TIMSK_REG, OCIE1B_BIT);
    #elif TIMER1_COMPB_INTERRUPT == TIMER1_INTERRUPT_DISABLE
        CLR_BIT(TIMERS_TIMSK_REG, OCIE1B_BIT);
    #endif

    // Adjust the ICU Input Capture Interrupt Enable
    #if TIMER1_ICU_INTERRUPT == TIMER1_INTERRUPT_ENABLE
        SET_BIT(TIMERS_TIMSK_REG, TICIE1_BIT);
    #elif TIMER1_ICU_INTERRUPT == TIMER1_INTERRUPT_DISABLE
        CLR_BIT(TIMERS_TIMSK_REG, TICIE1_BIT);
    #endif

    // Load Initial Counter and Compare and Input Capture Values
    TIMERS_TCNT1_REG = TIMER1_INITIAL_VALUE;
    TIMERS_OCR1A_REG = TIMER1_COMPARE_VALUE_A;
    TIMERS_OCR1B_REG = TIMER1_COMPARE_VALUE_B;
    TIMERS_ICR1_REG  = TIMER1_ICU_INITIAL_VALUE;

    // ICU Trigger Edge Selection
    #if TIMER1_ICU_TRIGGER == TIMER1_ICU_RISING_EDGE
        SET_BIT(TIMERS_TCCR1B_REG, ICES1_BIT);
    #elif TIMER1_ICU_TRIGGER == TIMER1_ICU_FALLING_EDGE
        CLR_BIT(TIMERS_TCCR1B_REG, ICES1_BIT);
    #endif
}

void TIMER1_voidEnable(void){
    // Prescaler Selection
    TIMERS_TCCR1B_REG &= ~(CS_MASK << CS10_BIT);
    TIMERS_TCCR1B_REG |= (TIMER1_PRESCALER << CS10_BIT);
}

void TIMER1_voidDisable(void){
    // Disable Timer
    TIMERS_TCCR1B_REG &= ~(CS_MASK << CS10_BIT);
}

void TIMER1_voidSetCallBack(void (*Copy_pVoidCallBack)(void)){
    if (Copy_pVoidCallBack != NULL){
        TIMER1_OVF_CallBack = Copy_pVoidCallBack;
    }
}




void TIMER1_voidSetICR1Value(u16 Copy_u16Value){
    TIMERS_ICR1_REG = Copy_u16Value;
}

u16 TIMER1_u16GetICR1Value(void){
    return TIMERS_ICR1_REG;
}

u16 TIMER1_u16GetCounterValue(void){
    return TIMERS_TCNT1_REG;
}




void TIMER1_voidCompAInterruptEnable(void){
    SET_BIT(TIMERS_TIMSK_REG, OCIE1A_BIT);
}

void TIMER1_voidCompAInterruptDisable(void){
    CLR_BIT(TIMERS_TIMSK_REG, OCIE1A_BIT);
}

void TIMER1_voidSetCompareValueA(u16 Copy_u16Value){
    TIMERS_OCR1A_REG = Copy_u16Value;
}

void TIMER1_voidCompASetCallBack(void (*Copy_pVoidCallBack)(void)){
    if (Copy_pVoidCallBack != NULL){
        TIMER1_COMPA_CallBack = Copy_pVoidCallBack;
    }
}




void TIMER1_voidCompBInterruptEnable(void){
    SET_BIT(TIMERS_TIMSK_REG, OCIE1B_BIT);
}

void TIMER1_voidCompBInterruptDisable(void){
    CLR_BIT(TIMERS_TIMSK_REG, OCIE1B_BIT);
}

void TIMER1_voidSetCompareValueB(u16 Copy_u16Value){
    TIMERS_OCR1B_REG = Copy_u16Value;
}

void TIMER1_voidCompBSetCallBack(void (*Copy_pVoidCallBack)(void)){
    if (Copy_pVoidCallBack != NULL){
        TIMER1_COMPB_CallBack = Copy_pVoidCallBack;
    }
}




void TIMER1_voidICUInterruptEnable(void){
    SET_BIT(TIMERS_TIMSK_REG, TICIE1_BIT);
}

void TIMER1_voidICUInterruptDisable(void){
    CLR_BIT(TIMERS_TIMSK_REG, TICIE1_BIT);
}

void TIMER1_voidICUSetTrigger(uint8_t Copy_u8MODE){
    if(Copy_u8MODE == TIMER1_ICU_RISING_EDGE){
        SET_BIT(TIMERS_TCCR1B_REG, ICES1_BIT);
    }
    else if(Copy_u8MODE == TIMER1_ICU_FALLING_EDGE){
        CLR_BIT(TIMERS_TCCR1B_REG, ICES1_BIT);
    }
}

void TIMER1_voidICUSetCallBack(void (*Copy_pVoidCallBack)(void)){
    if(Copy_pVoidCallBack != NULL){
        TIMER1_ICU_CallBack = Copy_pVoidCallBack;
    }
}




/* Timer1 Overflow ISR */
void __vector_9(void) __attribute__((signal));
void __vector_9(void) {
    if (TIMER1_OVF_CallBack != NULL){
        TIMER1_OVF_CallBack();
    }
}

/* Timer1 CTC Compare Match B ISR */
void __vector_8(void) __attribute__((signal));
void __vector_8(void) {
    if (TIMER1_COMPB_CallBack != NULL){
        TIMER1_COMPB_CallBack();
    }
}

/* Timer1 CTC Compare Match A ISR */
void __vector_7(void) __attribute__((signal));
void __vector_7(void) {
    if (TIMER1_COMPA_CallBack != NULL){
        TIMER1_COMPA_CallBack();
    }
}

/* Timer1 Input Capture Unit ISR */
void __vector_6(void) __attribute__((signal));
void __vector_6(void) {
    if (TIMER1_ICU_CallBack != NULL){
        TIMER1_ICU_CallBack();
    }
}
