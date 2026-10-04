// decomp: module=arm7 addr=0x022c4014 name=FUN_022c4014
// flags: -O4,s -noThumb
// size: 0x20c - the nominal 0x84 stops at the computed jump; the routine runs
// through the 32-step unrolled divide to the `bx lr` at 0x022c421c (the
// symbol list's next entry, FUN_022c4228, is mid-way into the unsigned twin
// that really starts at 0x022c4220).
//
// Compiler-runtime signed 32-bit division (_s32_div_f shape): divides |a| by
// |b| with a normalise-then-unrolled restoring loop entered by a computed
// jump, returns the quotient in r0 and the remainder in r1, then fixes the
// signs (quotient by sign(a)^sign(b), remainder by sign(a)). The two-result
// register ABI cannot be expressed in C - HAND-ASM PRIMITIVE.

asm int FUN_022c4014(int numerator, int denominator)
{
    eor     ip, r0, r1
    and     ip, ip, #0x80000000
    cmp     r0, #0
    rsblt   r0, r0, #0
    addlt   ip, ip, #1
    cmp     r1, #0
    rsblt   r1, r1, #0
    beq     @fixsign
    cmp     r0, r1
    movlo   r1, r0
    movlo   r0, #0
    blo     @fixsign
    mov     r2, #0x1c
    mov     r3, r0, lsr #4
    cmp     r1, r3, lsr #12
    suble   r2, r2, #0x10
    movle   r3, r3, lsr #0x10
    cmp     r1, r3, lsr #4
    suble   r2, r2, #8
    movle   r3, r3, lsr #8
    cmp     r1, r3
    suble   r2, r2, #4
    movle   r3, r3, lsr #4
    mov     r0, r0, lsl r2
    rsb     r1, r1, #0
    adds    r0, r0, r0
    add     r2, r2, r2, lsl #1
    add     pc, pc, r2, lsl #2
    mov     r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0

    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0

    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0

    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0
    adcs    r3, r1, r3, lsl #1
    sublo   r3, r3, r1
    adcs    r0, r0, r0

    mov     r1, r3
@fixsign:
    ands    r3, ip, #0x80000000
    rsbne   r0, r0, #0
    ands    r3, ip, #1
    rsbne   r1, r1, #0
    bx      lr
}
