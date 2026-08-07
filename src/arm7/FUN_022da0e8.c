// decomp: module=arm7 addr=0x022da0e8 name=FUN_022da0e8
// flags: -noThumb

unsigned short FUN_022da0e8(int idx)
{
    int base = *(int *)(*(int *)0x0380FFF4 + 0x31c);
    return *(unsigned short *)(base + idx * 0x1c + 2);
}
