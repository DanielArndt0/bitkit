# bitkit Usage

bitkit contains portable, header-only macros for unsigned 8, 16, 32, and 64-bit integer operations in C99 and C++11 or later.

## Bit Operations

```c
#include <stdint.h>
#include "bitkit.h"

uint8_t flags = 0;

BIT_SET(flags, 3);
BIT_TEST(flags, 3);
BIT_CLEAR(flags, 3);
BIT_TOGGLE(flags, 2);
BIT_WRITE(flags, 7, 1);
BIT_WRITE(flags, 7, 0);
```

`BIT_TEST(value, bit)` returns a truth value. `BIT_WRITE(value, bit, state)` sets the bit for any nonzero state and clears it for zero.

## Masks and Shifts

```c
uint16_t value = 0x1234;

unsigned long long mask = BIT_MASK(15);
unsigned long long shifted = BIT_SHL(value, 2);
unsigned long long reduced = BIT_SHR(value, 4);
unsigned int masked = BIT_AND(value, 0x00FFU);
```

`BIT_MASK(bit)` produces a 64-bit unsigned mask. Values below zero or greater than 63 produce zero.

`BIT_SHL` and `BIT_SHR` operate on unsigned values and return an unsigned 64-bit-or-wider result, limited to the width of the input expression. A shift outside that width returns zero.

```c
uint8_t high = 0x80;

BIT_SHL(high, 1);
```

The last expression evaluates to `0`, since the shifted bit no longer fits in an 8-bit value.

## Byte Operations

```c
uint32_t word = 0x12345678U;

BYTE_LOW(word);
BYTE_SHR(word);
```

Results:

```text
BYTE_LOW(word) = 0x78
BYTE_SHR(word) = 0x123456
```

`BYTE_SHR` shifts the entire value eight bits to the right. It does not isolate a single upper byte.

## Supported Widths

```c
uint8_t u8 = 0;
uint16_t u16 = 0;
uint32_t u32 = 0;
uint64_t u64 = 0;

BIT_SET(u8, 7);
BIT_SET(u16, 15);
BIT_SET(u32, 31);
BIT_SET(u64, 63);
```

For mutation macros, the first argument must be a modifiable unsigned integer lvalue. A bit index beyond the value's width cannot be stored and therefore leaves that value unchanged.

## Limitations

- Use unsigned integer types. Signed shifts and signed assignments can have different or implementation-defined behavior.
- Do not pass expressions with side effects, such as `i++`, for bit indices or shift counts. Macros may evaluate those arguments more than once.
- `BIT_SHL` and `BIT_SHR` return an unsigned wide integer, not the original integer type.
- Read-modify-write operations are not atomic and may be inappropriate for hardware registers with special write semantics.
- The macros do not depend on microcontroller-specific headers and can be included in Arduino, ESP32, and ordinary C/C++ projects.
