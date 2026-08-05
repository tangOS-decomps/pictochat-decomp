//cpp
// decomp: module=unk_autoload_0 addr=0x02321db4 name=FUN_02321db4

// Reprograms sub BG3CNT (0x0400100e) keeping only bits 0, 1 and 6, then clears
// and re-registers a 0x600-byte tile buffer.

#pragma thumb on
extern "C" {
extern int FUN_023215c8(void);
extern void FUN_0233746c(int, int, int);
extern void FUN_023314e8(int, int);
extern void FUN_02321568(int);
void FUN_02321db4(void)
{
    int v;
    *(unsigned short *)0x0400100e = (*(unsigned short *)0x0400100e & 0x43) | 0x810;
    v = FUN_023215c8();
    FUN_0233746c(0x8e008e, v, 0x600);
    v = FUN_023215c8();
    FUN_023314e8(v, 0x600);
    FUN_02321568(8);
}
}
