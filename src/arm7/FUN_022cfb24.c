// decomp: module=arm7 addr=0x022cfb24 name=FUN_022cfb24
// flags: -noThumb
// NONMATCHING: same CSE-steering floor as FUN_022ce658; tried 4 phrasings (div=999). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022cfb24 name=FUN_022cfb24
// NONMATCHING: allocates a packet buffer (FUN_022ce718), fills type=0x2b and
// the caller's param, enqueues it (func_037c9e90); on alloc failure OR a
// zero enqueue result, checks a "connected" flag and sends a notification
// via func_037d14bc/func_037d1464 if set. Logic-correct, same call sequence
// and count, but the target caches the 0x023180dc base in r4 once (right
// after the FUN_022ce718 call) and reuses it for both the +0x88 argument
// and the later +0x1000+0x54c dereference; every phrasing tried (raw
// integer-cast pointer arithmetic, a local `char *base`, a `volatile` local
// to force materialization, referencing the already-declared
// G_023180dc[] extern from FUN_022ce5b4.c) either constant-folds the first
// use into its own fresh pool load or (for the volatile attempt) spills to
// a stack slot the target doesn't have. Same CSE-steering floor as
// FUN_022ce658 (div counted via size mismatch: candidate compiles 8 bytes
// longer from the extra pool load). Counts as decompiled, not matched.
extern void *FUN_022ce718(void);
extern int func_037c9e90(void *a, void *pkt, int c);
extern void *func_037d14bc(void);
extern void func_037d1464(void *pkt);

void FUN_022cfb24(int param) {
    int *pkt = (int *)FUN_022ce718();
    char *base = (char *)0x023180dc;
    int r;
    if (pkt != 0) {
        pkt[0] = 0x2b;
        pkt[1] = param;
        r = func_037c9e90(base + 0x88, pkt, 0);
    } else {
        r = 0;
    }
    if (r == 0) {
        if (*(int *)(base + 0x1000 + 0x54c) != 0) {
            unsigned short *ind = (unsigned short *)func_037d14bc();
            ind[0] = 0x80;
            ind[1] = 8;
            ind[2] = 0x16;
            ind[3] = 0x2b;
            func_037d1464(ind);
        }
    }
}
