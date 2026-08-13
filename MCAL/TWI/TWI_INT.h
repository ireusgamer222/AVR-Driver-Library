/*
 * TWI_INT.h
 *
 *  Created on: Aug 3, 2026
 *      Author: dell
 */

#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_

void TWI_voidInit(void);


void TWI_voidEnable(void);
void TWI_voidDisable(void);


void TWI_voidInterruptEnable(void);
void TWI_voidInterruptDisable(void);


Std_ReturnType TWI_SendStartCondition(void);
Std_ReturnType TWI_SendRepeatedStartCondition(void);
void TWI_SendStopCondition(void);



Std_ReturnType TWI_SendSlaveAddressWrite(uint8_t Copy_u8SlaveAddress);
Std_ReturnType TWI_SendSlaveAddressRead(uint8_t Copy_u8SlaveAddress);
Std_ReturnType TWI_MasterWriteDataByte(uint8_t Copy_u8Data);



Std_ReturnType TWI_MasterReadDataByteAck(uint8_t* Copy_pu8Data);
Std_ReturnType TWI_MasterReadDataByteNack(uint8_t* Copy_pu8Data);

uint8_t TWI_u8GetStatusCode(void);


void TWI_voidSetSlaveAddress(uint8_t Copy_u8SlaveAddress);

void TWI_voidSetCallBack(void (*Copy_pVoidCallBack)(void));
#endif /* MCAL_TWI_TWI_INT_H_ */
