#include "bitkit.h"

#include <stdint.h>

int main(void)
{
    uint8_t small = 0;
    uint8_t high_byte = UINT8_C(0x80);
    uint16_t medium = 0;
    uint32_t large = 0;
    uint64_t wide = 0;

    BIT_SET(small, 7);
    BIT_SET(medium, 15);
    BIT_SET(large, 31);
    BIT_SET(wide, 63);

    if (small != UINT8_C(0x80) || medium != UINT16_C(0x8000))
        return 1;

    if (large != UINT32_C(0x80000000) || wide != (UINT64_C(1) << 63))
        return 1;

    if (!BIT_TEST(wide, 63) || BIT_TEST(small, 6))
        return 1;

    BIT_TOGGLE(small, 7);
    BIT_WRITE(small, 3, 2);
    BIT_WRITE(small, 3, 0);

    if (small != 0 || BIT_SHR(wide, 63) != 1ULL)
        return 1;

    if (BIT_SHL(high_byte, 1) != 0ULL)
        return 1;

    if (BIT_MASK(64) != 0ULL || BIT_SHR(high_byte, 8) != 0ULL)
        return 1;

    BIT_SET(high_byte, 8);
    if (high_byte != UINT8_C(0x80))
        return 1;

    if (BYTE_LOW(UINT32_C(0x12345678)) != 0x78ULL)
        return 1;

    if (BYTE_SHR(UINT32_C(0x12345678)) != 0x123456ULL)
        return 1;

    BIT_CLEAR(medium, 15);
    return medium == 0 && BIT_AND(0xF0U, 0x30U) == 0x30U ? 0 : 1;
}
