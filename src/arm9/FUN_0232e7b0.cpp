//cpp
// decomp: module=unk_autoload_0 addr=0x0232e7b0 name=FUN_0232e7b0

// Shutdown sequence: drains FUN_02337a28 until it stops reporting work, then
// runs the four teardown steps in order. The loop argument is hoisted into a
// callee-saved register, which is what the do/while spelling produces.

#pragma thumb on
extern "C" {
extern int FUN_02337a28(int);
extern void FUN_0232eaa8(void);
extern void FUN_0232f080(void);
extern void FUN_0232ff20(void);
extern void FUN_02337b54(int);
void FUN_0232e7b0(void)
{
    int r;
    do { r = FUN_02337a28(0); } while (r != 0);
    FUN_0232eaa8();
    FUN_0232f080();
    FUN_0232ff20();
    FUN_02337b54(0);
}
}
