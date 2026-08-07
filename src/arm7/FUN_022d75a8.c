// decomp: module=arm7 addr=0x022d75a8 name=FUN_022d75a8
// flags: -O4,s -noThumb

// Publishes a WEP/key descriptor to both the ARM7 state block copy (+0x3a8)
// and the wifi hardware key window at 0x04808020, then flips the "key valid"
// bit 0x400 in the 0x048080d0 control register according to bit 0 of the
// descriptor's first halfword.

extern void FUN_022d811c(void *dst, void *src);

int FUN_022d75a8(unsigned short *key)
{
    FUN_022d811c((void *)(*(int *)0x0380fff4 + 0x3a8), key);
    FUN_022d811c((void *)0x04808020, key);
    if (key[0] & 1) {
        *(volatile unsigned short *)0x048080d0 &= ~0x400;
    } else {
        *(volatile unsigned short *)0x048080d0 |= 0x400;
    }
    return 0;
}
