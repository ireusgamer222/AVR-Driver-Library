/*
 * SERVO_PROG.c
 *
 *  Created on: Jul 30, 2026
 *      Author: dell
 */

#include "SERVO_INT.h"
#include "SERVO_CONFIG.h"
#include "../../STD_TYPES.h"

#include "../../MCAL/DIO_INIT.h"
#include "../../MCAL/TIMERS/TIMER1_INT.h"


// ICR1 of TIMER1 Value calculation equation
#define SERVO_ICR1_TOP_VALUE   (F_CPU / (TIMER1_PRESCALER_VAL * SERVO_PWM_FREQ_HZ))
#define SERVO_ANGLE_INCREAMENT ((SERVO_MAX_PULSE_US - SERVO_MIN_PULSE_US) / SERVO_MAX_ANGLE)



void SERVO_voidInit(void) {
    DIO_setPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);

    TIMER1_voidSetICR1Value(SERVO_ICR1_TOP_VALUE);

    TIMER1_voidEnable();
}

void SERVO_voidSetAngle(uint8_t Copy_u8Angle) {

    if (Copy_u8Angle > SERVO_MAX_ANGLE) {
        Copy_u8Angle = SERVO_MAX_ANGLE;
    }



    u16 Local_u16PulseWidth = SERVO_MIN_PULSE_US + (u16) ((uint32_t)Copy_u8Angle * SERVO_ANGLE_INCREAMENT);
    TIMER1_voidSetCompareValueA(Local_u16PulseWidth);
}
