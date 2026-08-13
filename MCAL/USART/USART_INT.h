/*
 * USART_INT.h
 *
 *  Created on: Aug 1, 2026
 *      Author: dell
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_

void USART_voidInit(void);

void USART_voidRXEnable(void);
void USART_voidRXDisable(void);

void USART_voidTXEnable(void);
void USART_voidTXDisable(void);


void USART_voidRXInterruptEnable(void);
void USART_voidRXInterruptDisable(void);


void USART_voidTXInterruptEnable(void);
void USART_voidTXInterruptDisable(void);


void USART_voidUDREmptyInterruptEnable(void);
void USART_voidUDREmptyInterruptDisable(void);




void USART_voidSendChar(uint8_t Copy_u8Data);
void USART_voidSendString(uint8_t *Copy_pu8String);
void USART_voidSendNumber(sint32_t Copy_s32Number);


// Use Variables for storing?
uint8_t USART_u8ReceiveChar(void);
void USART_voidReceiveString(uint8_t *Copy_pu8String, uint8_t Copy_u8MaxLen);
sint32_t USART_s32ReceiveNumber(void);


uint8_t USART_u8ReadERROR(void);


void USART_voidRXCallBack(void (*Copy_pVoidCallBack)(void));
void USART_voidUDREmptyCallBack(void (*Copy_pVoidCallBack)(void));
void USART_voidTXCallBack(void (*Copy_pVoidCallBack)(void));


#endif /* MCAL_USART_USART_INT_H_ */
