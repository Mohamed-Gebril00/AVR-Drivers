#ifndef ADC_H
#define ADC_H


#include "../drivers/DIO_int.h"
#include "../libraries/macros.h"
#include "../libraries/typedef.h"
#include "../libraries/ADC_REG.h"
#include "../confgs/ADC_Confg.h"


#define ADC_FLAGCHECK	((ADCSRA >> 4)&1)
#define ADC_HIGHBYTE 	ADCH
#define ADC_LOWBYTE		ADCL

/*********************************************************************************************************************************************  Gebro*/
/* This Enums are used in the ADC_Confg.h file */
typedef enum {ADC_2EnumDiv=1, ADC_4EnumDiv, ADC_8EnumDiv, ADC_16EnumDiv, ADC_32EnumDiv, ADC_64EnumDiv, ADC_128EnumDiv} ADC_EnumDivisionFactor;
typedef enum {ADC_EnumRightAdj=0 , ADC_EnumLeftAdj} ADC_EnumDataRegAdj;
typedef enum {ADC_EnumAref=0, ADC_EnumVcc, ADC_EnumInternal=3} ADC_EnumReferenceVoltage;
typedef enum {ADC_EnumAutoTrigDis=0, ADC_EnumAutoTrigEn} ADC_EnumAutoTrig;
typedef enum {ADC_EnumDisInt=0, ADC_EnumEnInt} ADC_EnumInterrupt;
typedef enum {ADC_EnumDisable=0, ADC_EnumEnable} ADC_Enable;
typedef enum {ADC_EnumFreeRunning=0, ADC_EnumAnalogComp, ADC_EnumExtInt0, ADC_EnumTimerCom0,
			  ADC_EnumTimerOver0, ADC_EnumTimerCompB, ADC_EnumTimerOver1, ADC_EnumCaptureEvent}ADC_TriggerEvent;;

/*********************************************************************************************************************************************  Gebro*/
typedef enum {ADC_Ch0=0,ADC_Ch1,ADC_Ch2,ADC_Ch3,ADC_Ch4,ADC_Ch5,ADC_Ch6,ADC_Ch7}ADC_EnumChannels;






/// This Enumeration used validate the function
typedef enum {ADC_OK=0,ADC_WrongCh= 1, ADC_NOK}ADC_EnumFunctionReturn;





/**
  * This Function used in specifying the prescalar value, Enable ADC interrupt, Left or right adjustment, reference selection bits, auto trigger enable
  * Return 0 Completed successfully
  * Return 1 No successful termination
  */
ADC_EnumFunctionReturn ADC_Init();

/**
 * This Function Is used in Choosing the channel you want to deal with it right now
 */
ADC_EnumFunctionReturn ADC_ChooseCh(ADC_EnumChannels Copy_ADCChannel);


/**
 * This Function Used in Starting the Conversion
 */
ADC_EnumFunctionReturn ADC_StartConv();


/// This function used to clear ADIF
/// Clearing is done be setting the ADIF to one
ADC_EnumFunctionReturn ADC_ConversionAck();


/**
 * This Function is used to select the trigger event (if ADATE bit in register ADCSRA is set).
 * returns 0 if no errors
 * the predicted error is giving wrong trigger event to the parameter Trigger_Event
 * If error occured this function returns 1
 */
ADC_EnumFunctionReturn ADC_AutoTrigger(ADC_TriggerEvent Trigger_Event);


#endif
