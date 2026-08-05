//cpp
// decomp: module=unk_autoload_0 addr=0x02332e1c name=FUN_02332e1c

// memchr: scans `n` bytes from `p` for `ch` and returns the address of the first
// match, or null.
//
// The pointer is post-incremented and backed off by one on the hit, which is what
// the ROM does; the pre-increment spelling is two bytes short.

#pragma thumb on
extern "C" {
unsigned char *FUN_02332e1c(unsigned char *p, int c, int n)
{
    unsigned char ch = (unsigned char)c;
    while (n != 0) {
        if (*p++ == ch) return p - 1;
        n--;
    }
    return 0;
}
}
