//cpp
// decomp: module=unk_autoload_0 addr=0x02325d28 name=FUN_02325d28
// verify: python tools/match.py --c src/arm9/FUN_02325d28.cpp --func FUN_02325d28 --addr 0x02325d28 --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Every twentieth tick, raises the flag at G_0239c914+8.

#pragma thumb on
extern "C" {
typedef struct V3 { int b[3]; } V3;
extern void FUN_02322be8(V3 *);
extern int *FUN_0232254c(void);
extern int G_0239c914[];
void FUN_02325d28(void)
{
    V3 v;

    FUN_02322be8(&v);
    if (FUN_0232254c()[1] % 0x14 == 0) G_0239c914[2] = 1;
}
}
