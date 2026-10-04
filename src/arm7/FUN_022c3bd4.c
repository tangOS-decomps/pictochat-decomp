// decomp: module=arm7 addr=0x022c3bd4 name=FUN_022c3bd4
// flags: -O4,s -noThumb
// size: 0x7c - the nominal 0x74 excludes the two trailing pool words.
// Matches under 2.0/sp2p2..sp2p4 (the title's build, see notes/setup-mwccarm.md);
// sp1..sp2 schedule the zero high word of the 1000 divisor differently.
//
// Busy-sleeps for `usec` microseconds: arms the alarm at +0x634 of the ARM7
// state block for that many ticks ((usec * 33514 / 64) / 1000) with `handler`
// and a pointer to a stack flag, then spins until the handler clears it.

typedef unsigned long long u64;

extern void FUN_022c651c(void *alarm, u64 tick, void (*handler)(void *), void *arg);

void FUN_022c3bd4(unsigned int usec, void (*handler)(void *))
{
    volatile int busy = 1;

    FUN_022c651c(*(char **)0x0380fff4 + 0x634, (u64)usec * 33514 / 64 / 1000,
                 handler, (void *)&busy);
    while (busy != 0) {
    }
}
