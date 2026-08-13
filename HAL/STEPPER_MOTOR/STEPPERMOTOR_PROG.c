/*
#include "../../STD_TYPES.h"
#include "../../MCAL/DIO_INIT.h" * STEPPERMOTOR_PROG.c
 *
 *  Created on: Jul 23, 2026
 *      Author: dell
 */
#include <util/delay.h>
#include "STEPPERMOTOR_INIT.h"
#include "STEPPERMOTOR_CONFIG.h"

void STEPPER_voidInit(void){
    DIO_setPinDirection(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_OUTPUT);
    DIO_setPinDirection(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_OUTPUT);
    DIO_setPinDirection(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_OUTPUT);
    DIO_setPinDirection(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_OUTPUT);


    DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_LOW);
    DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_LOW);
    DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_LOW);
    DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_LOW);
}


void STEPPER_voidRotate(uint32_t Copy_u8Steps, uint8_t Copy_u8Direction){
    uint32_t COUNTER1 = 0;

    if(Copy_u8Direction == STEPPER_CCW){
        for(; COUNTER1 < Copy_u8Steps; COUNTER1++){

            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_HIGH);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_LOW);
            _delay_ms(DELAY_MS_TIME);


            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_HIGH);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_LOW);
            _delay_ms(DELAY_MS_TIME);


            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_HIGH);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_LOW);
            _delay_ms(DELAY_MS_TIME);


            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_HIGH);
            _delay_ms(DELAY_MS_TIME);
        }
    }
    else if(Copy_u8Direction == STEPPER_CW){
        for(; COUNTER1 < Copy_u8Steps; COUNTER1++){

            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_HIGH);
            _delay_ms(DELAY_MS_TIME);


            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_HIGH);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_LOW);
            _delay_ms(DELAY_MS_TIME);


            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_HIGH);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_LOW);
            _delay_ms(DELAY_MS_TIME);


            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_HIGH);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_LOW);
            DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_LOW);
            _delay_ms(DELAY_MS_TIME);
        }
    }
}

void STEPPER_voidStop(void){
    DIO_setPinValue(STEPPER_PORT, STEPPER_PIN0, DIO_PIN_LOW);
    DIO_setPinValue(STEPPER_PORT, STEPPER_PIN1, DIO_PIN_LOW);
    DIO_setPinValue(STEPPER_PORT, STEPPER_PIN2, DIO_PIN_LOW);
    DIO_setPinValue(STEPPER_PORT, STEPPER_PIN3, DIO_PIN_LOW);
}
