// decomp: module=arm7 addr=0x022d188c name=FUN_022d188c
// flags: -noThumb

// Folds `v` into the 16-bit checksum at 0x02ffff98: XOR with the old value
// shifted up one, then XOR-fold the two halves together.

void FUN_022d188c(unsigned int v)
{
    unsigned short *p = (unsigned short *)0x02ffff98;
    v ^= (unsigned int)*p << 1;
    *p = (unsigned short)(v ^ (v >> 16));
}
