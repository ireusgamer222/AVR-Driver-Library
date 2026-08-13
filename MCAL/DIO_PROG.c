/*
 * DIO_PROG.c
 */

#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "DIO_INIT.h"
#include "DIO_REG.h"


// ============================================================================================
// Setting a certain bit by choice in a register functions
// ============================================================================================
void DIO_setPinDirection(uint8_t PortId, uint8_t PinId, uint8_t PinDirection)
{
    if ((PortId <= 3) && (PinId <= 7) && ((DIO_PIN_OUTPUT == PinDirection) || (DIO_PIN_INPUT == PinDirection)))
    {
        switch (PortId)
        {
        case DIO_PORTA:
            if (DIO_PIN_OUTPUT == PinDirection) {
            	SET_BIT(DDRA_Register, PinId);
            }
            else {
            	CLR_BIT(DDRA_Register, PinId);
            }
            break;



        case DIO_PORTB:
            if (DIO_PIN_OUTPUT == PinDirection) {
            	SET_BIT(DDRB_Register, PinId);
            }
            else {
            	CLR_BIT(DDRB_Register, PinId);
            }
            break;


        case DIO_PORTC:
            if (DIO_PIN_OUTPUT == PinDirection) {
            	SET_BIT(DDRC_Register, PinId);
            }
            else {
            	CLR_BIT(DDRC_Register, PinId);
            }
            break;



        case DIO_PORTD:
            if (DIO_PIN_OUTPUT == PinDirection) {
            	SET_BIT(DDRD_Register, PinId);
            }
            else {
            	CLR_BIT(DDRD_Register, PinId);
            }
            break;
        }
    }
}


void DIO_setPinValue(uint8_t PortId, uint8_t PinId, uint8_t PinValue)
{
    if ((PortId <= 3) && (PinId <= 7))
    {
        switch (PortId)
        {
        case DIO_PORTA:
            if (DIO_PIN_HIGH == PinValue) {
            	SET_BIT(PORTA_Register, PinId);
            }
            else {
            	CLR_BIT(PORTA_Register, PinId);
            }
            break;


        case DIO_PORTB:
            if (DIO_PIN_HIGH == PinValue) {
            	SET_BIT(PORTB_Register, PinId);
            }
            else {
            	CLR_BIT(PORTB_Register, PinId);
            }
            break;



        case DIO_PORTC:
            if (DIO_PIN_HIGH == PinValue) {
            	SET_BIT(PORTC_Register, PinId);
            }
            else {
            	CLR_BIT(PORTC_Register, PinId);
            }
            break;



        case DIO_PORTD:
            if (DIO_PIN_HIGH == PinValue) {
            	SET_BIT(PORTD_Register, PinId);
            }
            else {
            	CLR_BIT(PORTD_Register, PinId);
            }
            break;
        }
    }
}


void DIO_getPinValue(uint8_t PortId, uint8_t PinId, uint8_t* PinValue)
{
    if ((PortId <= 3) && (PinId <= 7) && (PinValue !=  (void *) 0))
    {
        switch (PortId)
        {
        case DIO_PORTA:
            *PinValue = GET_BIT(PINA_Register, PinId);
            break;


        case DIO_PORTB:
            *PinValue = GET_BIT(PINB_Register, PinId);
            break;


        case DIO_PORTC:
            *PinValue = GET_BIT(PINC_Register, PinId);
            break;


        case DIO_PORTD:
            *PinValue = GET_BIT(PIND_Register, PinId);
            break;
        }
    }
}


void DIO_togglePinValue(uint8_t PortId, uint8_t PinId)
{
    if ((PortId <= 3) && (PinId <= 7))
    {
        switch (PortId)
        {
        case DIO_PORTA:
            TOG_BIT(PORTA_Register, PinId);
            break;


        case DIO_PORTB:
            TOG_BIT(PORTB_Register, PinId);
            break;


        case DIO_PORTC:
            TOG_BIT(PORTC_Register, PinId);
            break;


        case DIO_PORTD:
            TOG_BIT(PORTD_Register, PinId);
            break;
        }
    }
}



// ============================================================================================
// Function used for setting up pull-up resistance or the pull-down resistance
// ============================================================================================

void DIO_PortactivePullUpResistance(uint8_t PortId)
{
    if (PortId <= 3)
    {
        switch (PortId)
        {
        case DIO_PORTA:
            PORTA_Register = 0xff;
            break;

        case DIO_PORTB:
            PORTB_Register = 0xff;
            break;

        case DIO_PORTC:
            PORTC_Register = 0xff;
            break;

        case DIO_PORTD:
            PORTD_Register = 0xff;
            break;
        }
    }
}


void DIO_PinactivePullUpResistance(uint8_t PortId, uint8_t PinId)
{
    if ((PortId <= 3) && (PinId <= 7))
    {
        switch (PortId)
        {
        case DIO_PORTA:
            SET_BIT(PORTA_Register, PinId);
            break;

        case DIO_PORTB:
            SET_BIT(PORTB_Register, PinId);
            break;

        case DIO_PORTC:
            SET_BIT(PORTC_Register, PinId);
            break;

        case DIO_PORTD:
            SET_BIT(PORTD_Register, PinId);
            break;
        }
    }
}

// ============================================================================================
// Setting the entire register
// ============================================================================================
void DIO_setPortDirection(uint8_t PortId, uint8_t PortDirection)
{
    if (PortId <= 3)
    {
        switch (PortId)
        {
        case DIO_PORTA:

            DDRA_Register = PortDirection;
            break;

        case DIO_PORTB:
            DDRB_Register = PortDirection;
            break;

        case DIO_PORTC:
            DDRC_Register = PortDirection;
            break;

        case DIO_PORTD:
            DDRD_Register = PortDirection;
            break;
        }
    }
}

void DIO_setPortValue(uint8_t PortId, uint8_t PortValue)
{
    if (PortId <= 3)
    {
        switch (PortId)
        {
        case DIO_PORTA:
            PORTA_Register = PortValue;
            break;

        case DIO_PORTB:
            PORTB_Register = PortValue;
            break;

        case DIO_PORTC:
            PORTC_Register = PortValue;
            break;

        case DIO_PORTD:
            PORTD_Register = PortValue;
            break;
        }
    }
}

void DIO_getPortValue(uint8_t PortId, uint8_t* PortValue)
{
    if ((PortId <= 3) && (PortValue != (void *)0))
    {
        switch (PortId)
        {
        case DIO_PORTA:
            *PortValue = PINA_Register;
            break;

        case DIO_PORTB:
            *PortValue = PINB_Register;
            break;

        case DIO_PORTC:
            *PortValue = PINC_Register;
            break;

        case DIO_PORTD:
            *PortValue = PIND_Register;
            break;
        }
    }
}

void DIO_togglePortValue(uint8_t PortId)
{
    if (PortId <= 3)
    {
        switch (PortId)
        {
        case DIO_PORTA:
            PORTA_Register ^= 0xff;
            break;


        case DIO_PORTB:
            PORTB_Register ^= 0xff;
            break;


        case DIO_PORTC:
            PORTC_Register ^= 0xff;
            break;


        case DIO_PORTD:
            PORTD_Register ^= 0xff;
            break;
        }
    }
}
