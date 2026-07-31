// decomp: module=unk_autoload_0 addr=0x02323d28 name=FUN_02323d28
// NONMATCHING: literal-pool reuse policy floor (same as FUN_023221b0): target reloads the same global pointer for both the call arg and the return value from one shared pool slot; separate-symbol version lands on a different slot (1-word immediate mismatch), same-symbol version gets register-cached across the call instead (div=1). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int G[];
extern int G2[];
extern void F(void *, int);
int *FUN_02323d28(void) {
    F(G, 0x2280);
    return G2;
}
