// decomp: module=arm7 addr=0x022c5a14 name=FUN_022c5a14
// flags: -O4,s -noThumb

// One-shot init guarded by the flag word at 0x03805164: brings up channels
// 1, 7 and 8 the first time it is called and does nothing afterwards.

extern void FUN_022c5a50(int channel);

extern int G_03805164;

void FUN_022c5a14(void)
{
    if (G_03805164 == 0) {
        G_03805164 = 1;
        FUN_022c5a50(1);
        FUN_022c5a50(7);
        FUN_022c5a50(8);
    }
}
