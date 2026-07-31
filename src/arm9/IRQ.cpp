// ==========================================================
// C++ Class Implementation: IRQ
// ==========================================================

// --- _ZN3IRQ7DisableEv_02332080.cpp ---
//cpp
// decomp: module=unk_autoload_0 addr=0x02332080 name=_ZN3IRQ7DisableEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN3IRQ7DisableEv.cpp. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN3IRQ7DisableEv --addr 0x02332080 --size 0x14 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
extern "C" unsigned int _ZN3IRQ7DisableEv(void);
extern "C" asm unsigned int _ZN3IRQ7DisableEv(void)
{
    mrs r0, cpsr
    orr r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// --- _ZN3IRQ7RestoreEj_02332094.cpp ---
//cpp
// decomp: module=unk_autoload_0 addr=0x02332094 name=_ZN3IRQ7RestoreEj
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN3IRQ7RestoreEj.cpp. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN3IRQ7RestoreEj --addr 0x02332094 --size 0x18 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
extern "C" unsigned int _ZN3IRQ7RestoreEj(unsigned int);
extern "C" asm unsigned int _ZN3IRQ7RestoreEj(unsigned int)
{
    mrs r1, cpsr
    bic r2, r1, #0x80
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0x80
    bx lr
}

// --- _ZN3IRQ10DisableAllEv_023320ac.cpp ---
//cpp
// decomp: module=unk_autoload_0 addr=0x023320ac name=_ZN3IRQ10DisableAllEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN3IRQ10DisableAllEv.cpp. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN3IRQ10DisableAllEv --addr 0x023320ac --size 0x14 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
extern "C" unsigned int _ZN3IRQ10DisableAllEv(void);
extern "C" asm unsigned int _ZN3IRQ10DisableAllEv(void)
{
    mrs r0, cpsr
    orr r1, r0, #0xc0
    msr cpsr_c, r1
    and r0, r0, #0xc0
    bx lr
}

// --- _ZN3IRQ10RestoreAllEj_023320c0.cpp ---
//cpp
// decomp: module=unk_autoload_0 addr=0x023320c0 name=_ZN3IRQ10RestoreAllEj
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN3IRQ10RestoreAllEj.cpp. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN3IRQ10RestoreAllEj --addr 0x023320c0 --size 0x18 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
extern "C" unsigned int _ZN3IRQ10RestoreAllEj(unsigned int);
extern "C" asm unsigned int _ZN3IRQ10RestoreAllEj(unsigned int)
{
    mrs r1, cpsr
    bic r2, r1, #0xc0
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0xc0
    bx lr
}

// --- _ZN3IRQ6EnableEv.cpp ---
//cpp
// decomp: module=unk_autoload_0 addr=0x0233206c name=_ZN3IRQ6EnableEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN3IRQ6EnableEv.cpp. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN3IRQ6EnableEv --addr 0x0233206c --size 0x14 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
extern "C" unsigned int _ZN3IRQ6EnableEv(void);
extern "C" asm unsigned int _ZN3IRQ6EnableEv(void)
{
    mrs r0, cpsr
    bic r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

