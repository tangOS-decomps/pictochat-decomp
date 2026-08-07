//cpp
// decomp: module=arm7 addr=0x022c77a0 name=FUN_022c77a0
// flags: -O4,s

typedef unsigned int u32;

extern "C" void FUN_022c77a0(int index, u32 flags)
{
    volatile u32* reg = (volatile u32*)0x04000400;
    u32 value = reg[index * 4] & 0x7FFFFFFF;

    if ((flags & 1) != 0) {
        value |= 0x8000;
    }

    reg[index * 4] = value;
}
