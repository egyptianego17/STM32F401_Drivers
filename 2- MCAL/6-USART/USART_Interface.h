/*****************************************************/
/*               SWC: USART Driver                   */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.0                    */
/*            Date: 23 September - 2023              */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* File Gaurd */
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/* Function Prototypes */
void USART_voidInit(u8 Copy_u8ID, u32 Copy_u32Baudrate);
void USART_voidTransByte(u8 Copy_u8ID, u8 Copy_u8Byte);
void USART_voidPrintln(u8 Copy_u8ID, u8 *Copy_u8String);
void USART_voidPrint(u8 Copy_u8ID, u8 *Copy_u8String);
void USART_voidRecByte(u8 Copy_u8ID, u8 *Copy_u8Byte);

/* Options for Copy_u8ID */
#define USART1 0 
#define USART2 1
#define USART6 2

/* Options for Copy_u32Baudrate: Desired baud rate (up to 921600)  */

#endif
