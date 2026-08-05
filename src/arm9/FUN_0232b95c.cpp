//cpp
// decomp: module=unk_autoload_0 addr=0x0232b95c name=FUN_0232b95c

// True when the mode from FUN_0232996c is 6 or 7 and the counter at
// G_023bd814+0x14 is zero. The mode is fetched twice.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern int G_023bd814[];
int FUN_0232b95c(void)
{
    if ((FUN_0232996c() == 6 || FUN_0232996c() == 7) && G_023bd814[5] == 0) return 1;
    return 0;
}
}
