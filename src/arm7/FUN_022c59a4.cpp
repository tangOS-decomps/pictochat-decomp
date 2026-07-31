//cpp
extern "C" {
// decomp: module=arm7 addr=0x022c59a4 name=FUN_022c59a4
// Contributed by opie-x (TangOS Discord): AI-assisted candidate (local
// checkpoints/final-v1 model), verified byte-exact via tools/match.py.
void FUN_022c59a4(void *o, void *node)
{
    void *head = *(void **)((char *)node + 0x10);
    void *tail = *(void **)((char *)node + 0x14);
    if (head == 0)
        *(void **)((char *)o + 0x70) = tail;
    else
        *(void **)((char *)head + 0x14) = tail;
    if (tail == 0)
        *(void **)((char *)o + 0x6c) = head;
    else
        *(void **)((char *)tail + 0x10) = head;
}

}
