//cpp
// decomp: module=unk_autoload_0 addr=0x0232e6e8 name=FUN_0232e6e8
// verify: python tools/match.py --c src/arm9/FUN_0232e6e8.cpp --func FUN_0232e6e8 --addr 0x0232e6e8 --size 0x20 --module unk_autoload_0 --version 2.0/sp1

// Rounds the region in to word boundaries and only builds an arena in it when
// at least 0x30 bytes survive.

#pragma thumb on
extern "C" {
extern void *FUN_0232e614(char *, char *, int);
void *FUN_0232e6e8(char *base, int size, int c)
{
    char *end = (char *)(((unsigned int)size + (unsigned int)base) & ~3u);
    char *start = (char *)(((unsigned int)base + 3) & ~3u);

    if (start > end) goto fail;
    if ((unsigned int)(end - start) >= 0x30) goto ok;
fail:
    return 0;
ok:
    return FUN_0232e614(start, end, c);
}
}
