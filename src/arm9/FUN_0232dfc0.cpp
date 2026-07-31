//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232dfc0 name=FUN_0232dfc0
struct Elem0232dfc0 { char pad[4]; unsigned short val; };
struct T0232dfc0 { char pad[8]; int field8; };
unsigned short FUN_0232dfc0(struct T0232dfc0 *s, int idx) {
    struct Elem0232dfc0 *e = (struct Elem0232dfc0 *)((char *)s + s->field8);
    return e[idx].val;
}

}
