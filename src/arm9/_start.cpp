//cpp
// decomp: module=main addr=0x02000c00 name=_start
// flags: -noThumb
extern "C" void FUN_02000e78(void);
extern "C" void FUN_02000d3c(int, void *, int);
extern "C" void FUN_02000d50(void *);
extern "C" void FUN_02000dfc(void);
extern "C" void FUN_023361fc(void);
extern "C" void FUN_02000f60(void);
extern "C" void FUN_02336200(void);

extern "C" asm void _start(void) {
    mov ip, #0x4000000
    str ip, [ip, #0x208]
@wait_vcount:
    ldrh r0, [ip, #6]
    cmp r0, #0
    bne @wait_vcount
    bl FUN_02000e78
    mov r0, #0x13
    msr cpsr_c, r0
    ldr r0, =0x03000000
    add r0, r0, #0x3fc0
    mov sp, r0
    mov r0, #0x12
    msr cpsr_c, r0
    ldr r0, =0x03000000
    add r0, r0, #0x3fc0
    sub r0, r0, #0x40
    sub sp, r0, #4
    tst sp, #4
    subeq sp, sp, #4
    ldr r1, =0x00001000
    sub r1, r0, r1
    mov r0, #0x1f
    msr cpsr_fsxc, r0
    sub sp, r1, #4
    tst sp, #4
    subne sp, sp, #4
    mov r0, #0
    ldr r1, =0x03000000
    mov r2, #0x4000
    bl FUN_02000d3c
    mov r0, #0
    ldr r1, =0x05000000
    mov r2, #0x400
    bl FUN_02000d3c
    mov r0, #0x200
    ldr r1, =0x07000000
    mov r2, #0x400
    bl FUN_02000d3c
    ldr r1, =0x02000f64
    ldr r0, [r1, #0x14]
    bl FUN_02000d50
    bl FUN_02000dfc
    ldr r0, =0x02000f64
    ldr r1, [r0, #0xc]
    ldr r2, [r0, #0x10]
    mov r3, r1
    mov r0, #0
@bss_clear:
    cmp r1, r2
    strlo r0, [r1], #4
    blo @bss_clear
    bic r1, r3, #0x1f
@cache_flush:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r1, c7, c5, 1
    mcr p15, 0, r1, c7, c14, 1
    add r1, r1, #0x20
    cmp r1, r2
    blt @cache_flush
    ldr r1, =0x02ffff9c
    str r0, [r1]
    ldr r1, =0x03000000
    add r1, r1, #0x3fc0
    add r1, r1, #0x3c
    ldr r0, =0x01ff8000
    str r0, [r1]
    bl FUN_023361fc
    bl FUN_02000f60
    blx FUN_02336200
    ldr r1, =0x02320001
    ldr lr, =0x023fee00
    bx r1
}
