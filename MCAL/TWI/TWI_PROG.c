/*
 * TWI_PROG.c
 *
 *  Created on: Aug 3, 2026
 *      Author: dell
 */

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "TWI_REG.h"
#include "TWI_CONFIG.h"
#include "TWI_PRIVATE.h"
#include "TWI_INT.h"

static void (* volatile TWI_INTERRUPT_CallBack)(void) = NULL;

// PRIVATE WAIT ASYNC FUNCTION
static uint8_t TWI_u8Wait(void) {
    u16 Local_u16Timeout = 0;
    while (GET_BIT(TWI_TWCR_REG, TWI_TWINT_BIT) == 0) {
        Local_u16Timeout++;

        if (Local_u16Timeout > TWI_FLAG_TIMEOUT) {
            return 0;
        }
    }
    return 1;
}




void TWI_voidInit(void) {
    // BIT RATE REGISTER SETTING
    TWI_TWBR_REG = (uint8_t) TWI_TWBR_VALUE;


    // PRESCALER REGISTER SETTING
    TWI_TWSR_REG = (TWI_PRESCALER & TWI_PRESCALER_MASK);


    // GENERAL CALL
    #if TWI_GENERAL_CALL == TWI_GENERAL_CALL_ENABLE
        SET_BIT(TWI_TWAR_REG, TWI_TWGCE_BIT);
    #else
        CLR_BIT(TWI_TWAR_REG, TWI_TWGCE_BIT);
    #endif
}

void TWI_voidEnable(void) {
    // I2C ENABLE
    SET_BIT(TWI_TWCR_REG, TWI_TWEN_BIT);
}

void TWI_voidDisable(void) {
    // I2C DISABLE
    CLR_BIT(TWI_TWCR_REG, TWI_TWEN_BIT);
}

void TWI_voidInterruptEnable(void) {
    // I2C INTERRUPT ENABLE
    SET_BIT(TWI_TWCR_REG, TWI_TWIE_BIT);
}

void TWI_voidInterruptDisable(void) {
    // I2C INTERRUPT DISABLE
    CLR_BIT(TWI_TWCR_REG, TWI_TWIE_BIT);
}



Std_ReturnType TWI_SendStartCondition(void){
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    uint8_t Local_u8Temp = (1 << TWI_TWINT_BIT) | (1 << TWI_TWSTA_BIT) | (1 << TWI_TWEN_BIT);

    TWI_TWCR_REG = Local_u8Temp;

    if (TWI_u8Wait() == 1){
        if (TWI_u8GetStatusCode() == TWI_STATUS_START){
            Local_ErrorStatus = E_OK;
        }
    }
    else{
    	TWI_SendStopCondition();
    }
    return Local_ErrorStatus;
}


Std_ReturnType TWI_SendRepeatedStartCondition(void){
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    uint8_t Local_u8Temp = (1 << TWI_TWINT_BIT) | (1 << TWI_TWSTA_BIT) | (1 << TWI_TWEN_BIT);

    TWI_TWCR_REG = Local_u8Temp;

    if (TWI_u8Wait() == 1){
        if (TWI_u8GetStatusCode() == TWI_STATUS_REP_START){
            Local_ErrorStatus = E_OK;
        }
    }
    else{
        TWI_SendStopCondition();
    }
    return Local_ErrorStatus;
}


void TWI_SendStopCondition(void) {
    uint8_t Local_u8Temp = (1 << TWI_TWINT_BIT) | (1 << TWI_TWSTO_BIT) | (1 << TWI_TWEN_BIT);
    TWI_TWCR_REG = Local_u8Temp;
}



Std_ReturnType TWI_SendSlaveAddressWrite(uint8_t Copy_u8SlaveAddress) {
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    TWI_TWDR_REG = (Copy_u8SlaveAddress << 1);

    uint8_t Local_u8Temp = (1 << TWI_TWINT_BIT) | (1 << TWI_TWEN_BIT);
    TWI_TWCR_REG = Local_u8Temp;

    if (TWI_u8Wait() == 1) {
        if (TWI_u8GetStatusCode() == TWI_STATUS_MT_SLA_ACK) {
            Local_ErrorStatus = E_OK;
        }
        else{
            TWI_SendStopCondition();
        }
    }
    else{
        TWI_SendStopCondition();
    }
    return Local_ErrorStatus;
}




Std_ReturnType TWI_SendSlaveAddressRead(uint8_t Copy_u8SlaveAddress){
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    TWI_TWDR_REG = ((Copy_u8SlaveAddress << 1) | 1);

    uint8_t Local_u8Temp = (1 << TWI_TWINT_BIT) | (1 << TWI_TWEN_BIT);
    TWI_TWCR_REG = Local_u8Temp;

    if (TWI_u8Wait() == 1){
        if (TWI_u8GetStatusCode() == TWI_STATUS_MR_SLA_ACK){
            Local_ErrorStatus = E_OK;
        }
        else{
            TWI_SendStopCondition();
        }
    }
    else{
        TWI_SendStopCondition();
    }
    return Local_ErrorStatus;
}



Std_ReturnType TWI_MasterWriteDataByte(uint8_t Copy_u8Data){
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;
    TWI_TWDR_REG = Copy_u8Data;

    uint8_t Local_u8Temp = (1 << TWI_TWINT_BIT) | (1 << TWI_TWEN_BIT);
    TWI_TWCR_REG = Local_u8Temp;

    if (TWI_u8Wait() == 1){
        if (TWI_u8GetStatusCode() == TWI_STATUS_MT_DATA_ACK){
            Local_ErrorStatus = E_OK;
        }
        else{
            TWI_SendStopCondition();
        }
    }
    else{
        TWI_SendStopCondition();
    }
    return Local_ErrorStatus;
}




Std_ReturnType TWI_MasterReadDataByteAck(uint8_t* Copy_pu8Data) {
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;

    if (Copy_pu8Data != NULL){
        uint8_t Local_u8Temp = (1 << TWI_TWINT_BIT) | (1 << TWI_TWEN_BIT) | (1 << TWI_TWEA_BIT);
        TWI_TWCR_REG = Local_u8Temp;

        if (TWI_u8Wait() == 1) {
            if (TWI_u8GetStatusCode() == TWI_STATUS_MR_DATA_ACK){
                *Copy_pu8Data = TWI_TWDR_REG;
                Local_ErrorStatus = E_OK;
            }
            else {
                TWI_SendStopCondition();
            }
        }
    }
    return Local_ErrorStatus;
}

Std_ReturnType TWI_MasterReadDataByteNack(uint8_t* Copy_pu8Data) {
    Std_ReturnType Local_ErrorStatus = E_NOT_OK;

    if (Copy_pu8Data != NULL){
        uint8_t Local_u8Temp = (1 << TWI_TWINT_BIT) | (1 << TWI_TWEN_BIT);
        TWI_TWCR_REG = Local_u8Temp;


        if (TWI_u8Wait() == 1){
            if (TWI_u8GetStatusCode() == TWI_STATUS_MR_DATA_NACK){
                *Copy_pu8Data = TWI_TWDR_REG;
                Local_ErrorStatus = E_OK;
            }
            else{
                TWI_SendStopCondition();
            }
        }
    }
    return Local_ErrorStatus;
}




uint8_t TWI_u8GetStatusCode(void) {
    return (TWI_TWSR_REG & TWI_STATUS_MASK);
}




void TWI_voidSetSlaveAddress(uint8_t Copy_u8SlaveAddress) {
    TWI_TWAR_REG = (Copy_u8SlaveAddress << 1);
}



void TWI_voidSetCallBack(void (*Copy_pVoidCallBack)(void)){
    if (Copy_pVoidCallBack != NULL) {
        TWI_INTERRUPT_CallBack = Copy_pVoidCallBack;
    }
}


// ISR FUNCTION for TWI
void __vector_19(void) __attribute__((signal));
void __vector_19(void) {
    if (TWI_INTERRUPT_CallBack != NULL) {
        TWI_INTERRUPT_CallBack();
    }
}
