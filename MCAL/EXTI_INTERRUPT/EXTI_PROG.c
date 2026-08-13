#include "EXTI_INIT.h"
#include "EXTI_CONFIG.h"
#include "EXTI_PRIVATE.h"
#include "EXTI_REG.h"
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

static void (*EXTI_CallBack[3])(void) = {NULL, NULL, NULL};

void EXTI_voidInit(void) {
    /* Configure INT0 */
    #if EXTI_INT0_SENSE == EXTI_LOW_LEVEL
        CLR_BIT(EXTI_MCUCR_REG, ISC00_BIT);
        CLR_BIT(EXTI_MCUCR_REG, ISC01_BIT);
    #elif EXTI_INT0_SENSE == EXTI_ON_CHANGE
        SET_BIT(EXTI_MCUCR_REG, ISC00_BIT);
        CLR_BIT(EXTI_MCUCR_REG, ISC01_BIT);
    #elif EXTI_INT0_SENSE == EXTI_FALLING_EDGE
        CLR_BIT(EXTI_MCUCR_REG, ISC00_BIT);
        SET_BIT(EXTI_MCUCR_REG, ISC01_BIT);
    #elif EXTI_INT0_SENSE == EXTI_RISING_EDGE
        SET_BIT(EXTI_MCUCR_REG, ISC00_BIT);
        SET_BIT(EXTI_MCUCR_REG, ISC01_BIT);
    #endif

    #if EXTI_INT0_INITIAL_STATE == EXTI_ENABLE
        SET_BIT(EXTI_GICR_REG, INT0_BIT);
    #elif EXTI_INT0_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(EXTI_GICR_REG, INT0_BIT);
    #endif



    /* Configure INT1 */
    #if EXTI_INT1_SENSE == EXTI_LOW_LEVEL
        CLR_BIT(EXTI_MCUCR_REG, ISC10_BIT);
        CLR_BIT(EXTI_MCUCR_REG, ISC11_BIT);
    #elif EXTI_INT1_SENSE == EXTI_ON_CHANGE
        SET_BIT(EXTI_MCUCR_REG, ISC10_BIT);
        CLR_BIT(EXTI_MCUCR_REG, ISC11_BIT);
    #elif EXTI_INT1_SENSE == EXTI_FALLING_EDGE
        CLR_BIT(EXTI_MCUCR_REG, ISC10_BIT);
        SET_BIT(EXTI_MCUCR_REG, ISC11_BIT);
    #elif EXTI_INT1_SENSE == EXTI_RISING_EDGE
        SET_BIT(EXTI_MCUCR_REG, ISC10_BIT);
        SET_BIT(EXTI_MCUCR_REG, ISC11_BIT);
    #endif

    #if EXTI_INT1_INITIAL_STATE == EXTI_ENABLE
        SET_BIT(EXTI_GICR_REG, INT1_BIT);
    #elif EXTI_INT1_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(EXTI_GICR_REG, INT1_BIT);
    #endif




    /* Configure INT2 */
    #if EXTI_INT2_SENSE == EXTI_FALLING_EDGE
        CLR_BIT(EXTI_MCUCSR_REG, ISC2_BIT);
    #elif EXTI_INT2_SENSE == EXTI_RISING_EDGE
        SET_BIT(EXTI_MCUCSR_REG, ISC2_BIT);
    #else
        #error "EXTI: Invalid INT2 Sense Configuration (Only FALLING or RISING supported)"
    #endif

    #if EXTI_INT2_INITIAL_STATE == EXTI_ENABLE
        SET_BIT(EXTI_GICR_REG, INT2_BIT);
    #elif EXTI_INT2_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(EXTI_GICR_REG, INT2_BIT);
    #endif
}

void EXTI_voidSetMODE(uint8_t Copy_u8InterruptID, uint8_t Copy_u8Mode) {
    switch (Copy_u8InterruptID) {
        case EXTI_INT0:
            switch (Copy_u8Mode) {
                case EXTI_LOW_LEVEL:
                    CLR_BIT(EXTI_MCUCR_REG, ISC00_BIT);
                    CLR_BIT(EXTI_MCUCR_REG, ISC01_BIT);
                    break;
                case EXTI_ON_CHANGE:
                    SET_BIT(EXTI_MCUCR_REG, ISC00_BIT);
                    CLR_BIT(EXTI_MCUCR_REG, ISC01_BIT);
                    break;
                case EXTI_FALLING_EDGE:
                    CLR_BIT(EXTI_MCUCR_REG, ISC00_BIT);
                    SET_BIT(EXTI_MCUCR_REG, ISC01_BIT);
                    break;
                case EXTI_RISING_EDGE:
                    SET_BIT(EXTI_MCUCR_REG, ISC00_BIT);
                    SET_BIT(EXTI_MCUCR_REG, ISC01_BIT);
                    break;
            }
            break;

        case EXTI_INT1:
            switch (Copy_u8Mode) {
                case EXTI_LOW_LEVEL:
                    CLR_BIT(EXTI_MCUCR_REG, ISC10_BIT);
                    CLR_BIT(EXTI_MCUCR_REG, ISC11_BIT);
                    break;
                case EXTI_ON_CHANGE:
                    SET_BIT(EXTI_MCUCR_REG, ISC10_BIT);
                    CLR_BIT(EXTI_MCUCR_REG, ISC11_BIT);
                    break;
                case EXTI_FALLING_EDGE:
                    CLR_BIT(EXTI_MCUCR_REG, ISC10_BIT);
                    SET_BIT(EXTI_MCUCR_REG, ISC11_BIT);
                    break;
                case EXTI_RISING_EDGE:
                    SET_BIT(EXTI_MCUCR_REG, ISC10_BIT);
                    SET_BIT(EXTI_MCUCR_REG, ISC11_BIT);
                    break;
            }
            break;

        case EXTI_INT2:
            switch (Copy_u8Mode) {
                case EXTI_FALLING_EDGE:
                    CLR_BIT(EXTI_MCUCSR_REG, ISC2_BIT);
                    break;
                case EXTI_RISING_EDGE:
                    SET_BIT(EXTI_MCUCSR_REG, ISC2_BIT);
                    break;
            }
            break;
    }
}

void EXTI_voidEnable(uint8_t Copy_u8InterruptID) {
    switch (Copy_u8InterruptID) {
        case EXTI_INT0:
            SET_BIT(EXTI_GICR_REG, INT0_BIT);
            break;
        case EXTI_INT1:
            SET_BIT(EXTI_GICR_REG, INT1_BIT);
            break;
        case EXTI_INT2:
            SET_BIT(EXTI_GICR_REG, INT2_BIT);
            break;
    }
}

void EXTI_voidDisable(uint8_t Copy_u8InterruptID) {
    switch (Copy_u8InterruptID) {
        case EXTI_INT0:
            CLR_BIT(EXTI_GICR_REG, INT0_BIT);
            break;

        case EXTI_INT1:
            CLR_BIT(EXTI_GICR_REG, INT1_BIT);
            break;

        case EXTI_INT2:
            CLR_BIT(EXTI_GICR_REG, INT2_BIT);
            break;
    }
}

void EXTI_voidSetCallBack(uint8_t Copy_u8InterruptID, void (*Copy_pVoidCallBack)(void)) {
    if ((Copy_pVoidCallBack != NULL) && (Copy_u8InterruptID <= EXTI_INT2)) {
        EXTI_CallBack[Copy_u8InterruptID] = Copy_pVoidCallBack;
    }
}





/* ISR for INT0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void) {
    if (EXTI_CallBack[EXTI_INT0] != NULL) {
        EXTI_CallBack[EXTI_INT0]();
    }
}

/* ISR for INT1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void) {
    if (EXTI_CallBack[EXTI_INT1] != NULL) {
        EXTI_CallBack[EXTI_INT1]();
    }
}

/* ISR for INT2 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void) {
    if (EXTI_CallBack[EXTI_INT2] != NULL) {
        EXTI_CallBack[EXTI_INT2]();
    }
}
