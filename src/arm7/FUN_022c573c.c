// decomp: module=arm7 addr=0x022c573c name=FUN_022c573c
// flags: -O4,s -noThumb

// Receive side of FUN_022c56b0: takes one message out of the ring-buffer
// queue under the interrupts-off critical section. When the ring is empty it
// either gives up (returning 0) or blocks on the scheduler helper - here on
// the second sync block at +8, waking the senders parked on the first.

typedef struct Queue573c {
    char sync0[8];
    char sync1[8];
    void **buf;   /* +0x10 */
    int cap;      /* +0x14 */
    int head;     /* +0x18 */
    int count;    /* +0x1c */
} Queue573c;

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c5274(void *sync);
extern void FUN_022c52c8(void *sync);

int FUN_022c573c(Queue573c *q, void **out, int flags)
{
    int state = FUN_022c6d40();
    int blocking = flags & 1;

    while (q->count == 0) {
        if (blocking == 0) {
            FUN_022c6d54(state);
            return 0;
        }
        FUN_022c5274(q->sync1);
    }

    if (out != 0) {
        *out = q->buf[q->head];
    }
    q->head = (q->head + 1) % q->cap;
    q->count--;
    FUN_022c52c8(q->sync0);
    FUN_022c6d54(state);
    return 1;
}
