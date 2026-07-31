//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232dfd0 name=FUN_0232dfd0
struct ElemA0232dfd0 { char pad[2]; unsigned short idx2; char pad2[2]; };
struct TB0232dfd0 { char pad[8]; int field8; int fieldc; };
void *FUN_0232dfd0(struct TB0232dfd0 *s, int idx) {
    char *baseC = (char *)s + s->fieldc;
    struct ElemA0232dfd0 *e = (struct ElemA0232dfd0 *)((char *)s + s->field8);
    unsigned short idx2 = e[idx].idx2;
    return baseC + idx2 * 0xc;
}

}
