#ifndef FIFO_H
#define FIFO_H

#include "../libraries/typedef.h"

typedef enum {FIFO_OK=0,FIFO_NOK}FIFO_FunctionReturn;
typedef struct {
	u8 FIFO_Data[90];
	u8 FIFO_Front;
	u8 FIFO_Size;
	FIFO_Front = 0;
	FIFO_Size=0;
}queue;

#define ISFIFOEMPTY(queue* FIFO) FIFO->FIFO_Size==0?1:0
#define ISFIFOFULL(queue* FIFO) FIFO->FIFO_Size==90?1:0

FIFO_FunctionReturn FIFO_Init(queue* FIFO_Ptr);
FIFO_FunctionReturn FIFO_Push(queue* FIFO_Ptr,u8 data);
FIFO_FunctionReturn FIFO_Pop(queue* FIFO_Ptr, u8* FIFO_PtrData);

#endif