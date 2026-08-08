//cpp
// decomp: module=unk_autoload_0 addr=0x02330784 name=FUN_02330784
// verify: python tools/match.py --c src/arm9/FUN_02330784.cpp --func FUN_02330784 --addr 0x02330784 --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Installs handler `i`: its two words go into their own tables, the matching
// interrupt bit is enabled, and the live flag is raised last.

#pragma thumb on
extern "C" {
extern int G_023c078c[];
extern int G_023c0790[];
extern int G_023c0794[];
extern unsigned int FUN_023307d4(unsigned int);
void FUN_02330784(int i, int a, int b)
{
    int off = i * 0xc;

    *(int *)((char *)G_023c078c + off) = a;
    *(int *)((char *)G_023c0794 + off) = b;
    FUN_023307d4(1u << (i + 3));
    *(int *)((char *)G_023c0790 + off) = 1;
}
}
