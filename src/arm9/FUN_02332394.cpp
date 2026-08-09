//cpp
// decomp: module=unk_autoload_0 addr=0x02332394 name=FUN_02332394
// NONMATCHING: identical instructions; the target's literal pool orders the control-block address before the buffer address, mwcc emits them the other way round, so the two pool words and the two `ldr` register assignments are transposed. (div=3). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

// Points the control block at the 0x60-byte buffer, blanks and flushes it,
// then registers handler 0xb.

#pragma thumb on
extern "C" {
extern char *G_023c0ba0;
extern char G_023c0b40[];
extern void FUN_0233746c(int, void *, int);
extern void FUN_02331504(void *, int);
extern void FUN_023382ac(int, void *);
extern void FUN_023324d0(void);
void FUN_02332394(void)
{
    G_023c0ba0 = G_023c0b40;
    FUN_0233746c(0, G_023c0b40, 0x60);
    FUN_02331504(G_023c0b40, 0x60);
    FUN_023382ac(0xb, (void *)FUN_023324d0);
}
}
