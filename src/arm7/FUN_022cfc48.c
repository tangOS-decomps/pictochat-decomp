// decomp: module=arm7 addr=0x022cfc48 name=FUN_022cfc48
// NONMATCHING: same CSE floor as FUN_022cfb24; -O4,s fixed the epilogue-sharing half but not the base-caching half (div=999). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022cfc48 name=FUN_022cfc48
// flags: -O4,s -noThumb
// NONMATCHING: zeroes 3 connection fields (+0x5e/+0x60/+0x88), then (same
// shape as FUN_022cfb24/FUN_022cfa90) allocates+enqueues a notification
// packet and sends a fallback notify if the enqueue failed or alloc failed.
// -O4,s (vs the default -O4,p) fixes the epilogue-sharing difference this
// family of functions hits (see FUN_022cfa90.c) - confirmed here too, down
// from 0xc bytes short to 4. The one remaining word is the same CSE
// floor as FUN_022cfb24/FUN_022ce658: target caches the 0x023180dc base in
// r4 once and reuses it for both the +0x88 call argument and the later
// +0x1000+0x54c dereference; candidate still folds the first use into its
// own fresh pool constant even with an explicit `char *base` local. Logic
// verified correct vs ROM; not byte-matchable from C at mwccarm dsi/1.3
// (div counted via size mismatch, candidate compiles 4 bytes longer).
// Counts as decompiled, not matched.
typedef struct Conn5 {
    char pad[0x5e];
    unsigned short f5e;
    unsigned short f60;
    char pad2[0x88 - 0x62];
    unsigned short f88;
} Conn5;

typedef struct ConnMgr9 {
    char pad[0x550];
    Conn5 *conn;
} ConnMgr9;

extern ConnMgr9 G_023190dc;
extern void *FUN_022ce718(void);
extern int func_037c9e90(void *a, void *pkt, int c);
extern void *func_037d14bc(void);
extern void func_037d1464(void *pkt);

void FUN_022cfc48(void) {
    int *pkt = (int *)FUN_022ce718();
    Conn5 *conn = G_023190dc.conn;
    conn->f5e = 0;
    conn->f60 = 0;
    char *base = (char *)0x023180dc;
    conn->f88 = 0;
    int r;
    if (pkt != 0) {
        pkt[0] = 0x2c;
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
            ind[3] = 0x2c;
            func_037d1464(ind);
        }
    }
}
