// decomp: module=unk_autoload_0 addr=0x02328e04 name=FUN_02328e04
// NONMATCHING: same instruction-scheduling floor as FUN_023292a8: target loads the base pointer (ldr r1,[pc]) before computing idx<<1 (lsls r0,r0,#1), keeping both idx and the base pointer live simultaneously in separate registers; every phrasing tried (pointer+idx addition, array subscript &base[idx], inline cast-and-add in the call argument, separate declaration/assignment) instead shifts idx first then loads the base into the now-free r0. Tail-call reloc slot (bx r3 to FUN_02336880) verified correctly wildcarded by the recent extract_func alignment fix. Logic verified correct; real floor. (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
extern void FUN_02336880(short *p, int a, int b);
void FUN_02328e04(int idx) {
    FUN_02336880((short *)0x023486e4 + idx, 0xb8, 2);
}
