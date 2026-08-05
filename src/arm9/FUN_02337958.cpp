//cpp
// decomp: module=unk_autoload_0 addr=0x02337958 name=FUN_02337958

// One-shot init guarded by the flag at G_023c1930: sets the flag, hands
// G_023c1934 to FUN_02331368, then runs FUN_023379a0 and FUN_02337e38.
//
// The two globals are adjacent but reached through SEPARATE pool words, so they
// have to be separate symbols rather than two indices into one array.

#pragma thumb on
extern "C" {
extern void FUN_02331368(int *);
extern void FUN_023379a0(void);
extern void FUN_02337e38(void);
extern int G_023c1930[];
extern int G_023c1934[];
void FUN_02337958(void)
{
    if (G_023c1930[0] == 0) {
        G_023c1930[0] = 1;
        FUN_02331368(G_023c1934);
        FUN_023379a0();
        FUN_02337e38();
    }
}
}
