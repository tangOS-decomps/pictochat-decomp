// decomp: module=arm7 addr=0x022d3bd4 name=FUN_022d3bd4
// flags: -noThumb
// Was parked NONMATCHING (pool-load-order scheduling (ip/r0 swapped) for a computed tail-call);
// that verdict said "not byte-matchable from C at mwccarm dsi/1.3" and
// was reached under the WRONG compiler. This ROM is built by 2.0/*
// (notes/setup-mwccarm.md); this file compiles BYTE-EXACT on
// 2.0/sp1..2.0/sp2p4 completely unchanged - no source edit was needed,
// only the correct toolchain.

extern int func_037fe508(void *arg);

int FUN_022d3bd4(void) {
    void *arg = (void *)0x03807230;
    return func_037fe508(arg);
}
