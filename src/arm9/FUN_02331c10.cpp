//cpp
// decomp: module=unk_autoload_0 addr=0x02331c10 name=FUN_02331c10
// verify: python tools/match.py --c src/arm9/FUN_02331c10.cpp --func FUN_02331c10 --addr 0x02331c10 --size 0x4c --module unk_autoload_0 --version 2.0/sp1

// One-shot bring-up of the timer-1 channel, sibling of FUN_02332044's
// shutdown: latches the flag, runs the reset hook, clears the two tail words,
// programs TM1 (control off, count 0, then 0xc1), installs FUN_02331c68 on
// interrupt bit 8 and clears the head word.
// The MMIO writes must be spelled as bare literal addresses: mwcc pools only
// 0x04000102 and derives 0x04000100 from it with a subs.

#pragma thumb on
extern "C" {
typedef struct Ctl1c10 {
    unsigned short on;
    unsigned short pad;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
} Ctl1c10;
extern Ctl1c10 G_023c0ae0;
extern void FUN_02331be8(int);
extern void FUN_02330728(int, void (*)(void));
extern void FUN_023307d4(int);
extern void FUN_02331c68(void);
void FUN_02331c10(void)
{
    if (G_023c0ae0.on == 0) {
        G_023c0ae0.on = 1;
        FUN_02331be8(0);
        G_023c0ae0.f8 = 0;
        G_023c0ae0.fc = 0;
        *(volatile unsigned short *)0x04000102 = 0;
        *(volatile unsigned short *)0x04000100 = 0;
        *(volatile unsigned short *)0x04000102 = 0xc1;
        FUN_02330728(8, FUN_02331c68);
        FUN_023307d4(8);
        G_023c0ae0.f4 = 0;
    }
}
}
