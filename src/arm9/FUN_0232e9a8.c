// decomp: module=unk_autoload_0 addr=0x0232e9a8 name=FUN_0232e9a8

// Sets the byte at +0x40 of the object pointed to by the first word of p, if
// that pointer is non-null. The pointer field must be volatile: the ROM loads
// p->q twice (guard, then store base) and a plain field CSEs to one load.

struct MyTarget {
    char pad[0x40];
    unsigned char f40;
};
struct MyStruct {
    struct MyTarget* volatile q;
};
void FUN_0232e9a8(struct MyStruct* p, unsigned char v) {
    if (p->q != 0) {
        p->q->f40 = v;
    }
}
