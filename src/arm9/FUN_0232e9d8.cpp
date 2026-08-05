//cpp
// decomp: module=unk_autoload_0 addr=0x0232e9d8 name=FUN_0232e9d8

// Forwards the handle byte at +0x3c of the object held in *p to FUN_02337720,
// but only when that object exists.
//
// `p` must be `volatile int *`. The ROM dereferences it TWICE - once to test and
// once to reload - and without volatile the compiler folds them into a single
// load, which is one instruction short.

#pragma thumb on
extern "C" {
extern void FUN_02337720(unsigned int, int);
void FUN_0232e9d8(volatile int *p, int a)
{
    if (*p != 0) FUN_02337720(*(unsigned char *)(*p + 0x3c), a);
}
}
