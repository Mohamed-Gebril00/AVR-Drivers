/*
 * DIO_prog.c
 *
 *  Created on: Aug 18, 2018
 *      Author: gebroo
 */


#include "../drivers/DIO_int.h"
#include "../confgs/DIO_cnfg.h"

/**
  *Initialize Ports Direction
  *Using Macros defined in The configuration file
*/
u8 DIO_Init(void)
{
	DDRA=CONC(U8_DIRPIN0,U8_DIRPIN1,U8_DIRPIN2,U8_DIRPIN3,U8_DIRPIN4,U8_DIRPIN5,U8_DIRPIN6,U8_DIRPIN7);
	DDRB=CONC(U8_DIRPIN8,U8_DIRPIN9,U8_DIRPIN10,U8_DIRPIN11,U8_DIRPIN12,U8_DIRPIN13,U8_DIRPIN14,U8_DIRPIN15);
	DDRC=CONC(U8_DIRPIN16,U8_DIRPIN17,U8_DIRPIN18,U8_DIRPIN19,U8_DIRPIN20,U8_DIRPIN21,U8_DIRPIN22,U8_DIRPIN23);
	DDRD=CONC(U8_DIRPIN24,U8_DIRPIN25,U8_DIRPIN26,U8_DIRPIN27,U8_DIRPIN28,U8_DIRPIN29,U8_DIRPIN30,U8_DIRPIN31);
	/* ********************************* */

	PORTA=CONC(U8_VALPIN0,U8_VALPIN1,U8_VALPIN2,U8_VALPIN3,U8_VALPIN4,U8_VALPIN5,U8_VALPIN6,U8_VALPIN7);
	PORTB=CONC(U8_VALPIN8,U8_VALPIN9,U8_VALPIN10,U8_VALPIN11,U8_VALPIN12,U8_VALPIN13,U8_VALPIN14,U8_VALPIN15);
	PORTC=CONC(U8_VALPIN16,U8_VALPIN17,U8_VALPIN18,U8_VALPIN19,U8_VALPIN20,U8_VALPIN21,U8_VALPIN22,U8_VALPIN23);
	PORTD=CONC(U8_VALPIN24,U8_VALPIN25,U8_VALPIN26,U8_VALPIN27,U8_VALPIN28,U8_VALPIN29,U8_VALPIN30,U8_VALPIN31);
	return 0;
}





/**
 *function used to set pin direction
 */
u8 DIO_SetPinDir(u8 Copy_u8PinNumber,u8 Copy_PinDir)
{

	//zero means operation is successfully finished
	u8 u8FuncErrorValidation=0;
	u8* u8ReqReg;
	if( Copy_u8PinNumber > DIO_PD7)
	{
		// Error Pin number doesn't exist
		u8FuncErrorValidation = 1;
	}
	else
	{
		u8 u8PortNumber=Copy_u8PinNumber / PINPERPORT;
		u8 u8PinNumber= Copy_u8PinNumber % PINPERPORT;

		// configure the pin as input
		switch (u8PortNumber)
		{
		case 0:
			u8ReqReg=&DDRA;
			break;
		case 1:
			u8ReqReg=&DDRB;
			break;
		case 2:
			u8ReqReg=&DDRC;
			break;
		case 3:
			u8ReqReg=&DDRD;
			break;
		}

		if(Copy_PinDir == DIO_u8INPUT)
		{
			CLEAR_BIT(*u8ReqReg,u8PinNumber);
		}
		else if(Copy_PinDir == DIO_u8OUTPUT)
		{
			SET_BIT(*u8ReqReg,u8PinNumber);
		}
		else
		{
			//error wrong direction input
			u8FuncErrorValidation = 2;
		}
	}


	return u8FuncErrorValidation;
}



/**
  *this function used to set pin value take Pin Number and its value
  *return 1 if the pin number is wrong
  *return 2 if the value is not 1 or 0
  *return 0 when returning successfully
  */
u8 DIO_SetPinValue(u8 Copy_u8PinNumber,u8 Copy_PinVal)
{

	//zero means operation is successfully finished
	u8 u8FuncErrorValidation=0,*u8ReqReg;
	if(Copy_u8PinNumber > DIO_PD7)
	{
		// Error Pin number doesn't exist
		u8FuncErrorValidation = 1;
	}
	else
	{

		u8 u8PortNumber=Copy_u8PinNumber / PINPERPORT;
		u8 u8PinNumber= Copy_u8PinNumber % PINPERPORT;

		// configure the pin as input
		switch(u8PortNumber)
		{
		case 0:
			u8ReqReg=&PORTA;
			break;
		case 1:
			u8ReqReg=&PORTB;
			break;
		case 2:
			u8ReqReg=&PORTC;
			break;
		case 3:
			u8ReqReg=&PORTD;
			break;

		}
		if(Copy_PinVal == DIO_u8LOW)
		{
			CLEAR_BIT(*u8ReqReg,u8PinNumber);
		}
		else if(Copy_PinVal == DIO_u8HIGH)
		{
			SET_BIT(*u8ReqReg,u8PinNumber);
		}
		else
		{
			//error wrong direction input
			u8FuncErrorValidation = 2;
		}
	}
	return u8FuncErrorValidation;
}


/**
  *this function used to get pin value takes pin number and a getter to get the value in
  *return 0 when terminating successfully
  */
u8 DIO_GetPinValue(u8 Copy_u8PinNumber,u8* u8Ptr_PinValue)
{

	//zero means operation is successfully finished
	//u8ReqReg take the address to change in the address not in the copy of the variable
	u8 u8FuncErrorValidation=0,*u8ReqReg;
	if( Copy_u8PinNumber > DIO_PD7)
	{
		// Error Pin number doesn't exist
		u8FuncErrorValidation = 1;
	}
	else
	{

		u8 u8PinNumber= Copy_u8PinNumber % PINPERPORT;
		u8 u8PortNumber=Copy_u8PinNumber / PINPERPORT;;

		switch(u8PortNumber)
		{
		 case 0:
			 //address of input register pina
			 u8ReqReg=&PINA;
			  break;
		 case 1:
			 //address of input reg B
			 u8ReqReg=&PINB;
			  break;
		 case 2:
			 //address of input reg C
			 u8ReqReg=&PINC;
			 break;
		 case 3:
			 //address of input reg C
			 u8ReqReg=&PIND;
		}
		*u8Ptr_PinValue=GET_BIT(*u8ReqReg,u8PinNumber);
	}
	return u8FuncErrorValidation;
}




/**
  *Set port Value
  *Argument U8 value, Port ID: 0 A,1 B,2 C,3 D
*/
u8 DIO_SetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortVal)
{
	u8 FuncErrorValidation=0;
	if( Copy_u8PortId > 3)
		FuncErrorValidation=1;
	else
	{
		switch(Copy_u8PortId)
		{
			case 0:
				PORTA=Copy_u8PortVal;
				break;
			case 1:
				PORTB=Copy_u8PortVal;
				break;
			case 2:
				PORTC=Copy_u8PortVal;
				break;
			case 3:
				PORTD=Copy_u8PortVal;
				break;
		}
	}
	return FuncErrorValidation;

}




/**
  *Set Port Direction
  *Ports ID: 0 A, 1 B, 2 C, 3 D
  */
u8 DIO_SetPortDir(u8 Copy_u8PortId,u8 Copy_u8PortDir)
{
	u8 FuncErrorValidation=0;

	// check if wrong Port Id has been entered
	if( Copy_u8PortId > 3)
		FuncErrorValidation=1;

	//if right ID set port direction
	else
	{
		switch(Copy_u8PortId)
		{
			case 0:
				DDRA=Copy_u8PortDir;
				break;
			case 1:
				DDRB=Copy_u8PortDir;
				break;
			case 2:
				DDRC=Copy_u8PortDir;
				break;
			case 3:
				DDRD=Copy_u8PortDir;
				break;
		}
	}
	return FuncErrorValidation;
}



/**
  * this function gets port value
  * takes port ID and a getter to put the port value in
  */
u8 DIO_GetPortValue(u8 Copy_u8PortId,u8* Ptr_u8PortVal)
{
	u8 FuncErrorValidation=0;

	// check if wrong Port Id has been entered
	if( Copy_u8PortId > 3)
		FuncErrorValidation=1;

	//if write ID get port value
	else
		{
			switch(Copy_u8PortId)
			{
				case 0:
					*Ptr_u8PortVal=PINA;
					break;
				case 1:
					*Ptr_u8PortVal=PINB;
					break;
				case 2:
					*Ptr_u8PortVal=PINC;
					break;
				case 3:
					*Ptr_u8PortVal=PIND;
					break;
			}
		}

	return FuncErrorValidation;
}



u8 DIO_PortPullUp(u8 Copy_u8PortId,u8 Copy_u8PullUpPins)
{
	if( Copy_u8PortId > 3)
		return 1;
	else
	{
		switch(Copy_u8PortId)
		{
			case 0:
				PORTA=Copy_u8PullUpPins;
				break;
			case 1:
				PORTB=Copy_u8PullUpPins;
				break;
			case 2:
				PORTC=Copy_u8PullUpPins;
				break;
			case 3:
				PORTD=Copy_u8PullUpPins;
				break;
		}
	}
	return 0;
}



/**************************************************************
 * this function chooses configure pin as input pull up
 * it configure it as input with pull up resistors
 **************************************************************/
u8 DIO_SetPinPullUp(u8 Copy_u8PinNumber)
{
	u8 Function_ValidationCheck=0, Called_FunctionReturn = 0;
	Called_FunctionReturn = DIO_SetPinDir(Copy_u8PinNumber, DIO_u8INPUT);
	if(Called_FunctionReturn == 1)
		Function_ValidationCheck = 1;
	else 
	{
			Called_FunctionReturn = DIO_SetPinValue(Copy_u8PinNumber, DIO_u8HIGH);
			if(Called_FunctionReturn == 1)
				Function_ValidationCheck = 1;
	}
	return Function_ValidationCheck;
}


u8 DIO_SetGroupOfBits(u8 *Copy_u8Reg, u8 Copy_u8StartBit,u8 Copy_u8NumberOfBits, u8 Copy_u8Data)
{
	u8 Idx=0,Data_Idx=0;

	for(Idx = Copy_u8StartBit; Idx < (Copy_u8NumberOfBits+Copy_u8StartBit); Idx++)
	{
		(*Copy_u8Reg) |= ( ((Copy_u8Data >> Data_Idx)&1) << Idx );
		Data_Idx ++;
	}
	return 0;
}
