/* SSD_INIT.h -- Seven Segment Display driver interface */
#ifndef HAL_SSD_INIT_H_
#define HAL_SSD_INIT_H_

#include "../../STD_TYPES.h"
#include "../../MCAL/DIO_INIT.h"
#define SSD_PORT        DIO_PORTC

void SSD_voidInit(void);
void SSD_displayDigit(uint8_t Digit);

#endif /* HAL_SSD_INIT_H_ */
