//cpp
// decomp: module=unk_autoload_0 addr=0x0232aabc name=FUN_0232aabc

// Releases the registration at G_023bd698+0x54 through FUN_02331ef0 and clears
// the slot, but only if it is occupied.

#pragma thumb on
extern "C" {
extern void FUN_02331ef0(int *);
extern int G_023bd698[];
extern int G_023bd6fc[];
void FUN_0232aabc(void)
{
    if (G_023bd698[0x15] != 0) {
        FUN_02331ef0(G_023bd6fc);
        G_023bd698[0x15] = 0;
    }
}
}
