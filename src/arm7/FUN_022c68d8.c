// decomp: module=arm7 addr=0x022c68d8 name=FUN_022c68d8
// flags: -O4,s -noThumb

// Arms an alarm block: samples VCOUNT, converts it to a wrap count via
// FUN_022c6ce8 (bumping by one when the requested scanline has already gone
// past this frame), records the period/handler/argument and hands the block to
// the scheduler at FUN_022c67e8.  Runs with interrupts masked throughout, and
// traps through FUN_022c6e94 if the block is null or still linked.

extern unsigned int IRQ_Disable(void);
extern unsigned int IRQ_Restore(unsigned int state);
extern void FUN_022c6e94(void);
extern int FUN_022c6ce8(int v);
extern void FUN_022c67e8(void *alarm, int mode);

typedef struct Alarm {
    void *next;              /* 0x00 */
    void *arg;               /* 0x04 */
    char pad8[4];            /* 0x08 */
    int frame;               /* 0x0c */
    unsigned short line;     /* 0x10 */
    unsigned short period;   /* 0x12 */
    char pad14[8];           /* 0x14 */
    int f1c;                 /* 0x1c */
    char pad20[4];           /* 0x20 */
    int f24;                 /* 0x24 */
} Alarm;

void FUN_022c68d8(Alarm *a, unsigned short line, unsigned short period,
                  void *handler, void *arg)
{
    unsigned int state = IRQ_Disable();
    int vcount;
    int frame;

    if (a == 0 || a->next != 0) {
        FUN_022c6e94();
    }

    vcount = *(volatile unsigned short *)0x04000006;
    frame = FUN_022c6ce8(vcount);
    a->f1c = 0;
    a->line = line;
    if (line <= vcount) {
        frame = frame + 1;
    }
    a->frame = frame;
    a->period = period;
    a->next = handler;
    a->arg = arg;
    a->f24 = 0;
    FUN_022c67e8(a, 0);
    IRQ_Restore(state);
}
