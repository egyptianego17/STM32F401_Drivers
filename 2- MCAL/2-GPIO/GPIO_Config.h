/*****************************************************/
/*                 SWC: GPIO Driver                  */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.1                    */
/*              Date: 28 July - 2023                 */
/*****************************************************/


#include "GPIO_Interface.h"

/* File Gaurd */
#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H


/*    Initial Mode for GPIO Pins                       */
/*    Options for Mode (INPUT - OUTPUT - AF - ANALOG)  */

#define GPIOA_MODE_0    ANALOG
#define GPIOA_MODE_1    ANALOG
#define GPIOA_MODE_2    ANALOG
#define GPIOA_MODE_3    ANALOG
#define GPIOA_MODE_4    ANALOG
#define GPIOA_MODE_5    ANALOG
#define GPIOA_MODE_6    ANALOG
#define GPIOA_MODE_7    ANALOG
#define GPIOA_MODE_8    ANALOG
#define GPIOA_MODE_9    ANALOG
#define GPIOA_MODE_10   ANALOG
#define GPIOA_MODE_11   ANALOG
#define GPIOA_MODE_12   ANALOG
#define GPIOA_MODE_15   ANALOG

#define GPIOB_MODE_0    ANALOG
#define GPIOB_MODE_1    ANALOG
#define GPIOB_MODE_2    ANALOG
#define GPIOB_MODE_3    ANALOG
#define GPIOB_MODE_4    ANALOG
#define GPIOB_MODE_5    ANALOG
#define GPIOB_MODE_6    ANALOG
#define GPIOB_MODE_7    ANALOG
#define GPIOB_MODE_8    ANALOG
#define GPIOB_MODE_9    ANALOG
#define GPIOB_MODE_10   ANALOG
#define GPIOB_MODE_12   ANALOG
#define GPIOB_MODE_13   ANALOG
#define GPIOB_MODE_14   ANALOG
#define GPIOB_MODE_15   ANALOG

#define GPIOC_MODE_13   ANALOG
#define GPIOC_MODE_14   ANALOG
#define GPIOC_MODE_15   ANALOG


/*    Initial Output Value for GPIOA Pins              */
/*    Options for Output (HIGH - LOW)                  */

#define GPIOA_OUTPUT_VALUE_0    LOW
#define GPIOA_OUTPUT_VALUE_1    LOW
#define GPIOA_OUTPUT_VALUE_2    LOW
#define GPIOA_OUTPUT_VALUE_3    LOW
#define GPIOA_OUTPUT_VALUE_4    LOW
#define GPIOA_OUTPUT_VALUE_5    LOW
#define GPIOA_OUTPUT_VALUE_6    LOW
#define GPIOA_OUTPUT_VALUE_7    LOW
#define GPIOA_OUTPUT_VALUE_8    LOW
#define GPIOA_OUTPUT_VALUE_9    LOW
#define GPIOA_OUTPUT_VALUE_10   LOW
#define GPIOA_OUTPUT_VALUE_11   LOW
#define GPIOA_OUTPUT_VALUE_12   LOW
#define GPIOA_OUTPUT_VALUE_15   LOW

#define GPIOB_OUTPUT_VALUE_0    LOW
#define GPIOB_OUTPUT_VALUE_1    LOW
#define GPIOB_OUTPUT_VALUE_2    LOW
#define GPIOB_OUTPUT_VALUE_3    LOW
#define GPIOB_OUTPUT_VALUE_4    LOW
#define GPIOB_OUTPUT_VALUE_5    LOW
#define GPIOB_OUTPUT_VALUE_6    LOW
#define GPIOB_OUTPUT_VALUE_7    LOW
#define GPIOB_OUTPUT_VALUE_8    LOW
#define GPIOB_OUTPUT_VALUE_9    LOW
#define GPIOB_OUTPUT_VALUE_10   LOW
#define GPIOB_OUTPUT_VALUE_12   LOW
#define GPIOB_OUTPUT_VALUE_13   LOW
#define GPIOB_OUTPUT_VALUE_14   LOW
#define GPIOB_OUTPUT_VALUE_15   LOW

#define GPIOC_OUTPUT_VALUE_13   LOW
#define GPIOC_OUTPUT_VALUE_14   LOW
#define GPIOC_OUTPUT_VALUE_15   LOW


/*    Initial Output Type for GPIO Pins                */
/*    Options for Output (OUTPUT_PP - OUTPUT_OD)       */

#define GPIOA_OUTPUT_TYPE_0    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_1    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_2    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_3    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_4    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_5    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_6    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_7    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_8    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_9    OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_10   OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_11   OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_12   OUTPUT_PP
#define GPIOA_OUTPUT_TYPE_15   OUTPUT_PP

#define GPIOB_OUTPUT_TYPE_0    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_1    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_2    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_3    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_4    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_5    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_6    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_7    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_8    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_9    OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_10   OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_12   OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_13   OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_14   OUTPUT_PP
#define GPIOB_OUTPUT_TYPE_15   OUTPUT_PP

#define GPIOC_OUTPUT_TYPE_13   OUTPUT_PP
#define GPIOC_OUTPUT_TYPE_14   OUTPUT_PP
#define GPIOC_OUTPUT_TYPE_15   OUTPUT_PP


/*    Initial Output Speed for GPIO Pins               */
/*    Options for Output (OUTPUT_LS - OUTPUT_MS        */
/*                        OUTPUT_HS - OUTPUT_VHS       */

#define GPIOA_OUTPUT_SPEED_0    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_1    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_2    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_3    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_4    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_5    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_6    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_7    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_8    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_9    OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_10   OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_11   OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_12   OUTPUT_LS
#define GPIOA_OUTPUT_SPEED_15   OUTPUT_LS

#define GPIOB_OUTPUT_SPEED_0    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_1    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_2    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_3    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_4    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_5    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_6    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_7    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_8    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_9    OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_10   OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_12   OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_13   OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_14   OUTPUT_LS
#define GPIOB_OUTPUT_SPEED_15   OUTPUT_LS

#define GPIOC_OUTPUT_SPEED_13   OUTPUT_LS
#define GPIOC_OUTPUT_SPEED_14   OUTPUT_LS
#define GPIOC_OUTPUT_SPEED_15   OUTPUT_LS


/*    Initial Pull-Up/Pull-Down configuration for GPIO Pins  */
/*    Options for Output (FLOATING - INPUT_PU - INPUT_PD)    */

#define GPIOA_PUPD_0    FLOATING
#define GPIOA_PUPD_1    FLOATING
#define GPIOA_PUPD_2    FLOATING
#define GPIOA_PUPD_3    FLOATING
#define GPIOA_PUPD_4    FLOATING
#define GPIOA_PUPD_5    FLOATING
#define GPIOA_PUPD_6    FLOATING
#define GPIOA_PUPD_7    FLOATING
#define GPIOA_PUPD_8    FLOATING
#define GPIOA_PUPD_9    FLOATING
#define GPIOA_PUPD_10   FLOATING
#define GPIOA_PUPD_11   FLOATING
#define GPIOA_PUPD_12   FLOATING
#define GPIOA_PUPD_15   FLOATING

#define GPIOB_PUPD_0    FLOATING
#define GPIOB_PUPD_1    FLOATING
#define GPIOB_PUPD_2    FLOATING
#define GPIOB_PUPD_3    FLOATING
#define GPIOB_PUPD_4    FLOATING
#define GPIOB_PUPD_5    FLOATING
#define GPIOB_PUPD_6    FLOATING
#define GPIOB_PUPD_7    FLOATING
#define GPIOB_PUPD_8    FLOATING
#define GPIOB_PUPD_9    FLOATING
#define GPIOB_PUPD_10   FLOATING
#define GPIOB_PUPD_12   FLOATING
#define GPIOB_PUPD_13   FLOATING
#define GPIOB_PUPD_14   FLOATING
#define GPIOB_PUPD_15   FLOATING

#define GPIOC_PUPD_13   FLOATING
#define GPIOC_PUPD_14   FLOATING
#define GPIOC_PUPD_15   FLOATING

#endif