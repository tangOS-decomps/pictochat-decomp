//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02330004 name=FUN_02330004
// Teardown/reset step: if a pointer field (+0x154) is set, zeroes the
// int it points to and clears the field itself; then clears three
// individual bit flags (1, 4, 2) in a flags word (+0x118) one at a time.
// The `volatile` cast is deliberate - the real binary genuinely does three
// separate read-modify-write cycles on the same word rather than combining
// the mask, matching this project's established no-CSE-without-a-local
// idiom (see notes/tooling.md).
struct S {
    char pad[0x118];
    int flags;
    char pad2[0x154 - 0x118 - 4];
    void *ptr;
};

void FUN_02330004(struct S *s)
{
    if (s->ptr != 0) {
        *(int *)s->ptr = 0;
        s->ptr = 0;
    }
    ((volatile struct S *)s)->flags &= ~1;
    ((volatile struct S *)s)->flags &= ~4;
    ((volatile struct S *)s)->flags &= ~2;
}

}
