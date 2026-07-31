// ==========================================================
// C++ Class / Module Implementation: WirelessProtocolDispatch.cpp
// ==========================================================

// --- FUN_02330558.cpp ---
//cpp
extern "C" {
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

}

// --- FUN_02330584.cpp ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02330584 name=FUN_02330584
void FUN_02330584(char *p)
{
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0xc) = 0;
    *(int *)(p + 0x8) = 0;
}

}

// --- FUN_023305c8.cpp ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x023305c8 name=FUN_023305c8
// Contributed by opie-x (TangOS Discord): AI-assisted candidate (local
// checkpoints/final-v1 model), verified byte-exact via tools/match.py.
struct S_023305c8 { char pad[8]; int f8; int fc; };
void FUN_023305c8(struct S_023305c8 *a) {
    if (a->f8 < a->fc)
        a->f8++;
}

}

// --- FUN_023305d8.cpp ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x023305d8 name=FUN_023305d8
struct S_023305d8 { int f0[2]; int f8; int fc; };
int FUN_023305d8(struct S_023305d8 *a) {
    if (a->f8 >= a->fc) {
        return 1;
    }
    return 0;
}

}

