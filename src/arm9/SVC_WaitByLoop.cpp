// decomp: module=unk_autoload_0 addr=0x02332d10 name=SVC_WaitByLoop
#pragma thumb on
extern "C" asm void SVC_WaitByLoop(void) {
    swi 0x3
    bx lr
}
