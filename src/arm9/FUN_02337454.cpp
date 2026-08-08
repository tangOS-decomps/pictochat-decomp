//cpp
// decomp: module=unk_autoload_0 addr=0x02337454 name=FUN_02337454
// NONMATCHING: matches the target exactly except the two moves are `ldmlt/stmlt r!,{r2}` (one-register block transfers) where mwcc emits `ldrlt/strlt r2,[r],#4`, and the end pointer sits in ip rather than r3. Same family as FUN_02337440. (div=4). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// flags: -noThumb

// Word copy of `nbytes` from `src` to `dst`.

extern "C" {
typedef struct Word { int b[1]; } Word;
void FUN_02337454(Word *src, Word *dst, int nbytes)
{
    Word *end = (Word *)((char *)dst + nbytes);

loop:
    if ((int)dst < (int)end) {
        *dst++ = *src++;
        goto loop;
    }
}
}
