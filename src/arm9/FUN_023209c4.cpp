//cpp
// decomp: module=unk_autoload_0 addr=0x023209c4 name=FUN_023209c4

// Runs FUN_023301a0, registers a 0x1000-byte buffer, and initialises the counter
// at G_0236b73c+8 if it is still zero.

#pragma thumb on
extern "C" {
extern void FUN_023301a0(void);
extern void FUN_0233016c(void *, int, int);
extern int G_0236b7e0[];
extern int G_0236b73c[];
void FUN_023209c4(void)
{
    FUN_023301a0();
    FUN_0233016c(G_0236b7e0, 0x1000, 1);
    if (G_0236b73c[2] == 0) G_0236b73c[2] = 1;
}
}
