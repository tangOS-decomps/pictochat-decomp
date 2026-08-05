//cpp
// decomp: module=unk_autoload_0 addr=0x02329bd8 name=FUN_02329bd8

// Writes `v` into the field at +0x14 of G_023bd5e0, but only if the field is
// below 0xc or `v` is exactly 0xe - a priority guard that 0xe overrides.

#pragma thumb on
extern "C" {
extern int G_023bd5e0[];
void FUN_02329bd8(int v)
{
    if (G_023bd5e0[5] < 0xc || v == 0xe) G_023bd5e0[5] = v;
}
}
