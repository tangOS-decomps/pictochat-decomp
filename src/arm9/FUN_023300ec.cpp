//cpp
// decomp: module=unk_autoload_0 addr=0x023300ec name=FUN_023300ec

// Counts down the timer at +0x128 and fires FUN_0232eed8 on the tick that
// reaches zero. `p` is `volatile int *` because the ROM re-reads the field after
// storing it rather than reusing the decremented value.

#pragma thumb on
extern "C" {
extern void FUN_0232eed8(volatile int *);
void FUN_023300ec(volatile int *p)
{
    int v = p[0x4a];
    if (v != 0) {
        p[0x4a] = v - 1;
        if (p[0x4a] == 0) FUN_0232eed8(p);
    }
}
}
