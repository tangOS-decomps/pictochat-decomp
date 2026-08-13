// decomp: module=arm7 addr=0x022d1e04 name=FUN_022d1e04
// NONMATCHING: register coloring only: ROM loads the err halfword into r1 at both test sites, candidate folds it into r0 (dead result reg); 4 words differ across the two ldrh/cmp pairs, shape identical; msg-var, decl-order and shared-variable spellings all leave it in r0 (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022d1e04 name=FUN_022d1e04
// flags: -O4,s -noThumb
// size: 0xd4 - the stated 0xc8 excludes the three trailing pool words.

// Type-0xb request handler, sibling of FUN_022d0edc: refuses with reason 3
// unless the state halfword is 5; otherwise queries FUN_022d08d4 (failure ->
// detail 0x302 via FUN_022d1ed8), parks the state at 2, and on the first pass
// (guarded by the halfword at +0x1ee) also runs FUN_022d05c0 (failure ->
// detail 0x20e). Success answers reason 0.

typedef struct Mgr1e04 {
    char pad[0x550];
    unsigned short *state;
} Mgr1e04;

extern Mgr1e04 G_023190dc;

extern unsigned short *FUN_022d08d4(void *out);
extern unsigned short *FUN_022d05c0(void *out, int arg);
extern void FUN_022d1ed8(int detail);
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d1e04(void) {
    char buf[0x200];
    char *bp = buf;
    unsigned short *state = G_023190dc.state;
    unsigned short *msg;
    unsigned short err;

    if (*state != 5) {
        msg = FUN_037d14bc();
        msg[0] = 0xb;
        msg[1] = 3;
        FUN_037d1464();
    } else {
        msg = FUN_022d08d4(bp);
        err = msg[2];
        if (err != 0) {
            FUN_022d1ed8(0x302);
        } else {
            *state = 2;
            if (state[0xf7] == 0) {
                msg = FUN_022d05c0(bp, 1);
                err = msg[2];
                if (err != 0) {
                    FUN_022d1ed8(0x20e);
                    return;
                }
                state[0xf7] = 1;
            }
            msg = FUN_037d14bc();
            msg[0] = 0xb;
            msg[1] = 0;
            FUN_037d1464();
        }
    }
}
