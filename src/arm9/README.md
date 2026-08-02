# src/arm9

Matched ARM9 functions, one per file, named after the function (or
`FUN_<hex_address>.cpp` if the real name isn't known yet). Nothing goes here
until `tools/match.py` reports a byte-identical match - see
[../../CONTRIBUTING.md](../../CONTRIBUTING.md) and
[../../notes/matching-style.md](../../notes/matching-style.md).

Most real PictoChat logic lives in the `unk_autoload_0` module
(`0x02320000`+) - see [../../notes/pictochat-layout.md](../../notes/pictochat-layout.md)
before assuming an address belongs to the tiny `main` crt0 stub instead.
