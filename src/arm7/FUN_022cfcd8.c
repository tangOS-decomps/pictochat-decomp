// decomp: module=arm7 addr=0x022cfcd8 name=FUN_022cfcd8
// flags: -noThumb

// Hands two adjacent IWRAM buffers to the external routine at 0x037cabc0.

extern void FUN_037cabc0(void *);
void FUN_022cfcd8(void)
{
    FUN_037cabc0((void *)0x03807204);
    FUN_037cabc0((void *)0x038071d8);
}
