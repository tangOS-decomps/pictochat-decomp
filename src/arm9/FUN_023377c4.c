// decomp: module=unk_autoload_0 addr=0x023377c4 name=FUN_023377c4
#pragma thumb on

extern void FUN_02337930(int, int, int, unsigned int, int);

void FUN_023377c4(int p1, int p2, int p3, int p4, int p5, int p6, int p7)
{
    FUN_02337930(0x11, p3, p4,
        (p1 << 31) | (p2 << 30) | (p5 << 29) | (p6 << 28) | (p7 << 27),
        0);
}
