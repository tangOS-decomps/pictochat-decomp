//cpp
// decomp: module=unk_autoload_0 addr=0x0232e5a0 name=FUN_0232e5a0
// verify: python tools/match.py --c src/arm9/FUN_0232e5a0.cpp --func FUN_0232e5a0 --addr 0x0232e5a0 --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Rounds the region in to word boundaries and only builds an arena in it when
// at least 0x4c bytes survive.

#pragma thumb on
extern "C" {
extern void *FUN_0232e2d4(char *, char *, int);
void *FUN_0232e5a0(char *base, int size, int c)
{
    char *end = (char *)(((unsigned int)size + (unsigned int)base) & ~3u);
    char *start = (char *)(((unsigned int)base + 3) & ~3u);

    if (start > end) goto fail;
    if ((unsigned int)(end - start) >= 0x4c) goto ok;
fail:
    return 0;
ok:
    return FUN_0232e2d4(start, end, c);
}
}
