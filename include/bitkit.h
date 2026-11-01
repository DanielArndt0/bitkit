#ifndef BITKIT_H
#define BITKIT_H

#include <limits.h>

#define BIT_WIDTH(value) (sizeof(value) * CHAR_BIT)
#define BIT_MASK(bit) (((unsigned long long)(bit) < 64ULL) ? (1ULL << (bit)) : 0ULL)
#define BIT_SET(value, bit) ((value) |= BIT_MASK(bit))
#define BIT_CLEAR(value, bit) ((value) &= ~BIT_MASK(bit))
#define BIT_TEST(value, bit) ((((unsigned long long)(value)) & BIT_MASK(bit)) != 0ULL)
#define BIT_TOGGLE(value, bit) ((value) ^= BIT_MASK(bit))
#define BIT_WRITE(value, bit, state) ((state) ? BIT_SET(value, bit) : BIT_CLEAR(value, bit))
#define BIT_AND(value, mask) ((value) & (mask))

#define BITKIT_WIDTH_MASK(value) (~0ULL >> ((sizeof(0ULL) * CHAR_BIT) - BIT_WIDTH(value)))
#define BIT_SHL(value, shift) (((unsigned long long)(shift) < BIT_WIDTH(value)) ? ((((unsigned long long)(value)) << (shift)) & BITKIT_WIDTH_MASK(value)) : 0ULL)
#define BIT_SHR(value, shift) (((unsigned long long)(shift) < BIT_WIDTH(value)) ? ((((unsigned long long)(value)) & BITKIT_WIDTH_MASK(value)) >> (shift)) : 0ULL)

#define BYTE_LOW(value) (((unsigned long long)(value)) & 0xFFULL)
#define BYTE_SHR(value) (((unsigned long long)(value)) >> 8U)

#endif
