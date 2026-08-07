// decomp: module=arm7 addr=0x022d7cf0 name=FUN_022d7cf0
// flags: -noThumb

unsigned int FUN_022d7cf0(unsigned int value)
{
    *(unsigned short *)(*(int *)0x0380FFF4 + 0x354) =
        (unsigned short)(value >> 1);
    *(volatile unsigned short *)0x0480803C = (unsigned short)value;
    return 0;
}
