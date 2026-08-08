// decomp: module=unk_autoload_0 addr=0x02331148 name=FUN_02331148
asm int FUN_02331148(void *ctx)
{
    stmfd sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, [pc, #0x38]
    blx r1
    ldmfd sp!, {r0, lr}
    add r1, r0, #0
    mrs r2, cpsr
    str r2, [r1], #4
    mov r0, #0xd3
    msr cpsr_c, r0
    str sp, [r1, #0x40]
    msr cpsr_c, r2
    mov r0, #1
    stmia r1, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr}
    add r0, pc, #8
    str r0, [r1, #0x3c]
    mov r0, #0
    bx lr
    DCD 0x02338A88
}
