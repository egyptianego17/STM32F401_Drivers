/*****************************************************/
/*               SWC: USART Driver                   */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.0                    */
/*            Date: 23 September - 2023              */
/*****************************************************/

/* File Gaurd */
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define USART_CLK 8000000

#define WORD_LENGTH 0                             /* Word length (M)
                                                    0: 1 Start bit, 8 Data bits
                                                    1: 1 Start bit, 9 Data bits
                                                  */

#define PARITY_CONTROL_ENABLE 0                   /* Parity control enable (PCE)
                                                    0: Parity control disabled
                                                    1: Parity control enabled
                                                  */

#define PARITY_SELECTION 0                        /* Parity selection (PS)
                                                    0: Even parity
                                                    1: Odd parity
                                                  */
  
             
#endif
