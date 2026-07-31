// decomp: module=unk_autoload_0 addr=0x02332e70 name=FUN_02332e70
// NONMATCHING: hand-optimized memset (align-to-4 byte fixup, byte broadcast to word, 32-byte-unrolled word-store loop, word remainder loop, byte remainder loop, all sharing one tail exit) - fully logic-correct and byte-identical except 4 words inside the unrolled 8-store bulk loop: target computes a base=dst copy AFTER the 7th store (offset 0x18) and uses r3/r4 for base-copy/counter, while every C structuring I tried (base declared at loop top, base declared right before use, volatile base, restructured via a w pointer) either reproduces the copy 1 instruction too early (before the 7th store) or lets the compiler prove the copy is unnecessary and collapses to a shorter direct-8th-store form - both wrong sizes or wrong order/registers. Tried 5+ C variants plus a 120s/1600+ iteration decomp-permuter run (base score 85, never reached 0). Logic verified correct vs ROM. (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void FUN_02332e70(unsigned char *dst, int c, unsigned int n) {
    unsigned int val = (unsigned char)c;

    if (n >= 0x20) {
        unsigned int misalign = (unsigned int)(-(int)(unsigned int)dst) & 3;
        if (misalign != 0) {
            n -= misalign;
            do {
                *dst++ = (unsigned char)val;
            } while (--misalign != 0);
        }

        if (val != 0) {
            val |= (val << 24) | (val << 16) | (val << 8);
        }

        {
            unsigned int nblk = n >> 5;
            if (nblk != 0) {
                do {
                    unsigned char *base = dst;
                    ((unsigned int *)dst)[0] = val;
                    ((unsigned int *)dst)[1] = val;
                    ((unsigned int *)dst)[2] = val;
                    ((unsigned int *)dst)[3] = val;
                    ((unsigned int *)dst)[4] = val;
                    ((unsigned int *)dst)[5] = val;
                    ((unsigned int *)dst)[6] = val;
                    dst += 0x20;
                    ((unsigned int *)base)[7] = val;
                } while (--nblk != 0);
            }
        }

        {
            unsigned int nword = (n & 0x1f) >> 2;
            if (nword != 0) {
                do {
                    *(unsigned int *)dst = val;
                    dst += 4;
                } while (--nword != 0);
            }
        }

        n &= 3;
    }

    if (n != 0) {
        do {
            *dst++ = (unsigned char)val;
        } while (--n != 0);
    }
}
