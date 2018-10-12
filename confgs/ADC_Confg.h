#ifndef ADC_CONFG_H
#define ADC_CONFG_H

#include "../drivers/ADC.h"


/* Coming macros enable the user to choose his own configuration */
/* **************************************************************************************** */
#define DIVISONFACTOR   ADC_2EnumDiv
#define VOLTAGEREF		ADC_EnumVcc
#define AUTO_TRIGENABLE	ADC_EnumAutoTrigDis
#define DATAADJUSTMENT  ADC_EnumLeftAdj
#define INTERRUPTENABLE ADC_EnumDisInt
#define ADCINCH			ADC_Ch0
#endif
