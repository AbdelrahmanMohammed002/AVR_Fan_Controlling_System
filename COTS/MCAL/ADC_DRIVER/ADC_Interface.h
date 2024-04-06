/*
 * ADC_Interface.h
 *
 *  Created on: Feb 21, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_ADC_DRIVER_ADC_INTERFACE_H_
#define MCAL_ADC_DRIVER_ADC_INTERFACE_H_

/**
 * @brief ADC channel types enumeration.
 */
typedef enum {
    ADC0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5,
    ADC6,
    ADC7
} ADC_Channel_Types;

/**
 * @brief Initialize the ADC module.
 */
void MADC_vInit(void);

/**
 * @brief Start ADC conversion on a specified channel.
 *
 * @param ADC_channel: ADC channel to start conversion on.
 */
void MADC_vStartConversion(ADC_Channel_Types ADC_channel);

/**
 * @brief Get the result of the last ADC conversion.
 *
 * @return ADC result as a 16-bit unsigned integer.
 */
u16 MADC_u16GetResult(void);

/**
 * @brief Enable ADC interrupt.
 */
void MADC_vInterruptEnable(void);

/**
 * @brief Disable ADC interrupt.
 */
void MADC_vInterruptDisable(void);

/**
 * @brief Set the callback function to be executed upon ADC interrupt.
 *
 * @param ptr_to_fun: Pointer to the callback function.
 */
void MADC_vSetCallBack(void (*ptr_to_fun)(void));

#endif /* MCAL_ADC_DRIVER_ADC_INTERFACE_H_ */
