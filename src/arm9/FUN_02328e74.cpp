//cpp
// decomp: module=unk_autoload_0 addr=0x02328e74 name=FUN_02328e74

// Resets the work area: clears the flag at G_023a0f0c, optionally runs
// FUN_0232a428, then clears 0x580 bytes at G_023a0f70 and re-registers it.

#pragma thumb on
extern "C" {
extern void FUN_0232a428(void);
extern void FUN_0233746c(int, void *, int);
extern void FUN_023314e8(void *, int);
extern void FUN_02329524(void);
extern int G_023a0f0c[];
extern int G_023a0f70[];
void FUN_02328e74(int f)
{
    G_023a0f0c[0] = 0;
    if (f != 0) FUN_0232a428();
    FUN_0233746c(0, G_023a0f70, 0x580);
    FUN_023314e8(G_023a0f70, 0x580);
    FUN_02329524();
}
}
