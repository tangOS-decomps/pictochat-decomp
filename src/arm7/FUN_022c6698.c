// decomp: module=arm7 addr=0x022c6698 name=FUN_022c6698
// flags: -O4,s -noThumb
// size: 0xf4 - the nominal 0xe8 excludes the three trailing pool words
// (0x04000106, 0x0380fff8, 0x03805200).

// The timer-3 alarm interrupt handler. Stops TM3, masks and re-flags the
// timer-3 IRQ, then pops the head of the alarm queue if it is due: unlinks it,
// clears its handler when it is a one-shot, runs the handler, re-inserts it
// when it is periodic, and finally re-arms the hardware timer for whatever is
// now at the head. If the head is not due yet the timer is simply re-armed.
//
// The alarm layout is the stock NitroSDK OSAlarm: `fire` and `period` are
// 64-bit ticks sitting at +0xc and +0x1c, which is what produces the paired
// `cmp hi / cmpeq lo` sequences.

typedef struct OSAlarm {
    void (*handler)(void *);   /* +0x00 */
    void *arg;                 /* +0x04 */
    unsigned int tag;          /* +0x08 */
    unsigned long long fire;   /* +0x0c */
    struct OSAlarm *prev;      /* +0x14 */
    struct OSAlarm *next;      /* +0x18 */
    unsigned long long period; /* +0x1c */
} OSAlarm;

typedef struct AlarmQueue {
    unsigned int pad;
    OSAlarm *head; /* +0x04 */
    OSAlarm *tail; /* +0x08 */
} AlarmQueue;

extern AlarmQueue G_03805200;

extern void FUN_022c48a4(unsigned int mask);
extern unsigned long long FUN_022c625c(void);
extern void FUN_022c6300(OSAlarm *alarm);
// Third argument inferred from the r1/r2 pair set up at the call site.
extern void FUN_022c63f0(OSAlarm *alarm, int a, int b);

void FUN_022c6698(void)
{
    OSAlarm *alarm;
    OSAlarm *next;
    void (*handler)(void *);
    unsigned long long tick;

    *(volatile unsigned short *)0x04000106 = 0;
    FUN_022c48a4(0x10);
    *(unsigned int *)0x0380fff8 |= 0x10;
    tick = FUN_022c625c();

    alarm = G_03805200.head;
    if (alarm == 0) {
        return;
    }

    if (tick < alarm->fire) {
        FUN_022c6300(alarm);
        return;
    }

    next = alarm->next;
    G_03805200.head = next;
    if (next == 0) {
        G_03805200.tail = 0;
    } else {
        next->prev = 0;
    }

    handler = alarm->handler;
    if (alarm->period == 0) {
        alarm->handler = 0;
    }

    if (handler != 0) {
        handler(alarm->arg);
    }

    if (alarm->period != 0) {
        alarm->handler = handler;
        FUN_022c63f0(alarm, 0, 0);
    }

    if (G_03805200.head != 0) {
        FUN_022c6300(G_03805200.head);
    }
}
