//cpp
// decomp: module=unk_autoload_0 addr=0x0232b834 name=FUN_0232b834
// verify: python tools/match.py --c src/arm9/FUN_0232b834.cpp --func FUN_0232b834 --addr 0x0232b834 --size 0x1e --module unk_autoload_0 --version 2.0/sp1

// Reports whether the queue is empty, sampled with interrupts held off - the
// saved state stays in r0 across the body, so restoring it costs no move.

#pragma thumb on
extern "C" {
typedef struct Q {
    char pad[8];
    unsigned short head;
    unsigned short tail;
} Q;
extern int FUN_02332080(void);
extern void FUN_02332094(int);
int FUN_0232b834(Q *q)
{
    int r;
    int s = FUN_02332080();

    if (q->head == q->tail) r = 1;
    else r = 0;
    FUN_02332094(s);
    return r;
}
}
