//cpp
// decomp: module=unk_autoload_0 addr=0x02330afc name=FUN_02330afc

// Increments the counter at +0x18 of G_023c07c4 and RETURNS the new value. The
// return is what puts the value in r0 and the base in r1; written as a plain
// `void` increment the two registers come out swapped.

#pragma thumb on
extern "C" {
extern int G_023c07c4[];
int FUN_02330afc(void)
{
    return ++G_023c07c4[6];
}
}
