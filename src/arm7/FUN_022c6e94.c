// decomp: module=arm7 addr=0x022c6e94 name=FUN_022c6e94
// flags: -noThumb

// Fatal-error entry: runs the one-time notify at 0x022c6ed0 the first time the
// flag at 0x03805224 is clear, reports through FUN_022c6d40 either way, then
// spins forever pumping FUN_022c5540.

extern void FUN_022c6ed0(int code);
extern void FUN_022c6d40(void);
extern void FUN_022c5540(void);

extern int G_03805224;

void FUN_022c6e94(void)
{
    if (G_03805224 == 0) {
        G_03805224 = 1;
        FUN_022c6ed0(0);
        FUN_022c6d40();
    } else {
        FUN_022c6d40();
    }

    for (;;) {
        FUN_022c5540();
    }
}
