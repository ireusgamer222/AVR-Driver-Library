/*
 * SERVO_CONFIG.h
 *
 *  Created on: Jul 30, 2026
 *      Author: dell
 */

#ifndef HAL_SERVO_MOTOR_SERVO_CONFIG_H_
#define HAL_SERVO_MOTOR_SERVO_CONFIG_H_

/* Microcontroller AND Timer Clocks */
#define F_CPU                   8000000UL
#define TIMER1_PRESCALER_VAL    8UL

/* Servo Motor Configuration */
#define SERVO_PWM_FREQ_HZ       50UL

/* Servo Angle */
#define SERVO_MIN_ANGLE         0
#define SERVO_MAX_ANGLE         180

/* Servo Pulse Width Limits */
#define SERVO_MIN_PULSE_US      500
#define SERVO_MED_PULSE_US      1400
#define SERVO_MAX_PULSE_US      2300

#endif /* HAL_SERVO_MOTOR_SERVO_CONFIG_H_ */
