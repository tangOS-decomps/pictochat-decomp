//cpp
// decomp: module=unk_autoload_0 addr=0x02332e70 name=FUN_02332e70
extern "C" void FUN_02332e70(unsigned char *dst, int c, unsigned int n) {
    unsigned int val = (unsigned char)c;

    if (n >= 0x20) {
        unsigned int count = (unsigned int)(-(int)(unsigned int)dst) & 3;
        if (count != 0) {
            n -= count;
            do {
                *dst++ = (unsigned char)val;
            } while (--count != 0);
        }

        if (val != 0) {
            val |= (val << 24) | (val << 16) | (val << 8);
        }

        count = n >> 5;
        if (count != 0) {
            do {
                ((unsigned int *)dst)[0] = val;
                ((unsigned int *)dst)[1] = val;
                ((unsigned int *)dst)[2] = val;
                ((unsigned int *)dst)[3] = val;
                ((unsigned int *)dst)[4] = val;
                ((unsigned int *)dst)[5] = val;
                ((unsigned int *)dst)[6] = val;
                unsigned int *q = (unsigned int *)dst + 7;
                dst += 32;
                q[0] = val;
            } while (--count != 0);
        }

        unsigned int nword = (n & 0x1f) >> 2;
        if (nword != 0) {
            do {
                *(unsigned int *)dst = val;
                dst += 4;
            } while (--nword != 0);
        }

        n &= 3;
    }

    if (n != 0) {
        do {
            *dst++ = (unsigned char)val;
        } while (--n != 0);
    }
}
