#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "../../MCAL/TWI/TWI_INT.h"
#include "EEPROM_CONFIG.h"
#include "EEPROM_INT.h"
#include <util/delay.h>

void EEPROM_voidInit(void) {
}

EEPROM_ErrorType EEPROM_uddtWriteByte(u16 Copy_u16Address, uint8_t Copy_u8Data) {

    EEPROM_ErrorType Local_ErrorStatus = EEPROM_OK;
    uint8_t Local_u8EEPROMDeviceAddress = EEPROM_BASE_ADDRESS | (Copy_u16Address >> 8);
    uint8_t Local_u8EEPROMMemoryByte = (uint8_t)Copy_u16Address;


    if(TWI_SendStartCondition() != E_OK){
        Local_ErrorStatus = EEPROM_START_ERROR;
    }
    else if(TWI_SendSlaveAddressWrite(Local_u8EEPROMDeviceAddress) != E_OK){
        Local_ErrorStatus = EEPROM_CHIP_ADDRESS_ERROR;
    }
    else if(TWI_MasterWriteDataByte(Local_u8EEPROMMemoryByte) != E_OK){
        Local_ErrorStatus = EEPROM_MEMORY_ADDRESS_ERROR;
    }
    else if(TWI_MasterWriteDataByte(Copy_u8Data) != E_OK){
        Local_ErrorStatus = EEPROM_DATA_WRITE_ERROR;
    }

    TWI_SendStopCondition();

    // Wait for the EEPROM
    _delay_ms(EEPROM_WRITE_DELAY_MS);

    return Local_ErrorStatus;
}

EEPROM_ErrorType EEPROM_uddtReadByte(u16 Copy_u16Address, uint8_t *Copy_pu8Data) {

    EEPROM_ErrorType Local_ErrorStatus = EEPROM_OK;
    uint8_t Local_u8EEPROMDeviceAddress = EEPROM_BASE_ADDRESS | (Copy_u16Address >> 8);
    uint8_t Local_u8EEPROMMemoryByte = (uint8_t)Copy_u16Address;

    if(Copy_pu8Data == NULL){
        Local_ErrorStatus = EEPROM_NULL_POINTER_ERROR;
    }
    else{
        if(TWI_SendStartCondition() != E_OK){
            Local_ErrorStatus = EEPROM_START_ERROR;
        }
        else if(TWI_SendSlaveAddressWrite(Local_u8EEPROMDeviceAddress) != E_OK){
            Local_ErrorStatus = EEPROM_CHIP_ADDRESS_ERROR;
        }
        else if(TWI_MasterWriteDataByte(Local_u8EEPROMMemoryByte) != E_OK){
            Local_ErrorStatus = EEPROM_MEMORY_ADDRESS_ERROR;
        }
        else if(TWI_SendRepeatedStartCondition() != E_OK){
            Local_ErrorStatus = EEPROM_REPEATED_START_ERROR;
        }
        else if(TWI_SendSlaveAddressRead(Local_u8EEPROMDeviceAddress) != E_OK){
            Local_ErrorStatus = EEPROM_CHIP_ADDRESS_ERROR;
        }
        else if(TWI_MasterReadDataByteNack(Copy_pu8Data) != E_OK){
            Local_ErrorStatus = EEPROM_DATA_READ_ERROR;
        }
    }

    TWI_SendStopCondition();

    return Local_ErrorStatus;
}



EEPROM_ErrorType EEPROM_uddtEraseEEPROM(void){
    EEPROM_ErrorType Local_uddtErrorState = EEPROM_OK;

    for(u16 Local_u16Address = 0; Local_u16Address < EEPROM_ADDRESS_SIZE; Local_u16Address++){
        Local_uddtErrorState = EEPROM_uddtWriteByte(Local_u16Address, 0xFF);
        if(Local_uddtErrorState != EEPROM_OK){
            break;
        }
    }

    return Local_uddtErrorState;
}
