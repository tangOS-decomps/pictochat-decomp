//cpp
// decomp: module=unk_autoload_0 addr=0x0232e1d8 name=FUN_0232e1d8

// Looks `a` up in the table rooted at G_023be524 and returns the payload at +0xc
// of the hit, or the table base itself on a miss.

#pragma thumb on
extern "C" {
extern int FUN_0232e198(int *, int);
extern int G_023be524[];
void *FUN_0232e1d8(int a)
{
    void *r = G_023be524;
    int x = FUN_0232e198(G_023be524, a);
    if (x != 0) r = (void *)(x + 0xc);
    return r;
}
}
