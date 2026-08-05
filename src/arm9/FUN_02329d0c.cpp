//cpp
// decomp: module=unk_autoload_0 addr=0x02329d0c name=FUN_02329d0c

// Stores `v` into the field at +0x20 of G_023bd60c under the
// FUN_02332080/FUN_02332094 lock pair.

#pragma thumb on
extern "C" {
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023bd60c[];
void FUN_02329d0c(int v)
{
    int c = FUN_02332080();
    G_023bd60c[8] = v;
    FUN_02332094(c);
}
}
