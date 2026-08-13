#include "ADC_INT.h"
#include "ADC_CONFIG.h"
#include "ADC_REG.h"
#include "ADC_PRIVATE.h"
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

#define ADC_TIMEOUT             50000
#define STD_TYPES_OK            1
#define STD_TYPES_NOK           0

// Pointer to store the callback function address
static void (*ADC_CallBack)(u16) = NULL;

void ADC_voidInit(void) {
    // Configure Voltage Reference
    #if ADC_VOLTAGE_REF == ADC_REF_AREF
        CLR_BIT(ADC_ADMUX, REFS1_BIT);
        CLR_BIT(ADC_ADMUX, REFS0_BIT);
    #elif ADC_VOLTAGE_REF == ADC_REF_AVCC
        CLR_BIT(ADC_ADMUX, REFS1_BIT);
        SET_BIT(ADC_ADMUX, REFS0_BIT);
    #elif ADC_VOLTAGE_REF == ADC_REF_INTERNAL
        SET_BIT(ADC_ADMUX, REFS1_BIT);
        SET_BIT(ADC_ADMUX, REFS0_BIT);
    #endif

    // Configure Result Adjustment
    #if ADC_ADJUSTMENT == ADC_RIGHT_ADJUST
        CLR_BIT(ADC_ADMUX, ADLAR_BIT);
    #elif ADC_ADJUSTMENT == ADC_LEFT_ADJUST
        SET_BIT(ADC_ADMUX, ADLAR_BIT);
    #endif

    // Apply the prescaler
    #if ADC_PRESCALER == ADC_PRESCALER_2
        CLR_BIT(ADC_ADCSRA, ADPS2_BIT);
        CLR_BIT(ADC_ADCSRA, ADPS1_BIT);
        SET_BIT(ADC_ADCSRA, ADPS0_BIT);
    #elif ADC_PRESCALER == ADC_PRESCALER_4
        CLR_BIT(ADC_ADCSRA, ADPS2_BIT);
        SET_BIT(ADC_ADCSRA, ADPS1_BIT);
        CLR_BIT(ADC_ADCSRA, ADPS0_BIT);
    #elif ADC_PRESCALER == ADC_PRESCALER_8
        CLR_BIT(ADC_ADCSRA, ADPS2_BIT);
        SET_BIT(ADC_ADCSRA, ADPS1_BIT);
        SET_BIT(ADC_ADCSRA, ADPS0_BIT);
    #elif ADC_PRESCALER == ADC_PRESCALER_16
        SET_BIT(ADC_ADCSRA, ADPS2_BIT);
        CLR_BIT(ADC_ADCSRA, ADPS1_BIT);
        CLR_BIT(ADC_ADCSRA, ADPS0_BIT);
    #elif ADC_PRESCALER == ADC_PRESCALER_32
        SET_BIT(ADC_ADCSRA, ADPS2_BIT);
        CLR_BIT(ADC_ADCSRA, ADPS1_BIT);
        SET_BIT(ADC_ADCSRA, ADPS0_BIT);
    #elif ADC_PRESCALER == ADC_PRESCALER_64
        SET_BIT(ADC_ADCSRA, ADPS2_BIT);
        SET_BIT(ADC_ADCSRA, ADPS1_BIT);
        CLR_BIT(ADC_ADCSRA, ADPS0_BIT);
    #elif ADC_PRESCALER == ADC_PRESCALER_128
        SET_BIT(ADC_ADCSRA, ADPS2_BIT);
        SET_BIT(ADC_ADCSRA, ADPS1_BIT);
        SET_BIT(ADC_ADCSRA, ADPS0_BIT);
    #endif

    // Configure Auto Triggering
    #if ADC_AUTO_TRIGGER_STATE == ADC_AUTO_TRIGGER_ENABLE
        // Set the trigger source in SFIOR
        SFIOR_REG = (SFIOR_REG & ~(ADTS_MASK << ADTS0_BIT)) | (ADC_TRIGGER_SOURCE << ADTS0_BIT);
        // Enable Auto Triggering
        SET_BIT(ADC_ADCSRA, ADATE_BIT);
    #elif ADC_AUTO_TRIGGER_STATE == ADC_AUTO_TRIGGER_DISABLE
        // Ensure Auto Triggering is disabled
        CLR_BIT(ADC_ADCSRA, ADATE_BIT);
    #endif

    // Enable the ADC peripheral
    SET_BIT(ADC_ADCSRA, ADEN_BIT);
}

uint8_t ADC_u8GetDigitalValue(uint8_t Copy_u8ChannelNumber, u16* Copy_pu16DigitalValue) {
	uint8_t Local_u8ErrorState = STD_TYPES_OK;
    uint32_t Local_u32TimeoutCounter = 0;

    if (Copy_pu16DigitalValue != NULL && Copy_u8ChannelNumber < 32) {
        // Clear MUX bits and set the channel
        ADC_ADMUX &= ~MUX_MASK;
        ADC_ADMUX |= Copy_u8ChannelNumber;

        // Start Conversion
        SET_BIT(ADC_ADCSRA, ADSC_BIT);

        // Wait for the conversion to complete
        while ((!GET_BIT(ADC_ADCSRA, ADIF_BIT)) && (Local_u32TimeoutCounter < ADC_TIMEOUT)) {
            Local_u32TimeoutCounter++;
        }

        if (Local_u32TimeoutCounter == ADC_TIMEOUT) {
            Local_u8ErrorState = STD_TYPES_NOK;
        }
        else {
            // Conversion succeeded
            SET_BIT(ADC_ADCSRA, ADIF_BIT);

            // Read the 16-bit ADC Data Register
            *Copy_pu16DigitalValue = ADC_READ_VALUE_REG;
        }
    }
    else {
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}

void ADC_voidStartConversion(uint8_t Copy_u8Channel) {
    if (Copy_u8Channel < 32) {
        // Bit masking, then setting the combination
        ADC_ADMUX = (ADC_ADMUX & ~MUX_MASK) | Copy_u8Channel;

        // Start a single conversion
        SET_BIT(ADC_ADCSRA, ADSC_BIT);
    }
}

void ADC_voidSetCallBack(void (*Copy_pVoidCallBack)(u16)) {
    // Store the callback address if a valid pointer is passed
    if (Copy_pVoidCallBack != NULL) {
        ADC_CallBack = Copy_pVoidCallBack;
        SET_BIT(ADC_ADCSRA, ADIE_BIT);
    }
}

// ADC hardware interrupt vector
void __vector_16(void) __attribute__((signal));
void __vector_16(void) {
    u16 Local_u16Result;

    Local_u16Result = ADC_READ_VALUE_REG;
    // Execute the application callback with the read result
    if (ADC_CallBack != NULL) {
        ADC_CallBack(Local_u16Result);
    }
}
