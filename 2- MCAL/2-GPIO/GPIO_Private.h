/*****************************************************/
/*                 SWC: GPIO Driver                  */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.0                    */
/*              Date: 28 July - 2023                 */
/*****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Config.h"

/* File Gaurd */
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


typedef struct 
{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUDPR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
} GPIO_t;

/* #define GPIOA     ((GPIO_t*)0x40020000)     GPIOA->MODER, Important: It's time to search :( */ 

/* Base Address of GPIOA 0x40020000 - 0x400203FF */
#define GPIOA       ((GPIO_t*)0x40020000)      /* GPIOA.MODER */

/* Base Address of GPIOB 0x40020400 - 0x400207FF */
#define GPIOB       ((GPIO_t*)0x40020400)      /* GPIOB.MODER */

/* Base Address of GPIOC 0x40020800 - 0x40020BFF */
#define GPIOC       ((GPIO_t*)0x40020800)      /* GPIOC.MODER */



/* Functions-like macro to concatenate GPIO mode values */
#define GPIOA_MODE CONCATENATE_32_BITS(GPIOA_MODE_0, GPIOA_MODE_1, GPIOA_MODE_2, GPIOA_MODE_3, \
                                           GPIOA_MODE_4, GPIOA_MODE_5, GPIOA_MODE_6, GPIOA_MODE_7, \
                                           GPIOA_MODE_8, GPIOA_MODE_9, GPIOA_MODE_10, GPIOA_MODE_11, \
                                           GPIOA_MODE_12, GPIOA_MODE_13, GPIOA_MODE_14, GPIOA_MODE_15)

#define GPIOB_MODE CONCATENATE_32_BITS(GPIOB_MODE_0, GPIOB_MODE_1, GPIOB_MODE_2, GPIOB_MODE_3, \
                                           GPIOB_MODE_4, GPIOB_MODE_5, GPIOB_MODE_6, GPIOB_MODE_7, \
                                           GPIOB_MODE_8, GPIOB_MODE_9, GPIOB_MODE_10, GPIOB_MODE_11, \
                                           GPIOB_MODE_12, GPIOB_MODE_13, GPIOB_MODE_14, GPIOB_MODE_15)

#define GPIOC_MODE CONCATENATE_32_BITS(GPIOC_MODE_13, GPIOC_MODE_14, GPIOC_MODE_15,0,0,0,0,0,0,0,0,0,0,0,0,0)

/* Functions-like macro to concatenate GPIO output speed values */
#define GPIOA_OUTPUT_SPEED CONCATENATE_32_BITS(GPIOA_OUTPUT_SPEED_0, GPIOA_OUTPUT_SPEED_1, GPIOA_OUTPUT_SPEED_2, GPIOA_OUTPUT_SPEED_3, \
                                                  GPIOA_OUTPUT_SPEED_4, GPIOA_OUTPUT_SPEED_5, GPIOA_OUTPUT_SPEED_6, GPIOA_OUTPUT_SPEED_7, \
                                                  GPIOA_OUTPUT_SPEED_8, GPIOA_OUTPUT_SPEED_9, GPIOA_OUTPUT_SPEED_10, GPIOA_OUTPUT_SPEED_11, \
                                                  GPIOA_OUTPUT_SPEED_12, GPIOA_OUTPUT_SPEED_13, GPIOA_OUTPUT_SPEED_14, GPIOA_OUTPUT_SPEED_15)

#define GPIOB_OUTPUT_SPEED CONCATENATE_32_BITS(GPIOB_OUTPUT_SPEED_0, GPIOB_OUTPUT_SPEED_1, GPIOB_OUTPUT_SPEED_2, GPIOB_OUTPUT_SPEED_3, \
                                                  GPIOB_OUTPUT_SPEED_4, GPIOB_OUTPUT_SPEED_5, GPIOB_OUTPUT_SPEED_6, GPIOB_OUTPUT_SPEED_7, \
                                                  GPIOB_OUTPUT_SPEED_8, GPIOB_OUTPUT_SPEED_9, GPIOB_OUTPUT_SPEED_10, GPIOB_OUTPUT_SPEED_11, \
                                                  GPIOB_OUTPUT_SPEED_12, GPIOB_OUTPUT_SPEED_13, GPIOB_OUTPUT_SPEED_14, GPIOB_OUTPUT_SPEED_15)

#define GPIOC_OUTPUT_SPEED CONCATENATE_32_BITS(GPIOC_OUTPUT_SPEED_13, GPIOC_OUTPUT_SPEED_14, GPIOC_OUTPUT_SPEED_15,0,0,0,0,0,0,0,0,0,0,0,0,0)

/* Functions-like macro to concatenate GPIO PUPD values */
#define GPIOA_PUPD CONCATENATE_32_BITS(GPIOA_PUPD_0, GPIOA_PUPD_1, GPIOA_PUPD_2, GPIOA_PUPD_3, \
                                           GPIOA_PUPD_4, GPIOA_PUPD_5, GPIOA_PUPD_6, GPIOA_PUPD_7, \
                                           GPIOA_PUPD_8, GPIOA_PUPD_9, GPIOA_PUPD_10, GPIOA_PUPD_11, \
                                           GPIOA_PUPD_12, GPIOA_PUPD_13, GPIOA_PUPD_14, GPIOA_PUPD_15)

#define GPIOB_PUPD CONCATENATE_32_BITS(GPIOB_PUPD_0, GPIOB_PUPD_1, GPIOB_PUPD_2, GPIOB_PUPD_3, \
                                           GPIOB_PUPD_4, GPIOB_PUPD_5, GPIOB_PUPD_6, GPIOB_PUPD_7, \
                                           GPIOB_PUPD_8, GPIOB_PUPD_9, GPIOB_PUPD_10, GPIOB_PUPD_11, \
                                           GPIOB_PUPD_12, GPIOB_PUPD_13, GPIOB_PUPD_14, GPIOB_PUPD_15)

#define GPIOC_PUPD CONCATENATE_32_BITS(GPIOC_PUPD_13, GPIOC_PUPD_14, GPIOC_PUPD_15,0,0,0,0,0,0,0,0,0,0,0,0,0)

/* Function-like macro to concatenate GPIO output values */
#define GPIOA_OUTPUT_VALUES CONCATENATE_16_BITS(GPIOA_OUTPUT_VALUE_0, GPIOA_OUTPUT_VALUE_1, GPIOA_OUTPUT_VALUE_2, GPIOA_OUTPUT_VALUE_3, \
                                             GPIOA_OUTPUT_VALUE_4, GPIOA_OUTPUT_VALUE_5, GPIOA_OUTPUT_VALUE_6, GPIOA_OUTPUT_VALUE_7, \
                                             GPIOA_OUTPUT_VALUE_8, GPIOA_OUTPUT_VALUE_9, GPIOA_OUTPUT_VALUE_10, GPIOA_OUTPUT_VALUE_11, \
                                             GPIOA_OUTPUT_VALUE_12, GPIOA_OUTPUT_VALUE_13, GPIOA_OUTPUT_VALUE_14, GPIOA_OUTPUT_VALUE_15)

#define GPIOB_OUTPUT_VALUES CONCATENATE_16_BITS(GPIOB_OUTPUT_VALUE_0, GPIOB_OUTPUT_VALUE_1, GPIOB_OUTPUT_VALUE_2, GPIOB_OUTPUT_VALUE_3, \
                                             GPIOB_OUTPUT_VALUE_4, GPIOB_OUTPUT_VALUE_5, GPIOB_OUTPUT_VALUE_6, GPIOB_OUTPUT_VALUE_7, \
                                             GPIOB_OUTPUT_VALUE_8, GPIOB_OUTPUT_VALUE_9, GPIOB_OUTPUT_VALUE_10, GPIOB_OUTPUT_VALUE_11, \
                                             GPIOB_OUTPUT_VALUE_12, GPIOB_OUTPUT_VALUE_13, GPIOB_OUTPUT_VALUE_14, GPIOB_OUTPUT_VALUE_15)

#define GPIOC_OUTPUT_VALUES CONCATENATE_16_BITS(GPIOC_OUTPUT_VALUE_13, GPIOC_OUTPUT_VALUE_14, GPIOC_OUTPUT_VALUE_15,0,0,0,0,0,0,0,0,0,0,0,0,0)

/* Function-like macro to concatenate GPIO output types */
#define GPIOA_OUTPUT_TYPES CONCATENATE_16_BITS(GPIOA_OUTPUT_TYPE_0, GPIOA_OUTPUT_TYPE_1, GPIOA_OUTPUT_TYPE_2, GPIOA_OUTPUT_TYPE_3, \
                                            GPIOA_OUTPUT_TYPE_4, GPIOA_OUTPUT_TYPE_5, GPIOA_OUTPUT_TYPE_6, GPIOA_OUTPUT_TYPE_7, \
                                            GPIOA_OUTPUT_TYPE_8, GPIOA_OUTPUT_TYPE_9, GPIOA_OUTPUT_TYPE_10, GPIOA_OUTPUT_TYPE_11, \
                                            GPIOA_OUTPUT_TYPE_12, GPIOA_OUTPUT_TYPE_13, GPIOA_OUTPUT_TYPE_14, GPIOA_OUTPUT_TYPE_15)

#define GPIOB_OUTPUT_TYPES CONCATENATE_16_BITS(GPIOB_OUTPUT_TYPE_0, GPIOB_OUTPUT_TYPE_1, GPIOB_OUTPUT_TYPE_2, GPIOB_OUTPUT_TYPE_3, \
                                            GPIOB_OUTPUT_TYPE_4, GPIOB_OUTPUT_TYPE_5, GPIOB_OUTPUT_TYPE_6, GPIOB_OUTPUT_TYPE_7, \
                                            GPIOB_OUTPUT_TYPE_8, GPIOB_OUTPUT_TYPE_9, GPIOB_OUTPUT_TYPE_10, GPIOB_OUTPUT_TYPE_11, \
                                            GPIOB_OUTPUT_TYPE_12, GPIOB_OUTPUT_TYPE_13, GPIOB_OUTPUT_TYPE_14, GPIOB_OUTPUT_TYPE_15)

#define GPIOC_OUTPUT_TYPES CONCATENATE_16_BITS(GPIOC_OUTPUT_TYPE_13, GPIOC_OUTPUT_TYPE_14, GPIOC_OUTPUT_TYPE_15,0,0,0,0,0,0,0,0,0,0,0,0,0)

#define CONCATENATE_32_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) \
    ((b0) | ((b1) << 2) | ((b2) << 4) | ((b3) << 6) | ((b4) << 8) | ((b5) << 10) | ((b6) << 12) | \
     ((b7) << 14) | ((b8) << 16) | ((b9) << 18) | ((b10) << 20) | ((b11) << 22) | ((b12) << 24) | \
     ((b13) << 26) | ((b14) << 28) | ((b15) << 30))

#define CONCATENATE_16_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) \
    ((b0) | ((b1) << 1) | ((b2) << 2) | ((b3) << 3) | ((b4) << 4) | ((b5) << 5) | ((b6) << 6) | \
     ((b7) << 7) | ((b8) << 8) | ((b9) << 9) | ((b10) << 10) | ((b11) << 11) | ((b12) << 12) | \
     ((b13) << 13) | ((b14) << 14) | ((b15) << 15))


#endif