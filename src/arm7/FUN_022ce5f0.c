// decomp: module=arm7 addr=0x022ce5f0 name=FUN_022ce5f0
// flags: -O4,s -noThumb

// Buckets a raw index into one of four bands.  The band widths depend on the
// byte at +0x53 of the object hanging off 0x023190dc+0x54c: mode 8 uses the
// wide bands (0x16 / 0x1c / 0x22), everything else the narrow ones (8 / 0xe /
// 0x14).  Every arm returns through r0 in place, which is what gives the ROM
// its chain of movlo/bxlo pairs.
// NOTE: verify with --size 0x68, not funcs.json's 0x64 - the stated size
// excludes this function's own trailing pool word.

extern unsigned char *G_023190dc[];

unsigned int FUN_022ce5f0(unsigned int n)
{
    if (G_023190dc[0x153][0x53] == 8) {
        if (n < 0x16) {
            return 0;
        }
        if (n < 0x1c) {
            return 1;
        }
        if (n < 0x22) {
            return 2;
        }
        return 3;
    }

    if (n < 8) {
        return 0;
    }
    if (n < 0xe) {
        return 1;
    }
    if (n < 0x14) {
        return 2;
    }
    return 3;
}
