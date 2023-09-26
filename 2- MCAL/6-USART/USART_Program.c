/*****************************************************/
/*               SWC: USART Driver                   */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.0                    */
/*            Date: 23 September - 2023              */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"


/*****************************************************************************/
/* Function Name: USART_voidInit                                             */
/* i/p Arguments: u8 Copy_u8ID: Options (USART1->USART6)                     */
/*                u32 Copy_u32Baudrate: Desired baud rate (up to 921600)     */
/* Return: void                                                              */
/* Description: Initializes the USART module with the specified baud rate.   */
/*****************************************************************************/

void USART_voidInit(u8 Copy_u8ID, u32 Copy_u32Baudrate)
{
    /* i/p validation */
    if ((Copy_u8ID > USART6) || (Copy_u32Baudrate > 921600))
    {
        /* Do nothing */
    }
    else
    {
        /* Calculate Mantissa and Fraction for baud rate.    */
        /* Tx/Rx baud = fCK/(8 × (2–OVER8) × USARTDIV)       */
        u32 Local_u32Mantissa = (u32)(USART_CLK / (16 * Copy_u32Baudrate));
        u8 Local_u32Fraction = EXTRACT_FRACTION(USART_CLK / (Copy_u32Baudrate * 16.0)) * 16;
        /* Concatenate Mantissa and Fraction to set BRR (Baud Rate Register). */
        u32 Local_u8BRR = (Local_u32Mantissa << 4) + Local_u32Fraction;

        /* Configure CR1 and CR2 registers (USART control registers). */
        MODIFY_REGISTER_BITS(USART[Copy_u8ID]->CR1, 0, 15, USART_CR1);
        MODIFY_REGISTER_BITS(USART[Copy_u8ID]->CR2, 0, 15, USART_CR2);

        /* Configure the Baudrate by setting the BRR register. */
        MODIFY_REGISTER_BITS(USART[Copy_u8ID]->BRR, 0, 15, Local_u8BRR);
    }
}


/***************************************************************/
/* Function Name: USART_voidTransByte                          */
/* i/p Arguments: u8 Copy_u8ID: Options (USART1->USART6)       */
/*                u8 Copy_u8Byte: Pointer to the byte to be    */
/*                                  transmitted.               */
/* Return: void                                                */
/* Description: Transmits a single byte over the USART.        */
/***************************************************************/

void USART_voidTransByte(u8 Copy_u8ID, u8 Copy_u8Byte)
{
    /* i/p validation */
    if (Copy_u8ID > USART6)
    {
        /* Do nothing */
    }
    else
    {
        /* Set the data byte to be transmitted. */
        MODIFY_REGISTER_BITS(USART[Copy_u8ID]->DR, DR0, DR7, Copy_u8Byte);

        /* Wait for the transmission to complete. */
        while (!GET_BIT(USART[Copy_u8ID]->SR, TC));

        /* Clear the transmission complete flag. */
        CLR_BIT(USART[Copy_u8ID]->SR, TC);
    }
}


/**********************************************************************/
/* Function Name: USART_voidPrintln                                   */
/* i/p Arguments: u8 Copy_u8ID: Options (USART1->USART6)              */
/*                u8 Copy_u8String: Pointer to the string to be       */
/*                                  transmitted.                      */
/* Return: void                                                       */
/* Description: Transmits a null-terminated string followed by a      */
/*              newline character over the USART.                     */
/**********************************************************************/

void USART_voidPrintln(u8 Copy_u8ID, u8 *Copy_u8String)
{
    /* i/p validation */
    if (Copy_u8ID > USART6 || (Copy_u8String == NULL))
    {
        /* Do nothing */
    }
    else
    {
        u8 Local_u8Counter = 0;
        while (*(Copy_u8String + Local_u8Counter) != '\0')
        {
            /* Transmit each character of the string. */
            MODIFY_REGISTER_BITS(USART[Copy_u8ID]->DR, DR0, DR7, *(Copy_u8String + Local_u8Counter));

            /* Wait for the transmission to complete. */
            while (!GET_BIT(USART[Copy_u8ID]->SR, TC));

            /* Clear the transmission complete flag. */
            CLR_BIT(USART[Copy_u8ID]->SR, TC);

            /* Move to the next character in the string. */
            Local_u8Counter++;
        }

        /* Transmit a newline character ('\n'). */
        MODIFY_REGISTER_BITS(USART[Copy_u8ID]->DR, DR0, DR7, 0x0A);

        /* Wait for the newline character transmission to complete. */
        while (!GET_BIT(USART[Copy_u8ID]->SR, TC));

        /* Clear the transmission complete flag. */
        CLR_BIT(USART[Copy_u8ID]->SR, TC);
    }
}


/**********************************************************************/
/* Function Name: USART_voidPrint                                     */
/* i/p Arguments: u8 Copy_u8ID: Options (USART1->USART6)              */
/*                u8 Copy_u8String: Pointer to the string to be       */
/*                                  transmitted.                      */
/* Return: void                                                       */
/* Description: Transmits a null-terminated string over the USART.    */
/**********************************************************************/

void USART_voidPrint(u8 Copy_u8ID, u8 *Copy_u8String)
{
    /* i/p validation */
    if (Copy_u8ID > USART6 || (Copy_u8String == NULL))
    {
        /* Do nothing */
    }
    else
    {
        u8 Local_u8Counter = 0;
        while (*(Copy_u8String + Local_u8Counter) != '\0')
        {
            /* Transmit each character of the string. */
            MODIFY_REGISTER_BITS(USART[Copy_u8ID]->DR, DR0, DR7, *(Copy_u8String + Local_u8Counter));

            /* Wait for the transmission to complete. */
            while (!GET_BIT(USART[Copy_u8ID]->SR, TC));

            /* Clear the transmission complete flag. */
            CLR_BIT(USART[Copy_u8ID]->SR, TC);

            /* Move to the next character in the string. */
            Local_u8Counter++;
        }
    }
}


/**********************************************************************/
/* Function Name: USART_voidRecByte                                   */
/* i/p Arguments: u8 Copy_u8ID: Options (USART1->USART6)              */
/*                u8 Copy_u8Byte: Pointer to where the received byte  */
/*                                will be stored.                     */
/* Return: void                                                       */
/* Description: Receives a single byte from the USART.                */
/**********************************************************************/

void USART_voidRecByte(u8 Copy_u8ID, u8 *Copy_u8Byte)
{
    /* i/p validation */
    if (Copy_u8ID > USART6)
    {
        /* Do nothing */
    }
    else
    {
        /* Wait for data reception. */
        while (GET_BIT(USART[Copy_u8ID]->SR, RXNE) == 0);

        /* Store the received byte. */
        *Copy_u8Byte = (u8)USART[Copy_u8ID]->DR;

        /* Clear the receive complete flag. */
        CLR_BIT(USART[Copy_u8ID]->SR, RXNE);
    }
}


/******************************************************************************/
/* Function Name: USART_voidRecString                                         */
/* i/p Arguments: u8 Copy_u8ID: Options (USART1->USART6)                      */
/*                u8 Copy_u8String: Pointer to where the received string will */
/*                                  will be stored.                           */
/* Return: void                                                               */
/* Description: Receives a string from the USART until null-terminated.       */
/******************************************************************************/

void USART_voidRecString(u8 Copy_u8ID, u8 *Copy_u8String)
{
    /* i/p validation */
    if (Copy_u8ID > USART6)
    {
        /* Do nothing */
    }
    else
    {
        u8 Local_u8Counter = 0;
        while ((u8)USART[Copy_u8ID]->DR != '\0')
        {
            /* Wait for data reception. */
            while (GET_BIT(USART[Copy_u8ID]->SR, RXNE) == 0);

            /* Store the received character in the string. */
            *(Copy_u8String + Local_u8Counter) = (u8)USART[Copy_u8ID]->DR;

            /* Clear the receive complete flag. */
            CLR_BIT(USART[Copy_u8ID]->SR, RXNE);

            /* Move to the next character in the string. */
            Local_u8Counter++;
        }

        /* Null-terminate the received string. */
        *(Copy_u8String + Local_u8Counter) = '\0';
    }
}
