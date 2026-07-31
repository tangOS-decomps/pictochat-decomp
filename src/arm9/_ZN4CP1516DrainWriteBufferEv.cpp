// decomp: module=unk_autoload_0 addr=0x02331528 name=_ZN4CP1516DrainWriteBufferEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP1516DrainWriteBufferEv.c. Compiles byte-identical here too (verified:
// tools/match.py --func _ZN4CP1516DrainWriteBufferEv --addr 0x02331528 --size 0xc
// --module unk_autoload_0 --version dsi/1.3) - this is a compiler-runtime/SDK
// primitive (NitroSDK/TwlSDK hardware abstraction layer) statically linked
// unchanged across both projects, not game-specific code. See
// notes/cross-project-matching.md.
asm void _ZN4CP1516DrainWriteBufferEv(void){
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}
