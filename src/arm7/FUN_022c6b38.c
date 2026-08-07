// decomp: module=arm7 addr=0x022c6b38 name=FUN_022c6b38
// flags: -O4,s -noThumb
// size: 0x1b0 - 0x1a0 of code plus the four trailing pool words (0x04000004,
// 0x0380fff8, 0x04000006 and 0x0380520c).

// The V-count alarm service routine. It turns the compare interrupt off, marks
// the pending bit in the word at 0x0380fff8, folds the current REG_DISPSTAT
// compare line back into a scanline number and feeds line-1 to the wrap
// counter. It then walks the alarm list at 0x0380520c from the head: an entry
// still in the future (wrap count, then scanline) is simply re-armed and the
// routine returns unless the hardware raced past it; an entry that is due, or
// overdue by no more than its slack at +0x12, is unlinked and fired; an entry
// overdue by more is unlinked and rescheduled for the next wrap.
//
// The two globals have to be spelled differently: 0x0380fff8 as a literal
// address (a symbol there rotates the r0/r1 pair in the prologue), 0x0380520c
// as a symbol (a literal lets the compiler fold the +8 field offset into the
// pool word and load 0x03805214 instead).

extern unsigned int FUN_022c48a4(unsigned int mask);
extern void FUN_022c48e0(unsigned int mask);
extern int FUN_022c6ce8(int line);

typedef struct Alarm {
    void (*fn)(void *); /* 0x00 */
    void *arg;          /* 0x04 */
    char pad08[4];
    int wraps;          /* 0x0c */
    short line;         /* 0x10 */
    short slack;        /* 0x12 */
    struct Alarm *prev; /* 0x14 */
    struct Alarm *next; /* 0x18 */
    int repeat;         /* 0x1c */
    char pad20[4];
    int busy;           /* 0x24 */
} Alarm;

typedef struct AlarmList {
    char pad00[8];
    int wraps;   /* 0x08 */
    Alarm *head; /* 0x0c */
    Alarm *tail; /* 0x10 */
} AlarmList;


extern AlarmList G_0380520c;

extern void FUN_022c69f8(Alarm *a);
extern void FUN_022c688c(Alarm *a);
extern void FUN_022c67e8(Alarm *a);

void FUN_022c6b38(void)
{
    void (*fn)(void *);
    int st;
    int vc;
    int now;
    int diff;
    int late;
    int k;
    Alarm *a;

    FUN_022c48a4(4);
    *(volatile unsigned short *)0x04000004 &= ~0x20;
    *(unsigned int *)0x0380fff8 |= 4;

    st = *(volatile unsigned short *)0x04000004;
    FUN_022c6ce8((((st >> 8) & 0xff) | ((st << 1) & 0x100)) - 1);

    while ((a = G_0380520c.head) != 0) {
        vc = *(volatile unsigned short *)0x04000006;
        now = FUN_022c6ce8(vc);
        diff = now - a->wraps;
        late = vc - a->line;

        if (diff < 0 || (diff == 0 && late < 0)) {
            k = 0;
        } else {
            if (late < 0) {
                late += 263;
            }
            k = late <= a->slack ? 1 : 2;
        }

        switch (k) {
        case 0:
            FUN_022c69f8(a);
            vc = *(volatile unsigned short *)0x04000006;
            if (a->line != vc || a->wraps != now) {
                return;
            }
            FUN_022c48a4(4);
            *(volatile unsigned short *)0x04000004 &= ~0x20;
            FUN_022c48e0(4);
            /* fall through */
        case 1:
            fn = a->fn;
            FUN_022c688c(a);
            a->fn = 0;
            if (fn != 0) {
                fn(a->arg);
            }
            if (a->repeat != 0 && a->busy == 0) {
                a->fn = fn;
                a->wraps = G_0380520c.wraps + 1;
                FUN_022c67e8(a);
            }
            break;
        case 2:
            FUN_022c688c(a);
            a->wraps = G_0380520c.wraps + 1;
            FUN_022c67e8(a);
            break;
        }
    }
}
