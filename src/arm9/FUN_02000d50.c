// decomp: module=main addr=0x02000d50 name=FUN_02000d50
// HAND-ASM PRIMITIVE: backwards in-place LZ decompressor used by crt0.
// Its pre-decrement stream walk and CP15 cache-maintenance epilogue are an
// SDK/runtime assembly primitive, rather than a compiler-generated C body.
asm void FUN_02000d50(void)
{
    cmp     r0, #0
    beq     done
    stmdb   sp!, {r4, r5, r6, r7}
    ldmdb   r0, {r1, r2}
    add     r2, r0, r2
    sub     r3, r0, r1, lsr #24
    bic     r1, r1, #0xff000000
    sub     r1, r0, r1
    mov     r4, r2
next_flags:
    cmp     r3, r1
    ble     flush_setup
    ldrb    r5, [r3, #-1]!
    mov     r6, #8
next_bit:
    subs    r6, r6, #1
    blt     next_flags
    tst     r5, #0x80
    bne     backref
    ldrb    r0, [r3, #-1]!
    strb    r0, [r2, #-1]!
    b       advance_flags
backref:
    ldrb    ip, [r3, #-1]!
    ldrb    r7, [r3, #-1]!
    orr     r7, r7, ip, lsl #8
    bic     r7, r7, #0xf000
    add     r7, r7, #2
    add     ip, ip, #0x20
copy_backref:
    ldrb    r0, [r2, r7]
    strb    r0, [r2, #-1]!
    subs    ip, ip, #0x10
    bge     copy_backref
advance_flags:
    cmp     r3, r1
    mov     r5, r5, lsl #1
    bgt     next_bit
flush_setup:
    mov     r0, #0
    bic     r3, r1, #0x1f
flush_line:
    mcr     p15, 0, r0, c7, c10, 4
    mcr     p15, 0, r3, c7, c5, 1
    mcr     p15, 0, r3, c7, c14, 1
    add     r3, r3, #0x20
    cmp     r3, r4
    blt     flush_line
    ldmia   sp!, {r4, r5, r6, r7}
done:
    bx      lr
}
