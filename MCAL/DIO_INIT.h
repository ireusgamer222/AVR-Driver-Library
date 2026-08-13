/*
 * DIO_INIT.h
 */


#ifndef MCAL_DIO_INIT_H_
#include"../STD_TYPES.h"
#define MCAL_DIO_INIT_H_



#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7



#define DIO_PIN_INPUT   0
#define DIO_PIN_OUTPUT  1



#define DIO_PIN_HIGH    1
#define DIO_PIN_LOW     0



#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3



#define DIO_PORT_INPUT  	0x00
#define DIO_PORT_OUTPUT		0xff



#define DIO_PORT_LOW  		0x00
#define DIO_PORT_HIGH		0xff



void DIO_setPinDirection  	(uint8_t PortId ,uint8_t PinId, uint8_t PinDirection);
void DIO_setPinValue   		(uint8_t PortId ,uint8_t PinId , uint8_t PinValue);
void DIO_getPinValue		(uint8_t PortId ,uint8_t PinId , uint8_t* PinValue);
void DIO_togglePinValue 	(uint8_t PortId , uint8_t PinId);


void DIO_PinactivePullUpResistance(uint8_t PortId , uint8_t PinId);
void DIO_PinactivePullDownResistance(uint8_t PortId, uint8_t PinId);
void DIO_PortactivePullUpResistance(uint8_t PortId);
void DIO_PortactivePullDownResistance(uint8_t PortId);



void DIO_setPortDirection   (uint8_t PortId , uint8_t PortDirection);
void DIO_setPortValue		(uint8_t PortId , uint8_t PortValue);
void DIO_getPortValue		(uint8_t PortId , uint8_t* PortValue);
void DIO_togglePortValue(uint8_t PortId);

#endif /* MCAL_DIO_INIT_H_ */
