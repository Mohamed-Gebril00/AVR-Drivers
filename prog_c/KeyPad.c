#include "../drivers/KeyPad.h"
#include "../confgs/KeyPad_Confg.h"

/********************************************************************************************************
 * The Coming arrays used to facilitate the initialization of pins.. 
 ********************************************************************************************************/
static const u8 KeyPad_Columns[]={KeyPad_Column0, KeyPad_Column1, KeyPad_Column2, KeyPad_Column3};
static const u8 KeyPad_Rows[]={KeyPad_Row0, KeyPad_Row1, KeyPad_Row2, KeyPad_Row3};
static const u8 KeyPad_Keys[4][4] =
	{ 
	{1, 2, 3, 'A'},
	  {4, 5, 6, 'B'},
	  {7, 8, 9, 'C'},
	  {'*', 0, '#', 'D'}
	};


KeyPad_ReturnType KeyPad_Init()
{
	KeyPad_ReturnType Function_ValidationCheck = KeyPad_OK;
	KeyPad_ReturnType Called_FunctionReturn = KeyPad_OK;
	u8 Loop_Idx=0, Err=0;
	
	for(Loop_Idx = 0;Loop_Idx < 4 && !Err;Loop_Idx++)
	{
			Called_FunctionReturn = DIO_SetPinDir(KeyPad_Columns[Loop_Idx], DIO_u8OUTPUT);
			if(Called_FunctionReturn == KeyPad_NOK)
			{
				Err = 1;
			}
			else 
			{
				Called_FunctionReturn = DIO_SetPinValue(KeyPad_Columns[Loop_Idx], DIO_u8HIGH);
			}
	}

	for(Loop_Idx = 0;Loop_Idx < 4 && !Err;Loop_Idx++)
	{
			Called_FunctionReturn = DIO_SetPinPullUp(KeyPad_Rows[Loop_Idx]);
			if(Called_FunctionReturn == KeyPad_NOK)
			{

				Err = 1;
			}
			else 
			{
				// Do Nothing
			}
	}

	if(Err == 1)
	{
		Function_ValidationCheck = KeyPad_NOK;
	}
	else
	{

		Function_ValidationCheck = KeyPad_OK;
	}
	DIO_SetPinDir(25,DIO_u8OUTPUT);
	return Function_ValidationCheck;
}

		
KeyPad_ReturnType KeyPad_GetKeyPressedLocation(u8* Copy_Column, u8* Copy_Row)
{

	KeyPad_ReturnType Function_ValidationCheck = KeyPad_OK , Called_FunctionReturn;



	static u8 Columm_Idx=0,Row_Idx=0;

	u8 Loop_Idx=0,Loop_Idx2=0, KeyPad_RowState= 1, Pressed = 0;

	for(Loop_Idx=0 ; Loop_Idx <4 && !Pressed ;Loop_Idx++,Columm_Idx++)
	{
		Called_FunctionReturn = DIO_SetPinValue(KeyPad_Columns[(Columm_Idx%4)], DIO_u8LOW);

		for(Loop_Idx2 = 0 ;Loop_Idx2 < 4 && !Pressed ;Loop_Idx2++,Row_Idx++ )
		{
			Called_FunctionReturn = DIO_GetPinValue(KeyPad_Rows[(Row_Idx%4)], &KeyPad_RowState);

			if(KeyPad_RowState == 0)
			{

				Pressed = 1;
				*Copy_Column = Columm_Idx%4, *Copy_Row = Row_Idx%4;
			}
		}
		Called_FunctionReturn = DIO_SetPinValue(KeyPad_Columns[(Columm_Idx%4)], DIO_u8HIGH);

	}
	return Function_ValidationCheck;
}



KeyPad_ReturnType KeyPad_GetKeyPressedValue(u8* Key)
{
	KeyPad_ReturnType Function_ValidationCheck = KeyPad_OK , Called_FunctionReturn;
	 u8 Column_Idx=-1,Row_Idx=-1;

	 Called_FunctionReturn = KeyPad_GetKeyPressedLocation(&Column_Idx, &Row_Idx);
	 if(Column_Idx == -1 || Row_Idx == -1)
		 *Key = -1;
	 else
		 *Key=KeyPad_Keys[Row_Idx][Column_Idx];
	 return Function_ValidationCheck;
}
