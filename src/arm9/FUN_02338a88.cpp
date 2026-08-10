//cpp
// decomp: module=unk_autoload_0 addr=0x02338a88 name=FUN_02338a88
// flags: -noThumb
//
// Saves the DIV/SQRT hardware-unit register context. FUN_02331148 calls this
// while saving a CPU context, and FUN_02338ac8 is its inverse restore primitive.
// The block transfers and fixed hardware-register ordering are the primitive's
// specification, so this is kept in its original assembly form.
extern "C" asm void FUN_02338a88(void *out)
{
    ldr     r1, [pc, #0x34]
    stmdb   sp!, {r4}
    ldmia   r1, {r2, r3, r4, r12}
    stmia   r0!, {r2, r3, r4, r12}
    ldrh    r12, [r1, #-0x10]
    add     r1, r1, #0x28
    ldmia   r1, {r2, r3}
    stmia   r0!, {r2, r3}
    and     r12, r12, #3
    ldrh    r2, [r1, #-8]
    strh    r12, [r0]
    and     r2, r2, #1
    strh    r2, [r0, #2]
    ldmia   sp!, {r4}
    bx      lr
    DCD     0x04000290
}
