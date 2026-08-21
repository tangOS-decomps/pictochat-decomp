//cpp
// decomp: module=unk_autoload_0 addr=0x0232164c name=FUN_0232164c
// flags: -thumb
#pragma thumb on

extern "C" void FUN_0232dd28(void *, int);
extern "C" void FUN_023219d8(void);
extern "C" void FUN_0232dc48(void *, int, int);
extern "C" void FUN_0232dc74(void *, int, int);
extern "C" void FUN_0232dcc0(int, int);
extern "C" void FUN_0232dcf4(int, int);

extern "C" asm void FUN_0232164c(void *arg0, int arg1, int *out_res_x, int *out_res_y, int *out_x, int *out_y, int arg6) {
    push {r3, r4, r5, r6, r7, lr}
    add r7, r2, #0
    str r3, [sp, #0]
    ldr r5, [sp, #0x18]
    ldr r6, [sp, #0x1c]
    bl FUN_0232dd28
    add r4, r0, #0
    bl FUN_023219d8
    ldrh r1, [r4, #6]
    mov r2, #4
    ldrsh r2, [r4, r2]
    lsl r1, r1, #16
    lsr r1, r1, #28
    lsl r1, r1, #5
    add r0, r0, r1
    lsl r2, r2, #24
    ldr r1, [sp, #0x20]
    asr r2, r2, #24
    bl FUN_0232dc48
    str r0, [r5, #0]
    bl FUN_023219d8
    ldrh r1, [r4, #6]
    mov r2, #4
    ldrsh r2, [r4, r2]
    lsl r1, r1, #16
    lsr r1, r1, #28
    lsl r1, r1, #5
    add r0, r0, r1
    lsl r2, r2, #16
    ldr r1, [sp, #0x20]
    asr r2, r2, #24
    bl FUN_0232dc74
    str r0, [r6, #0]
    mov r1, sp
    ldrh r0, [r4, #0]
    sub r1, r1, #4
    strh r0, [r1, #0]
    ldr r0, [r1, #0]
    ldr r1, [r5, #0]
    bl FUN_0232dcc0
    str r0, [r7, #0]
    mov r1, sp
    ldrh r0, [r4, #2]
    sub r1, r1, #4
    strh r0, [r1, #0]
    ldr r0, [r1, #0]
    ldr r1, [r6, #0]
    bl FUN_0232dcf4
    ldr r1, [sp, #0]
    str r0, [r1, #0]
    pop {r3, r4, r5, r6, r7, pc}
}
