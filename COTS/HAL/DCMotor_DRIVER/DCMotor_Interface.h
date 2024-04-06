/*
 * DCMotor_Interface.h
 *
 *  Created on: Apr 2, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

// Enum to define possible states of the DC motor
typedef enum {
    STOP = 0,           // Motor is stopped
    CLOCKWISE,          // Motor rotates clockwise
    ANTI_CLOCKWISE      // Motor rotates anti-clockwise
} DCMotor_State;

// Structure to hold configuration parameters of a DC motor
typedef struct {
    u8 port_name;       // GPIO port name where motor control pins are connected
    u8 input_pin1;      // Pin number for motor input control (e.g., IN1)
    u8 input_pin2;      // Pin number for motor input control (e.g., IN2)
    DCMotor_State State;    // Current state of the motor (STOP, CLOCKWISE, ANTI_CLOCKWISE)
    u8 Speed;           // Speed percentage of the motor (0 to 100)
    u8 pwm_timer0;      // Pin number for PWM control (optional, used for speed control)
} DCMotor;

/**
 * @brief Initialize the DC motor.
 *
 * @param Motor: Structure containing DC motor configuration.
 */
void HDCMotor_vInit(DCMotor Motor);

/**
 * @brief Set the direction and speed of the DC motor.
 *
 * @param Motor: Structure containing DC motor configuration.
 */
void HDCMotor_RotateDirection_Speed(DCMotor Motor);

#endif /* HAL_DCMOTOR_DRIVER_DCMOTOR_INTERFACE_H_ */
