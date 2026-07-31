// decomp: module=unk_autoload_0 addr=0x02332188 name=FUN_02332188
// NONMATCHING: tail-call trampoline (const_addr, x, 6) -> FUN_02337584; logic-correct and byte-identical except the two literal-pool words (callee ptr vs the 0x2fffcf4 constant) and the arg-eval instruction order are swapped vs target - tried 7+ C rephrasings (direct call, local temps in various orders, unsigned/cast literal, fn-ptr local, fn-ptr global, reversed decl order, -O4,s) all reproduce the identical (wrong) order; genuine scheduling floor, not a logic issue (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int FUN_02337584(unsigned int a0, int a1, int a2);

int FUN_02332188(int x) {
    return FUN_02337584(0x2fffcf4, x, 6);
}
