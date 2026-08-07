// decomp: module=arm7 addr=0x022d8984 name=FUN_022d8984
// flags: -O4,s -noThumb

// If the radio helper reports 0 ("nothing in flight") this just latches bit 6
// of the status halfword at +0x33e of the ARM7 state block; otherwise it walks
// the three queues at +0x608 / +0x634 / +0x660 and flushes each one.

extern int func_037cabb0(void);
extern void func_037cabc0(void *q);

void FUN_022d8984(void)
{
    int base = *(int *)0x0380fff4;

    if (func_037cabb0() == 0) {
        *(unsigned short *)(base + 0x33e) |= 0x40;
    } else {
        func_037cabc0((void *)(base + 0x608));
        func_037cabc0((void *)(base + 0x634));
        func_037cabc0((void *)(base + 0x660));
    }
}
