/*
 * EEPROM_INT.h
 *
 *  Created on: Aug 3, 2026
 *      Author: dell
 */

#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

#include "../../STD_TYPES.h"

typedef enum {
    EEPROM_OK = 0,
    EEPROM_START_ERROR,
    EEPROM_REPEATED_START_ERROR,
    EEPROM_CHIP_ADDRESS_ERROR,
    EEPROM_MEMORY_ADDRESS_ERROR,
    EEPROM_DATA_WRITE_ERROR,
    EEPROM_DATA_READ_ERROR,
    EEPROM_NULL_POINTER_ERROR,
} EEPROM_ErrorType;



void EEPROM_voidInit(void);

EEPROM_ErrorType EEPROM_uddtWriteByte(u16 Copy_u16Address, uint8_t Copy_u8Data);
EEPROM_ErrorType EEPROM_uddtReadByte(u16 Copy_u16Address, uint8_t *Copy_pu8Data);

EEPROM_ErrorType EEPROM_uddtEraseEEPROM(void);



#endif /* HAL_EEPROM_EEPROM_INT_H_ */
