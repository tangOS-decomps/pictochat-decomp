//cpp
// decomp: module=arm7 addr=0x022c3fc4 name=FUN_022c3fc4
// flags: -noThumb
extern "C" {

// HAND-ASM PRIMITIVE: 64-bit integer multiply runtime helper. The target is
// the conventional ARM UMULL/MLA implementation; compiling the equivalent C
// uses ip/lr instead of the runtime's callee-saved r4/r5 pair.
asm unsigned long long FUN_022c3fc4(unsigned long long left,
                                    unsigned long long right)
{
    stmdb sp!, {r4, r5, lr}
    umull r5, r4, r0, r2
    mla r4, r0, r3, r4
    mla r4, r2, r1, r4
    mov r1, r4
    mov r0, r5
    ldmia sp!, {r4, r5, lr}
    bx lr
}

}
