//cpp
// decomp: module=unk_autoload_0 addr=0x0232b9cc name=FUN_0232b9cc
#pragma thumb on
extern "C" {
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int G_023bd814[];
void FUN_0232b9cc(int v)
{
    int c = FUN_02332080();
    G_023bd814[15] = v;
    FUN_02332094(c);
}
}
