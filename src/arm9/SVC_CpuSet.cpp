// decomp: module=unk_autoload_0 addr=0x02332d2e name=SVC_CpuSet
#pragma thumb on
extern "C" asm void SVC_CpuSet(void) {
    swi 0xb
    bx lr
}
