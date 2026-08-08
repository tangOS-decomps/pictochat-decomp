//cpp
// decomp: module=unk_autoload_0 addr=0x0233621c name=FUN_0233621c
// verify: python tools/match.py --c src/arm9/FUN_0233621c.cpp --func FUN_0233621c --addr 0x0233621c --size 0x18 --module unk_autoload_0 --version 2.0/sp1

// Byte-clears `n` bytes and returns the buffer, tolerating a null pointer or a
// zero count.

#pragma thumb on
extern "C" {
char *FUN_0233621c(char *p, int n)
{
    char *q = p;

    if (p == 0) return p;
    if (n == 0) return p;
    do {
        n--;
        *q++ = 0;
    } while (n != 0);
    return p;
}
}
