// decomp: module=arm7 addr=0x022e00ec name=FUN_022e00ec
// flags: -O4,s -noThumb
// size: 0xa4 - the nominal 0x9c excludes the two trailing pool words.
//
// Serialises the Supported Rates element (id 1) at `dst`: one byte per rate
// enabled in the mask at +0x344+0x62, taken from the rate table at
// G_023165fc and tagged 0x80 when it is also in the basic-rate mask at +0x60.
// The length byte is patched in last. Returns the element's total length.

typedef unsigned short u16;

extern const u16 G_023165fc[];
extern void FUN_022d8d40(unsigned char *p, unsigned char v);

int FUN_022e00ec(unsigned char *dst)
{
    unsigned char *p = *(unsigned char **)0x0380fff4 + 0x344;
    int n = 0;
    unsigned int i;

    FUN_022d8d40(dst + n, 1);
    n += 2;
    for (i = 0; i < 16; i++) {
        if (*(u16 *)(p + 0x62) & (1 << i)) {
            if (*(u16 *)(p + 0x60) & (1 << i)) {
                FUN_022d8d40(dst + n, G_023165fc[i] | 0x80);
            } else {
                FUN_022d8d40(dst + n, G_023165fc[i]);
            }
            n++;
        }
    }
    FUN_022d8d40(dst + 1, n - 2);
    return n;
}
