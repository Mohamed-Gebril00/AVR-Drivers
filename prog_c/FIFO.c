#include "../drivers/FIFO.h"

static const FIFO_CAPACITY = 90; 

FIFO_FunctionReturn FIFO_Init(queue* FIFO_Ptr)
{
	FIFO_FunctionReturn Function_ValidationCheck = FIFO_OK;
	FIFO_Ptr -> FIFO_Front = 0;
	FIFO_Ptr -> FIFO_Size = 0;
	return Function_ValidationCheck;
}

FIFO_FunctionReturn FIFO_Push(u8 Copy_Data,queue* FIFO_Ptr)
{
	FIFO_FunctionReturn Function_ValidationCheck = FIFO_OK;
	if(ISFIFOFULL(FIFO_Ptr) == 1)
	{
		Function_ValidationCheck = FIFO_NOK;
	}
	else{
	(FIFO_Ptr -> FIFO_Size) %= FIFO_CAPACITY;  
	FIFO_Ptr -> FIFO_Data[((FIFO_Ptr -> FIFO_Size) + (FIFO_Ptr-> FIFO_Front)) % FIFO_CAPACITY] = Copy_Data;
	(FIFO_Ptr -> FIFO_Size)++;	// Don't make modulus to know if the capacity reached 90
	}
	
}

FIFO_FunctionReturn FIFO_Pop(queue* FIFO_Ptr, u8* FIFO_PtrData)
{
	FIFO_FunctionReturn Function_ValidationCheck = FIFO_OK;
	if(ISFIFOEMPTY(FIFO_Ptr) == 1)
	{
			Function_ValidationCheck = FIFO_NOK;
	}
	else
	{
		*FIFO_PtrData = FIFO_Ptr->FIFO_Data[FIFO_Ptr-> FIFO_Front];
		(FIFO_Ptr -> FIFO_Front)++;
		(FIFO_Ptr -> FIFO_Front) %= FIFO_CAPACITY;
	}
}
