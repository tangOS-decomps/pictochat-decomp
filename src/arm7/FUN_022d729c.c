// decomp: module=arm7 addr=0x022d729c name=FUN_022d729c
// flags: -O4,s -noThumb

// Copies 16 halfwords from `src` into the 32-byte field at +0x384 of the ARM7
// state block pointed to by 0x0380fff4.  Always reports success.

int FUN_022d729c(const unsigned short *src)
{
    unsigned short *dst = (unsigned short *)(*(char **)0x0380fff4 + 0x384);
    unsigned int i = 0;
    do {
        *dst++ = *src++;
        i++;
    } while (i < 0x10);
    return 0;
}
