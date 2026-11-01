#include "bitkit.h"

#include <cstdint>

int main()
{
    std::uint8_t small = 0;
    std::uint16_t medium = 0;
    std::uint32_t large = 0;
    std::uint64_t wide = 0;

    BIT_SET(small, 7);
    BIT_SET(medium, 15);
    BIT_SET(large, 31);
    BIT_SET(wide, 63);

    if (!BIT_TEST(small, 7) || !BIT_TEST(wide, 63))
        return 1;

    if (medium != 0x8000U || large != 0x80000000U)
        return 1;

    BIT_WRITE(small, 7, false);
    BIT_TOGGLE(small, 2);

    if (small != 4 || BIT_SHL(small, 1) != 8ULL)
        return 1;

    if (BIT_WIDTH(wide) != 64 || BIT_MASK(63) != (1ULL << 63))
        return 1;

    if (BIT_MASK(64) != 0ULL || BIT_SHR(wide, 64) != 0ULL)
        return 1;

    if (BYTE_LOW(0x1234U) != 0x34ULL || BYTE_SHR(0x1234U) != 0x12ULL)
        return 1;

    BIT_CLEAR(wide, 63);
    return wide == 0 ? 0 : 1;
}
