/* ADC_INIT.h */
#ifndef MCAL_ADC_INIT_H_
#define MCAL_ADC_INIT_H_
#include "../../STD_TYPES.h"

#define ADC_CHANNEL0    0
#define ADC_CHANNEL1    1
#define ADC_CHANNEL2    2
#define ADC_CHANNEL3    3
#define ADC_CHANNEL4    4
#define ADC_CHANNEL5    5
#define ADC_CHANNEL6    6
#define ADC_CHANNEL7    7

void ADC_voidInit(void);
void ADC_voidStartConversion(uint8_t Copy_u8Channel);
void ADC_voidSetCallBack(void (*Copy_pVoidCallBack)(u16));

uint8_t ADC_u8GetDigitalValue(uint8_t Copy_u8ChannelNumber, u16* Copy_pu16DigitalValue);
#endif
