// decomp: module=unk_autoload_0 addr=0x0232575c name=FUN_0232575c
// NONMATCHING: instruction-scheduling swap: target loads the struct-pointer register before the value register for both field stores, every plain-C rephrasing (direct field access, explicit pointer local) keeps value-then-pointer order (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct S { void *f0; void *f4; };
extern struct S G2;
extern int G[];
extern int G3[];
void FUN_0232575c(void) {
    G2.f0 = G;
    G2.f4 = G3;
}
