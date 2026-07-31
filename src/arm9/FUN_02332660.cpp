// decomp: module=unk_autoload_0 addr=0x02332660 name=FUN_02332660
// Ghidra's cached size (8) excluded this function's trailing literal-pool
// words (the FUN_02332598 pointer and the G_023c10c4 address, physically
// right after `bx lr`) - same undercounting bug noted in notes/tooling.md;
// true size is 0x10.
extern void FUN_02332598(void);
extern void (*G_023c10c4)(void);

void FUN_02332660(void) {
    G_023c10c4 = FUN_02332598;
}
