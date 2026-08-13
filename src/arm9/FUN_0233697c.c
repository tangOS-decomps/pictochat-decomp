// decomp: module=unk_autoload_0 addr=0x0233697c name=FUN_0233697c
// verify: python tools/match.py --c src/arm9/FUN_0233697c.c --func FUN_0233697c --addr 0x0233697c --size 0x3c --module unk_autoload_0 --version 2.0/sp1

// Sibling of FUN_02336940 for the 0x06600000 VRAM window; same
// `dst = base; dst += b;` spelling (see that file for why).

extern void FUN_02337240(int, int, int, unsigned int, int);
extern void FUN_02337454(int, int, unsigned int);
extern int G_0236a17c[];

void FUN_0233697c(int a, int b, unsigned int n)
{
    int dst = 0x06600000;
    dst += b;
    if (G_0236a17c[0] != -1 && n > 0x30) {
        FUN_02337240(G_0236a17c[0], a, dst, n, 1);
        return;
    }
    FUN_02337454(a, dst, n);
}
