//cpp
// decomp: module=unk_autoload_0 addr=0x0232308c name=FUN_0232308c
// verify: python tools/match.py --c src/arm9/FUN_0232308c.cpp --func FUN_0232308c --addr 0x0232308c --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Lazily carves the 0x17c000-byte arena out of 0x02004000 the first time it is
// asked for.

#pragma thumb on
extern "C" {
extern void *FUN_0232e5a0(void *, int, int);
extern void *G_0238ef04[];
void FUN_0232308c(void)
{
    if (G_0238ef04[1] == 0)
        G_0238ef04[1] = FUN_0232e5a0((void *)0x02004000, 0x17C000, 0);
}
}
