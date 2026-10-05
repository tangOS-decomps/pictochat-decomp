//cpp
// decomp: module=unk_autoload_0 addr=0x02337584 name=FUN_02337584
// flags: -noThumb

// Byte copy (MI_CpuCopy8): copies `size` bytes from `src` to `dst` using only
// halfword and word accesses. A leading/trailing odd byte is merged into the
// neighbouring destination halfword; when src and dst differ in halfword
// parity the bytes are re-aligned through a shift register. Hand-written ARM
// in the original SDK, like its neighbours FUN_023374b8 and FUN_023374f0.
extern "C" {
asm void FUN_02337584(const void *src, void *dst, unsigned int size)
{
    cmp r2, #0
    bxeq lr
    tst r1, #1
    beq @dst_even
    ldrh ip, [r1, #-1]
    and ip, ip, #0xff
    tst r0, #1
    ldrneh r3, [r0, #-1]
    movne r3, r3, lsr #8
    ldreqh r3, [r0]
    orr r3, ip, r3, lsl #8
    strh r3, [r1, #-1]
    add r0, r0, #1
    add r1, r1, #1
    subs r2, r2, #1
    bxeq lr
@dst_even:
    eor ip, r1, r0
    tst ip, #1
    beq @same_parity
    bic r0, r0, #1
    ldrh ip, [r0], #2
    mov r3, ip, lsr #8
    subs r2, r2, #2
    blo @shift_tail
@shift_loop:
    ldrh ip, [r0], #2
    orr ip, r3, ip, lsl #8
    strh ip, [r1], #2
    mov r3, ip, lsr #16
    subs r2, r2, #2
    bhs @shift_loop
@shift_tail:
    tst r2, #1
    bxeq lr
    ldrh ip, [r1]
    and ip, ip, #0xff00
    orr ip, ip, r3
    strh ip, [r1]
    bx lr
@same_parity:
    tst ip, #2
    beq @same_align
    bics r3, r2, #1
    beq @tail
    sub r2, r2, r3
    add ip, r3, r1
@half_loop:
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    cmp r1, ip
    blo @half_loop
    b @tail
@same_align:
    cmp r2, #2
    blo @tail
    tst r1, #2
    beq @words
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    subs r2, r2, #2
    bxeq lr
@words:
    bics r3, r2, #3
    beq @half
    sub r2, r2, r3
    add ip, r3, r1
@word_loop:
    ldr r3, [r0], #4
    str r3, [r1], #4
    cmp r1, ip
    blo @word_loop
@half:
    tst r2, #2
    ldrneh r3, [r0], #2
    strneh r3, [r1], #2
@tail:
    tst r2, #1
    bxeq lr
    ldrh r2, [r1]
    ldrh r0, [r0]
    and r2, r2, #0xff00
    and r0, r0, #0xff
    orr r0, r2, r0
    strh r0, [r1]
    bx lr
}
}
