//cpp
// decomp: module=unk_autoload_0 addr=0x02332df4 name=FUN_02332df4
// verify: python tools/match.py --c src/arm9/FUN_02332df4.cpp --func FUN_02332df4 --addr 0x02332df4 --size 0x1a --module unk_autoload_0 --version 2.0/sp1

// Byte copy of `n` bytes returning the destination; the source is read as
// signed char, which in Thumb only has the register-offset load form.

#pragma thumb on
extern "C" {
char *FUN_02332df4(char *dst, const signed char *src, int n)
{
    char *d = dst;

    if (n != 0) {
        do {
            *d = *src++;
            d++;
            n--;
        } while (n != 0);
    }
    return dst;
}
}
