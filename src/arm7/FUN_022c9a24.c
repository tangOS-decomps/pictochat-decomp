// decomp: module=arm7 addr=0x022c9a24 name=FUN_022c9a24
// flags: -O4,s

// Stores v into the halfword at +0x20 + b*2 of the 0x24-byte record `a` of the
// table pointed to by 0x03805838.

#pragma thumb on
extern int G_03805838;

void FUN_022c9a24(int a, int b, unsigned short v)
{
    int p = G_03805838 + a * 0x24;
    *(unsigned short *)(p + b * 2 + 0x20) = v;
}
