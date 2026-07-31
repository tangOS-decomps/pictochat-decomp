// decomp: module=unk_autoload_0 addr=0x0233229c name=_ZN4CP1516WaitForInterruptEv
extern "C" asm void _ZN4CP1516WaitForInterruptEv(void){
    mov r0, #0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}
