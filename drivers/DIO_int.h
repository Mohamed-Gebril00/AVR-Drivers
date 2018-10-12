#ifndef DIO_INT_H
#define DIO_INT_H


#include "../libraries/typedef.h"
#include "../libraries/macros.h"
#include "../libraries/avr_io.h"
#define DIO_u8HIGH 1
#define DIO_u8LOW 0
#define DIO_u8INPUT 0
#define DIO_u8OUTPUT 1
#define PINPERPORT 8

/**
  *there coming macros used in initialize ports value
  */
#define CONC(x0,x1,x2,x3,x4,x5,x6,x7) CONC_HELPER(x0,x1,x2,x3,x4,x5,x6,x7)
#define CONC_HELPER(x0,x1,x2,x3,x4,x5,x6,x7) 0b##x7##x6##x5##x4##x3##x2##x1##x0


enum DIO_enuPinNum
{
	DIO_PA0=0,
	DIO_PA1,
	DIO_PA2,
	DIO_PA3,
	DIO_PA4,
	DIO_PA5,
	DIO_PA6,
	DIO_PA7,
	DIO_PB0,
	DIO_PB1,
	DIO_PB2,
	DIO_PB3,
	DIO_PB4,
	DIO_PB5,
	DIO_PB6,
	DIO_PB7,
	DIO_PC0,
	DIO_PC1,
	DIO_PC2,
	DIO_PC3,
	DIO_PC4,
	DIO_PC5,
	DIO_PC6,
	DIO_PC7,
	DIO_PD0,
	DIO_PD1,
	DIO_PD2,
	DIO_PD3,
	DIO_PD4,
	DIO_PD5,
	DIO_PD6,
	DIO_PD7
};

enum DIO_enuPortNum {
	DIO_u8Port0=0,
	DIO_u8Port1,
	DIO_u8Port2,
	DIO_u8Port3
};

typedef struct {
	 const u8 Register_PortAddress;
}Register;

/**
  * initialize Directions for ports depends on the configuration file
  *	return 0 upon returning successfully
  */
u8 DIO_Init(void);





/**
  *this function used to set pin value take Pin Number and its Direction
  *return 1 if the pin number is wrong 
  *return 2 if the value is not 1 or 0
  *return 0 when returning successfully
  */
u8 DIO_SetPinDir(u8 Copy_u8PinNumber,u8 Copy_PinDir);



/**
  *this function used to set pin value take Pin Number and its value
  *return 1 if the pin number is wrong 
  *return 2 if the value is not 1 or 0
  *return 0 when returning successfully
  */
u8 DIO_SetPinValue(u8 Copy_u8PinNumber,u8 Copy_PinVal);


/**
  *this function used to get pin value takes pin number and a getter to get the value in
  *return 0 when terminating successfully
  */
u8 DIO_GetPinValue(u8 Copy_u8PinNumber,u8* u8Ptr_PinValue);


/**
  *Set port Value
  *Argument U8 value, Port ID: 0 A,1 B,2 C,3 D
  */
u8 DIO_SetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortVal);


/**
  *Set Port Direction
  *Ports ID: 0 A, 1 B, 2 C, 3 D
  */
u8 DIO_SetPortDir(u8 Copy_u8PortId,u8 Copy_u8PortDir);

/**
  * this function gets port value
  * takes port ID and a getter to put the port value in
  */
u8 DIO_GetPortValue(u8 Copy_u8PortId,u8* Ptr_u8PortVal);


/**
 * this function chooses configure pin as input pull up
 * it configure it as input with pull up resistors
 */
u8 DIO_SetPinPullUp(u8 Copy_u8PinNumber);


u8 DIO_SetGroupOfBits(u8 *Copy_u8Reg, u8 Copy_u8StartBit,u8 Copy_u8NumberOfBits, u8 Copy_u8Data);

 
#endif
