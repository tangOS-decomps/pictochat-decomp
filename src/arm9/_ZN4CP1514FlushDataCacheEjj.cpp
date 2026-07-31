// decomp: module=unk_autoload_0 addr=0x023314e8 name=_ZN4CP1514FlushDataCacheEjj
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP1514FlushDataCacheEjj.c. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN4CP1514FlushDataCacheEjj --addr 0x023314e8 --size 0x1c --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
asm void _ZN4CP1514FlushDataCacheEjj(unsigned int addr, unsigned int size){
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c10, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}
