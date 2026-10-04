//cpp
// decomp: module=main addr=0x02000dfc name=FUN_02000dfc
// flags: -noThumb
// The segment loader branches to the bx-lr return stub at 0x02000e74.
// 0x02000e78 starts the separate MPU initialization routine.
extern "C" void FUN_02000e74(void);
extern "C" asm void FUN_02000dfc(void) {
    ldr r0, =0x02000f64
    ldr r1, [r0, #0]
    ldr r2, [r0, #4]
    ldr r3, [r0, #8]
@loop_seg:
    cmp r1, r2
    beq @end
    ldr r5, [r1], #4
    ldr r7, [r1], #4
    add r6, r5, r7
    mov r4, r5
@copy_loop:
    cmp r4, r6
    ldrmi r7, [r3], #4
    strmi r7, [r4], #4
    bmi @copy_loop
    ldr r7, [r1], #4
    add r6, r4, r7
    mov r7, #0
@clear_loop:
    cmp r4, r6
    strlo r7, [r4], #4
    blo @clear_loop
    bic r4, r5, #0x1f
@cache_loop:
    mcr p15, 0, r7, c7, c10, 4
    mcr p15, 0, r4, c7, c5, 1
    mcr p15, 0, r4, c7, c14, 1
    add r4, r4, #0x20
    cmp r4, r6
    blt @cache_loop
    b @loop_seg
@end:
    b FUN_02000e74
}
