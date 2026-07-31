// decomp: module=unk_autoload_0 addr=0x0233146c name=_ZN4CP1514FlushDataCacheEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP1514FlushDataCacheEv.c. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN4CP1514FlushDataCacheEv --addr 0x0233146c --size 0x2c --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
asm void _ZN4CP1514FlushDataCacheEv(void){
    mov r1, #0
outer:
    mov r0, #0
seg:
    orr r2, r1, r0
    mcr p15, 0, r2, c7, c10, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt seg
    add r1, r1, #0x40000000
    cmp r1, #0
    bne outer
    bx lr
}
