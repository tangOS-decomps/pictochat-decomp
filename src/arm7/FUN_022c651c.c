// decomp: module=arm7 addr=0x022c651c name=FUN_022c651c
// flags: -O4,s -noThumb
//
// Arms an alarm block: rejects a null or already-armed block, then under the
// usual interrupt-off critical section publishes the handler/user argument and
// links the block in at `tick` ticks past the current tick count.
// The 64-bit `tick` rides in r1:r2 (APCS does not even-align long long), and
// FUN_022c625c hands its 64-bit result back in r0:r1.
//
// NOTE: FUN_022c6e94 is called here with no argument set up; src/arm7/
// FUN_022c4914.c declares it as taking an unsigned short.  This call site only
// reproduces with a (void) declaration.

typedef struct Alarm651c {
    void (*handler)(void *);
    void *arg;
    char pad[0x14];
    int f1c;
    int f20;
} Alarm651c;

extern void FUN_022c6e94(void);
extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern long long FUN_022c625c(void);
extern void FUN_022c63f0(Alarm651c *alarm, long long when);

void FUN_022c651c(Alarm651c *alarm, long long tick, void (*handler)(void *),
                  void *arg) {
    int state;

    if (alarm == 0 || alarm->handler != 0) {
        FUN_022c6e94();
    }

    state = FUN_022c6d40();
    alarm->f1c = 0;
    alarm->f20 = 0;
    alarm->handler = handler;
    alarm->arg = arg;
    FUN_022c63f0(alarm, tick + FUN_022c625c());
    FUN_022c6d54(state);
}
