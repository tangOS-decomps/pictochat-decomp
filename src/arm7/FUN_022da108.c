// decomp: module=arm7 addr=0x022da108 name=FUN_022da108
// flags: -noThumb

unsigned short FUN_022da108(int idx)
{
    int base = *(int *)(*(int *)0x0380FFF4 + 0x31c);
    return *(unsigned short *)(base + idx * 0x1c + 0x16);
}
