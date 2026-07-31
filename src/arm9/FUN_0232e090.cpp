//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232e090 name=FUN_0232e090
struct Elem0232e090 { int field0; int field4; };
struct S0232e090 { void *f0; void *f4; unsigned short f8; unsigned short fa; };
void FUN_0232e090(struct S0232e090 *s, char *arr) {
    struct Elem0232e090 *e = (struct Elem0232e090 *)(arr + s->fa);
    e->field4 = 0;
    e->field0 = 0;
    s->f0 = arr;
    s->f4 = arr;
    s->f8 = s->f8 + 1;
}

}
