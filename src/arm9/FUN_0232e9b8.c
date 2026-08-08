// decomp: module=unk_autoload_0 addr=0x0232e9b8 name=FUN_0232e9b8
// NONMATCHING: drive near-miss: 5 word(s) differ from the extracted binary (closest: 2.0/sp1, `-O4,p -enum int -lang c99 -char signed -interworking -thumb -proc arm946e -gccext,on -msgstyle gcc`) (div=5). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=unk_autoload_0 addr=0x0232e9b8 name=FUN_0232e9b8
#pragma thumb on
extern void FUN_02330590(void *, int);

void FUN_0232e9b8(volatile int *p, int a)
{
    if (*p != 0) {
        int obj = *p;
        if (*(unsigned char *)(obj + 0x2c) != 2)
            FUN_02330590((void *)(obj + 0x1c), a << 8);
    }
}
