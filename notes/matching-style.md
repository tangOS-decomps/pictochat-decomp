# Matching conventions

Adopted from `sm64ds-decomp` - same standard the N64 `sm64` project and the
whole pret/decomp community holds to.

## What counts as a match

Source that, compiled with the pinned `mwccarm` version and flags, produces
object code **byte-identical** to the real binary - every instruction word,
and every relocation slot pointing at the correct destination (a raw byte
diff alone would wildcard a wrong callee/global sitting in a reloc slot;
`tools/match.py` checks both).

Nothing is "close enough." A function that's off by one instruction is not
matched - keep iterating, or leave it unmatched and move on rather than
committing a near-miss as if it were done.

## File extensions and C++ reorganization

All source files in `src/arm9/` and `src/arm7/` are `.cpp` files.
PictoChat was originally written in C++. Put `//cpp` on the first line of
every C++ source file. Functions with C linkage should be wrapped in `extern "C"`.

## One function per file

`src/arm9/<name>.cpp` or `src/arm7/<name>.cpp`, named after the function's real
symbol name if known (e.g. `_ZN3IRQ10DisableAllEv.cpp`), otherwise `FUN_<hex_address>.cpp`.
Small groups of tightly related functions (e.g. a getter/setter pair) in one file are fine;
whole subsystems in one file are not.

## C++ Demangling & Class Indexing Tools

See `notes/cpp-naming-guide.md` for full details on Itanium C++ name mangling,
constructor/destructor variants, thunk signatures, and tool usage:

- `python tools/demangle.py <symbol>`: Demangle Itanium C++ names.
- `python tools/cpp_index.py`: Class-level summary and progress tracking.
- `python tools/cpp_rename.py`: Safely rename `FUN_ADDR.cpp` files to demangled symbol names.
- `python tools/verify_mangled.py`: Batch verify C++ functions match byte-for-byte.

## Import knowledge, write code

You may use publicly known symbol names, struct layouts, or field offsets
(from community reverse-engineering of PictoChat/NitroSDK/TWL SDK) -
but all code in `src/` must be written from scratch against this project's own
extracted binary. Never paste source from another project.

## Workflow

1. Pick an unmatched function. `python tools/disasm.py --module <mod> --addr
   0x... --length 0x...` to read it (or open it in Ghidra - see
   `notes/ghidra-setup.md`).
2. Write C++ for it.
3. `python tools/match.py --c yourfile.cpp --func name --addr 0x... --size 0x..
   --module <mod>` and iterate until every word matches.
4. Move the finished file into `src/<cpu>/`.
