// ==========================================================
// C++ Class Implementation: CP15
// ==========================================================

// --- _ZN4CP159EnableMPUEv.cpp ---
// decomp: module=unk_autoload_0 addr=0x023317a4 name=_ZN4CP159EnableMPUEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP159EnableMPUEv.c. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN4CP159EnableMPUEv --addr 0x023317a4 --size 0x10 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
unsigned int _ZN4CP159EnableMPUEv(void){
    unsigned int v;
    asm { mrc p15,0,v,c1,c0,0 }
    v |= 1;
    asm { mcr p15,0,v,c1,c0,0 }
    return v;
}

// --- _ZN4CP1510DisableMPUEv.cpp ---
// decomp: module=unk_autoload_0 addr=0x023317b4 name=_ZN4CP1510DisableMPUEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP1510DisableMPUEv.c. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN4CP1510DisableMPUEv --addr 0x023317b4 --size 0x10 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
unsigned int _ZN4CP1510DisableMPUEv(void){
    unsigned int v;
    asm { mrc p15,0,v,c1,c0,0 }
    asm { bic v,v,#1 }
    asm { mcr p15,0,v,c1,c0,0 }
    return v;
}

// --- _ZN4CP1514FlushDataCacheEv.cpp ---
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

// --- _ZN4CP1514FlushDataCacheEjj.cpp ---
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

// --- _ZN4CP1516DrainWriteBufferEv.cpp ---
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

// --- _ZN4CP1516WaitForInterruptEv.cpp ---
// decomp: module=unk_autoload_0 addr=0x0233229c name=_ZN4CP1516WaitForInterruptEv
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP1516WaitForInterruptEv.c. CP15 system-control coprocessor
// primitive (SDK hardware abstraction layer), not game-specific code. See
// notes/cross-project-matching.md.
//
// NOTE: unlike every other matched function so far, this one does NOT
// compile byte-identical on any dsi/ build - only the NTR-era 1.2/* family
// (verified: tools/match.py --func _ZN4CP1516WaitForInterruptEv --addr
// 0x0233229c --size 0xc --module unk_autoload_0 --version 1.2/sp2p3 --flags
// "-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e
// -gccext,on -msgstyle gcc"). Every dsi/ build instead materializes the
// local `v = 0` via a literal-pool load instead of `mov r0,#0` - likely an
// optimizer-heuristic change between the compiler families, not evidence
// this ROM used 1.2/*: every other matched function only lines up on dsi/,
// and tools/probe_versions.py finds the whole dsi/ family codegen-identical
// for everything tried so far. Flagged here in case a pattern emerges.
void _ZN4CP1516WaitForInterruptEv(void){
    unsigned int v = 0;
    asm { mcr p15,0,v,c7,c0,4 }
}

// --- _ZN4CP1519InvalidateDataCacheEjj.cpp ---
// decomp: module=unk_autoload_0 addr=0x023314cc name=_ZN4CP1519InvalidateDataCacheEjj
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/_ZN4CP1519InvalidateDataCacheEjj.c. Compiles byte-identical here too (verified: tools/match.py
// --func _ZN4CP1519InvalidateDataCacheEjj --addr 0x023314cc --size 0x1c --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
asm void _ZN4CP1519InvalidateDataCacheEjj(unsigned int addr, unsigned int size){
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c6, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

