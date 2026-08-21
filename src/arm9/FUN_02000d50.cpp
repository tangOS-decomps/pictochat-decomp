//cpp
// decomp: module=main addr=0x02000d50 name=FUN_02000d50
// flags: -noThumb
extern "C" asm void FUN_02000d50(void *ptr) {
    cmp r0, #0
    beq @end
    stmfd sp!, {r4, r5, r6, r7}
    ldmdb r0, {r1, r2}
    add r2, r0, r2
    sub r3, r0, r1, lsr #24
    bic r1, r1, #0xff000000
    sub r1, r0, r1
    mov r4, r2
@loop_outer:
    cmp r3, r1
    ble @flush_cache
    ldrb r5, [r3, #-1]!
    mov r6, #8
@bit_loop:
    subs r6, r6, #1
    blt @loop_outer
    tst r5, #0x80
    bne @compressed
    ldrb r0, [r3, #-1]!
    strb r0, [r2, #-1]!
    b @next_bit
@compressed:
    ldrb ip, [r3, #-1]!
    ldrb r7, [r3, #-1]!
    orr r7, r7, ip, lsl #8
    bic r7, r7, #0xf000
    add r7, r7, #2
    add ip, ip, #0x20
@copy_loop:
    ldrb r0, [r2, r7]
    strb r0, [r2, #-1]!
    subs ip, ip, #0x10
    bge @copy_loop
@next_bit:
    cmp r3, r1
    mov r5, r5, lsl #1
    bgt @bit_loop
@flush_cache:
    mov r0, #0
    bic r3, r1, #0x1f
@cache_loop:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r3, c7, c5, 1
    mcr p15, 0, r3, c7, c14, 1
    add r3, r3, #0x20
    cmp r3, r4
    blt @cache_loop
    ldmfd sp!, {r4, r5, r6, r7}
@end:
    bx lr
}
