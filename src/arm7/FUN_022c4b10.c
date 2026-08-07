// decomp: module=arm7 addr=0x022c4b10 name=FUN_022c4b10
// flags: -O4,s -noThumb
// Drives the transfer helper until it reports nothing left to do, waiting
// 0x400 ticks between attempts.
extern void FUN_022c49bc(int delay);
extern int FUN_022c4a9c(void *ctx, void *a, void *b, int mode);

void FUN_022c4b10(void *ctx)
{
    while (FUN_022c4a9c(ctx, (void *)0x02ffffe8, (void *)0x037fc63c, 1) > 0) {
        FUN_022c49bc(0x400);
    }
}
