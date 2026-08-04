// decomp: module=arm7 addr=0x022ce658 name=FUN_022ce658
// flags: -noThumb
// Was parked NONMATCHING (optimizer CSE-caches a repeated base pointer across calls where the target reloads it fresh);
// that verdict said "not byte-matchable from C at mwccarm dsi/1.3" and
// was reached under the WRONG compiler. This ROM is built by 2.0/*
// (notes/setup-mwccarm.md); this file compiles BYTE-EXACT on
// 2.0/sp1..2.0/sp2p4 completely unchanged - no source edit was needed,
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
