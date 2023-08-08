/*****************************************************/
/*                 SWC: GPIO Driver                  */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.1                    */
/*              Date: 28 July - 2023                 */
/*****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"


/*****************************************************************************/
/* Function Name: GPIO_voidSetPinMode                                        */
/* i/p Arguments: u8 Copy_u8PortId Options (IOA, IOB, IOC)                   */
/* i/p Arguments: u8 Copy_u8PinId Options (PIN0->PIN15)                      */
/* i/p Arguments: u8 Copy_u8PinMode Options (INPUT, OUTPUT, AF, ANALOG)      */
/* Return: Void                                                              */
/* Description: This function sets the mode (input, output,                  */
/*              alternate function, or analog) of a specified GPIO pin.      */
/*****************************************************************************/

void GPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinMode)
{
    /* i/p validation */
    if ((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinMode > ANALOG))
    {
        /* Do nothing */
    }
    else
    {
       switch (Copy_u8PortId)
       {
           case IOA:
               MODIFY_REGISTER_BITS(GPIOA->MODER, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinMode);
               break;
           case IOB:
               MODIFY_REGISTER_BITS(GPIOB->MODER, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinMode);
               break;
           case IOC:
               MODIFY_REGISTER_BITS(GPIOC->MODER, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinMode);
               break;
           default:
               break;
       }
    }
}


/***********************************************************************************/
/* Function Name: GPIO_voidSetPinType                                              */
/* i/p Arguments: u8 Copy_u8PortId Options (IOA, IOB, IOC)                         */
/* i/p Arguments: u8 Copy_u8PinId Options (PIN0->PIN15)                            */
/* i/p Arguments: u8 Copy_u8PinType Options (OUTPUT_PP, OUTPUT_OD)                 */
/* Return: Void                                                                    */
/* Description: This function sets the type (output push-pull, output open-drain.) */
/***********************************************************************************/

void GPIO_voidSetPinType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinType)
{
    /* i/p validation */
    if ((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinType>OUTPUT_OD))
    {
        /* Do nothing */
    }
    else
    {
        switch (Copy_u8PinType)
        {
            case OUTPUT_PP:
                switch (Copy_u8PortId)
                {
                    case IOA:
                        CLR_BIT(GPIOA->OTYPER, Copy_u8PinId);
                        break;

                    case IOB:
                        CLR_BIT(GPIOB->OTYPER, Copy_u8PinId);
                        break;

                    case IOC:
                        CLR_BIT(GPIOC->OTYPER, Copy_u8PinId);
                        break;

                    default:
                        break;
                }
                break;

            case OUTPUT_OD:
                switch (Copy_u8PortId)
                {
                    case IOA:
                        SET_BIT(GPIOA->OTYPER, Copy_u8PinId);
                        break;

                    case IOB:
                        SET_BIT(GPIOB->OTYPER, Copy_u8PinId);
                        break;

                    case IOC:
                        SET_BIT(GPIOC->OTYPER, Copy_u8PinId);
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}


/******************************************************************************/
/* Function Name: GPIO_voidSetPinSpeed                                        */
/* i/p Arguments: u8 Copy_u8PortId Options (IOA, IOB, IOC)                    */
/* i/p Arguments: u8 Copy_u8PinId Options (PIN0->PIN15)                       */
/* i/p Arguments: u8 Copy_u8PinSpeed Options (OUTPUT_LS, OUTPUT_MS,           */
/*                                            OUTPUT_HS, OUTPUT_VHS)          */
/* Return: void                                                               */
/* Description: This function sets the output speed for a specified GPIO pin. */
/******************************************************************************/

void GPIO_voidSetPinSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinSpeed)
{
    /* i/p validation */
    if ((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinSpeed > OUTPUT_VHS))
    {
        /* Do nothing */
    }
    else
    {
        switch (Copy_u8PortId)
        {
            case IOA:
                MODIFY_REGISTER_BITS(GPIOA->OSPEEDR, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinSpeed);
                break;

            case IOB:
                MODIFY_REGISTER_BITS(GPIOB->OSPEEDR, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinSpeed);
                break;

            case IOC:
                MODIFY_REGISTER_BITS(GPIOC->OSPEEDR, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinSpeed);
                break;

            default:
                break;
        }
    }
}


/********************************************************************************/
/* Function Name: GPIO_voidDefaultInit                                            */
/* i/p Arguments: u8 Copy_u8PortId: Options (IOA, IOB, IOC)                       */
/* i/p Arguments: u8 Copy_u8PinId: Options (PIN0->PIN15)                          */
/* i/p Arguments: u8 Copy_u8PinPUPDOption: Options (FLOATING, INPUT_PU, INPUT_PD) */
/* Return: void                                                                   */
/* Description: This function sets the pull-up/pull-down configuration for        */
/*              a specified GPIO pin.                                             */
/********************************************************************************/

void GPIO_voidSetPinPUPD(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinPUPDOption)
{
    /* i/p validation */
    if ((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15) || (Copy_u8PinPUPDOption > INPUT_PD))
    {
        /* Do nothing */
    }
    else
    {
        switch (Copy_u8PortId)
        {
            case IOA:
                MODIFY_REGISTER_BITS(GPIOA->PUDPR, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinPUPDOption);
                break;

            case IOB:
                MODIFY_REGISTER_BITS(GPIOB->PUDPR, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinPUPDOption);
                break;

            case IOC:
                MODIFY_REGISTER_BITS(GPIOC->PUDPR, Copy_u8PinId*2, Copy_u8PinId*2+1, Copy_u8PinPUPDOption);
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************/
/* Function Name: GPIO_voidSetPinValue                                       */
/* i/p Arguments: u8 Copy_u8PortId Options (IOA, IOB, IOC)                   */
/* i/p Arguments: u8 Copy_u8PinId Options (PIN0->PIN15)                      */
/* i/p Arguments: u8 Copy_u8PinValue Options (LOW, HIGH)                     */
/* Return: Void                                                              */
/* Description: This function sets the value of a specified GPIO pin.        */
/*              The value can be either LOW (0) or HIGH (1).                 */
/*****************************************************************************/

void GPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
    /* i/p validation */
    if ((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15))
    {
        /* Do nothing */
    }
    else
    {
        switch (Copy_u8PinValue)
        {
            case LOW:
                switch (Copy_u8PortId)
                {
                    case IOA:
                        CLR_BIT(GPIOA->ODR, Copy_u8PinId);
                        break;

                    case IOB:
                        CLR_BIT(GPIOB->ODR, Copy_u8PinId);
                        break;

                    case IOC:
                        CLR_BIT(GPIOC->ODR, Copy_u8PinId);
                        break;

                    default:
                        break;
                }
                break;

            case HIGH:
                switch (Copy_u8PortId)
                {
                    case IOA:
                        SET_BIT(GPIOA->ODR, Copy_u8PinId);
                        break;

                    case IOB:
                        SET_BIT(GPIOB->ODR, Copy_u8PinId);
                        break;

                    case IOC:
                        SET_BIT(GPIOC->ODR, Copy_u8PinId);
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************/
/* Function Name: GPIO_voidSetPinValueDirectAccess                           */
/* i/p Arguments: u8 Copy_u8PortId Options (IOA, IOB, IOC)                   */
/* i/p Arguments: u8 Copy_u8PinId Options (PIN0->PIN15)                      */
/* i/p Arguments: u8 Copy_u8PinValue Options (LOW, HIGH)                     */
/* Return: Void                                                              */
/* Description: This function directly sets or resets a specified GPIO pin.  */
/*****************************************************************************/

void GPIO_voidSetPinValueDirectAccess(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
    /* i/p validation */
    if ((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15))
    {
        /* Do nothing */
    }
    else
    {
        switch (Copy_u8PinValue)
        {
            case RST:
                switch (Copy_u8PortId)
                {
                    case IOA:
                        GPIOA->BSRR = (1 << Copy_u8PinId) + 16;
                        break;

                    case IOB:
                        GPIOB->BSRR = (1 << Copy_u8PinId) + 16;
                        break;

                    case IOC:
                        GPIOC->BSRR = (1 << Copy_u8PinId) + 16;
                        break;

                    default:
                        break;
                }
                break;

            case SET:
                switch (Copy_u8PortId)
                {
                    case IOA:
                        GPIOA->BSRR = (1 << Copy_u8PinId);
                        break;

                    case IOB:
                        GPIOB->BSRR = (1 << Copy_u8PinId);
                        break;

                    case IOC:
                        GPIOC->BSRR = (1 << Copy_u8PinId);
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************/
/* Function Name: GPIO_voidSetPortValue                                      */
/* i/p Arguments: u8 Copy_u8PortId Options (IOA, IOB, IOC)                   */
/* i/p Arguments: u16 Copy_u8PortValue (0x0000 to 0xFFFF)                    */
/* Return: Void                                                              */
/* Description: This function sets the value of the entire GPIO port.        */
/*              The port value is specified by a 16-bit binary number,       */
/*              where each bit represents the state of a corresponding pin.  */
/*              The function supports ports A, B, and C.                     */
/*****************************************************************************/

void GPIO_voidSetPortValue(u8 Copy_u8PortId, u16 Copy_u8PortValue)
{
    /* i/p validation */
    if (Copy_u8PortId > IOC)
    {
        /* Do nothing */
    }
    else
    {
        switch (Copy_u8PortId)
        {
            case IOA:
                MODIFY_REGISTER_BITS(GPIOA->ODR, PIN0, PIN15,Copy_u8PortValue);
                break;
            case IOB:
                MODIFY_REGISTER_BITS(GPIOB->ODR, PIN0, PIN15,Copy_u8PortValue);
                break;
            case IOC:
                MODIFY_REGISTER_BITS(GPIOC->ODR, PIN0, PIN15,Copy_u8PortValue);
                break;
            default:
                break;
        }
    }
}


/*****************************************************************************/
/* Function Name: GPIO_u8GetPinValue                                         */
/* i/p Arguments: u8 Copy_u8PortId Options (IOA, IOB, IOC)                   */
/* i/p Arguments: u8 Copy_u8PinId Options (PIN0->PIN15)                      */
/* Return: u8                                                                */
/* Description: This function reads and returns the value of a specified     */
/*              GPIO pin. The pin value can be either LOW (0) or HIGH (1).   */
/*****************************************************************************/

u8   GPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    u8 Local_u8PinValue;
    if ((Copy_u8PortId > IOC) || (Copy_u8PinId > PIN15))
    {
        /* Do nothing */
    }
    else
    {
        switch (Copy_u8PortId)
        {
            case IOA:
                Local_u8PinValue = GET_BIT(GPIOA->IDR, Copy_u8PinId);
                break;

            case IOB:
                Local_u8PinValue = GET_BIT(GPIOB->IDR, Copy_u8PinId);
                break;

            case IOC:
                Local_u8PinValue = GET_BIT(GPIOC->IDR, Copy_u8PinId);
                break;

            default:
                break;
        }
    }
    return Local_u8PinValue;
}


/*****************************************************************************/
/* Function Name: GPIO_voidDefaultInit                                       */
/* i/p Arguments: none                                                       */
/* Return: void                                                              */
/* Description: This function initializes the GPIO pins to their default     */
/*              configuration. It sets the mode, output speed, pull-up/pull- */
/*              down configuration, output value, and output type for all    */
/*              pins of GPIO Ports A, B, and C.                              */
/*****************************************************************************/

void GPIO_voidDefaultInit()
{
    /* Set the GPIO mode for all pins of Port A, B, and C to the configured value. */
    MODIFY_REGISTER_BITS(GPIOA->MODER, PIN0, PIN15*2+1, GPIOA_MODE);
    MODIFY_REGISTER_BITS(GPIOB->MODER, PIN0, PIN15*2+1, GPIOB_MODE);
    MODIFY_REGISTER_BITS(GPIOC->MODER, PIN13*2, PIN15*2+1, GPIOC_MODE);

    /* Set the output speed for all pins of Port A, B, and C to the configured value. */
    MODIFY_REGISTER_BITS(GPIOA->OSPEEDR, PIN0, PIN15*2+1, GPIOA_OUTPUT_SPEED);
    MODIFY_REGISTER_BITS(GPIOB->OSPEEDR, PIN0, PIN15*2+1, GPIOB_OUTPUT_SPEED);
    MODIFY_REGISTER_BITS(GPIOC->OSPEEDR, PIN13*2, PIN15*2+1, GPIOC_OUTPUT_SPEED);

    /* Set the pull-up/pull-down configuration for all pins of Port A, B, and C to the configured value. */
    MODIFY_REGISTER_BITS(GPIOA->PUDPR, PIN0, PIN15*2+1, GPIOA_PUPD);
    MODIFY_REGISTER_BITS(GPIOB->PUDPR, PIN0, PIN15*2+1, GPIOB_PUPD);
    MODIFY_REGISTER_BITS(GPIOC->PUDPR, PIN13*2, PIN15*2+1, GPIOC_PUPD);


    /* Set the output value for all pins of Port A, B, and C to the configured value.   */
    MODIFY_REGISTER_BITS(GPIOA->ODR, PIN0, PIN15, GPIOA_OUTPUT_VALUES);
    MODIFY_REGISTER_BITS(GPIOB->ODR, PIN0, PIN15, GPIOB_OUTPUT_VALUES);
    MODIFY_REGISTER_BITS(GPIOC->ODR, PIN13, PIN15, GPIOC_OUTPUT_VALUES);

    /* Set the output type for all pins of Port A, B, and C to the configured value. */
    MODIFY_REGISTER_BITS(GPIOA->OTYPER, PIN0, PIN15, GPIOA_OUTPUT_TYPES);
    MODIFY_REGISTER_BITS(GPIOB->OTYPER, PIN0, PIN15, GPIOB_OUTPUT_TYPES);
    MODIFY_REGISTER_BITS(GPIOC->OTYPER, PIN13, PIN15, GPIOC_OUTPUT_TYPES);

    /* Set the alternate function registers of Port A, B, and C to the configured value. */
    MODIFY_REGISTER_BITS(GPIOA->AFRL, PIN0, PIN15*2+1, GPIOA_AFRL);
    MODIFY_REGISTER_BITS(GPIOB->AFRL, PIN0, PIN15*2+1, GPIOB_AFRL);

    MODIFY_REGISTER_BITS(GPIOA->AFRH, PIN0, PIN15*2+1, GPIOA_AFRH);
    MODIFY_REGISTER_BITS(GPIOB->AFRH, PIN0, PIN15*2+1, GPIOB_AFRH);
    MODIFY_REGISTER_BITS(GPIOC->AFRH, PIN10*2, PIN15*2+1, GPIOC_AFRH);

}