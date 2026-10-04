// decomp: module=arm7 addr=0x022c2e40 name=FUN_022c2e40
// flags: -O4,s -noThumb
// size: 0xc8 - the nominal 0xc4 excludes the trailing pool word.
//
// TX abort hook (called from FUN_022c22b0). Stops the three TX queues, then
// for each of them (2, 1, 0) that is marked active either notes that a frame
// is still queued or clears the active flag. Event 0xe is reported if any
// frame was left over; event 0x14 always.
//
// CALLEE NOTE: the three `bl`s decode to 0x00dda510 - a placeholder name in
// the same sense as FUN_00dd8cfc in FUN_022c22b0.

typedef unsigned short u16;

typedef struct TxQ {
    u16 active;
    u16 pad02[3];
    u16 *frame;
    char pad0c[8];
} TxQ;

extern void FUN_00dda510(int q);
extern void FUN_022c0e48(int a, int b);

void FUN_022c2e40(void)
{
    TxQ *q = (TxQ *)(*(char **)0x0380fff4 + 0x42c);
    int pending = 0;

    FUN_00dda510(2);
    FUN_00dda510(1);
    FUN_00dda510(0);

    if (q[2].active != 0) {
        if (*q[2].frame != 0) {
            pending = 1;
        } else {
            q[2].active = 0;
        }
    }
    if (q[1].active != 0) {
        if (*q[1].frame == 0) {
            q[1].active = 0;
        } else {
            pending = 1;
        }
    }
    if (q[0].active != 0) {
        if (*q[0].frame == 0) {
            q[0].active = 0;
        } else {
            pending = 1;
        }
    }

    if (pending) {
        FUN_022c0e48(0, 0xe);
    }
    FUN_022c0e48(0, 0x14);
}
