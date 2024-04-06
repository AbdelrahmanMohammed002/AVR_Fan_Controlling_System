/*
 * ADC_Program.c
 *
 *  Created on: Feb 21, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"

void (*ptr_to_ADCINT)(void) = NULL;

/**
 * @brief Initialize the ADC module based on configured settings.
 */
void MADC_vInit(void) {
    // Select ADC mode (Auto-Triggered or Single Conversion)
#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
    SET_BIT(ADCSRA, ADATE);                    // Enable Auto-Triggering mode
    SFIOR &= ADC_AUTO_TRIGGER_SRC_CLR_msk;      // Clear auto-trigger source bits
    SFIOR |= ADC_AUTO_TRIG_SRC_SELECTOR;        // Set auto-trigger source
#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
    CLR_BIT(ADCSRA, ADATE);                    // Disable Auto-Triggering mode
#endif

    // Enable ADC
    SET_BIT(ADCSRA, ADEN);

    // Set ADC Prescaler
    ADCSRA = (ADCSRA & 0xF8) | (ADC_PRESCALER_SELECTOR & 0x07);

    // Select ADC voltage reference
    ADMUX &= ADC_VLOT_REF_CLR_MSK;              // Clear voltage reference bits
    ADMUX |= ADC_VOLTAGE_REF_SELECTOR_msk;      // Set voltage reference

    // Set ADC data adjustment (Right or Left)
#if ADC_ADJUSTMENT_SELECTOR == ADC_RIGHT_ADJUSTED
    CLR_BIT(ADMUX, ADLAR);                      // Right adjustment
#elif ADC_ADJUSTMENT_SELECTOR == ADC_LEFT_ADJUSTED
    SET_BIT(ADMUX, ADLAR);                      // Left adjustment
#endif

    // Clear ADC interrupt flag
    SET_BIT(ADCSRA, ADIF);                      // Clear interrupt flag by writing logical one
}

/**
 * @brief Start ADC conversion on a specified channel.
 *
 * @param ADC_channel: ADC channel to start conversion on.
 */
void MADC_vStartConversion(ADC_Channel_Types ADC_channel) {
    if (ADC_channel < 8) {
        ADMUX &= ADC_CHANNEL_MSK;               // Clear channel bits
        ADMUX |= ADC_channel;                   // Select ADC channel
        SET_BIT(ADCSRA, ADSC);                  // Start ADC conversion
        while (GET_BIT(ADCSRA, ADIF) == 0);     // Wait for conversion to complete
        SET_BIT(ADCSRA, ADIF);                  // Clear conversion complete flag
    }
}

/**
 * @brief Get the result of the last ADC conversion.
 *
 * @return ADC result as a 16-bit unsigned integer.
 */
u16 MADC_u16GetResult(void) {
#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
    return ADC;                                // Return ADC result in auto-trigger mode
#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
    while (GET_BIT(ADCSRA, ADSC));             // Wait for conversion to complete in single conversion mode
    return ADC;                                // Return ADC result
#endif
}

/**
 * @brief Enable ADC interrupt.
 */
void MADC_vInterruptEnable(void) {
    SET_BIT(ADCSRA, ADIE);                      // Enable ADC interrupt
}

/**
 * @brief Disable ADC interrupt.
 */
void MADC_vInterruptDisable(void) {
    CLR_BIT(ADCSRA, ADIE);                      // Disable ADC interrupt
}

/**
 * @brief Set the callback function to be executed upon ADC interrupt.
 *
 * @param ptr_to_fun: Pointer to the callback function.
 */
void MADC_vSetCallBack(void (*ptr_to_fun)(void)) {
    ptr_to_ADCINT = ptr_to_fun;                 // Set the callback function pointer
}

/**
 * @brief ADC interrupt service routine.
 */
void __vector_16(void) {
    if (ptr_to_ADCINT != NULL)
        ptr_to_ADCINT();                        // Execute callback function if assigned
}
