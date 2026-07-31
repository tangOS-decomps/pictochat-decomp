// decomp: module=unk_autoload_0 addr=0x023221b0 name=FUN_023221b0
// NONMATCHING: literal-pool reuse policy: target reloads the same global pointer twice (once per call) sharing one pool slot; every C shape tried (distinct symbol, local temp, volatile pointer) either uses a different pool slot (1-word immediate mismatch) or gets register-cached across the call instead of reloaded (div=1). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern int FUN_02321684(void *, void *, int);
extern int G1[];
extern int G2[];
extern int G3[];
extern int G4[];
void FUN_023221b0(void) {
    FUN_02321684(G1, G2, 0x2d);
    FUN_02321684(G3, G4, 0x2e);
}
