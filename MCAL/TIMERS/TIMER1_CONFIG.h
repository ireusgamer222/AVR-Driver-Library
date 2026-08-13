// TIMER1_CONFIG.h

#ifndef MCAL_TIMERS_TIMER1_CONFIG_H_
#define MCAL_TIMERS_TIMER1_CONFIG_H_

// TIMER1 MODES
#define TIMER1_MODE_NORMAL                        0
#define TIMER1_MODE_CTC_OCR1A                     4
#define TIMER1_MODE_CTC_ICR1                      12
#define TIMER1_MODE_FAST_PWM_ICR1                 14

// TIMER1 MODE SELECTION
#define TIMER1_MODE                               TIMER1_MODE_NORMAL



// TIMER1 PRESCALER MODES
#define TIMER1_NO_CLOCK                           0
#define TIMER1_NO_PRESCALER                       1
#define TIMER1_PRESCALER_8                        2
#define TIMER1_PRESCALER_64                       3
#define TIMER1_PRESCALER_256                      4
#define TIMER1_PRESCALER_1024                     5
#define TIMER1_EXT_FALLING                        6
#define TIMER1_EXT_RISING                         7

// TIMER1 PRESCALER MODE SELECTION
#define TIMER1_PRESCALER                          TIMER1_PRESCALER_8



// CTC COMPARE OUTPUT MODES
#define TIMER1_COMP_OUT_DISCONNECTED              0
#define TIMER1_COMP_OUT_TOGGLE                    1
#define TIMER1_COMP_OUT_CLEAR                     2
#define TIMER1_COMP_OUT_SET                       3

// CTC COMPARE OUTPUT MODE SELECTIONS
#define TIMER1_COMP_OUT_MODE_A                    TIMER1_COMP_OUT_CLEAR
#define TIMER1_COMP_OUT_MODE_B                    TIMER1_COMP_OUT_DISCONNECTED



// INTERRUPT OR FLAG ENABLE OPTIONS
#define TIMER1_INTERRUPT_DISABLE                  0
#define TIMER1_INTERRUPT_ENABLE                   1

// Overflow Interrupt
#define TIMER1_OVF_INTERRUPT                      TIMER1_INTERRUPT_DISABLE

// Compare Match A Interrupt
#define TIMER1_COMPA_INTERRUPT                    TIMER1_INTERRUPT_DISABLE

// Compare Match B Interrupt
#define TIMER1_COMPB_INTERRUPT                    TIMER1_INTERRUPT_DISABLE

// Input Capture Interrupt
#define TIMER1_ICU_INTERRUPT                      TIMER1_INTERRUPT_DISABLE


// INITIAL VALUES FOR TIMER1
// Preload value for TCNT1
#define TIMER1_INITIAL_VALUE                      0

// CTC Compare value for OCR1A
#define TIMER1_COMPARE_VALUE_A                    0

// CTC Compare value for OCR1B
#define TIMER1_COMPARE_VALUE_B                    0

// Initial value for ICR1 (Used as Top in CTC_ICR1 mode)
#define TIMER1_ICU_INITIAL_VALUE                  20000



// ICU OPTIONS
#define TIMER1_ICU_RISING_EDGE      1
#define TIMER1_ICU_FALLING_EDGE     0

// ICU OPTION SELECTION
#define TIMER1_ICU_TRIGGER      TIMER1_ICU_RISING_EDGE


#endif
