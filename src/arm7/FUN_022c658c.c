// decomp: module=arm7 addr=0x022c658c name=FUN_022c658c
// flags: -O4,s -noThumb

// Periodic-alarm cousin of FUN_022c651c: takes TWO 64-bit tick values (the
// second split r3:[sp,#0x18] because APCS does not even-align long long, which
// is why its high half is loaded into r5 at entry), stores them at +0x1c and
// +0x24, publishes the handler/argument pair and links the block in with a
// zero base tick.
// Same FUN_022c6e94 quirk as FUN_022c651c: only reproduces with a (void)
// declaration.

typedef struct Alarm658c {
    void (*handler)(void *);
    void *arg;
    char pad[0x14];
    long long f1c;
    long long f24;
} Alarm658c;

extern void FUN_022c6e94(void);
extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c63f0(Alarm658c *alarm, long long when);

void FUN_022c658c(Alarm658c *alarm, long long ab, long long de,
                  void (*handler)(void *), void *arg) {
    int state;

    if (alarm == 0 || alarm->handler != 0) {
        FUN_022c6e94();
    }

    state = FUN_022c6d40();
    alarm->f1c = de;
    alarm->f24 = ab;
    alarm->handler = handler;
    alarm->arg = arg;
    FUN_022c63f0(alarm, 0);
    FUN_022c6d54(state);
}
