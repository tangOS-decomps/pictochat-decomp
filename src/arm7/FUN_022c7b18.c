// decomp: module=arm7 addr=0x022c7b18 name=FUN_022c7b18
// flags: -O4,s

// One-shot startup of the worker thread: guarded by the flag at G_03805300, it
// initialises the subsystem and then creates and wakes the thread that runs on
// the 1 KiB stack ending at G_03805814, at the caller-supplied priority.

#pragma thumb on

extern int G_03805300;
extern char G_03805370[];  // OSThread
extern char G_03805814[];  // stack top

extern void func_022c9c18(void);
extern void func_022c09e0(void *thread, void (*fn)(void *), void *arg,
                          void *stackTop, unsigned int stackSize,
                          unsigned int prio);
extern void func_022c0a20(void *thread);

void FUN_022c7b18(unsigned int prio)
{
    if (G_03805300 == 0) {
        G_03805300 = 1;
        func_022c9c18();
        func_022c09e0(G_03805370, (void (*)(void *))0x037ff671, 0,
                      G_03805814, 0x400, prio);
        func_022c0a20(G_03805370);
    }
}
