// decomp: module=unk_autoload_0 addr=0x02331194 name=FUN_02331194
asm void FUN_02331194(void *ctx)
{
    stmfd sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, [pc, #0x30]
    blx r1
    ldmfd sp!, {r0, lr}
    mrs r1, cpsr
    bic r1, r1, #0x1f
    orr r1, r1, #0xd3
    msr cpsr_c, r1
    ldr r1, [r0], #4
    msr spsr_fsxc, r1
    ldr sp, [r0, #0x40]
    ldr lr, [r0, #0x3c]
    ldmia r0, {r0-lr}^
    mov r0, r0
    subs pc, lr, #4
    DCD 0x02338AC8
}
