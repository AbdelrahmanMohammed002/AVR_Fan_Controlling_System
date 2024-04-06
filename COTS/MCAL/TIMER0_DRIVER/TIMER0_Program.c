/*
 * TIMER0_Program.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER0_Interface.h"
#include "TIMER0_Private.h"
#include "TIMER0_Config.h"

#define NULL   ((void *) 0)

void (*TIMER0_CTC_Call_Back)(void) = NULL;
void (*TIMER0_OVF_Call_Back)(void) = NULL;


void MTIMER0_vInit(void) {
	/* SELECT TIMER WAVEFORM */

#if TIMER0_u8_WAVEFORM_MODE ==	TIMER0_u8_NORMAL
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_PWM_PHASE_CORRECT
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_CTC
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_FAST_PWM
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	#endif

	/* SELECT TIMER MODE */

#if	TIMER0_u8_OUTPUT_MODE == TIMER0_OC0_DISCONNECTED
	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
#elif TIMER0_u8_OUTPUT_MODE == TIMER0_u8_OC0_TOGGLE
		#if	TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_PWM_PHASE_CORRECT || TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_FAST_PWM
		#warning ("CHOOSED UNAVAILABLE OPTION IN TIMER OUTPUT MODE!!")
		#else
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		#endif
	#elif TIMER0_u8_OUTPUT_MODE == TIMER0_u8_OC0_CLEAR
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#elif TIMER0_u8_OUTPUT_MODE == TIMER0_u8_OC0_SET
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#endif

	/* SELECT TIMER PRESCALER */

#if TIMER0_u8_PRESCALLER == TIMER0_u8_STOP
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_1
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_8
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_64
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_256
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_1024
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	#endif


}

void MTIMER0_vSetOVFRegister(u8 A_u8Value)
{
	TCNT0 = A_u8Value;
}

void MTIMER0_vSetCTCRegister(u8 A_u8Value)
{
	OCR0 = A_u8Value;
}

void MTIMER0_vClearCTCRegister(void){
	OCR0 = 0x00;
}

void MTIMER0_vClearOVFRegister(void){
	TCNT0 = 0x00;
}

void MTIMER0_vEnableOVFINT(void){
	SET_BIT(TIMSK , TOIE0);
}
void MTIMER0_vDisableOVFINT(void)
{
	CLR_BIT(TIMSK , TOIE0);
}
void MTIMER0_vClearOVFFlag(void)
{
	SET_BIT(TIFR , TOV0);
}

void MTIMER0_vEnableCTCINT(void)
{
	SET_BIT(TIFR , TOV0);
}
void MTIMER0_vDisableCTCINT(void)
{
	CLR_BIT(TIMSK , OCIE0);
}
void MTIMER0_vClearCTCFlag(void)
{
	SET_BIT(TIFR , OCF0);
}

void MTIMER0_vForceOutputCompare(void){
	SET_BIT(TCCR0,FOC0);
}

void MTIMER0_vSetCTCCallBack(void (*CallBack) (void)){
	if(CallBack != NULL){
		TIMER0_CTC_Call_Back = CallBack;
	}
}

void MTIMER0_vSetOVFCallBack(void (*CallBack) (void)){
	if(CallBack != NULL){
		TIMER0_OVF_Call_Back = CallBack;
	}
}


void __vector_11(void){
	if(TIMER0_OVF_Call_Back != NULL)
		TIMER0_OVF_Call_Back();
	MTIMER0_vClearOVFFlag();
}


void __vector_10(void){
	if(TIMER0_CTC_Call_Back !=NULL)
			TIMER0_CTC_Call_Back();
	MTIMER0_vClearCTCFlag();
}
