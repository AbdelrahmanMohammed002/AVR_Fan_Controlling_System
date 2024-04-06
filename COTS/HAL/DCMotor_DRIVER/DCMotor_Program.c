/*
 * DcMotor_Program.c
 *
 *  Created on: Apr 2, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

// Include standard libraries and custom header files
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO_DRIVER/DIO_Interface.h"
#include "../../MCAL/TIMER0_DRIVER/TIMER0_Interface.h"

#include "DCMotor_Interface.h"
#include "DCMotor_Config.h"

/**
 * @brief Initialize the DC motor.
 *
 * @param Motor: Structure containing DC motor configuration.
 */
void HDCMotor_vInit(DCMotor Motor) {
    // Set direction of motor control pins
    MDIO_vSetPinDirection(Motor.port_name, Motor.input_pin1, OUTPUT);
    MDIO_vSetPinDirection(Motor.port_name, Motor.input_pin2, OUTPUT);

    // Set initial values to motor control pins
    MDIO_vSetPinValue(Motor.port_name, Motor.input_pin1, LOW);
    MDIO_vSetPinValue(Motor.port_name, Motor.input_pin2, LOW);

    // Optionally initialize PWM pin for motor speed control
#if TIMER_PWM == ENABLED
    MDIO_vSetPinDirection(PORT_B, Motor.pwm_timer0, OUTPUT);
    MDIO_vSetPinValue(PORT_B, Motor.pwm_timer0, LOW);
#endif

    // Initialize motor speed and state
    Motor.Speed = 0;
    Motor.State = STOP;
}

/**
 * @brief Set the direction and speed of the DC motor.
 *
 * @param Motor: Structure containing DC motor configuration.
 */
void HDCMotor_RotateDirection_Speed(DCMotor Motor) {
    // Control motor direction based on the motor state
    switch (Motor.State) {
        case STOP:
            MDIO_vSetPinValue(Motor.port_name, Motor.input_pin1, LOW);
            MDIO_vSetPinValue(Motor.port_name, Motor.input_pin2, LOW);
            break;
        case CLOCKWISE:
            MDIO_vSetPinValue(Motor.port_name, Motor.input_pin1, HIGH);
            MDIO_vSetPinValue(Motor.port_name, Motor.input_pin2, LOW);
            break;
        case ANTI_CLOCKWISE:
            MDIO_vSetPinValue(Motor.port_name, Motor.input_pin1, LOW);
            MDIO_vSetPinValue(Motor.port_name, Motor.input_pin2, HIGH);
            break;
        default:
            break;
    }

    // Optionally control motor speed using PWM
#if TIMER_PWM == ENABLED
    // Calculate PWM value based on motor speed percentage
    u8 local_u8SpeedValue = (Motor.Speed * 255) / 100;

    // Initialize and set PWM value using Timer0
    MTIMER0_vInit();
    MTIMER0_vClearCTCRegister();
    MTIMER0_vSetCTCRegister(local_u8SpeedValue);
#endif
}
