//cpp
// decomp: module=unk_autoload_0 addr=0x023320fc name=FUN_023320fc

// Doubles `n` and, if the result is past 0x10, forwards the excess to
// FUN_023320f0. The comparison is UNSIGNED - the ROM has `bls`, and a signed
// compare gives `ble`.

#pragma thumb on
extern "C" {
extern void FUN_023320f0(unsigned int);
void FUN_023320fc(unsigned int n)
{
    unsigned int v = n * 2;
    if (v > 0x10) FUN_023320f0(v - 0x10);
}
}
