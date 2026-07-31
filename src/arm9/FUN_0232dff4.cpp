// decomp: module=unk_autoload_0 addr=0x0232dff4 name=FUN_0232dff4
struct Elem0232dff4 { char pad[2]; unsigned short idx2; char pad2[2]; };
struct S0232dff4 { char pad[8]; int field8; };
void *FUN_0232dff4(struct S0232dff4 *s, int idx) {
    struct Elem0232dff4 *e = (struct Elem0232dff4 *)((char *)s + s->field8);
    return &e[idx];
}
