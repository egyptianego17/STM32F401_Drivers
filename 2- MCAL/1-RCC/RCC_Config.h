/*****************************************************/
/*                 SWC: RCC Driver                   */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.0                    */
/*              Date: 21 July - 2023                 */
/*****************************************************/

/* File Gaurd */
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options for Clk Source (HSI - HSE - PLL)                */
#define RCC_CLK_SRC HSI

/* Options for PLL Source (HSI - HSE)                      */
#define RCC_PLL_SRC HSI

/* PLLM: REG_Range 2 ≤ PLLM ≤ 63
   0.5≤Fsrc(Mhz)/PLLM≤1 
   Recommended to be 0.5 × Fsrc(Mhz)                       */
#define RCC_PLLM 8

/* PLLN: REG_Range 192 ≤ PLLN ≤ 432 
   192≤(PLLN×Fsrc(Mhz)/PLLM)≤432                           */
#define RCC_PLLN 210

/* PLLP Options: 0: PLLP = 2
                 1: PLLP = 4
                 2: PLLP = 6
                 3: PLLP = 8 
   PLLN×Fsrc(Mhz)/(PLLM*PLLP) Must not exceed 84 MHz       */
#define RCC_PLLP 2

#endif