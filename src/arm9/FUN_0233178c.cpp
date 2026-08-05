//cpp
// decomp: module=unk_autoload_0 addr=0x0233178c name=FUN_0233178c

// Writes `v` into slot `i` of the word table at 0x02fffdc4.

#pragma thumb on
extern "C" {
void FUN_0233178c(int i, int v)
{
    ((int *)0x02fffdc4)[i] = v;
}
}
