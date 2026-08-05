//cpp
// decomp: module=unk_autoload_0 addr=0x02322870 name=FUN_02322870

// Reads the low nibble of the byte at 0x02fffc82.
//
// The nibble is a BITFIELD, not an `& 0xf`. The ROM extracts it with an
// lsls/lsrs #28 pair; writing the mask - even spelled as those two shifts -
// gets folded back into a single `and` and does not match. Declaring the field
// in a struct is what reproduces the shifts. The `>= 0x10` test can never fire
// on a 4-bit field, but it is in the ROM, so it is here.

#pragma thumb on
extern "C" {
struct S { unsigned char f : 4; unsigned char rest : 4; };
int FUN_02322870(void)
{
    int v = ((struct S *)0x02fffc82)->f;
    if (v >= 0x10) v = 1;
    return v;
}
}
