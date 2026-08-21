//cpp
// decomp: module=unk_autoload_0 addr=0x02337e20 name=FUN_02337e20
#pragma thumb on
extern "C" asm void FUN_02337e20(void *p) {
    sub sp, #8
    mov r1, #0
    str r1, [r0]
    str r1, [sp, #0]
    str r1, [sp, #4]
    str r1, [r0, #4]
    add sp, #8
    bx lr
}
