/*
 * TIMER2_CONFIG.h
 *
 * Created on: Jul 30, 2026
 * Author: dell
 */

#ifndef MCAL_TIMERS_TIMER2_CONFIG_H_
#define MCAL_TIMERS_TIMER2_CONFIG_H_

// Operation MODES
#define TIMER2_MODE_NORMAL             		0
#define TIMER2_MODE_PWM_PHASE_CORRECT  		1
#define TIMER2_MODE_CTC                		2
#define TIMER2_MODE_FAST_PWM           		3

// Select the MODE SELECTION in TIMER2
#define TIMER2_MODE                    		TIMER2_MODE_NORMAL

// Output Compare Output Mode OC2 Pin Behavior
#define TIMER2_COM_DISCONNECTED        		0
#define TIMER2_COM_TOGGLE              		1
#define TIMER2_COM_NON_INVERTING       		2
#define TIMER2_COM_INVERTING           		3

// Select Output Compare Mode for OC2 pin
#define TIMER2_COM_MODE                		TIMER2_COM_DISCONNECTED

// Clock Source OPTIONS
#define TIMER2_CLOCK_SYNCHRONOUS       		0
#define TIMER2_CLOCK_ASYNCHRONOUS      		1

// Clock Source Selection
#define TIMER2_CLOCK_SOURCE            		TIMER2_CLOCK_SYNCHRONOUS

// Prescalers MODES
#define TIMER2_NO_CLOCK                		0
#define TIMER2_NO_PRESCALER            		1
#define TIMER2_PRESCALER_8             		2
#define TIMER2_PRESCALER_32            		3
#define TIMER2_PRESCALER_64            		4
#define TIMER2_PRESCALER_128           		5
#define TIMER2_PRESCALER_256           		6
#define TIMER2_PRESCALER_1024          		7

// Select the prescaler MODE
#define TIMER2_PRESCALER               		TIMER2_PRESCALER_8

// Interrupt Enable Options
#define TIMER2_INTERRUPT_DISABLE       		0
#define TIMER2_INTERRUPT_ENABLE        		1

// Overflow and CTC interrupt Init
#define TIMER2_OVF_INTERRUPT           		TIMER2_INTERRUPT_ENABLE
#define TIMER2_COMPARE_INTERRUPT       		TIMER2_INTERRUPT_DISABLE

// Initial and Compare Values
#define TIMER2_INITIAL_VALUE           		0
#define TIMER2_COMPARE_VALUE           		0

#endif /* MCAL_TIMERS_TIMER2_CONFIG_H_ */
