// decomp: module=unk_autoload_0 addr=0x02331504 name=FUN_02331504
// flags: -noThumb

/* CP15 store-and-flush over an address range: drain the write buffer, then
   clean+invalidate one 32-byte data cache line per iteration. Coprocessor
   ops have no C spelling; same form as CP15_FlushDataCacheRange.cpp. */
asm void FUN_02331504(unsigned int addr, unsigned int size)
{
    mov ip, #0
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r0, c7, c14, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}
