// decomp: module=unk_autoload_0 addr=0x0232e6bc name=FUN_0232e6bc

// Resets the list at +0x24: head takes the buffer at +0x18, tail is cleared and
// that zero is also the return value (the ROM builds 0 in r0 and copies p to r2
// first, which only happens when the zero doubles as the return). The mixed
// access paths matter: head via p->q, tail via the q pointer.

struct MyList {
    void* head;
    char pad[0x4];
    void* tail;
};
struct MyStruct {
    char pad[0x18];
    void* f18;
    char pad2[0x8];
    struct MyList q;
};
void* FUN_0232e6bc(struct MyStruct* p) {
    struct MyList* q = &p->q;
    p->q.head = p->f18;
    return q->tail = 0;
}
