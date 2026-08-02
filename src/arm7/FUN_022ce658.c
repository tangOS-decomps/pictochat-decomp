// decomp: module=arm7 addr=0x022ce658 name=FUN_022ce658
// flags: -noThumb
// NONMATCHING: optimizer CSE-caches repeated base pointer across calls; target reloads fresh each time; tried 3 phrasings (div=999). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022ce658 name=FUN_022ce658
// NONMATCHING: under an IRQ-disable/restore bracket, calls func_037c9d2c(),
// then func_037c9b84() three times with a mix of fixed string/address
// constants and 3 adjacent ConnMgr fields (+0x584/+0x588/+0x58c) - the
// middle call's first arg is FUN_022d6bec()'s return value - then
// func_037c9d64(). Logic-correct, same call sequence and count, but the
// target reloads the ConnMgr base pool constant fresh before each of the 3
// field accesses (3 separate `ldr rX,[pc,#N]` of the same 0x023190dc value)
// while the candidate's -O4 CSE always caches it in a callee-saved register
// across the intervening calls instead, needing 2-3 more callee-saved
// registers than the target (push {r4,r5,r6,lr} vs just {r4,lr}). Tried 3
// phrasings (struct-field access, separate extern globals per field, raw
// pointer-cast arithmetic per access) - CSE persisted every time; a real
// optimizer floor (see notes/tooling.md's "pointer register reused via
// cheap arithmetic" note), not a logic issue (candidate compiles 8 bytes
// shorter from the 2 elided reloads). Counts as decompiled, not matched.
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
