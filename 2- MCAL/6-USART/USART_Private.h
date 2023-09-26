/*****************************************************/
/*               SWC: USART Driver                   */
/*            Author: Abdulrahman Omar               */
/*                 Version: v 1.0                    */
/*            Date: 23 September - 2023              */
/*****************************************************/

#include "USART_Config.h"

/* File Gaurd */
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/* Base Address of USART1 0x40011000 - 0x400113FF */
/* Base Address of USART2 0x40004400 - 0x400147FF */
/* Base Address of USART6 0x40011400 - 0x400117FF */

typedef struct
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;
} USART_R;

USART_R* USART[3] = {(USART_R*)0x40011000, (USART_R*)0x40004400, (USART_R*)0x40011400};

#define RXNE          5                          /* Read data register not empty */
#define TC            6                          /* Transmission complete bit    */
#define DR0           0
#define DR7           7

/*               CR1 Bits               */
#define USART_ENABLE 1                            /* USART enable (UE)
                                                    0: USART prescaler and outputs disabled
                                                    1: USART enabled
                                                  */

#define RECEIVER_WAKEUP 0                          /* Receiver wakeup (RWU)
                                                   0: Receiver in active mode
                                                   1: Receiver in mute mode
                                                   Note: Before selecting Mute mode (by setting the RWU bit), the USART must first receive a data byte, otherwise, it cannot function in Mute mode with wakeup by Idle line detection. In Address Mark Detection wakeup configuration (WAKE bit=1), the RWU bit cannot be modified by software while the RXNE bit is set.
                                                  */
                                            
#define OVER8_16 0                                /* Oversampling mode (OVER8)
                                                   0: Oversampling by 16
                                                   1: Oversampling by 8
                                                   Note: Oversampling by 8 is not available in Smartcard, IrDA, and LIN modes when SCEN=1, IREN=1, or LINEN=1; OVER8 is forced to '0 by hardware.
                                                  */

#define WAKEUP_METHOD 0                           /* Wakeup method (WAKE)
                                                    0: Idle Line
                                                    1: Address Mark
                                                  */

#define PE_INTERRUPT_ENABLE 0                      /* PE interrupt enable (PEIE)
                                                   0: Interrupt is inhibited
                                                   1: An USART interrupt is generated whenever PE=1 in the USART_SR register
                                                   */

#define TXE_INTERRUPT_ENABLE 0                    /* TXE interrupt enable (TXEIE)
                                                   0: Interrupt is inhibited
                                                   1: An USART interrupt is generated whenever TXE=1 in the USART_SR register
                                                  */

#define TRANSMISSION_COMPLETE_INTERRUPT_ENABLE 0  /* Transmission complete interrupt enable (TCIE)
                                                     0: Interrupt is inhibited
                                                     1: An USART interrupt is generated whenever TC=1 in the USART_SR register
                                                   */

#define RXNE_INTERRUPT_ENABLE 0                     /* RXNE interrupt enable (RXNEIE)
                                                    0: Interrupt is inhibited
                                                    1: An USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register
                                                   */
             
#define IDLE_INTERRUPT_ENABLE 0                    /* IDLE interrupt enable (IDLEIE)
                                                     0: Interrupt is inhibited
                                                     1: An USART interrupt is generated whenever IDLE=1 in the USART_SR register
                                                   */

#define TRANSMITTER_ENABLE 1                       /* Transmitter enable (TE)
                                                     0: Transmitter is disabled
                                                     1: Transmitter is enabled
                                                     Note: During transmission, a "0" pulse on the TE bit ("0" followed by "1") sends a preamble (idle line) after the current word, except in smart card mode. When TE is set, there is a 1 bit-time delay before the transmission starts.
                                                   */
             
#define RECEIVER_ENABLE 1                          /* Receiver enable (RE)
                                                     0: Receiver is disabled
                                                     1: Receiver is enabled and begins searching for a start bit
                                                   */

#define SEND_BREAK 0                               /* Send break (SBK)
                                                     0: No break character is transmitted
                                                     1: Break character will be transmitted
                                                   */

/*               CR2 Bits               */
#define LINEN 0                                     /* LIN mode enable (LINEN)
                                                       0: LIN mode disabled
                                                       1: LIN mode enabled
                                                       The LIN mode enables the capability to send LIN Synch Breaks (13 low bits) using the SBK bit in the USART_CR1 register, and to detect LIN Sync breaks.
                                                    */

#define STOP_BIT0 0                             
#define STOP_BIT1 0                                 /* STOP bits (STOP)
                                                      00: 1 Stop bit
                                                      01: 0.5 Stop bit
                                                      10: 2 Stop bits
                                                      11: 1.5 Stop bit
                                                    */

#define CLKEN 0                                     /* Clock enable (CLKEN)
                                                      0: CK pin disabled
                                                      1: CK pin enabled
                                                    */

#define CPOL 0                                      /* Clock polarity (CPOL)
                                                      0: Steady low value on CK pin outside the transmission window.
                                                      1: Steady high value on CK pin outside the transmission window.
                                                    */

#define CPHA 0                                      /* Clock phase (CPHA)
                                                       0: The first clock transition is the first data capture edge
                                                       1: The second clock transition is the first data capture edge
                                                       Note: See figures 179 to 180 for details.
                                                    */

#define LBCL 0                                      /* Last bit clock pulse (LBCL)
                                                       0: The clock pulse of the last data bit is not output to the CK pin
                                                       1: The clock pulse of the last data bit is output to the CK pin
                                                       1: The last bit is the 8th or 9th data bit transmitted depending on the 8 or 9 bit format selected by the M bit in the USART_CR1 register.
                                                    */

#define LBDIE 0                                     /* LIN break detection interrupt enable (LBDIE)
                                                      Break interrupt mask (break detection using break delimiter).
                                                      0: Interrupt is inhibited
                                                      1: An interrupt is generated whenever LBD=1 in the USART_SR register
                                                    */

#define LBDL 0                                      /* LIN break detection length (LBDL)
                                                      This bit is for selection between 11-bit or 10-bit break detection.
                                                      0: 10-bit break detection
                                                      1: 11-bit break detection
                                                    */

#define ADD_MASK0 0
#define ADD_MASK1 0  
#define ADD_MASK2 0 
#define ADD_MASK3 0                                 /* Address of the USART node bit mask (ADD[3:0])
                                                      This bit-field gives the address of the USART node. It is used in multiprocessor communication during mute mode for wake-up with address mark detection.
                                                    */

/* Define CR1 using CONCATENATE_16_BITS */
#define USART_CR1 CONCATENATE_16_BITS(SEND_BREAK, RECEIVER_WAKEUP, RECEIVER_ENABLE, TRANSMITTER_ENABLE, IDLE_INTERRUPT_ENABLE, \
                               RXNE_INTERRUPT_ENABLE, TRANSMISSION_COMPLETE_INTERRUPT_ENABLE, TXE_INTERRUPT_ENABLE, PE_INTERRUPT_ENABLE, \
                               PARITY_SELECTION, PARITY_CONTROL_ENABLE, WAKEUP_METHOD, WORD_LENGTH, USART_ENABLE, \
                               0, OVER8_16)

/* Define CR2 using CONCATENATE_16_BITS */
#define USART_CR2 CONCATENATE_16_BITS(ADD_MASK0, ADD_MASK1, ADD_MASK2, ADD_MASK3, 0, LBDL, LBDIE, 0, \
                                     LBCL, CPHA, CPOL, CLKEN, STOP_BIT0, STOP_BIT1, LINEN, 0)


#define CONCATENATE_16_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15) \
    ((b0) | ((b1) << 1) | ((b2) << 2) | ((b3) << 3) | ((b4) << 4) | ((b5) << 5) | ((b6) << 6) | \
     ((b7) << 7) | ((b8) << 8) | ((b9) << 9) | ((b10) << 10) | ((b11) << 11) | ((b12) << 12) | \
     ((b13) << 13) | ((b14) << 14) | ((b15) << 15))

/* Function-like macro to extract the fractional part */
#define EXTRACT_FRACTION(x) ((x) - (int)(x))

#endif
