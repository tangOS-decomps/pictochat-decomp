//cpp
// decomp: module=unk_autoload_0 addr=0x023369b8 name=FUN_023369b8

// Blits a run of `n` bytes at offset `b` of the BG0 screen base: long runs go
// through FUN_023372b0 with the handle from G_0236a17c, short runs and an
// unset handle fall back to FUN_02337424.
//
// FUN_023372b0 takes FIVE arguments, the last on the stack. Ghidra drafted it
// with six, which put an extra argument setup in the prologue.

#pragma thumb on
extern "C" {
extern void *FUN_02336460(void);
extern void FUN_023372b0(int, int, int, unsigned int, int);
extern void FUN_02337424(int, int, unsigned int);
extern int G_0236a17c[];

void FUN_023369b8(int a, int b, unsigned int n, int d)
{
    void *p = FUN_02336460();
    if (G_0236a17c[0] != -1 && n > 0x1c) {
        FUN_023372b0(G_0236a17c[0], a, (int)p + b, n, 1);
        return;
    }
    FUN_02337424(a, (int)p + b, n);
}
}
