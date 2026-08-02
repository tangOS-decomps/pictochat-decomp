// decomp: module=arm7 addr=0x022ce718 name=FUN_022ce718
// flags: -noThumb
// NONMATCHING: optimizer elides target's redundant loop-entry test branch; tried 5 phrasings (div=999). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022ce718 name=FUN_022ce718
// NONMATCHING: scans a 32-entry, 16-byte-stride slot array (embedded at
// +0xd0 in the connection struct) for the first entry with bit 0x8000 set in
// its flags word, clears that bit, and returns a pointer to it (or NULL if
// the connection struct itself doesn't exist yet) - a "allocate a free
// packet-buffer slot" primitive, called from FUN_022ce8b0 and others.
// Logic-correct, same instruction shapes/count, but the candidate's -O4
// optimizer proves the first loop iteration (i=0 < 0x20) always executes and
// elides the target's redundant initial "jump to the bottom test before
// entering the loop body" branch (the standard for-loop test-at-bottom
// rotation, which the target keeps even though it's providably always taken
// on the first pass). Tried 5 phrasings (nested if+for, while, merged
// null-check into the for condition, `i != 0x20` instead of `<`, raw
// pointer arithmetic instead of an array member) - none reproduce the extra
// branch; likely a real codegen floor around when this compiler elides a
// provably-true loop-entry test, not a logic issue (candidate is 4 bytes
// shorter from the one missing branch). Counts as decompiled, not matched.
typedef struct Slot {
    unsigned int flags;
    char pad[0xc];
} Slot;

typedef struct Conn2 {
    char pad[0xd0];
    Slot slots[0x20];
} Conn2;

typedef struct ConnMgr4 {
    char pad[0x54c];
    Conn2 *conn;
} ConnMgr4;

extern ConnMgr4 G_023190dc;
extern int func_037cb520(void);
extern void func_037cb534(int state);

void *FUN_022ce718(void) {
    void *result = 0;
    int state = func_037cb520();
    Conn2 *conn = G_023190dc.conn;
    if (conn != 0) {
        int i;
        for (i = 0; i < 0x20; i++) {
            if (conn->slots[i].flags & 0x8000) {
                conn->slots[i].flags &= ~0x8000;
                result = &conn->slots[i];
                break;
            }
        }
    }
    func_037cb534(state);
    return result;
}
