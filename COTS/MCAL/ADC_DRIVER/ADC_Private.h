/*
 * ADC_Private.h
 *
 *  Created on: Feb 21, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_ADC_DRIVER_ADC_PRIVATE_H_
#define MCAL_ADC_DRIVER_ADC_PRIVATE_H_

#define ADMUX	*((volatile u8 *) 0x27)
#define ADCSRA	*((volatile u8 *) 0x26)
#define ADC		*((volatile u16 *) 0x24) // ADC is ADCL + ADCH
#define SFIOR	*((volatile u8 *) 0x50) //Special functionIO register

/*ADMUX REGISTER BITS*/
#define REFS1 7
#define REFS0 6
#define ADLAR 5

//ADC voltage reference select
#define ADC_VLOT_REF_CLR_MSK	0b00111111
#define ADC_VOLT_REF_AVCC		0b01000000
#define ADC_VOLT_REF_AREF		0b00000000
#define ADC_VOLT_REF_INTRENAL	0b11000000

//LEFT OR RIGHT ADJUSTED
#define ADC_RIGHT_ADJUSTED	0
#define ADC_LEFT_ADJUSTED	1

//CHANNEL MASK
#define ADC_CHANNEL_MSK 0b11100000


/*ADCSRA REGISTER BITS*/

#define ADEN 	7	/* ADC enable*/
#define ADSC 	6	/* ADC start conversion */
#define ADATE 	5	/* ADC auto trigger enable */
#define ADIF	4	/* ADC Interrupt flag */
#define ADIE	3	/* ADC Interrupt enable */
/*ADC pre-scaler selections ADCSRA register	*/
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

//ADC MODE SELECT
#define ADC_MODE_AUTO_TRIGGER 		1
#define ADC_MODE_SINGLE_CONVERSION	0

//ADC Interrupt status
#define ENABLED		1
#define DISABLED	0

//ADC PRESCALER SELECT
#define ADC_PRESCALER_Clr_msk		0b11111000
#define ADC_PRESCALER_2_msk			0b00000000
#define ADC_PRESCALER_4_msk			0b00000010
#define ADC_PRESCALER_8_msk			0b00000011
#define ADC_PRESCALER_16_msk		0b00000100
#define ADC_PRESCALER_32_msk		0b00000101
#define ADC_PRESCALER_64_msk		0b00000110
#define ADC_PRESCALER_128_msk		0b00000111

/* SFIOR */
/*********/
#define ADTS0	5
#define ADTS1	6
#define ADTS2	7

//ADC Auto Trigger Select
#define ADC_AUTO_TRIGGER_SRC_CLR_msk			0b00011111
#define ADC_AUTO_TRIGGER_FREE_RUNNING_msk		0b00000000
#define ADC_AUTO_TRIGGER_ANALOG_COMP_msk		0b00100000
#define ADC_AUTO_TRIGGER_EXTI0_msk				0b01000000
#define ADC_AUTO_TRIGGER_TIMER0_COMP_msk		0b01100000
#define ADC_AUTO_TRIGGER_TIMER0_OVF_msk			0b10000000
#define ADC_AUTO_TRIGGER_TIMER1_COMP_msk		0b10100000
#define ADC_AUTO_TRIGGER_TIMER1_OVF_msk			0b11000000
#define ADC_AUTO_TRIGGER_TIMER1_CAPT_msk		0b11100000
/**********************************************************/

void __vector_16()__attribute__((signal));


#endif /* MCAL_ADC_DRIVER_ADC_PRIVATE_H_ */
