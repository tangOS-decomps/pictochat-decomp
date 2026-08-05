//cpp
// decomp: module=unk_autoload_0 addr=0x02336800 name=FUN_02336800

// Blits a run of `n` bytes into the fixed VRAM window at 0x05000400 - the
// FUN_023369b8 shape against a constant base rather than a fetched one.

#pragma thumb on
extern "C" {
extern void FUN_023372b0(int, int, int, unsigned int, int);
extern void FUN_02337424(int, int, unsigned int);
extern int G_0236a17c[];
void FUN_02336800(int a, int b, unsigned int n, int d)
{
    if (G_0236a17c[0] != -1 && n > 0x1c) {
        FUN_023372b0(G_0236a17c[0], a, b + 0x05000400, n, 1);
        return;
    }
    FUN_02337424(a, b + 0x05000400, n);
}
}
