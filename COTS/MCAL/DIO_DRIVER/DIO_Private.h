/*
 * DIO_Private.h
 *
 *  Created on: Feb 15, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 */

#ifndef MCAL_DIO_DRIVER_DIO_PRIVATE_H_
#define MCAL_DIO_DRIVER_DIO_PRIVATE_H_

/* Direction registers */
#define DDRA  *((volatile u8 *)0x3A)
#define DDRB  *((volatile u8 *)0x37)
#define DDRC  *((volatile u8 *)0x34)
#define DDRD  *((volatile u8 *)0x31)

/* Output registers */
#define PORTA *((volatile u8 *)0x3B)
#define PORTB *((volatile u8 *)0x38)
#define PORTC *((volatile u8 *)0x35)
#define PORTD *((volatile u8 *)0x32)

/* Input registers */
#define PINA  *((volatile u8 *)0x39)
#define PINB  *((volatile u8 *)0x36)
#define PINC  *((volatile u8 *)0x33)
#define PIND  *((volatile u8 *)0x30)



#endif /* MCAL_DIO_DRIVER_DIO_PRIVATE_H_ */
