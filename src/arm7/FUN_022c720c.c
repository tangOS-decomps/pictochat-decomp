// decomp: module=arm7 addr=0x022c720c name=FUN_022c720c
// flags: -O4,s

// Arms the periodic housekeeping alarm at 0x0380522c: only if both readiness
// probes pass and the "already armed" flag at 0x03805228 is still clear does it
// create the alarm and schedule FUN_037fed40 to fire every 0x82e ticks, starting
// 0x82e ticks from now. Returns 1 when the alarm was armed, 0 otherwise.

#pragma thumb on

extern int FUN_022c7274(void);
extern int FUN_022c7280(void);
extern void FUN_022c728c(void *alarm);
extern long long FUN_022c7298(void);
extern void FUN_022c72a4(void *alarm, long long start, long long period,
                         void *handler, void *arg);
extern void FUN_037fed40(void);

extern int G_03805228;
extern int G_0380522c;

int FUN_022c720c(void)
{
    if (FUN_022c7274() == 0 || FUN_022c7280() == 0) {
        return 0;
    }
    if (G_03805228 != 0) {
        return 0;
    }
    FUN_022c728c(&G_0380522c);
    FUN_022c72a4(&G_0380522c, FUN_022c7298() + 0x82e, 0x82e,
                 (void *)FUN_037fed40, 0);
    G_03805228 = 1;
    return 1;
}
