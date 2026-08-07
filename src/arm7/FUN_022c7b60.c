// decomp: module=arm7 addr=0x022c7b60 name=FUN_022c7b60
// flags: -O4,s
// Arms the periodic alarm object at 0x03805344 to first fire 0x10000 ticks
// from now and then repeat every 0xaa8 ticks, with a null user argument.
// FUN_022c7298 / FUN_022c72a4 are the Thumb->ARM veneers parked after this
// code (they forward to 0x037fdcec and 0x037fe01c).  The handler pool word is
// the odd Thumb address 0x037ff65d, spelled as a literal here so the pool
// reproduces exactly rather than going through a relocation.
// NOTE: verify with --size 0x40, not funcs.json's 0x32 - the stated size
// excludes the 2-byte alignment nop and the three trailing pool words.
#pragma thumb on

typedef long long OSTick;

extern char G_03805344[];
extern OSTick FUN_022c7298(void);
extern void FUN_022c72a4(void *alarm, OSTick start, OSTick period,
                         void *handler, void *arg);

void FUN_022c7b60(void) {
    FUN_022c72a4(G_03805344, FUN_022c7298() + 0x10000, 0xaa8,
                 (void *)0x037ff65d, 0);
}
