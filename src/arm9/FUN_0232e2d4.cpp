//cpp
// decomp: module=unk_autoload_0 addr=0x0232e2d4 name=FUN_0232e2d4
// verify: python tools/match.py --c src/arm9/FUN_0232e2d4.cpp --func FUN_0232e2d4 --addr 0x0232e2d4 --size 0x50 --module unk_autoload_0 --version 2.0/sp1

// Sibling of FUN_0232e614: initialises the 'HPXE'-tagged sub-block at +0x24,
// clears its state halfwords (and explicitly the bit-0 flag), derives the
// 'RF' handle from the two words at +0x18/+0x1c and seeds the head/tail
// words before returning the object.

#pragma thumb on
extern "C" {
typedef struct Sube2d4 {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
    unsigned short f10;
    unsigned short f12;
    char f14[1];
} Sube2d4;
typedef struct Obje2d4 {
    char pad[0x18];
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
} Obje2d4;
extern void FUN_0232e1f4(Obje2d4 *, unsigned int, char *, int, int);
extern unsigned int FUN_0232e2b8(unsigned int *, unsigned int);
Obje2d4 *FUN_0232e2d4(Obje2d4 *a, int b, int c)
{
    Sube2d4 *s = (Sube2d4 *)((char *)a + 0x24);
    unsigned int tmp[2];

    FUN_0232e1f4(a, 0x45585048, s->f14, b, c);
    s->f10 = 0;
    s->f12 = 0;
    s->f12 &= ~1;
    tmp[0] = a->f18;
    tmp[1] = a->f1c;
    a->f24 = FUN_0232e2b8(tmp, 0x4652);
    s->f4 = a->f24;
    s->f8 = 0;
    s->fc = 0;
    return a;
}
}
