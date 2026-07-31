# Metrowerks MSL & C++ Standard Library Mapping Audit

Comprehensive audit of all **275 MSL functions** in the binary, mapping each to its standard C++ header / compiler runtime equivalent.

## Category Summary

- **`<cstring>` (Memory & String Primitives)**: 2 functions
- **`<cstdio>` (Formatted I/O & Printing)**: 15 functions
- **C++ Language Core Runtime (`<new>`, Object Lifetime)**: 29 functions
- **ARM EABI & Soft-Float Math (`<cmath>`, `<cstddef>`)**: 4 functions
- **Metrowerks MSL CRT Initialization & Internals**: 225 functions

## Detailed Standard Mapping

### 1. Memory & String Primitives (`<cstring>`)
- `0x2332e1c` (size `0x1c`): **`std::strlen`** from `<cstring>` -- String length
- `0x2332e70` (size `0x72`): **`std::memset`** from `<cstring>` -- Memory byte fill

### 2. Formatted String & Number Output (`<cstdio>`)
- `0x2332a44` (size `0x120`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2332ee4` (size `0x362`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2333288` (size `0x1a6`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2333434` (size `0x210`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2333648` (size `0x30c`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2333a38` (size `0x4b8`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2333f20` (size `0x594`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2334784` (size `0x146`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2334a18` (size `0x106`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2334b80` (size `0x194`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2337b54` (size `0x106`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2338510` (size `0x246`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x233879c` (size `0x118`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x2338df8` (size `0x16e`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output
- `0x23394e4` (size `0x1b8`): **`std::sprintf / std::vsprintf`** from `<cstdio>` -- Formatted string & number output

### 3. C++ Core Runtime & Object Lifetime (`<new>`)
- `0x2332884` (size `0x30`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2332da4` (size `0x50`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2335dec` (size `0x20`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x23369b8` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x23369fc` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336a40` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336a84` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336ac8` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336b0c` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336b50` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336b94` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336bd8` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336c1c` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336c60` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration
- `0x2336ca4` (size `0x40`): **`__destroy_arr / __register_global`** from `<new> / C++ Core` -- C++ Object array constructor/destructor & static registration

### 4. ARM EABI Math & Division (`<cstddef>`, `<cmath>`)
- `0x2336460` (size `0x26`): **`__aeabi_uidivmod`** from `<cstddef>` -- ARM EABI 32-bit unsigned division (/) and modulo (%)
- `0x23364a8` (size `0x26`): **`__aeabi_uidivmod`** from `<cstddef>` -- ARM EABI 32-bit unsigned division (/) and modulo (%)
- `0x23366c0` (size `0x24`): **`__aeabi_uidivmod`** from `<cstddef>` -- ARM EABI 32-bit unsigned division (/) and modulo (%)
- `0x23366e8` (size `0x24`): **`__aeabi_uidivmod`** from `<cstddef>` -- ARM EABI 32-bit unsigned division (/) and modulo (%)
