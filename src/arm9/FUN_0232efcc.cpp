//cpp
// decomp: module=unk_autoload_0 addr=0x0232efcc name=FUN_0232efcc

// Releases an object: hands its +0x48 handle to FUN_0232e8a4, unlinks it through
// FUN_0232e13c, then clears bit 0 of its flags at +0x2c.

#pragma thumb on
extern "C" {
extern void FUN_0232e8a4(int);
extern void FUN_0232e13c(int *, void *);
extern int G_023bee48[];
void FUN_0232efcc(void *p)
{
    FUN_0232e8a4(*(int *)((char *)p + 0x48));
    FUN_0232e13c(G_023bee48, p);
    *(unsigned int *)((char *)p + 0x2c) &= ~1;
}
}
