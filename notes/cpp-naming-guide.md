# C++ Naming Guide

This guide explains the C++ naming conventions and Itanium ABI mangling rules used in the PictoChat decompilation project (`pictochat-decomp`). Understanding these is essential for writing C++ code that matches the original symbols and vtable structures.

## 1. Itanium ABI Name Mangling Quick Reference

The compiler (`mwccarm`) uses the standard Itanium C++ ABI for mangling symbols.

*   `_Z` - Mangled name prefix. All C++ symbols start with this.
*   `N...E` - Nested name sequence (used for classes/namespaces). The `N` begins the nesting, `E` ends it.
*   **Length-Prefixed Names:** Identifiers are prefixed by their length in characters (e.g., `3IRQ` for `IRQ`, `4CP15` for `CP15`).

### Type Codes (Arguments & Returns)
*   `v` = `void`
*   `b` = `bool`
*   `c` = `char`
*   `h` = `unsigned char`
*   `s` = `short`
*   `t` = `unsigned short`
*   `i` = `int`
*   `j` = `unsigned int`
*   `l` = `long`
*   `m` = `unsigned long`
*   `x` = `long long`
*   `y` = `unsigned long long`
*   `f` = `float`
*   `d` = `double`

### Qualifiers
*   `P` = Pointer (`*`)
*   `R` = Reference (`&`)
*   `K` = `const`

### Real PictoChat Examples
*   `_ZN3IRQ10DisableAllEv` &rarr; `IRQ::DisableAll(void)`
*   `_ZN3IRQ10RestoreAllEj` &rarr; `IRQ::RestoreAll(unsigned int)`
*   `_ZN4CP1510DisableMPUEv` &rarr; `CP15::DisableMPU(void)`
*   `_ZN4CP1514FlushDataCacheEjj` &rarr; `CP15::FlushDataCache(unsigned int, unsigned int)`

## 2. Constructor & Destructor Variants

In C++, constructors and destructors have multiple variants in the compiled object file to handle virtual inheritance and allocation.

*   **Constructors:**
    *   `C1` - Complete object constructor.
    *   `C2` - Base object constructor.
    *   `C3` - Allocating constructor.
*   **Destructors:**
    *   `D0` - Deleting destructor (destroys the object and calls `delete`/deallocator).
    *   `D1` - Complete object destructor.
    *   `D2` - Base object destructor.

## 3. Thunks Explained

Thunks are small compiler-generated functions that adjust the `this` pointer before jumping to the actual function implementation.

*   `_ZThn<offset>_` - Non-virtual `this`-adjustment thunk.
*   `_ZTv<voff>_n<off>_` - Virtual `this`-adjustment thunk.

## 4. File Naming Conventions & Reorganization

All source files in `src/arm9/` and `src/arm7/` use `.cpp` extensions:

*   **Extensions:** Use `.cpp` for source files in `src/`.
*   **The `//cpp` Marker:** Place `//cpp` on the first line of C++ source files.
*   **`extern "C"` Patterns:** Wrap unmangled C-linkage functions or system primitives in `extern "C"`.
*   **One Function per File:** Each file contains one function, named after its symbol (e.g. `_ZN3IRQ10DisableAllEv_023320ac.cpp` or `FUN_02320e14.cpp`).

## 5. Tooling Reference

*   **Demangle a Symbol:** `python tools/demangle.py _ZN4CP1514FlushDataCacheEjj`
*   **Class Summary / Index:** `python tools/cpp_index.py --class CP15`
*   **Rename Verified Functions:** `python tools/cpp_rename.py --dry-run`
*   **Batch-Verify Mangled Functions:** `python tools/verify_mangled.py`
