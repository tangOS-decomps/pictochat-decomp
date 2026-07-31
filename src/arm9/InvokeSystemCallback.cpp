// decomp: module=unk_autoload_0 addr=0x02332c68 name=InvokeSystemCallback
// Ghidra's cached size (8) excludes this function's trailing literal-pool
// word (the FUN_023374f0 callee pointer, physically right after `bx r3`) -
// same undercounting bug documented in notes/tooling.md; true size is 0xc.
extern int FUN_023374f0(int, int, int);

int InvokeSystemCallback(int a) {
    return FUN_023374f0(a, 0, 0x24);
}
