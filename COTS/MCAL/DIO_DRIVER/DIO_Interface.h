/*
 * DIO_Interface.h
 *
 *  Created on: Feb 15, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 */

#ifndef MCAL_DIO_DRIVER_DIO_INTERFACE_H_
#define MCAL_DIO_DRIVER_DIO_INTERFACE_H_

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define WRONG_VALUE 50

/**
 * @brief Pin direction (Output / input).
 *
 * @param A_u8PortNumber The number of the port (0 for Port A, 1 for Port B, ..., 3 for Port D).
 * @param A_u8PinNumber The number of the pin (0 for Pin 0, 1 for Pin 1, ..., 7 for Pin 7).
 * @param A_u8Dir The direction to set (0 for input, 1 for output).
 */
void MDIO_vSetPinDirection(u8 A_u8PortNumber, u8 A_u8PinNumber, u8 A_u8Dir);

/**
 * @brief Set port direction (Output / input).
 *
 * @param A_u8PortNumber The number of the port (0 for Port A, 1 for Port B, ..., 3 for Port D).
 * @param A_u8Dir The direction to set (0 - 255).
 */
void MDIO_vSetPortDirection(u8 A_u8PortNumber, u8 A_u8Dir);

/**
 * @brief Set pin value (high / low).
 *
 * @param A_u8PortNumber The number of the port (0 for Port A, 1 for Port B, ..., 3 for Port D).
 * @param A_u8PinNumber The number of the pin (0 for Pin 0, 1 for Pin 1, ..., 7 for Pin 7).
 * @param A_u8Value The value to set (0 for low, 1 for high).
 */
void MDIO_vSetPinValue(u8 A_u8PortNumber, u8 A_u8PinNumber, u8 A_u8Value);

/**
 * @brief Set port value (high / low).
 *
 * @param A_u8PortNumber The number of the port (0 for Port A, 1 for Port B, ..., 3 for Port D).
 * @param A_u8Value The value to set (0 - 255).
 */
void MDIO_vSetPortValue(u8 A_u8PortNumber, u8 A_u8Value);

/**
 * @brief Get pin value/status (High / Low).
 *
 * @param A_u8PortNumber The number of the port (0 for Port A, 1 for Port B, ..., 3 for Port D).
 * @param A_u8PinNumber The number of the pin (0 for Pin 0, 1 for Pin 1, ..., 7 for Pin 7).
 * @return u8 Value of the pin (0 for low, 1 for high).
 */
u8 MDIO_u8GetPinValue(u8 A_u8PortNumber, u8 A_u8PinNumber);

/**
 * @brief Toggle pin value/status (High / Low).
 *
 * @param A_u8PortNumber The number of the port (0 for Port A, 1 for Port B, ..., 3 for Port D).
 * @param A_u8PinNumber The number of the pin (0 for Pin 0, 1 for Pin 1, ..., 7 for Pin 7).
 */
void MDIO_vTogglePinValue(u8 A_u8PortNumber, u8 A_u8PinNumber);

/**
 * @brief Get port value.
 *
 * @param A_u8PortNumber The number of the port (0 for Port A, 1 for Port B, ..., 3 for Port D).
 * @return u8 Port value (0 - 255).
 */
u8 MDIO_u8GetPortValue(u8 A_u8PortNumber);

#endif /* MCAL_DIO_DRIVER_DIO_INTERFACE_H_ */
