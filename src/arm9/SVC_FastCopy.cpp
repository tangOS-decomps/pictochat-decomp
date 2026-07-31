// decomp: module=unk_autoload_0 addr=0x02332d32 name=SVC_FastCopy
#pragma thumb on
extern "C" asm void SVC_FastCopy(void) {
    swi 0xc
    bx lr
}
