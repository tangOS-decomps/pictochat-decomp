// decomp: module=arm7 addr=0x022c5038 name=FUN_022c5038
// flags: -O4,s -noThumb
// size: 0x108 - the nominal 0xf8 excludes the four trailing pool words.
//
// Thread creation (OS_CreateThread shape). With interrupts masked it takes
// the next id from the thread-info block at 0x03804f68 (+0x18), sets
// priority/id/state, links the thread into the priority-sorted list
// (FUN_022c4d84), records the stack bounds and plants the two stack guard
// words, builds the initial context (FUN_022c55bc) with `arg` in r0 and the
// thread-exit routine at 0x037fcbd0 as lr, zero-fills the stack body and
// clears the mutex/queue/link/specific/alarm/destructor fields.

typedef unsigned int u32;

typedef struct Context {
    u32 cpsr;            /* +0x00 */
    u32 r[13];           /* +0x04 */
    u32 sp;              /* +0x38 */
    u32 lr;              /* +0x3c */
    u32 pc_plus4;        /* +0x40 */
    u32 sp_svc;          /* +0x44 */
} Context;

typedef struct Thread Thread;

typedef struct ThreadQueue {
    Thread *head;
    Thread *tail;
} ThreadQueue;

struct Thread {
    Context context;           /* +0x00 */
    u32 state;                 /* +0x48 */
    Thread *next;              /* +0x4c */
    u32 id;                    /* +0x50 */
    u32 priority;              /* +0x54 */
    void *profiler;            /* +0x58 */
    void *queue;               /* +0x5c */
    Thread *linkPrev;          /* +0x60 */
    Thread *linkNext;          /* +0x64 */
    void *mutex;               /* +0x68 */
    void *mutexHead;           /* +0x6c */
    void *mutexTail;           /* +0x70 */
    u32 stackTop;              /* +0x74 */
    u32 stackBottom;           /* +0x78 */
    u32 stackWarningOffset;    /* +0x7c */
    ThreadQueue joinQueue;     /* +0x80 */
    void *specific[3];         /* +0x88 */
    void *alarmForSleep;       /* +0x94 */
    void *destructor;          /* +0x98 */
};

typedef struct ThreadInfo {
    char pad[0x18];
    int idCount;               /* +0x18 */
} ThreadInfo;

extern ThreadInfo G_03804f68;
extern void G_037fcbd0(void);

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c4d84(Thread *thread);
extern void FUN_022c55bc(Context *ctx, void (*func)(void *), u32 sp);
extern void FUN_022c6fc8(int value, void *dst, u32 size);

void FUN_022c5038(Thread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio)
{
    int enable = FUN_022c6d40();
    int id = ++G_03804f68.idCount;

    thread->priority = prio;
    thread->id = id;
    thread->state = 0;
    thread->profiler = 0;
    FUN_022c4d84(thread);

    thread->stackBottom = (u32)stack;
    thread->stackTop = (u32)stack - stackSize;
    thread->stackWarningOffset = 0;
    *(u32 *)(thread->stackBottom - 8) = 0xd73bfdf7;
    *(u32 *)thread->stackTop = 0xfbdd37bb;

    thread->joinQueue.head = thread->joinQueue.tail = 0;

    FUN_022c55bc(&thread->context, func, (u32)stack - 8);
    thread->context.r[0] = (u32)arg;
    thread->context.lr = (u32)G_037fcbd0;

    FUN_022c6fc8(0, (void *)((u32)stack - stackSize + 4), stackSize - 12);

    thread->mutex = 0;
    thread->mutexHead = 0;
    thread->mutexTail = 0;
    thread->destructor = 0;
    thread->queue = 0;
    thread->linkPrev = thread->linkNext = 0;
    FUN_022c6fc8(0, thread->specific, sizeof(thread->specific));
    thread->alarmForSleep = 0;

    FUN_022c6d54(enable);
}
