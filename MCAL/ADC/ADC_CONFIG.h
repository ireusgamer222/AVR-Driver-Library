/* ADC_CONFIG.h */

#ifndef MCAL_ADC_CONFIG_H_
#define MCAL_ADC_CONFIG_H_

/* 1. Prescaler Configuration */
#define ADC_PRESCALER_2      1
#define ADC_PRESCALER_4      2
#define ADC_PRESCALER_8      3
#define ADC_PRESCALER_16     4
#define ADC_PRESCALER_32     5
#define ADC_PRESCALER_64     6
#define ADC_PRESCALER_128    7

#define ADC_PRESCALER        ADC_PRESCALER_64



/* Voltage Reference Selection Options */
#define ADC_REF_AREF         0b00    // External AREF, internal Vref turned off
#define ADC_REF_AVCC         0b01    // AVCC with external capacitor at AREF pin
#define ADC_REF_INTERNAL     0b11    // Internal 2.56V Voltage Reference with external capacitor at AREF pin

// Voltage Reference Selection
#define ADC_VOLTAGE_REF      ADC_REF_AVCC


/*Result Adjustment */
#define ADC_RIGHT_ADJUST     0       // Read 10-bit value (Default)
#define ADC_LEFT_ADJUST      1       // Read 8-bit value quickly from ADCH

#define ADC_ADJUSTMENT       ADC_RIGHT_ADJUST


// Auto Trigger OPTIONS
#define ADC_AUTO_TRIGGER_DISABLE   0
#define ADC_AUTO_TRIGGER_ENABLE    1

// Auto Trigger Mode Selection
#define ADC_AUTO_TRIGGER_STATE     ADC_AUTO_TRIGGER_DISABLE


/* 5. Auto Trigger Source Options */
#define ADC_TRIG_FREE_RUNNING       0b000
#define ADC_TRIG_ANALOG_COMP        0b001
#define ADC_TRIG_EXT_INT0           0b010
#define ADC_TRIG_TIMER0_COMP        0b011
#define ADC_TRIG_TIMER0_OVF         0b100
#define ADC_TRIG_TIMER1_COMPB       0b101
#define ADC_TRIG_TIMER1_OVF         0b110
#define ADC_TRIG_TIMER1_CAPT        0b111

// Auto Trigger Source Selection Mode
#define ADC_TRIGGER_SOURCE          ADC_TRIG_FREE_RUNNING

#endif /* MCAL_ADC_CONFIG_H_ */

