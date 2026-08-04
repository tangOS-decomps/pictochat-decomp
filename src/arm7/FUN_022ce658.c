// decomp: module=arm7 addr=0x022ce658 name=FUN_022ce658
// flags: -noThumb
//
// Under an IRQ-disable/restore bracket: calls func_037c9d2c(), then
// func_037c9b84() three times with a mix of fixed string/address constants
// and 3 adjacent ConnMgr fields (+0x584/+0x588/+0x58c) - the middle call's
// first argument is FUN_022d6bec()'s return value - then func_037c9d64().
//
// History: was parked NONMATCHING on the grounds that the target reloads the
// ConnMgr base pool constant fresh before each of the 3 field accesses (3
// separate `ldr rX,[pc,#N]` of the same 0x023190dc) while -O4 CSE cached it
// in a callee-saved register across the intervening calls, needing 2-3 more
// callee-saved registers (push {r4,r5,r6,lr} vs the target's {r4,lr}). Three
// phrasings were tried and it was recorded as a real optimizer floor. It was
// not: that verdict was reached at mwccarm dsi/1.3, and this ROM is built by
// 2.0/* (notes/setup-mwccarm.md). This file compiles BYTE-EXACT on
// 2.0/sp1..2.0/sp2p4 completely unchanged - no source edit was ever needed,
// only the correct toolchain.

typedef struct ConnMgr6 {
    char pad[0x584];
    unsigned int f584;
    unsigned int f588;
    unsigned int f58c;
} ConnMgr6;

extern ConnMgr6 G_023190dc;
extern int func_037cb520(void);
extern void func_037cb534(int state);
extern void func_037c9d2c(void);
extern void func_037c9b84(void *a, unsigned int b);
extern char *FUN_022d6bec(void);
extern void func_037c9d64(void);

void FUN_022ce658(void) {
    int state = func_037cb520();
    func_037c9d2c();
    func_037c9b84((void *)0x03807090, G_023190dc.f58c);
    char *r = FUN_022d6bec();
    func_037c9b84(r, G_023190dc.f588);
    func_037c9b84((void *)0x03807134, G_023190dc.f584);
    func_037c9d64();
    func_037cb534(state);
}
