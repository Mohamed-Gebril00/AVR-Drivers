#ifndef LCD_INT_H
#define LCD_INT_H

#include "../libraries/typedef.h"
#include "../libraries/macros.h"
#include "../libraries/avr_io.h"
#include "../drivers/DIO_int.h"
#include "../confgs/LCD_cnfg.h"
#define LCD_OUTPUT 1
#define LCD_HIGH 1
#define LCD_LOW 0
#define CLEAR_DISPLAY 0b00000001
#define CURSOR_LEFT 0b00000100
#define CURSOR_RIGHT 0b00000110
#define SHIFT_DISPLAY_R 0b00000101
#define SHIFT_DISPLAY_L 0b00000111


typedef enum{LCD_OK=0,LCD_NOK} LCD_CheckType;


/**
  * This Function used in initialize the LCD for eight data mode
  */
LCD_CheckType LCD_Init8DataMode(void);

/**
  * This function used in write commands to LCD
  * Input: The Command Supposed to be written
  * Return 0 Complete Successfully
  * Return 1 Completed Unsuccessfully
  */
LCD_CheckType LCD_WriteCmd(u8 Copy_u8Cmd);


/**
  * This Function used in write one byte to LCD
  * Input: The Byte supposed to be written
  * Return 0 Complete Successfully
  * Return 1 Completed Unsuccessfully
  */
LCD_CheckType LCD_WriteByte(u8 Copy_u8Data);

/**
  * This Function used in moving between rows and columns
  * Input: Rows {0,1}.., Column [0:15]
  * Return 0 Complete Successfully
  * Return 1 Completed Unsuccessfully
  */
LCD_CheckType LCD_GoToX_Y(u8 LCD_u8Row,u8 LCD_u8Column);


/**
 * This Function Writes string to the LCD
 * Input: Array of chars
 * Return 0 Completed successfully
 * Return 1 unsuccessful
 */
LCD_CheckType LCD_WriteString(s8 LCD_Chars[]);


/**
 * This Function Writes Decimal Numbers to the screen
 * Input Number max unsigned long long
 * Return 0 completed successfully
 * Return 1 unsuccessful
 */
LCD_CheckType LCD_WriteDecimal(u64 LCD_u64Number);


/**
 * This Function Clear Display
 * Take No Input
 * Return 0 Upon  Completing successfully
 * Return 1 Upon Un Successful Completing
 */
LCD_CheckType LCD_ClearDisplay(void);

/*
 * This Function Desides the direction cursor Moves
 * Input: 1 For left Moving, 0 For Right Moving
 * Return 0 Upon Completing Successfully
 * Return 1 Upon Un Successful completing
 */
LCD_CheckType LCD_CursorMove(u8 Cursor_u8Move);

/**
 * This Function is used to shift entire Diplay
 * Input 1 Shifts Diplay Right while cursor moves left
 * Input 0 Shifts display Left While Cursor Moves Right
 * Return 0 Upon  Completing successfully
 * Return 1 Upon Un Successful Completing
 */
LCD_CheckType LCD_ShiftDiplay(u8 Copy_ShiftLOrR);

/**
 * This functions control LCD Display
 * LCD display ON/OFF
 * Cursor Display On/Off
 * Cursor Blinking on/off
 * enter 1 to turn on the function you want
 * enter 0 to turn it off
 * Return 0 Upon Completing Successfully
 * Return 1 Upon Un Successful completing
 */
LCD_CheckType LCD_DisplayControl(u8 Copy_LcdDisplay,u8 Copy_CursorDisplay,u8 Copy_CursorBlink);

/*******************************************************************************
 * This Function prints a decimal number to the lcd maximum 20 digit uint32_t
 * return 1 completed successfully
 *******************************************************************************/
LCD_CheckType LCD_PrintNumber(s64 Copy_Number);

#endif
