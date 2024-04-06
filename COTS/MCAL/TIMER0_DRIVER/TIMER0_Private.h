/*
 * TIMER0_Private.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_TIMER0_DRIVER_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_DRIVER_TIMER0_PRIVATE_H_

#define TCCR0	*((volatile u8 *)(0x53))
#define TCNT0	*((volatile u8 *)(0x52))
#define OCR0	*((volatile u8 *)(0x5C))
#define TIMSK	*((volatile u8 *)(0x59))
#define TIFR	*((volatile u8 *)(0x58))

#define FOC0	7
#define WGM00	6
#define COM01	5
#define COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0

#define OCIE0	1
#define TOIE0	0

#define OCF0	1
#define TOV0	0

#define TIMER0_u8_NORMAL				0
#define TIMER0_u8_PWM_PHASE_CORRECT		1
#define TIMER0_u8_CTC					2
#define TIMER0_u8_FAST_PWM				3

#define TIMER0_u8_OC0_DISCONNECTED		0
#define TIMER0_u8_OC0_TOGGLE			1
#define TIMER0_u8_OC0_CLEAR				2
#define TIMER0_u8_OC0_SET				3

#define	TIMER0_u8_STOP					0
#define	TIMER0_u8_DIV_BY_1				1
#define TIMER0_u8_DIV_BY_8				2
#define TIMER0_u8_DIV_BY_64				3
#define TIMER0_u8_DIV_BY_256			4
#define TIMER0_u8_DIV_BY_1024			5

#define	TIMER0_u8_DISABLE_INTERRUPT		0
#define	TIMER0_u8_ENABLE_INTERRUPT		1

void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));

#endif /* MCAL_TIMER0_DRIVER_TIMER0_PRIVATE_H_ */
