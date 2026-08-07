// decomp: module=arm7 addr=0x022c0d90 name=FUN_022c0d90
// flags: -O4,s -noThumb

// ARM7 message-dispatch loop: pulls one queued OS message from the state
// block's message queue (+0x308) and forwards it, then walks a ring of
// pending command slots (+0x00, read index +0x10, saved index +0x12,
// active index +0x14) under an IRQ-masked critical section
// (FUN_022c48a4 / FUN_022c486c), invoking the handler function-pointer
// table at +0xc0 (8-byte stride) for the slot resolved by FUN_022c0f00.
// Never returns - infinite dispatch loop, so there is no epilogue.
// NOTE: verify with --size 0xb8, not the nominal 0xac - the stated size
// excludes this function's own trailing 3-word literal pool.

typedef struct HandlerEntry {
    void (*fn)(void);        /* +0x00 */
    unsigned int unused;     /* +0x04 */
} HandlerEntry;

typedef struct Ctx {
    unsigned short slots[8];             /* +0x00 */
    unsigned short readIdx;              /* +0x10 */
    unsigned short savedIdx;             /* +0x12 */
    unsigned short activeIdx;            /* +0x14 */
    unsigned char pad1[0xc0 - 0x16];
    HandlerEntry handlers[1];            /* +0xc0 */
    unsigned char pad2[0x308 - 0xc8];
    void *queue;                         /* +0x308 */
} Ctx;

extern int FUN_022c573c(void *queue, void *out, int flag);
extern void FUN_022c0fb4(void *msg);
extern unsigned int FUN_022c48a4(unsigned int mask);
extern unsigned int FUN_022c486c(unsigned int mask);
extern unsigned short FUN_022c0f00(unsigned short idx);

void FUN_022c0d90(void)
{
    void *msg;
    Ctx *ctx = *(Ctx **)0x0380fff4;

    ctx->readIdx = 0;
    ctx->activeIdx = 0;

    for (;;) {
        unsigned int state;
        unsigned short entry;

        if (FUN_022c573c((*(Ctx **)0x0380fff4)->queue, &msg, 0) != 0) {
            FUN_022c0fb4(&msg);
        }

        unsigned short idx;

        state = FUN_022c48a4(0x01000010);
        idx = ctx->readIdx;
        ctx->savedIdx = idx;
        entry = ctx->slots[idx];
        if (entry == 0xffff) {
            ctx->readIdx = ctx->readIdx + 1;
            FUN_022c486c(state);
        } else {
            FUN_022c486c(state);
            ctx->activeIdx = FUN_022c0f00(ctx->savedIdx);
            ctx->handlers[ctx->activeIdx].fn();
            ctx->activeIdx = 0xffff;
        }
    }
}
