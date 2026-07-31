// decomp: module=unk_autoload_0 addr=0x023292a8 name=FUN_023292a8
// NONMATCHING: instruction-scheduling floor: target loads the base pointer (ldr r2,[pc]) before the idx*0x58 multiply (muls r1,r0,r1), keeping both idx and the pointer live simultaneously; every source structure tried (direct &arr[idx], local struct*, local char*, swapped addition operand order) instead schedules the multiply first then loads the pointer into r0 after idx is dead. Also tried decomp-permuter (1500+ iterations, stuck at score 510) and -O4,s (no change). Logic verified correct vs ROM (returns base+idx*0x58); not a shortcut, a real floor. (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
void *FUN_023292a8(int idx) {
    char *base = (char *)0x023a0f70;
    return base + idx * 0x58;
}
