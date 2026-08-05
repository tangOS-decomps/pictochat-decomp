//cpp
// decomp: module=unk_autoload_0 addr=0x02326780 name=FUN_02326780

// Distance between two ring positions: subtracts `v` from the field at +0x20,
// wraps a negative result by the 0x400 ring size, then subtracts that from the
// field at +4.

#pragma thumb on
extern "C" {
extern int G_0239c930[];
int FUN_02326780(int v)
{
    int d = G_0239c930[8] - v;
    if (d < 0) d += 0x400;
    return G_0239c930[1] - d;
}
}
