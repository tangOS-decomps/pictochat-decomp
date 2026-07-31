// decomp: module=unk_autoload_0 addr=0x023314cc name=_ZN4CP1519InvalidateDataCacheEjj
extern "C" asm void _ZN4CP1519InvalidateDataCacheEjj(unsigned int addr, unsigned int size){
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c6, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}
