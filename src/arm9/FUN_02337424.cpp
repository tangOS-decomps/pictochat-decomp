//cpp
// decomp: module=unk_autoload_0 addr=0x02337424 name=FUN_02337424
// verify: python tools/match.py --c src/arm9/FUN_02337424.cpp --func FUN_02337424 --addr 0x02337424 --size 0x1c --module unk_autoload_0 --version 2.0/sp1
// flags: -noThumb

// Halfword copy of `nbytes` from `src` to `dst`.

extern "C" {
void FUN_02337424(char *src, char *dst, int nbytes)
{
    int i = 0;

loop:
    if (i < nbytes) {
        *(unsigned short *)(dst + i) = *(unsigned short *)(src + i);
        i += 2;
        goto loop;
    }
}
}
