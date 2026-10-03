//cpp
// decomp: module=unk_autoload_0 addr=0x02337e08 name=FUN_02337e08
// verify: python tools/match.py --c src/arm9/FUN_02337e08.cpp --func FUN_02337e08 --addr 0x02337e08 --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Probes the 0x04fff200 mailbox under the FUN_02332080/94 lock pair: writes
// 0x10 and reports whether anything reads back (always 1 when FUN_02331218
// says the channel is closed).

#pragma thumb on
extern "C" {
extern int FUN_02331218(void);
extern int FUN_02332080(void);
extern void FUN_02332094(int);
int FUN_02337e08(void)
{
    int s;
    int v;

    if (FUN_02331218() == 0) return 1;
    s = FUN_02332080();
    *(volatile unsigned int *)0x04fff200 = 0x10;
    v = *(volatile unsigned int *)0x04fff200;
    FUN_02332094(s);
    if (v != 0) return 1;
    return 0;
}
}
