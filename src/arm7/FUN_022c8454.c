// decomp: module=arm7 addr=0x022c8454 name=FUN_022c8454
// flags: -O4,s
//
// Tears down every entry selected by `mask` (bit i -> G_0380583c[i], stride
// 0x54) that is not already listed in G_03805814[1], then folds `mask` into
// one of the two G_03805814 word masks depending on bit 0 of `which`.
//
// FUN_022c4438 is declared here with four parameters purely from register
// liveness at the bl: r0 = entry, r1 = 0, r2 = entry->f4c, r3 = entry->f48,
// where f48 is the very field tested against zero to guard the call. This
// disagrees with the empty stub left in src/FUN_022c4438.c - inferred, and
// the reloc slot is wildcarded either way.
//
// NOTE: verify with --size 0xa0, not 0x96 - the stated bound stops inside
// this function's own alignment padding + trailing pool.

#pragma thumb on

typedef struct Ent8454 {
    unsigned char f00[3];
    unsigned char flags;     /* +0x03 */
    unsigned char f04[0x1e];
    unsigned char f22;       /* +0x22 */
    unsigned char f23[0x25];
    void *f48;               /* +0x48 */
    void *f4c;               /* +0x4c */
    unsigned char f50[4];
} Ent8454;                   /* 0x54 */

extern Ent8454 G_0380583c[];
extern unsigned long G_03805814[];

extern void FUN_022c4438(Ent8454 *e, int a, void *b, void *c);
extern void FUN_022c77a0(int index, int a);
extern void FUN_022c83d0(Ent8454 *e);

void FUN_022c8454(unsigned long mask, int which)
{
    Ent8454 *e;
    int i;
    unsigned long m;

    m = mask;
    i = 0;
    while (i < 0x10 && m != 0) {
        if (m & 1) {
            e = &G_0380583c[i];
            if (!(G_03805814[1] & (1UL << i))) {
                if (e->f48 != 0) {
                    FUN_022c4438(e, 0, e->f4c, e->f48);
                }
                FUN_022c77a0(i, 0);
                e->f22 = 0;
                FUN_022c83d0(e);
                e->flags &= ~0xf8;
                e->flags &= ~1;
            }
        }
        i++;
        m >>= 1;
    }

    if (which & 1) {
        G_03805814[0] |= mask;
    } else {
        G_03805814[1] |= mask;
    }
}
