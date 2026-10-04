// decomp: module=arm7 addr=0x022c011c name=FUN_022c011c
// flags: -O4,s -noThumb
// size: 0x118 - the nominal 0xf8 excludes the eight trailing pool words.
//
// Boot-time hardware probe (SDK crt0-style startup asm). On TWL hardware
// (SCFG_EXT bit 31) it snapshots SCFG_MC / the SCFG ROM-control bytes into
// the shared work area at 0x0380ffc0, copies that area's words to
// 0x02fffdf0, then sizes main RAM by testing which mirror of 0x02fffffa
// (4 MB, 8 MB, +0xb000000) echoes writes, storing 1/2/4/8 (plus bit 15 when
// 0x04004700 reports 0x8000) back to 0x02fffffa.
//
// HAND-ASM PRIMITIVE: the original is assembly (leaf with no frame, ip used
// as a scratch while r0 is free, mirror pointer stepped from the previous
// one) - the asm block is the faithful source.

asm void FUN_022c011c(void)
{
    ldr     r2, =0x04004008
    ldr     r0, [r2]
    tst     r0, #0x80000000
    beq     @copy
    ldr     r2, =0x0380ffc0
    ldr     r3, =0x04004024
    ldrh    r0, [r3]
    strh    r0, [r2, #8]
    ldr     r3, =0x04004006
    ldrb    r0, [r3]
    ldr     r3, =0x04004004
    ldrh    r1, [r3]
    and     r1, r1, #0x80
    orr     r0, r0, r1, lsr #1
    strb    r0, [r2, #9]
@copy:
    ldr     r2, =0x0380ffc0
    ldr     r3, =0x02fffdf0
    ldr     r0, [r2, #4]
    str     r0, [r3]
    ldrh    r0, [r2, #8]
    strh    r0, [r3, #4]
    mov     r1, #0
    ldr     r2, =0x02fffffa
    sub     r3, r2, #0x400000
@loop4m:
    strh    r1, [r2]
    ldrh    ip, [r3]
    cmp     r1, ip
    bne     @not4m
    add     r1, r1, #1
    cmp     r1, #2
    bne     @loop4m
    mov     r0, #1
    b       @done
@not4m:
    mov     r1, #0
    sub     r3, r3, #0x400000
@loop8m:
    strh    r1, [r2]
    ldr     ip, [r3]
    cmp     r1, ip
    bne     @not8m
    add     r1, r1, #1
    cmp     r1, #2
    bne     @loop8m
    mov     r0, #2
    b       @done
@not8m:
    mov     r1, #0
    add     r3, r2, #0xb000000
@loop16m:
    strh    r1, [r2]
    ldr     ip, [r3]
    cmp     r1, ip
    movne   r0, #4
    bne     @done
    add     r1, r1, #1
    cmp     r1, #2
    bne     @loop16m
    mov     r0, #8
@done:
    ldr     r3, =0x04004700
    ldrh    r1, [r3]
    and     r1, r1, #0xa000
    cmp     r1, #0x8000
    orreq   r0, r0, #0x8000
    strh    r0, [r2]
    bx      lr
}
