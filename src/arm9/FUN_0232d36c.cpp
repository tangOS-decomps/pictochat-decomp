//cpp
// decomp: module=unk_autoload_0 addr=0x0232d36c name=FUN_0232d36c
// verify: python tools/match.py --c src/arm9/FUN_0232d36c.cpp --func FUN_0232d36c --addr 0x0232d36c --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Fills in only the low bitfield of a stack message with the shared-WRAM
// status byte at 0x02FFFCE7 and hands the slot on by address - the rest of the
// word is left as it lay, which is why the store is a read-modify-write of an
// otherwise untouched local.

#pragma thumb on
extern "C" {
typedef struct Msg {
    unsigned int lo : 8;
    unsigned int hi : 24;
} Msg;

extern void FUN_02339a24(Msg *);
void FUN_0232d36c(void)
{
    Msg m;

    m.lo = *(unsigned char *)0x02FFFCE7;
    FUN_02339a24(&m);
}
}
