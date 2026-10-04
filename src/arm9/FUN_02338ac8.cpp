//cpp
// decomp: module=unk_autoload_0 addr=0x02338ac8 name=FUN_02338ac8
// flags: -O4,p -noThumb

// Restore the hardware divider/sqrt unit state (numerator/denominator, sqrt
// parameter, DIVCNT, SQRTCNT) from a saved context. Assembly in the original
// SDK runtime.
extern "C" {
asm void FUN_02338ac8(const void *ctx)
{
    stmfd sp!, {r4}
    ldr r1, =0x04000290
    ldmia r0, {r2-r4, ip}
    stmia r1, {r2-r4, ip}
    ldrh r2, [r0, #0x18]
    ldrh r3, [r0, #0x1a]
    strh r2, [r1, #-0x10]
    strh r3, [r1, #0x20]
    add r0, r0, #0x10
    add r1, r1, #0x28
    ldmia r0, {r2-r3}
    stmia r1, {r2-r3}
    ldmfd sp!, {r4}
    bx lr
}
}
