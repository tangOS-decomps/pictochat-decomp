//cpp
// decomp: module=unk_autoload_0 addr=0x02337818 name=FUN_02337818

// Forwards to the FUN_02337930 dispatcher under opcode 0x1a, with the two
// trailing arguments fixed at zero.

#pragma thumb on
extern "C" {
extern void FUN_02337930(int, int, int, int, int);
void FUN_02337818(int a, int b)
{
    FUN_02337930(0x1a, a, b, 0, 0);
}
}
