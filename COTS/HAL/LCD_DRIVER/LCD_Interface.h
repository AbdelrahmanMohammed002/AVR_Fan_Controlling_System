/*
 * LCD_Interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Abdelrahman (Ta'laab) Mohammed
 */

#ifndef COTS_HAL_LCD_DRIVER_LCD_INTERFACE_H_
#define COTS_HAL_LCD_DRIVER_LCD_INTERFACE_H_

// LCD Command Definitions
#define FUNCTION_SET    0b00111000
#define DISPLAY_ON_OFF  0b00001111
#define DISPLAY_CLEAR   0b00000001
#define ENTRY_MODE_SET  0b00000110

/**
 * @brief Initialize the LCD module.
 */
void HLCD_vInit(void);

/**
 * @brief Send a command to the LCD.
 *
 * @param A_u8Command: The command to be sent to the LCD (HEX).
 */
void HLCD_vSendCommand(u8 A_u8Command);

/**
 * @brief Send data to the LCD.
 *
 * @param A_u8Data: The data to be sent to the LCD (HEX).
 */
void HLCD_vSendData(u8 A_u8Data);

/**
 * @brief Send a string (array of characters) to the LCD.
 *
 * @param A_u8String: Pointer to the string (array of characters).
 */
void HLCD_vSendString(u8 *A_u8String);

/**
 * @brief Move the cursor of the LCD to a specified row and column.
 *
 * @param A_u8Row: Row number (0 for the first row, 1 for the second row).
 * @param A_u8Col: Column number (1 to 16).
 */
void HLCD_vMoveTo(u8 A_u8Row, u8 A_u8Col);

/**
 * @brief Clear the LCD display.
 */
void HLCD_vDisplayClear(void);

#endif /* COTS_HAL_LCD_DRIVER_LCD_INTERFACE_H_ */
