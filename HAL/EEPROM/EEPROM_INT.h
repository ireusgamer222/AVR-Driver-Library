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

EEPROM_ErrorType EEPROM_uddtWriteString(u16 Copy_u16Address, uint8_t *Copy_pu8String);
EEPROM_ErrorType EEPROM_uddtReadString(u16 Copy_u16Address, uint8_t *Copy_pu8String);

EEPROM_ErrorType EEPROM_uddtWritePage(u16 Copy_u16Address, uint8_t Copy_pu8Data, uint8_t Copy_u8Length);
EEPROM_ErrorType EEPROM_uddtReadPage(u16 Copy_u16Address, uint8_t *Copy_pu8Data, uint8_t Copy_u8Length);

EEPROM_ErrorType EEPROM_uddtUpdateByte(u16 Copy_u16Address, uint8_t Copy_u8Data);
EEPROM_ErrorType EEPROM_uddtDeleteByte(u16 Copy_u16Address);
EEPROM_ErrorType EEPROM_uddtEraseEEPROM(void);

EEPROM_ErrorType EEPROM_uddtManagerInit(void);
EEPROM_ErrorType EEPROM_uddtManagerReader(void);
EEPROM_ErrorType EEPROM_uddtManagerSaveName(uint8_t *Copy_pu8Name);
EEPROM_ErrorType EEPROM_uddtManagerReadName(uint8_t Copy_u8Index, uint8_t *Copy_pu8String);

#endif /* HAL_EEPROM_EEPROM_INT_H_ */
