//cpp
// decomp: module=main addr=0x02000d3c name=FUN_02000d3c
// flags: -noThumb
extern "C" asm void FUN_02000d3c(unsigned int val, void *dst, unsigned int size) {
    add ip, r1, r2
@loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt @loop
    bx lr
}
