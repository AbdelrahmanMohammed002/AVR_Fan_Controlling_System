/*
 * DIO_Program.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 */

//include libraries
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

//include DIO header files
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

void MDIO_vSetPinDirection(u8 A_u8PortNumber,u8 A_u8PinNumber, u8 A_u8Dir )
{
	if(A_u8Dir == INPUT)
	{
		switch (A_u8PortNumber)
		{
		case PORT_A: CLR_BIT(DDRA, A_u8PinNumber); break;
		case PORT_B: CLR_BIT(DDRB, A_u8PinNumber); break;
		case PORT_C: CLR_BIT(DDRC, A_u8PinNumber); break;
		case PORT_D: CLR_BIT(DDRD, A_u8PinNumber); break;
		}
	}else if (A_u8Dir == OUTPUT)
	{
		switch (A_u8PortNumber)
		{
		case PORT_A: SET_BIT(DDRA, A_u8PinNumber); break;
		case PORT_B: SET_BIT(DDRB, A_u8PinNumber); break;
		case PORT_C: SET_BIT(DDRC, A_u8PinNumber); break;
		case PORT_D: SET_BIT(DDRD, A_u8PinNumber); break;
		}
	}else {
		//Do Nothing.
	}
}

void MDIO_vSetPortDirection(u8 A_u8PortNumber, u8 A_u8Dir){
	switch (A_u8PortNumber){
	case PORT_A: DDRA = A_u8Dir; break;
	case PORT_B: DDRB = A_u8Dir; break;
	case PORT_C: DDRC = A_u8Dir; break;
	case PORT_D: DDRD = A_u8Dir; break;
	}
}

void MDIO_vSetPinValue(u8 A_u8PortNumber, u8 A_u8PinNumber, u8 A_u8Value)
{
	if(A_u8Value == HIGH)
	{
		switch (A_u8PortNumber)
		{
		case PORT_A: SET_BIT(PORTA, A_u8PinNumber); break;
		case PORT_B: SET_BIT(PORTB, A_u8PinNumber); break;
		case PORT_C: SET_BIT(PORTC, A_u8PinNumber); break;
		case PORT_D: SET_BIT(PORTD, A_u8PinNumber); break;
		}
	}else if (A_u8Value == LOW)
	{
		switch (A_u8PortNumber)
		{
		case PORT_A: CLR_BIT(PORTA, A_u8PinNumber); break;
		case PORT_B: CLR_BIT(PORTB, A_u8PinNumber); break;
		case PORT_C: CLR_BIT(PORTC, A_u8PinNumber); break;
		case PORT_D: CLR_BIT(PORTD, A_u8PinNumber); break;
		}
	}else{
		//DO Nothing
	}
}

void MDIO_vSetPortValue(u8 A_u8PortNumber, u8 A_u8Value){
	switch (A_u8PortNumber){
	case PORT_A: PORTA = A_u8Value; break;
	case PORT_B: PORTB = A_u8Value; break;
	case PORT_C: PORTC = A_u8Value; break;
	case PORT_D: PORTD = A_u8Value; break;
	}
}

u8 MDIO_u8GetPinValue(u8 A_u8PortNumber, u8 A_u8PinNumber)
{
	u8 Local_u8PinValue = WRONG_VALUE;
	switch (A_u8PortNumber){
		case PORT_A: Local_u8PinValue = GET_BIT(PINA, A_u8PinNumber); break;
		case PORT_B: Local_u8PinValue = GET_BIT(PINB, A_u8PinNumber); break;
		case PORT_C: Local_u8PinValue = GET_BIT(PINC, A_u8PinNumber); break;
		case PORT_D: Local_u8PinValue = GET_BIT(PIND, A_u8PinNumber); break;
		}
	return Local_u8PinValue;
}
u8 MDIO_u8GetPortValue(u8 A_u8PortNumber)
{
	u8 Local_u8PortValue = WRONG_VALUE;
	switch (A_u8PortNumber){
		case PORT_A: Local_u8PortValue = PINA; break;
		case PORT_B: Local_u8PortValue = PINB; break;
		case PORT_C: Local_u8PortValue = PINC; break;
		case PORT_D: Local_u8PortValue = PIND; break;
		}
	return Local_u8PortValue;
}

void MDIO_vTogglePinValue(u8 A_u8PortNumber, u8 A_u8PinNumber)
{
	switch (A_u8PortNumber){
			case PORT_A: TOGGLE_BIT(PORTA, A_u8PinNumber); break;
			case PORT_B: TOGGLE_BIT(PORTB, A_u8PinNumber); break;
			case PORT_C: TOGGLE_BIT(PORTC, A_u8PinNumber); break;
			case PORT_D: TOGGLE_BIT(PORTD, A_u8PinNumber); break;
			}
}

