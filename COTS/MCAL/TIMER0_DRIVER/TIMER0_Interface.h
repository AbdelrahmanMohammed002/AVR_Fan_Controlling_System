/*
 * TIMER0_Interface.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_TIMER0_DRIVER_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_DRIVER_TIMER0_INTERFACE_H_



void MTIMER0_vInit(void);

void MTIMER0_vSetOVFRegister(u8 A_u8Value);
void MTIMER0_vSetCTCRegister(u8 A_u8Value);

void MTIMER0_vEnableOVFINT(void);
void MTIMER0_vDisableOVFINT(void);
void MTIMER0_vClearOVFFlag(void);
void MTIMER0_vClearOVFRegister(void);

void MTIMER0_vEnableCTCINT(void);
void MTIMER0_vDisableCTCINT(void);
void MTIMER0_vClearCTCFlag(void);
void MTIMER0_vClearCTCRegister(void);

void MTIMER0_vForceOutputCompare(void);
void MTIMER0_vSetCTCCallBack(void (*CallBack)(void));
void MTIMER0_vSetOVFCallBack(void (*CallBack)(void));

#endif /* MCAL_TIMER0_DRIVER_TIMER0_INTERFACE_H_ */
