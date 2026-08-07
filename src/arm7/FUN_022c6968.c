// decomp: module=arm7 addr=0x022c6968 name=FUN_022c6968
// flags: -O4,s -noThumb

// Fills in an alarm descriptor and queues it.  Runs with interrupts masked.
// The tick stamp comes from FUN_022c6ce8 fed with the live VCOUNT; if the
// requested scanline has already gone past this frame the stamp is bumped to
// the next one.  A null descriptor, or one that is still armed, trips
// FUN_022c6e94.
// NOTE: verify with --size 0x90, not funcs.json's 0x8c - the stated size
// excludes this function's own trailing pool word.

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c6e94(void);
extern int FUN_022c6ce8(int vcount);
extern void FUN_022c67e8(void *node);

typedef struct Alarm {
    void *fn;      /* +0x00 */
    void *arg;     /* +0x04 */
    char pad8[4];  /* +0x08 */
    int tick;      /* +0x0c */
    short line;    /* +0x10 */
    short f12;     /* +0x12 */
    char pad14[8]; /* +0x14 */
    int armed;     /* +0x1c */
    char pad20[4]; /* +0x20 */
    int f24;       /* +0x24 */
} Alarm;

void FUN_022c6968(Alarm *n, int line, int f12, void *fn, void *arg)
{
    int state = FUN_022c6d40();
    int vcount;
    int tick;

    if (n == 0 || n->fn != 0) {
        FUN_022c6e94();
    }

    vcount = *(volatile unsigned short *)0x04000006;
    tick = FUN_022c6ce8(vcount);

    n->armed = 1;
    n->line = line;
    if (line <= vcount) {
        tick = tick + 1;
    }
    n->tick = tick;
    n->f12 = f12;
    n->fn = fn;
    n->arg = arg;
    n->f24 = 0;

    FUN_022c67e8(n);
    FUN_022c6d54(state);
}
