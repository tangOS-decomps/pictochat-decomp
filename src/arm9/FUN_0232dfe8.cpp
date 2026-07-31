//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232dfe8 name=FUN_0232dfe8
struct S0232dfe8 { char pad[0x10]; int field10; };
void *FUN_0232dfe8(struct S0232dfe8 *s) {
    return (char *)s + s->field10;
}

}
