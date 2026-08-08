//cpp
// decomp: module=unk_autoload_0 addr=0x02334980 name=FUN_02334980
// verify: python tools/match.py --c src/arm9/FUN_02334980.cpp --func FUN_02334980 --addr 0x02334980 --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Shrinks the record to `n` entries, running the compaction pass only when the
// probe says the tail is still reachable.

#pragma thumb on
extern "C" {
typedef struct S {
    char pad[4];
    unsigned char n;
} S;
extern int FUN_023348fc(S *, int);
extern void FUN_02334948(S *, int);
void FUN_02334980(S *s, int n)
{
    int rc;

    if (n <= 0) return;
    if (n >= s->n) return;
    rc = FUN_023348fc(s, n);
    s->n = (unsigned char)n;
    if (rc < 0) return;
    FUN_02334948(s, n);
}
}
