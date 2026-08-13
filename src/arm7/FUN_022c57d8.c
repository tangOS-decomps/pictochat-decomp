// decomp: module=arm7 addr=0x022c57d8 name=FUN_022c57d8
// flags: -O4,s -noThumb

// Peek flavour of FUN_022c573c: waits (or gives up, by bit 0 of `flags`) until
// the ring holds a message, copies the head slot out without consuming it, and
// wakes nobody.

typedef struct Queue57d8 {
    char sync0[8];
    char sync1[8];
    void **buf;   /* +0x10 */
    int cap;      /* +0x14 */
    int head;     /* +0x18 */
    int count;    /* +0x1c */
} Queue57d8;

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c5274(void *sync);

int FUN_022c57d8(Queue57d8 *q, void **out, int flags)
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
    FUN_022c6d54(state);
    return 1;
}
