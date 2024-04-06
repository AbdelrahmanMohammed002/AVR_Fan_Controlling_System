/*
 * main.c
 *
 *  Created on: Apr 6, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO_DRIVER/DIO_Interface.h"
#include "../MCAL/ADC_DRIVER/ADC_Interface.h"
#include "../HAL/DCMotor_DRIVER/DCMotor_Interface.h"
#include "../HAL/LCD_DRIVER/LCD_Interface.h"

#include <util/delay.h>

#define F_CPU 8000000UL

#define IN1 0
#define IN2 1
#define FAN_PORT PORT_B
#define OC0 3

int main(int argc, char **argv) {
    // Initialize digital pin for LM35 sensor
    MDIO_vSetPinDirection(PORT_A, 0, INPUT);
    MDIO_vSetPinValue(PORT_A, 0, LOW); // Ensure internal pull-down resistor

    u16 local_u16ADC_value = 0;
    u8 local_u8Digital_value = 0;
    u8 local_u8Temperature = 0;
    u8 local_u8LCD_value[5];

    // Initialize DC fan control parameters
    DCMotor local_DCFan;
    local_DCFan.Speed = 0;
    local_DCFan.State = STOP;
    local_DCFan.input_pin1 = IN1;
    local_DCFan.input_pin2 = IN2;
    local_DCFan.port_name = FAN_PORT;
    local_DCFan.pwm_timer0 = OC0;

    // Initialize DC fan motor
    HDCMotor_vInit(local_DCFan);

    // Initialize LCD
    HLCD_vInit();

    // Display initial messages on LCD
    u8 local_u8String_Fan[] = "FAN is ";
    HLCD_vMoveTo(0, 0);
    HLCD_vSendString(local_u8String_Fan);

    u8 local_u8String_Temp[] = "Temperature: ";
    HLCD_vMoveTo(1, 0);
    HLCD_vSendString(local_u8String_Temp);

    u8 local_u8State_off[] = "OFF";
    u8 local_u8State_on[] = "ON ";

    // Initialize ADC
    MADC_vInit();

    while (1) {
        // Start ADC conversion
        MADC_vStartConversion(ADC0);
        local_u16ADC_value = MADC_u16GetResult();

        // Map ADC value to temperature (0-255)
        local_u8Digital_value = (u8)((local_u16ADC_value * 255) / 1023);
        local_u8Temperature = local_u8Digital_value;

        // Control DC fan based on temperature
        if (local_u8Temperature < 30) {
            local_DCFan.State = STOP;
            local_DCFan.Speed = 0;
            HDCMotor_RotateDirection_Speed(local_DCFan);
        } else if (local_u8Temperature >= 30 && local_u8Temperature < 60) {
            local_DCFan.State = CLOCKWISE;
            local_DCFan.Speed = 25;
            HDCMotor_RotateDirection_Speed(local_DCFan);
        } else if (local_u8Temperature >= 60 && local_u8Temperature < 90) {
            local_DCFan.State = CLOCKWISE;
            local_DCFan.Speed = 50;
            HDCMotor_RotateDirection_Speed(local_DCFan);
        } else if (local_u8Temperature >= 90 && local_u8Temperature < 120) {
            local_DCFan.State = CLOCKWISE;
            local_DCFan.Speed = 75;
            HDCMotor_RotateDirection_Speed(local_DCFan);
        } else if (local_u8Temperature >= 120) {
            local_DCFan.State = CLOCKWISE;
            local_DCFan.Speed = 100;
            HDCMotor_RotateDirection_Speed(local_DCFan);
        }

        // Display fan state on LCD
        HLCD_vMoveTo(0, 7);
        if (local_DCFan.Speed == 0) {
            HLCD_vSendString(local_u8State_off);
        } else {
            HLCD_vSendString(local_u8State_on);
        }

        // Display temperature on LCD
        HLCD_vMoveTo(1, 12);
        itoa(local_u8Temperature, local_u8LCD_value, 10);
        HLCD_vSendString(local_u8LCD_value);
        HLCD_vMoveTo(1, 15);
        HLCD_vSendData(0xDF); // Degree symbol
        _delay_ms(1000);
    }

    return 0;
}
