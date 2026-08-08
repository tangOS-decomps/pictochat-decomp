//cpp
// decomp: module=unk_autoload_0 addr=0x02321df4 name=FUN_02321df4
// verify: python tools/match.py --c src/arm9/FUN_02321df4.cpp --func FUN_02321df4 --addr 0x02321df4 --size 0x30 --module unk_autoload_0 --version 2.0/sp1

// Resets the ten-word descriptor at G_0238e028 and tail-calls the setup for
// the block that follows it.

#pragma thumb on
extern "C" {
extern int G_0238e028[];
extern char G_0238e050[];
extern void FUN_0232131c(void *);
void FUN_02321df4(void)
{
    G_0238e028[0] = 0x90;
    G_0238e028[5] = -1;
    G_0238e028[1] = 0;
    G_0238e028[2] = 0;
    G_0238e028[3] = 0;
    G_0238e028[4] = 0;
    G_0238e028[6] = 0;
    G_0238e028[7] = 0;
    G_0238e028[8] = 0;
    G_0238e028[9] = 0;
    FUN_0232131c(G_0238e050);
}
}
