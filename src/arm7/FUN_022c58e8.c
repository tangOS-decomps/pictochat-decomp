// decomp: module=arm7 addr=0x022c58e8 name=FUN_022c58e8
// flags: -noThumb

// Mutex unlock.  Under interrupts-off, drops one level of the recursion count
// held by the current thread; on the last release the mutex is unlinked from
// that thread's owned-mutex list, marked free and any waiter is woken.

typedef struct Thread Thread;

typedef struct Mutex {
    char pad[8];
    Thread *owner;
    int count;
} Mutex;

typedef struct Sched {
    char pad[4];
    Thread *cur;
} Sched;

extern Sched G_03804f84;

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c59a4(Thread *t, Mutex *m);
extern void FUN_022c52c8(Mutex *m);

void FUN_022c58e8(Mutex *m)
{
    int state = FUN_022c6d40();
    Thread *cur = G_03804f84.cur;

    if (m->owner == cur) {
        if (--m->count == 0) {
            FUN_022c59a4(cur, m);
            m->owner = 0;
            FUN_022c52c8(m);
        }
    }

    FUN_022c6d54(state);
}
