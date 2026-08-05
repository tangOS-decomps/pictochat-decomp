//cpp
// decomp: module=unk_autoload_0 addr=0x0232ef28 name=FUN_0232ef28

// Tests the low bit of the word at +0x2c and, when set, passes the object on to
// FUN_0232ef7c.
//
// Two details are load-bearing. The bit test is a sign-extending shift pair
// (`lsls #31`, `asrs #31`), not an `and`, so it has to be written as the shift.
// And FUN_0232ef7c TAKES the object: the ROM leaves r0 untouched across the
// test, which only happens if the pointer is still live for the call.

#pragma thumb on
extern "C" {
extern void FUN_0232ef7c(int);
void FUN_0232ef28(int p)
{
    if (((*(int *)(p + 0x2c) << 31) >> 31) != 0) FUN_0232ef7c(p);
}
}
