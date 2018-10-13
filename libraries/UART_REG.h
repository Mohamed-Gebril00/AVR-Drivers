#ifndef UART_REG_H
#define UART_REG_H
#include "../libraries/typedef.h"

#define UDR 			(*(volatile u8*) 	0x2C)
#define UCSRA 			(*(volatile u8*)	0x2B)
#define UCSRB 			(*(volatile u8*) 	0x2A)
#define UCSRC			(*(volatile  u8*)	0x40)
#define UBRRL			(*(volatile u8*)	0x29)
#define UBRRH			(*(volatile  u8*)	0x40)

#endf