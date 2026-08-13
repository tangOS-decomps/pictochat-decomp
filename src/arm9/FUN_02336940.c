// decomp: module=unk_autoload_0 addr=0x02336940 name=FUN_02336940
// verify: python tools/match.py --c src/arm9/FUN_02336940.c --func FUN_02336940 --addr 0x02336940 --size 0x3c --module unk_autoload_0 --version 2.0/sp1

// Sibling of FUN_023367c0 for the 0x06400000 VRAM window with a 0x30-byte
// cutoff. The dest address must be built as `dst = base; dst += b;` - written
// as one `base + b` expression mwcc rematerialises the constant in each branch
// (one word bigger) and flips the adds operands.

extern void FUN_02337240(int, int, int, unsigned int, int);
extern void FUN_02337454(int, int, unsigned int);
extern int G_0236a17c[];

void FUN_02336940(int a, int b, unsigned int n)
{
    int dst = 0x06400000;
    dst += b;
    if (G_0236a17c[0] != -1 && n > 0x30) {
        FUN_02337240(G_0236a17c[0], a, dst, n, 1);
        return;
    }
    FUN_02337454(a, dst, n);
}
