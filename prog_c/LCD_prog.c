/*
 * LCD_prog.c
 *
 *  Created on: Oct 5, 2018
 *      Author: gebroo
 */


#include "E:\IMT codes\avr_projects\drivers\LCD_int.h"
#include "avr/delay.h"

const u8 Data_u8Pins[]={LCD_D0,LCD_D1,LCD_D2,LCD_D3,LCD_D4,LCD_D5,LCD_D6,LCD_D7};


LCD_CheckType LCD_Init8DataMode(void)
{

	// Indicator function finished successfully
	LCD_CheckType FuncErrValidation=LCD_OK;
	u8 Data_PinNum;
	// Set Pins Direction Supposingly R/W Pin is attachec to GND
	DIO_SetPinDir(LCD_RS,DIO_u8OUTPUT);
	DIO_SetPinDir(LCD_EN,DIO_u8OUTPUT);

	for(Data_PinNum=0;Data_PinNum<8;Data_PinNum++)
	{
		DIO_SetPinDir(Data_u8Pins[Data_PinNum],DIO_u8OUTPUT);
	}

	// Initialization ritual from Data sheet
	_delay_ms(50);
	LCD_WriteCmd(0b00111100);
	_delay_ms(2);

	LCD_WriteCmd(0b00001111);
	_delay_ms(2);

	LCD_WriteCmd(0b00000001);
	_delay_ms(2);


	return FuncErrValidation;
}


void LCD_PrivateSetDataPinVal(u8 Copy_u8Data)
{
	u8 Bit_Number,Data_Val;
	for(Bit_Number=0;Bit_Number<8;Bit_Number++)
	{
		Data_Val=GET_BIT(Copy_u8Data,Bit_Number);
		DIO_SetPinValue(Data_u8Pins[Bit_Number],Data_Val);
	}
}


/**
 * This function used in write commands to LCD
 * Input: The Command Supposed to be written
 * Return 0 Complete Successfully
 * Return 1 Completed Unsuccessfully
 */
LCD_CheckType LCD_WriteCmd(u8 Copy_u8Cmd)
{

	LCD_CheckType FuncErrValidation=LCD_OK;
	DIO_SetPinValue(LCD_RS,LCD_LOW);

	// Dividing the Cmd To the Pins
	LCD_PrivateSetDataPinVal(Copy_u8Cmd);

	// Trigger the enable pins to read the command
	DIO_SetPinValue(LCD_EN,LCD_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_EN,LCD_LOW);

	return FuncErrValidation;
}


/**
 * This Function used in write one byte to LCD
 * Input: The Byte supposed to be written
 * Return 0 Complete Successfully
 * Return 1 Completed Unsuccessfully
 */
LCD_CheckType LCD_WriteByte(u8 Copy_u8Data)
{

	LCD_CheckType FuncErrValidation=LCD_OK;
	DIO_SetPinValue(LCD_RS,LCD_HIGH);

	// Dividing the Cmd To the Pins
	LCD_PrivateSetDataPinVal(Copy_u8Data);

	// Trigger the enable pins to read the command
	DIO_SetPinValue(LCD_EN,LCD_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_EN,LCD_LOW);

	return FuncErrValidation;

}


/**
 * This Function Clear Display
 * Take No Input
 * Return 0 Upon  Completing successfully
 * Return 1 Upon Un Successful Completing
 */
LCD_CheckType LCD_ClearDisplay(void)
{
	LCD_WriteCmd(CLEAR_DISPLAY);
	return LCD_OK;
}


/*
 * This Function Desides the direction cursor Moves
 * Input: 1 For left Moving, 0 For Right Moving
 * Return 0 Upon Completing Successfully
 * Return 1 Upon Un Successful completing
 */
LCD_CheckType LCD_CursorMove(u8 Cursor_u8Move)
{
	if(Cursor_u8Move < 0 || Cursor_u8Move > 1) return LCD_NOK;
	else
	{
		switch(Cursor_u8Move)
		{
		case 0:
			LCD_WriteCmd(CURSOR_LEFT);
			break;
		case 1:
			LCD_WriteCmd(CURSOR_RIGHT);
			break;
		}
		return LCD_OK;
	}
}


/**
 * This Function used in moving between rows and columns
 * Input: Rows {0,1}.., Column [0:15]
 * Return 0 Complete Successfully
 * Return 1 Completed Unsuccessfully
 */
LCD_CheckType LCD_GoToX_Y(u8 LCD_u8Row,u8 LCD_u8Column)
{
	u8 FuncErrorVaidation;
	if(LCD_u8Row < 0 || LCD_u8Row > 1) FuncErrorVaidation = LCD_NOK;
	else if(LCD_u8Column < 0 || LCD_u8Column > 15) FuncErrorVaidation = LCD_OK;
	else
	{
		FuncErrorVaidation = LCD_OK;
		switch(LCD_u8Row)
		{
		case 0:
			LCD_WriteCmd(128 + LCD_u8Column);
			break;
		case 1:
			LCD_WriteCmd(192 + LCD_u8Column);
			break;
		}
	}
	return FuncErrorVaidation;
}


/**
 * This Function Writes string to the LCD
 * Input: Array of chars
 * maximum size of array of chars is 2^64-1
 * Return 0 Completed successfully
 * Return 1 unsuccessful
 */
LCD_CheckType LCD_WriteString(s8 LCD_Chars[])
{

	u8 LCD_CharsIdx=0;
	LCD_CheckType FuncErrorValid=LCD_OK;
	while(LCD_Chars[LCD_CharsIdx] != '\0')
	{
		LCD_WriteByte(LCD_Chars[LCD_CharsIdx++]);
	}

	return FuncErrorValid;
}


/*******************************************************************************
 * This Function prints a decimal number to the lcd maximum 20 digit uint32_t
 * return 1 completed successfully
 *******************************************************************************/
LCD_CheckType LCD_PrintNumber(s64 Copy_Number)
{
	LCD_CheckType Function_ValidationCheck=LCD_OK;
	u8 LCD_Digit[22],Signed=0;
	s8 Loop_Idx=0,NumberOfDigit=0;
	if(Copy_Number < 0)
	{
		Signed = 1;
		Copy_Number *= -1;
	}
	else
	{
		Signed = 0;
	}
	if(Copy_Number == 0)
	{
		LCD_WriteByte('0');
	}
	else
	{
		while (Copy_Number > 0)
		{
			LCD_Digit[NumberOfDigit++]=Copy_Number%10;
			Copy_Number/=10;
		}
		if(Signed == 1)
		{
			LCD_WriteByte('-');
		}
		else
		{
			// Do NoThing
		}
		for(Loop_Idx = (NumberOfDigit-1) ; Loop_Idx >= 0; Loop_Idx--)
		{
			LCD_WriteByte(LCD_Digit[Loop_Idx]+'0');
		}
	}
	return Function_ValidationCheck;
}

