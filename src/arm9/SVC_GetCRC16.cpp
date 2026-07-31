// decomp: module=unk_autoload_0 addr=0x02332d3a name=SVC_GetCRC16
#pragma thumb on
extern "C" asm void SVC_GetCRC16(void) {
    swi 0xe
    bx lr
}
