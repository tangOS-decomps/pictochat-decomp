//cpp
extern "C" {
// decomp: module=arm7 addr=0x022c6fc8 name=MultiStore_Int
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiStore_Int.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiStore_Int --addr 0x022c6fc8 --size 0x14 --module arm7
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
asm void MultiStore_Int(int val, int *dst, int len) {
    add ip, r1, r2
loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt loop
    bx lr
}

}
