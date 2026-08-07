// decomp: module=arm7 addr=0x022c565c name=FUN_022c565c
// flags: -O4,s -noThumb
//
// Exception-return / context-restore primitive.  Takes the saved context block
// in r0: switches into SVC mode with IRQ+FIQ masked, reloads SPSR from the
// first word, restores the exception mode's own sp/lr from +0x40/+0x3c, then
// bulk-restores the user-bank registers r0-lr with an `ldm ^` and returns to
// the interrupted instruction with `subs pc, lr, #4`.
//
// HAND-ASM PRIMITIVE: byte-faithful asm-block match.  This was assembly in the
// original (CPSR/SPSR bank switching, user-bank ldm, and an S-bit pc write have
// no C spelling at all), so the asm block is the faithful source, not a
// transcription of a compiled function.  Counts as matched under the
// asm-primitive policy - cf. src/arm7/_ZN3IRQ10DisableAllEv_022c6d6c.cpp.

extern void FUN_022c565c(void *ctx);

asm void FUN_022c565c(void *ctx)
{
    mrs     r1, cpsr
    bic     r1, r1, #0x1f
    orr     r1, r1, #0xd3
    msr     cpsr_c, r1
    ldr     r1, [r0], #4
    msr     spsr_fsxc, r1
    ldr     sp, [r0, #0x40]
    ldr     lr, [r0, #0x3c]
    ldmia   r0, {r0-lr}^
    mov     r0, r0
    subs    pc, lr, #4
}
