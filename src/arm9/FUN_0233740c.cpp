//cpp
// decomp: module=unk_autoload_0 addr=0x0233740c name=FUN_0233740c
// verify: python tools/match.py --c src/arm9/FUN_0233740c.cpp --func FUN_0233740c --addr 0x0233740c --size 0x18 --module unk_autoload_0 --version 2.0/sp1
// flags: -noThumb

// Halfword fill across `nbytes` starting at `dst`.

extern "C" {
void FUN_0233740c(short value, char *dst, int nbytes)
{
    int i = 0;

loop:
    if (i < nbytes) {
        *(short *)(dst + i) = value;
        i += 2;
        goto loop;
    }
}
}
