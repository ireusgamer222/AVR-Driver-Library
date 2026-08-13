/*
 * ADC_REG.h
 *
 *  Created on: Jul 27, 2026
 *      Author: dell
 */

#ifndef MCAL_ADC_REG_H_
#define MCAL_ADC_REG_H_

#define ADC_READ_VALUE_REG 		*((volatile u16*) 0x24)
#define ADC_ADCL        		*((volatile uint8_t*) 0x24)
#define ADC_ADCH        		*((volatile uint8_t*) 0x25)
#define ADC_ADCSRA      		*((volatile uint8_t*) 0x26)
#define ADC_ADMUX       		*((volatile uint8_t*) 0x27)
#define SFIOR_REG       		*((volatile u8*) 0x50)

#endif /* MCAL_ADC_REG_H_ */
