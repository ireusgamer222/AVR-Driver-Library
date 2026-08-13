/*
 * TWI_CONFIG.h
 *
 *  Created on: Aug 3, 2026
 *      Author: dell
 */

#ifndef MCAL_TWI_TWI_CONFIG_H_
#define MCAL_TWI_TWI_CONFIG_H_

#define TWI_F_CPU                   8000000UL
#define TWI_SCL_FREQUENCY           100000UL

// Clock Rate Prescaler Options
#define TWI_PRESCALER_1             0
#define TWI_PRESCALER_4             1
#define TWI_PRESCALER_16            2
#define TWI_PRESCALER_64            3

// Clock Rate Prescaler Options Selection
#define TWI_PRESCALER               TWI_PRESCALER_1

// General Call Recognition
#define TWI_GENERAL_CALL_DISABLE    0
#define TWI_GENERAL_CALL_ENABLE     1

#define TWI_GENERAL_CALL            TWI_GENERAL_CALL_DISABLE

// TWI Interrupt Options
#define TWI_INTERRUPT_DISABLE       0
#define TWI_INTERRUPT_ENABLE        1

#define TWI_INTERRUPT               TWI_INTERRUPT_DISABLE

#endif /* MCAL_TWI_TWI_CONFIG_H_ */
