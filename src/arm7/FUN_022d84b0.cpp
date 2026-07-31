// decomp: module=arm7 addr=0x022d84b0 name=FUN_022d84b0
// Contributed by opie-x (TangOS Discord): AI-assisted candidate (local
// checkpoints/final-v1 model), verified byte-exact via tools/match.py.
struct S_022d84b0 { unsigned short f0; unsigned short f2; unsigned short f4; };
int FUN_022d84b0(struct S_022d84b0 *a, struct S_022d84b0 *b) {
    if (a->f4 == b->f4 && a->f2 == b->f2 && a->f0 == b->f0)
        return 1;
    return 0;
}
