// decomp: module=unk_autoload_0 addr=0x023305c8 name=FUN_023305c8
// Contributed by opie-x (TangOS Discord): AI-assisted candidate (local
// checkpoints/final-v1 model), verified byte-exact via tools/match.py.
struct S_023305c8 { char pad[8]; int f8; int fc; };
void FUN_023305c8(struct S_023305c8 *a) {
    if (a->f8 < a->fc)
        a->f8++;
}
