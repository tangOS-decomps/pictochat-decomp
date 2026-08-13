//cpp
// decomp: module=unk_autoload_0 addr=0x0232b030 name=FUN_0232b030
// verify: python tools/match.py --c src/arm9/FUN_0232b030.cpp --func FUN_0232b030 --addr 0x0232b030 --size 0x34 --module unk_autoload_0 --version 2.0/sp1

// Gate on FUN_0232981c: with the block's halfword at +2 clear, raises event 1,
// zeroes the +0x30/+0x40 words and kicks FUN_0232a1e4; otherwise raises the
// error event 0xc.

#pragma thumb on
extern "C" {
extern int FUN_0232981c(void);
extern void FUN_02329bd8(int);
extern void FUN_0232a1e4(void);
extern int G_023bd698[];
void FUN_0232b030(unsigned short *p)
{
    if (FUN_0232981c() == 0) {
        if (p[1] == 0) {
            FUN_02329bd8(1);
            G_023bd698[0xc] = 0;
            G_023bd698[0x10] = 0;
            FUN_0232a1e4();
        } else {
            FUN_02329bd8(0xc);
        }
    }
}
}
