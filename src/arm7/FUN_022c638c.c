// decomp: module=arm7 addr=0x022c638c name=FUN_022c638c
// flags: -O4,s -noThumb

// One-shot bring-up of the block at 0x03805200: marks it started, runs
// FUN_022c614c, clears both counters and enables IRQ line 0x10.
//
// Two spellings are load-bearing here. The block has to be reached through a
// local pointer holding the raw address - an `extern` symbol, or the address
// used inline at each field, colours the base/value registers the other way
// round. And `-O4,s` is what makes the guard branch to the shared epilogue;
// under any `,p` level mwcc inlines a `popne`/`bxne` return instead.

extern void FUN_022c614c(void);
extern void FUN_022c48a4(unsigned int mask);

typedef struct {
    unsigned short started; /* +0x00 */
    int a;                  /* +0x04 */
    int b;                  /* +0x08 */
} Block022c638c;

void FUN_022c638c(void)
{
    Block022c638c *p = (Block022c638c *)0x03805200;

    if (p->started == 0) {
        p->started = 1;
        FUN_022c614c();
        p->a = 0;
        p->b = 0;
        FUN_022c48a4(0x10);
    }
}
