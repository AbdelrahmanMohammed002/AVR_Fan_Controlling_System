/*
 * TIMER0_Config.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_TIMER0_DRIVER_TIMER0_CONFIG_H_
#define MCAL_TIMER0_DRIVER_TIMER0_CONFIG_H_


/*
 * 				WAVEFORM GENERATION MODE
 *
 * OPTIONS:-
 * 			1-TIMER0_u8_NORMAL
 * 			2-TIMER0_u8_PWM_PHASE_CORRECT
 * 			3-TIMER0_u8_CTC
 * 			4-TIMER0_u8_FAST_PWM
 */

#define TIMER0_u8_WAVEFORM_MODE	TIMER0_u8_FAST_PWM

/*
 * 				OUTPUT MODE  OC0 (PORTB 3)
 *
 * OPTIONS (NON-PWM MODE):-
 * 			1-TIMER0_u8_OC0_DISCONNECTED
 * 			2-TIMER0_u8_OC0_TOGGLE
 * 			3-TIMER0_u8_OC0_CLEAR
 * 			4-TIMER0_u8_OC0_SET
 *
 * OPTIONS (FAST-PWM MODE):-
 * 			1-TIMER0_u8_OC0_DISCONNECTED
 * 			2-TIMER0_u8_OC0_CLEAR			(Clear OC0 on compare match, set OC0 at TOP)
 * 			3-TIMER0_u8_OC0_SET				(Set OC0 on compare match, clear OC0 at TOP)
 *
 * OPTIONS (PHASE-CORRECT-PWM MODE):-
 * 			1-TIMER0_u8_OC0_DISCONNECTED
 * 			2-TIMER0_u8_OC0_CLEAR			(Clear OC0 on compare match when up-counting. Set OC0 on compare match when down-counting.)
 * 			3-TIMER0_u8_OC0_SET				(Set OC0 on compare match when up-counting. Clear OC0 on compare match when down-counting.)
 */

#define TIMER0_u8_OUTPUT_MODE	TIMER0_u8_OC0_CLEAR

/*
 * 				PRESCALLER
 *
 * OPTIONS:-
 * 			1-TIMER0_u8_STOP				(No clock source (Timer/Counter stopped).)
 * 			2-TIMER0_u8_DIV_BY_1
 * 			3-TIMER0_u8_DIV_BY_8
 * 			4-TIMER0_u8_DIV_BY_64
 * 			5-TIMER0_u8_DIV_BY_256
 * 			6-TIMER0_u8_DIV_BY_1024
 *
 */

#define TIMER0_u8_PRESCALLER	TIMER0_u8_DIV_BY_8

/*
 * 				INTERRUPT
 *
 * OPTIONS:-
 * 			1-TIMER0_u8_ENABLE_INTERRUPT
 * 			2-TIMER0_u8_DISABLE_INTERRUPT
 *
 */

#define TIMER0_u8_INTERRUPT		TIMER0_u8_DISABLE_INTERRUPT


#endif /* MCAL_TIMER0_DRIVER_TIMER0_CONFIG_H_ */
