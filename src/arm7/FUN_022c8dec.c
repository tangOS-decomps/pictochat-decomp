// decomp: module=arm7 addr=0x022c8dec name=FUN_022c8dec

// Returns the 0x40-byte slot in G_03805fbc named by the byte at +8+i of `p`, or
// null when the index is out of range or the byte is the 0xff sentinel.

#pragma thumb on
extern unsigned char G_03805fbc[];
void *FUN_022c8dec(int p, int i)
{
    unsigned int v;
    if (i > 0xf) return 0;
    v = *(unsigned char *)(p + i + 8);
    if (v == 0xff) return 0;
    return G_03805fbc + v * 0x40;
}
