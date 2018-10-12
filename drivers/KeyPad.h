#ifndef KEY_PAD_H
#define KEY_PAD_H
#include "../drivers/DIO_int.h"

typedef enum{KeyPad_OK=0, KeyPad_NOK}KeyPad_ReturnType;

/***************************************************************************************************
 * This Function Sets the direction of the output (Columns) and inputs (Rows) and sets the pull up
 * for he input rows
 ***************************************************************************************************/
KeyPad_ReturnType KeyPad_Init();

/****************************************************************************************************
 * This Function is used to get the location of the pressed key (its column and rows)
 ****************************************************************************************************/
KeyPad_ReturnType KeyPad_GetKeyPressedLocation(u8* Copy_Column, u8* Copy_Row);


KeyPad_ReturnType KeyPad_GetKeyPressedValue(u8* Key);



#endif
