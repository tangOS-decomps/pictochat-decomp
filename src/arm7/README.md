# src/arm7

Matched ARM7 functions, one per file, named after the function (or
`FUN_<hex_address>.cpp` if the real name isn't known yet). Nothing goes here
until `tools/match.py` reports a byte-identical match - see
[../../CONTRIBUTING.md](../../CONTRIBUTING.md) and
[../../notes/matching-style.md](../../notes/matching-style.md).

ARM7 handles the wireless hardware driver and IPC with ARM9; the whole image
is one flat module at `0x022c0000` (no autoload split, unlike ARM9 - see
[../../notes/pictochat-layout.md](../../notes/pictochat-layout.md)).
