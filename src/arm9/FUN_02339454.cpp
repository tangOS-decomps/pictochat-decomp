//cpp
// decomp: module=unk_autoload_0 addr=0x02339454 name=FUN_02339454

// Retries FUN_0233831c(8, a, 0) until it stops reporting work.

#pragma thumb on
extern "C" {
extern int FUN_0233831c(int, int, int);
void FUN_02339454(int a)
{
    int r;
    do { r = FUN_0233831c(8, a, 0); } while (r != 0);
}
}
