//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02332e38 name=memcmp
// memcmp-style ordering comparator: returns 0 if the first n bytes of p0/p1
// are equal, else -1/1 by unsigned byte magnitude at the first mismatch
// (not a general difference like libc memcmp). The `if (p0[-1] < p1[-1])
// return -1; return 1;` polarity (rather than the more natural `>=` first)
// matters for the match - it decides which branch falls straight through
// to its own `pop {r3,r4}; bx lr` vs which one is reached by the bhs
// branch.
int memcmp(unsigned char *p0, unsigned char *p1, unsigned int n) {
    if (n != 0) {
        do {
            if (*p0++ != *p1++) {
                if (p0[-1] < p1[-1]) {
                    return -1;
                }
                return 1;
            }
        } while (--n != 0);
    }
    return 0;
}

}
