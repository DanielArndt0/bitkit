# bitkit

A lightweight, header-only collection of bitwise macros for C and C++.

bitkit provides bit manipulation, width-aware shifts, masking, and byte extraction for unsigned 8, 16, 32, and 64-bit integers.

## Requirements

- C99 or later, or C++11 or later
- CMake 3.16 or later for CMake integration

## Usage

```c
#include <stdint.h>
#include "bitkit.h"

int main(void)
{
    uint32_t flags = 0;

    BIT_SET(flags, 7);
    BIT_WRITE(flags, 3, 1);

    return BIT_TEST(flags, 7) && BIT_TEST(flags, 3) ? 0 : 1;
}
```

For additional examples and API documentation, see [Usage Documentation](docs/usage.md).

## Manual Integration

Download [bitkit.h](https://github.com/DanielArndt0/bitkit/blob/main/include/bitkit.h) from the repository and add it to your project's include directory.

Include the header using `#include "bitkit.h"`. No additional dependencies or separate compilation are required.

## CMake Integration

bitkit can be integrated directly from GitHub using CMake's `FetchContent` module.

Add the following to your project's `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    bitkit
    GIT_REPOSITORY https://github.com/DanielArndt0/bitkit.git
    GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(bitkit)

target_link_libraries(my_target PRIVATE bitkit::bitkit)
```

Replace `my_target` with your application's CMake target.

If you already have the bitkit source directory inside your CMake project, you can add it instead:

```cmake
add_subdirectory(path/to/bitkit)
target_link_libraries(my_target PRIVATE bitkit::bitkit)
```

bitkit is header-only and does not require a separately compiled binary.

## Compatibility

bitkit uses standard C99/C++11 integer operations and the standard `<limits.h>` header. It does not depend on Arduino, ESP32, or other platform-specific APIs.

Use unsigned integer types with widths of 8, 16, 32, or 64 bits. Macro arguments representing bit positions or shifts should not have side effects. Consult the usage documentation for width and register limitations.

## Disclaimer

bitkit is developed for educational purposes and experimentation with bitwise operations and macros.

It is not intended to replace platform-specific register APIs or synchronization mechanisms.
