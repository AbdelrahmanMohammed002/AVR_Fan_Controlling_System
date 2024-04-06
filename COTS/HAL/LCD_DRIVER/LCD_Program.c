/*
 * LCD_Interface.c
 *
 *  Created on: (Date)
 *      Author: (Author Name)
 *		Github: (GitHub Link)
 */

/* libraries */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

/* MCAL */
#include "../../MCAL/DIO_Driver/DIO_Interface.h"

/* Component */
#include "LCD_Config.h"
#include "LCD_Interface.h"

/**
 * @brief Initialize the LCD module.
 */
void HLCD_vInit(void)
{
    // Set control pins direction as OUTPUT
    MDIO_vSetPinDirection(CONTROL_PORT, RS, OUTPUT);
    MDIO_vSetPinDirection(CONTROL_PORT, RW, OUTPUT);
    MDIO_vSetPinDirection(CONTROL_PORT, EN, OUTPUT);

    // Set data port direction as OUTPUT (all pins)
    MDIO_vSetPortDirection(DATA_PORT, 0xFF);

    // Wait for LCD to power up
    _delay_ms(40);

    // Send LCD initialization commands
    HLCD_vSendCommand(FUNCTION_SET);
    _delay_ms(1);
    HLCD_vSendCommand(DISPLAY_ON_OFF);
    _delay_ms(1);
    HLCD_vSendCommand(DISPLAY_CLEAR);
    _delay_ms(3);
    HLCD_vSendCommand(ENTRY_MODE_SET);
    _delay_ms(3);
}

/**
 * @brief Send a command to the LCD.
 *
 * @param A_u8Command: Command to be sent.
 */
void HLCD_vSendCommand(u8 A_u8Command)
{
    // Set RS to 0 (Command Mode)
    MDIO_vSetPinValue(CONTROL_PORT, RS, LOW);

    // Set RW to 0 (Write Mode)
    MDIO_vSetPinValue(CONTROL_PORT, RW, LOW);

    // Send command on data bus (data port)
    MDIO_vSetPortValue(DATA_PORT, A_u8Command);

    // Enable pulse (E = 1 then E = 0)
    MDIO_vSetPinValue(CONTROL_PORT, EN, HIGH);
    _delay_ms(1);
    MDIO_vSetPinValue(CONTROL_PORT, EN, LOW);
    _delay_ms(1);
}

/**
 * @brief Send data (character) to the LCD.
 *
 * @param A_u8Data: Data (character) to be sent.
 */
void HLCD_vSendData(u8 A_u8Data)
{
    // Set RS to 1 (Data Mode)
    MDIO_vSetPinValue(CONTROL_PORT, RS, HIGH);

    // Set RW to 0 (Write Mode)
    MDIO_vSetPinValue(CONTROL_PORT, RW, LOW);

    // Send data on data bus (data port)
    MDIO_vSetPortValue(DATA_PORT, A_u8Data);

    // Enable pulse (E = 1 then E = 0)
    MDIO_vSetPinValue(CONTROL_PORT, EN, HIGH);
    _delay_ms(1);
    MDIO_vSetPinValue(CONTROL_PORT, EN, LOW);
    _delay_ms(1);
}

/**
 * @brief Send a string to display on the LCD.
 *
 * @param A_u8String: Pointer to the string to be displayed.
 */
void HLCD_vSendString(u8 *A_u8String)
{
    // Loop through each character in the string until null terminator is encountered
    for (u8 Local_u8Index = 0; A_u8String[Local_u8Index] != '\0'; Local_u8Index++)
    {
        // Send each character to the LCD
        HLCD_vSendData(A_u8String[Local_u8Index]);
    }
}

/**
 * @brief Move the cursor to the specified row and column on the LCD.
 *
 * @param A_u8Row: Row number (0 or 1).
 * @param A_u8Col: Column number (0 to 15).
 */
void HLCD_vMoveTo(u8 A_u8Row, u8 A_u8Col)
{
    // Calculate cursor position based on row and column
    switch (A_u8Row)
    {
        case 0:
            HLCD_vSendCommand(A_u8Col + 128); // Move to 1st row
            break;
        case 1:
            HLCD_vSendCommand(A_u8Col + 192); // Move to 2nd row
            break;
    }
}

/**
 * @brief Clear the display of the LCD.
 */
void HLCD_vDisplayClear(void)
{
    // Send clear display command
    HLCD_vSendCommand(DISPLAY_CLEAR);
    _delay_ms(1); // Delay for command execution
}
