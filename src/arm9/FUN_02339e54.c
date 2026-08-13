// decomp: module=unk_autoload_0 addr=0x02339e54 name=FUN_02339e54
// NONMATCHING: register coloring only: ROM keeps the pool base in ip, candidate uses r1 (2 words); extern/literal/return-value/param-pressure/C++ spellings all leave it in r1 (div=2). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=unk_autoload_0 addr=0x02339e54 name=FUN_02339e54

// ARM-mode spin: parks until the word at 0x023c35a4 leaves state 1.

#pragma thumb off
void FUN_02339e54(void)
{
    while (*(volatile int *)0x023c35a4 == 1) {}
}
