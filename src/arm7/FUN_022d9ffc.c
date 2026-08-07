// decomp: module=arm7 addr=0x022d9ffc name=FUN_022d9ffc
// flags: -noThumb

unsigned short FUN_022d9ffc(int idx)
{
    int base = *(int *)(*(int *)0x0380FFF4 + 0x31c);
    return *(unsigned short *)(base + idx * 0x1c);
}
