// ==========================================================
// C++ Class Implementation: MultiCopy
// ==========================================================

// --- MultiCopy32Bytes.cpp ---
// decomp: module=unk_autoload_0 addr=0x023374b8 name=MultiCopy32Bytes
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiCopy32Bytes.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiCopy32Bytes --addr 0x023374b8 --size 0x38 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
asm void MultiCopy32Bytes(int *src, int *dst, int len) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10}
    add r10, r1, r2
    mov ip, r2, lsr #5
    add ip, r1, ip, lsl #5
loop32:
    cmp r1, ip
    ldmltia r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    stmltia r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    blt loop32
loop4:
    cmp r1, r10
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt loop4
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10}
    bx lr
}

// --- MultiCopyHalf.cpp ---
// decomp: module=unk_autoload_0 addr=0x02337424 name=MultiCopyHalf
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiCopyHalf.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiCopyHalf --addr 0x02337424 --size 0x1c --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
asm void MultiCopyHalf(void)
{
    mov ip, #0
loop:
    cmp ip, r2
    ldrlth r3, [r0, ip]
    strlth r3, [r1, ip]
    addlt ip, ip, #2
    blt loop
    bx lr
}

// --- MultiCopy_Int.cpp ---
// decomp: module=unk_autoload_0 addr=0x02337454 name=MultiCopy_Int
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiCopy_Int.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiCopy_Int --addr 0x02337454 --size 0x18 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match. This function was assembly
// in the original (SDK/runtime primitive: block copy, matrix/math, CP15, context
// switch, etc.), so there is no C to decompile it to -- the asm block is the
// faithful source. Counts as matched (asm-primitive policy), not a C transcription.
asm void MultiCopy_Int(int *dst, int *src, int len)
{
    add ip, r1, r2
loop:
    cmp r1, ip
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt loop
    bx lr
}

// --- MultiStore16.cpp ---
// decomp: module=unk_autoload_0 addr=0x0233740c name=MultiStore16
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiStore16.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiStore16 --addr 0x0233740c --size 0x18 --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
//
// NOTE: this one is compiled ARM-mode in the real binary despite being plain C
// (no asm block for match.py's auto-detect to key off) - pass
// --flags "-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc"
// (i.e. the default minus -thumb) to reproduce the match.
void MultiStore16(short val, char *dst, int nbytes) {
    int i = 0;
    do {
        if (i < nbytes) {
            *(short*)(dst + i) = val;
            i += 2;
        } else break;
    } while (1);
}

// --- MultiStore32Bytes.cpp ---
// decomp: module=unk_autoload_0 addr=0x0233746c name=MultiStore32Bytes
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiStore32Bytes.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiStore32Bytes --addr 0x0233746c --size 0x4c --module unk_autoload_0
// --version dsi/1.3) - this is a compiler-runtime/SDK primitive (MSL or
// NitroSDK/TwlSDK hardware abstraction layer) statically linked unchanged
// across both projects, not game-specific code. See notes/cross-project-matching.md.
// HAND-ASM PRIMITIVE: byte-faithful asm-block match (assembly-only primitive). Per asm policy.
asm void MultiStore32Bytes(unsigned val, int *dst, int len) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9}
    add r9, r1, r2
    mov ip, r2, lsr #5
    add ip, r1, ip, lsl #5
    mov r2, r0
    mov r3, r2
    mov r4, r2
    mov r5, r2
    mov r6, r2
    mov r7, r2
    mov r8, r2
loop32:
    cmp r1, ip
    stmltia r1!, {r0, r2, r3, r4, r5, r6, r7, r8}
    blt loop32
loop4:
    cmp r1, r9
    stmltia r1!, {r0}
    blt loop4
    ldmia sp!, {r4, r5, r6, r7, r8, r9}
    bx lr
}

// --- MultiStore_Int_02000d3c.cpp ---
// decomp: module=main addr=0x02000d3c name=MultiStore_Int
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiStore_Int.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiStore_Int --addr 0x02000d3c --size 0x14 --module main
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

// --- MultiStore_Int_02337440.cpp ---
// decomp: module=unk_autoload_0 addr=0x02337440 name=MultiStore_Int
// Cross-matched from sm64ds-decomp (https://github.com/tangosdev/sm64ds-decomp),
// src/MultiStore_Int.c. Compiles byte-identical here too (verified: tools/match.py
// --func MultiStore_Int --addr 0x02337440 --size 0x14 --module unk_autoload_0
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

