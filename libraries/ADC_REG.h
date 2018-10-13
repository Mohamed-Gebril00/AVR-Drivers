#ifndef ADC_REG_H
#define ADC_REG_H

#include "../libraries/typedef.h"

/**************************************************************
 *	Registers in ADC module in AVR micro-controller
 **************************************************************/
#define ADMUX (*((volatile u8*) (0x27)))
#define ADCSRA (*((volatile u8*) (0x26)))
#define ADCH (*((volatile u8*) (0x25)))
#define ADCL (*((volatile u8*) (0x24)))
#define SFIOR (*((volatile u8*) (0x50)))

/******************************************************************
 * The Following are defines for the bit field in the ADMUX register
 ******************************************************************/
#define MUX   0b00011111    // Choose Input channel
#define REFS  0b11000000	// Choose reference selection
#define ADLAR 0b00100000	// Choose data representation left or right adjustment


/*****************************************************************
 * The Following are defined for the bit fields in the ADCSRA register (ADC Control and Status).
 *****************************************************************/
#define ADEN 		0b10000000		// ADC Enable
#define ADSC 		0b01000000		// ADC Start Conversion
#define ADATE 		0b00100000		// ADC Auto Trigger Enable
#define ADIF		0b00010000		// ADC interrupt flag
#define ADIE 		0b00001000		// ADC interrupt enable
#define ADPS        0b00000111		// ADC pre scalar bits


/****************************************************************
 * The Following is defined for the bit fields in SFIOR register
 ****************************************************************/
#define ADTSBITS 0b11100000


#endif
