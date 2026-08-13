#ifndef MCAL_TIMERS_TIMER0_CONFIG_H_
#define MCAL_TIMERS_TIMER0_CONFIG_H_

// Operation MODES
#define TIMER0_MODE_NORMAL             0
#define TIMER0_MODE_PWM_PHASE_CORRECT  1
#define TIMER0_MODE_CTC                2
#define TIMER0_MODE_FAST_PWM           3

// Select the MODE SELECTION in TIMER0
#define TIMER0_MODE                    TIMER0_MODE_FAST_PWM

// CTC COMPARE OUTPUT MODE OC0 PIN BEHAVIOR
#define TIMER0_COMP_OUT_DISCONNECTED   0
#define TIMER0_COMP_OUT_TOGGLE         1
#define TIMER0_COMP_OUT_CLEAR          2
#define TIMER0_COMP_OUT_SET            3

// Select CTC Output Compare Mode for OC0 pin
#define TIMER0_COMP_OUT_MODE           TIMER0_COMP_OUT_CLEAR

// Prescalers MODES
#define TIMER0_NO_CLOCK                0
#define TIMER0_NO_PRESCALER            1
#define TIMER0_PRESCALER_8             2
#define TIMER0_PRESCALER_64            3
#define TIMER0_PRESCALER_256           4
#define TIMER0_PRESCALER_1024          5
#define TIMER0_EXT_FALLING             6
#define TIMER0_EXT_RISING              7

// Select the prescaler MODE
#define TIMER0_PRESCALER               TIMER0_PRESCALER_8

// Interrupt Enable Options
#define TIMER0_INTERRUPT_DISABLE       0
#define TIMER0_INTERRUPT_ENABLE        1

// Overflow interrupt TOGGLE Init
#define TIMER0_OVF_INTERRUPT           TIMER0_INTERRUPT_DISABLE

// CTC interrupt TOGGLE at Init
#define TIMER0_COMPARE_INTERRUPT       TIMER0_INTERRUPT_DISABLE

// Loaded into TCNT0 at Init NORMAL AND PWM modes
#define TIMER0_INITIAL_VALUE           0

// Loaded into OCR0 at Init CTC MODE
#define TIMER0_COMPARE_VALUE           0

#endif /* MCAL_TIMERS_TIMER0_CONFIG_H_ */
