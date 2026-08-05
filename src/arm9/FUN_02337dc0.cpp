//cpp
// decomp: module=unk_autoload_0 addr=0x02337dc0 name=FUN_02337dc0

// Retries FUN_0233831c(7, 0, 0) until it stops returning a negative value. The
// three arguments are loop-invariant and the ROM hoists them into r4/r5 outside
// the loop, which is what the do/while spelling produces.

#pragma thumb on
extern "C" {
extern int FUN_0233831c(int, int, int);
void FUN_02337dc0(void)
{
    int r;
    do { r = FUN_0233831c(7, 0, 0); } while (r < 0);
}
}
