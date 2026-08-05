// decomp: module=arm7 addr=0x022c8238 name=FUN_022c8238

// Stores a remapped index at +0x1c: below 0x6d the value is complemented
// directly, at or above it the value comes from the lookup table at G_038045f4
// indexed from the top.

#pragma thumb on
extern unsigned char G_038045f4[];
void FUN_022c8238(int p, int n)
{
    unsigned char v;
    if (n < 0x6d) v = (unsigned char)(0xff - n);
    else v = G_038045f4[0x7f - n];
    *(unsigned char *)(p + 0x1c) = v;
}
