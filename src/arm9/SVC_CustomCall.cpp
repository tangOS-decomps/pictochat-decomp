// decomp: module=unk_autoload_0 addr=0x02332d4e name=SVC_CustomCall
#pragma thumb on
extern "C" asm void SVC_CustomCall(void) {
    swi 0x13
    bx lr
}
