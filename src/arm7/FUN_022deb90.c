// decomp: module=arm7 addr=0x022deb90 name=FUN_022deb90
// flags: -noThumb

// Kicks the power-management write with interrupts for the source masked out,
// flushing the pending request at +0x468 first, then restores the mask.

typedef struct Pending {
    char pad[0x3c];
    unsigned short f3c;
} Pending;

typedef struct State {
    char pad[0x42c];
    Pending pending;
} State;

extern unsigned int FUN_037c9084(unsigned int mask);
extern void FUN_037c904c(unsigned int mask);
extern void FUN_037c7d3c(void);

void FUN_022deb90(void) {
    Pending *pending = &(*(State **)0x0380fff4)->pending;
    unsigned int old = FUN_037c9084(0x1000000);
    *(volatile unsigned short *)0x048080b4 = 2;
    if (pending->f3c != 0) FUN_037c7d3c();
    FUN_037c904c(old);
}
