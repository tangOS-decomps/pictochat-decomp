// decomp: module=arm7 addr=0x022c3ba8 name=FUN_022c3ba8
// flags: -O4,s -noThumb

// Spins up to 0xfa0 times waiting for bit 7 of the halfword register at
// 0x0480819c to come up, then returns regardless of whether it ever did.

void FUN_022c3ba8(void)
{
    int n = 0xfa0;

    while (n != 0) {
        if (*(volatile unsigned short *)0x0480819c & 0x80) return;
        n--;
    }
}
