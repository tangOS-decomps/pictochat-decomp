// decomp: module=arm7 addr=0x022c56b0 name=FUN_022c56b0
// flags: -O4,s -noThumb

// Posts one message into a ring-buffer queue under an interrupts-off critical
// section.  When the ring is full it either gives up (returning 0) or blocks
// on the scheduler helper, depending on bit 0 of `flags`.  The slot index is
// the signed modulo (head + count) % capacity, which is why r1 (the remainder
// half of the _s32_div_f result) survives the call.

typedef struct Queue {
    char pad[8];
    char sync[8];
    void **buf;
    int cap;
    int head;
    int count;
} Queue;

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c5274(void *q);
extern void FUN_022c52c8(void *sync);

int FUN_022c56b0(Queue *q, void *msg, int flags)
{
    int state = FUN_022c6d40();
    int blocking = flags & 1;

    while (q->cap <= q->count) {
        if (blocking == 0) {
            FUN_022c6d54(state);
            return 0;
        }
        FUN_022c5274(q);
    }

    q->buf[(q->head + q->count) % q->cap] = msg;
    q->count++;
    FUN_022c52c8(q->sync);
    FUN_022c6d54(state);
    return 1;
}
