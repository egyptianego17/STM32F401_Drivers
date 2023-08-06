/*****************************************************/
/*              SWC: SysTick Driver                  */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.0                    */
/*              Date: 4 August - 2023                */
/*****************************************************/

/* File Gaurd */
#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

/* Options for SysTick Clk Source (AHB - AHB_DIV_BY_8)             */
#define STK_CLK_SOURCE          AHB_DIV_BY_8

/* Number of Ticks of One Second After SysTick Clk Prescaling
   Note: Max AHB Freq These Delay Functions Can Handle is 16Mhz    */
#define AHB_CLK_VALUE           8000000


#endif