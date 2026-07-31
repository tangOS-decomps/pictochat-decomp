# PictoChat Symbol & Function Classification

Functions are categorized into **App Space** (PictoChat Application Logic), **SDK Space** (Nintendo NITRO-SDK), and **MSL Space** (Metrowerks C/C++ Runtime).

## Space Breakdown

- **APP Space**: 800 functions (72.8%)
- **SDK Space**: 24 functions (2.2%)
- **MSL Space**: 275 functions (25.0%)

## Sample App Functions
- `FUN_01ff8000` @ `0x1ff8000` (size `0x50`): PictoChat Application Logic (< 0x02332800)
- `FUN_01ff81b4` @ `0x1ff81b4` (size `0x90`): PictoChat Application Logic (< 0x02332800)
- `FUN_01ff824c` @ `0x1ff824c` (size `0x1e`): PictoChat Application Logic (< 0x02332800)
- `_start` @ `0x2000c00` (size `0x118`): PictoChat Application Logic (< 0x02332800)
- `FUN_02000d3c` @ `0x2000d3c` (size `0x14`): PictoChat Application Logic (< 0x02332800)
- `FUN_02000d50` @ `0x2000d50` (size `0xac`): PictoChat Application Logic (< 0x02332800)
- `FUN_02000dfc` @ `0x2000dfc` (size `0x78`): PictoChat Application Logic (< 0x02332800)
- `FUN_02000e78` @ `0x2000e78` (size `0xb8`): PictoChat Application Logic (< 0x02332800)
- `FUN_02000f60` @ `0x2000f60` (size `0x4`): PictoChat Application Logic (< 0x02332800)
- `FUN_02320000` @ `0x2320000` (size `0x166`): PictoChat Application Logic (< 0x02332800)

## Sample SDK Functions
- `FUN_023202b0` @ `0x23202b0` (size `0x3a8`): Hardware IO Access (0x0400XXXX)
- `FUN_0232074c` @ `0x232074c` (size `0x1a4`): Display Engine VRAM Access
- `FUN_023247c8` @ `0x23247c8` (size `0x17a`): Display Engine VRAM Access
- `FUN_02324958` @ `0x2324958` (size `0x13c`): Display Engine VRAM Access
- `FUN_02326140` @ `0x2326140` (size `0x2d8`): Display Engine VRAM Access
- `FUN_02327e80` @ `0x2327e80` (size `0xd3c`): Display Engine VRAM Access
- `FUN_0232b410` @ `0x232b410` (size `0x252`): Display Engine VRAM Access
- `FUN_0232d4cc` @ `0x232d4cc` (size `0x26`): Display Engine VRAM Access
- `FUN_0232da88` @ `0x232da88` (size `0x4`): SWI BIOS System Call
- `FUN_0232e324` @ `0x232e324` (size `0xee`): Hardware IO Access (0x0400XXXX)

## Sample MSL Runtime Functions
- `FUN_02332884` @ `0x2332884` (size `0x30`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_023328b8` @ `0x23328b8` (size `0x24`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_023328e0` @ `0x23328e0` (size `0x36`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_0233291c` @ `0x233291c` (size `0x16`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_02332934` @ `0x2332934` (size `0x2e`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_02332964` @ `0x2332964` (size `0x64`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_023329cc` @ `0x23329cc` (size `0x64`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_02332a44` @ `0x2332a44` (size `0x120`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_02332be8` @ `0x2332be8` (size `0xe`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
- `FUN_02332c04` @ `0x2332c04` (size `0x52`): Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)
