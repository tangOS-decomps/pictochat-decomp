// decomp: module=arm7 addr=0x022c678c name=FUN_022c678c
// flags: -O4,s -noThumb

// One-shot bring-up of the block at 0x0380520c: marks it started, clears the
// two tail counters, allocates IRQ line 4 and clears the two head counters.

extern void FUN_022c48a4(unsigned int mask);

typedef struct {
    unsigned short started; /* +0x00 */
    int a;                  /* +0x04 */
    int b;                  /* +0x08 */
    int c;                  /* +0x0c */
    int d;                  /* +0x10 */
} Block022c678c;

extern Block022c678c G_0380520c;

void FUN_022c678c(void)
{
    if (G_0380520c.started == 0) {
        G_0380520c.started = 1;
        G_0380520c.c = 0;
        G_0380520c.d = 0;
        FUN_022c48a4(4);
        G_0380520c.b = 0;
        G_0380520c.a = 0;
    }
}
