// decomp: module=unk_autoload_0 addr=0x02330558 name=FUN_02330558
// Bounds-checked array element lookup: returns &items[idx] if idx is in
// range [0, count) AND the element's first field isn't the -1 sentinel
// (a "slot free" marker), else NULL.
struct Elem {
    int field0;
    char pad[8];
};
struct Container {
    char pad[0x1c];
    unsigned int count;
    char pad2[0x20 - 0x1c - 4];
    struct Elem items[1];
};

struct Elem *FUN_02330558(struct Container *c, int idx)
{
    if (idx < 0) return 0;
    if ((unsigned int)idx >= c->count) return 0;
    struct Elem *e = &c->items[idx];
    if (e->field0 == -1) return 0;
    return e;
}
