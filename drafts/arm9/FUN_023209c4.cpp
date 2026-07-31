// decomp: module=unk_autoload_0 addr=0x023209c4 name=FUN_023209c4
// NONMATCHING: constant-hoisting floor: source uses literal 1 twice (a shift operand and a later conditional store); mwccarm CSEs it into r4 across the intervening call, target reloads it fresh both times (push {r3,lr}, no r4). Tried -O4,s and -O3,p, both still hoist (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void F1(void);
extern void F2(void *, int, int);
extern int G1[];
struct S { char pad[8]; int f8; };
extern struct S G2;
void FUN_023209c4(void) {
    F1();
    F2(G1, 0x1000, 1);
    if (G2.f8 == 0) G2.f8 = 1;
}
