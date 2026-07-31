// decomp: module=unk_autoload_0 addr=0x02320c44 name=FUN_02320c44
// NONMATCHING: constant-hoisting floor: source uses the literal 0x400 as a 3rd-arg shift result in two separate calls; mwccarm CSEs it into r4 across both calls, target recomputes it fresh each time (push {r3,lr}, no r4). Tried -O4,s and -O3,p, both still hoist (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct S { char pad[0x60]; int f60; };
extern struct S G1;
extern void F1(void *, int, int);
extern void F2(void *, int, int);
extern int G2[];
extern int G3[];
void FUN_02320c44(void) {
    if (G1.f60 != 0) {
        F1(G2, 0, 0x400);
        F2(G3, 0, 0x400);
    }
}
