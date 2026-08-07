// decomp: module=arm7 addr=0x022c4e28 name=FUN_022c4e28
// flags: -O4,s -noThumb

// Scheduler reschedule point. Bails out while the lock word at
// G_03804f68+0x04 is held; if a "defer" flag is set at G_03804f68+0x1e, or we
// are running in IRQ mode (ARMProcessorMode() == 0x12), it just latches the
// pending-switch halfword at G_03804f84 and leaves. Otherwise it picks the
// next runnable node (FUN_022c537c), and if that differs from the current one
// and the current node is either already in state 2 or successfully saved by
// FUN_022c5628, runs the two switch hooks (G_03804f68.hook / G_03804f84.hook,
// both called with (current, next)), publishes `next` at G_03804f68+0x20 and
// resumes it via FUN_022c565c.
//
// FUN_022c6d98 is the ARMProcessorMode() accessor landed as
// src/arm7/ARMProcessorMode_022c6d98.cpp; the reloc slot is wildcarded so the
// spelling here is local.
//
// NOTE: verify with --size 0xd4, not 0xcc - the stated bound excludes this
// function's own two trailing pool words.

typedef void (*Hook4e28)(void *cur, void *next);

typedef struct Node4e28 {
    char pad[0x48];
    int state; /* +0x48 */
} Node4e28;

typedef struct Sched4e28 {
    Hook4e28 hook;      /* +0x00 */
    int lock;           /* +0x04 */
    Node4e28 **cur;     /* +0x08 */
    char pad0c[0x12];
    unsigned short defer; /* +0x1e */
    Node4e28 *running;  /* +0x20 */
} Sched4e28;

typedef struct Pend4e28 {
    unsigned short pending; /* +0x00 */
    char pad02[0xa];
    Hook4e28 hook;          /* +0x0c */
} Pend4e28;

extern Sched4e28 G_03804f68;
extern Pend4e28 G_03804f84;

extern int FUN_022c6d98(void);
extern Node4e28 *FUN_022c537c(void);
extern int FUN_022c5628(Node4e28 *node);
extern void FUN_022c565c(Node4e28 *node);

void FUN_022c4e28(void)
{
    Pend4e28 *pend;
    Node4e28 *next;
    Node4e28 *cur;
    Hook4e28 hook;

    if (G_03804f68.lock != 0) {
        return;
    }

    pend = &G_03804f84;
    if (G_03804f68.defer != 0 || FUN_022c6d98() == 0x12) {
        pend->pending = 1;
        return;
    }

    cur = *G_03804f68.cur;
    next = FUN_022c537c();
    if (cur == next || next == 0) {
        return;
    }

    if (cur->state != 2) {
        if (FUN_022c5628(cur) != 0) {
            return;
        }
    }

    hook = G_03804f68.hook;
    if (hook != 0) {
        hook(cur, next);
    }
    hook = pend->hook;
    if (hook != 0) {
        hook(cur, next);
    }

    G_03804f68.running = next;
    FUN_022c565c(next);
}
