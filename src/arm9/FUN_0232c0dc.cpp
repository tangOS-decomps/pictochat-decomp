//cpp
// decomp: module=unk_autoload_0 addr=0x0232c0dc name=FUN_0232c0dc

// True when FUN_0232b834 accepts G_023bd878 and the flag at G_023bd874 is clear.

#pragma thumb on
extern "C" {
extern int FUN_0232b834(void *);
extern int G_023bd878[];
extern int G_023bd874[];
int FUN_0232c0dc(void)
{
    if (FUN_0232b834(G_023bd878) != 0 && G_023bd874[0] == 0) return 1;
    return 0;
}
}
