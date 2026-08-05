//cpp
// decomp: module=unk_autoload_0 addr=0x023376e0 name=FUN_023376e0

// Forwards its four arguments to the FUN_02337930 dispatcher under opcode 2.

#pragma thumb on
extern "C" {
extern void FUN_02337930(int, int, int, int, int);
void FUN_023376e0(int a, int b, int c, int d)
{
    FUN_02337930(2, a, b, c, d);
}
}
