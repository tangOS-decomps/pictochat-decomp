// decomp: module=arm7 addr=0x022c4a10 name=FUN_022c4a10
// flags: -O4,s -noThumb
//
// Releases a lock word: refused with -2 unless `id` owns it. With interrupts
// masked (IRQ+FIQ when `all` is set, IRQ only otherwise) it clears the owner,
// runs the optional release hook, clears the lock flag and restores the
// previous interrupt state.

typedef struct LockWord {
    unsigned int flag;
    unsigned short owner;
    unsigned short ext;
} LockWord;

extern int FUN_022c6d6c(void);
extern int FUN_022c6d40(void);
extern void FUN_022c6d80(int prev);
extern void FUN_022c6d54(int prev);

int FUN_022c4a10(unsigned short id, LockWord *lock, void (*hook)(void), int all)
{
    int prev;

    if (id != lock->owner) {
        return -2;
    }
    if (all) {
        prev = FUN_022c6d6c();
    } else {
        prev = FUN_022c6d40();
    }
    lock->owner = 0;
    if (hook) {
        hook();
    }
    lock->flag = 0;
    if (all) {
        FUN_022c6d80(prev);
    } else {
        FUN_022c6d54(prev);
    }
    return 0;
}
