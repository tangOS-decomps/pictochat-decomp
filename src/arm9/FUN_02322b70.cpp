//cpp
// decomp: module=unk_autoload_0 addr=0x02322b70 name=FUN_02322b70
// flags: -thumb
#pragma thumb on
extern "C" asm void FUN_02322b70(void *arg0, int arg1) {
    push {r4, lr}
    mov r2, #0xa
    strb r2, [r0, #0]
    mov r3, #1
    mov r2, #0
    b @check_zero
@zero_loop:
    strb r2, [r0, r3]
    add r3, r3, #1
@check_zero:
    cmp r3, #6
    blo @zero_loop
    cmp r1, #0x10
    ble @cap_len
    mov r1, #0x10
@cap_len:
    mov r4, #0
    mov r3, #0x1c
    b @fill_check
@fill_loop:
    add r2, r0, r4
    strb r3, [r2, #6]
    add r4, r4, #1
@fill_check:
    cmp r4, r1
    blt @fill_loop
    pop {r4, pc}
}
