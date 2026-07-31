// decomp: module=unk_autoload_0 addr=0x02329bf0 name=FUN_02329bf0
// NONMATCHING: register-coloring floor: target keeps the global-struct pointer in r1 across the branch (load field via r1, store via r1); every source variant tried (early-return, named intermediate for the loaded field, flipped comparison operand order, direct double-dereference with no local var) instead assigns the pointer to r2 and the loaded field to r1 - a straight register swap, all other bytes identical. Also tried decomp-permuter (2 runs, ~1200 iterations total, best score 125/0 errors at best but never hit 0). Logic verified correct vs ROM (guards a 'locked' state value of 0xe); not a shortcut, a real floor. (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct State02329bd8 { char pad[0x14]; int state; };
void FUN_02329bf0(int arg0) {
    struct State02329bd8 *g = (struct State02329bd8 *)0x023bd5e0;
    int state = g->state;
    if (state != 0xe) {
        g->state = arg0;
    }
}
