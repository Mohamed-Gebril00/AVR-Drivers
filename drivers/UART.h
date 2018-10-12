#ifndef UART_H
#define UART_H
#include "../libraries/typedef.h"
#include "../libraries/UART_REG.h"

typedef enum {UART_OK=0 ,UART_NOK) UART_FunctionReturn;
typedef enum {UART_ReceiverDiable=0, UART_ReceiverEnable} UART_ReceiverMode;
typedef enum {UART_TransmitterDisable=0, UART_TransmitterEnable} UART_TransmitterMode;
typedef enum{ UART_FiveBits=0, UART_SixBits, UART_SevenBits, UART_EightBits, UART_NineBits=8} UART_DataSize;
typedef enum{ UART_Asynchornous=0, UART_Synchronous=1} UART_ModeSelect;
typedef enum { UART_Disabled=0, UART_EvenParity=2, UART_OddParity=3} UART_ParityMode;
typedef enum { UART_OneBit=0, UART_TwoBits=1} UART_StopBits;

UART_FunctionReturn UART_Init();

UART_FunctionReturn UART_SendChar();

UART_FunctionReturn UART_ReceiveChar();

#endif