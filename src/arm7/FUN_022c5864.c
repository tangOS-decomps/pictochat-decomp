// decomp: module=arm7 addr=0x022c5864 name=FUN_022c5864
// flags: -O4,s -noThumb -interworking
// size: 0x84 - the stated 0x80 excludes the trailing pool word (0x03804f84).

// Mutex lock, the acquire side of FUN_022c58e8. Under interrupts-off: a free
// mutex is claimed (owner set, count bumped, FUN_022c5980 links it into the
// thread's owned list), a recursive take just bumps the count, and a
// contended one parks the thread on the mutex (+0x68 back-pointer) via the
// scheduler helper, then rechecks after waking.

typedef struct Thread5864 {
    char pad[0x68];
    void *f68;
} Thread5864;

typedef struct Mutex5864 {
    char pad[8];
    Thread5864 *owner;
    int count;
} Mutex5864;

typedef struct Sched5864 {
    char pad[4];
    Thread5864 *cur;
} Sched5864;

extern Sched5864 G_03804f84;

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c5980(Thread5864 *t, Mutex5864 *m);
extern void FUN_022c5274(Mutex5864 *m);

void FUN_022c5864(Mutex5864 *m)
{
    int state = FUN_022c6d40();
    Thread5864 *cur = G_03804f84.cur;

    for (;;) {
        Thread5864 *o = m->owner;
        if (o == 0) {
            m->owner = cur;
            m->count++;
            FUN_022c5980(cur, m);
        } else if (o == cur) {
            m->count++;
        } else {
            cur->f68 = m;
            FUN_022c5274(m);
            cur->f68 = 0;
            continue;
        }
        break;
    }

    FUN_022c6d54(state);
}
