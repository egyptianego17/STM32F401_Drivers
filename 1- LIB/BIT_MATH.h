#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#define MODIFY_REGISTER_BITS(REG, START_BIT, END_BIT, VALUE) \
    u32 BITMASK = ((1U << ((END_BIT) - (START_BIT) + 1)) - 1) << (START_BIT); \
    (REG) = ((REG) & ~BITMASK) | (((VALUE) << (START_BIT)) & BITMASK); \

#endif