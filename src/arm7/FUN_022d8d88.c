// decomp: module=arm7 addr=0x022d8d88 name=FUN_022d8d88
// flags: -O4,s -noThumb

// Programs the adjacent halfwords at +0x5f0/+0x5f2 of the ARM7 state block:
// the first gets the 8-byte-aligned payload length plus the 5-byte header, the
// second the caller's control word with its enable bit forced on.
//
// The two halfwords are adjacent but are reached through two different objects
// (a descriptor at +0x500 whose field sits at +0xf0, and a control block at
// +0x5f0 whose field sits at +2), so the ROM materialises a fresh
// `base + 0x5f0` for the second store rather than reusing the `base + 0x500`
// register from the first.  mwcc's copy/address propagation rewrites that
// second address back onto the first register - `#pragma opt_propagation off`
// is what keeps the two base computations apart.  (Phrasing alone does not do
// it: inline casts, a named local, an `unsigned short` array index, a
// `volatile` qualifier, a static inline helper taking the pointer by value, a
// second deref of 0x0380fff4, `#pragma opt_common_subs off` and -O4,p/-O2 were
// all tried and all still fold to `strh [r0, #0xf2]`.)
#pragma opt_propagation off

typedef struct Len8d88 {
    char pad[0xf0];
    unsigned short f0;
} Len8d88;

typedef struct Ctl8d88 {
    char pad[2];
    unsigned short f2;
} Ctl8d88;

void FUN_022d8d88(unsigned int len, unsigned int ctl)
{
    char *base = *(char **)0x0380fff4;
    Ctl8d88 *c = (Ctl8d88 *)(base + 0x5f0);

    ((Len8d88 *)(base + 0x500))->f0 = (unsigned short)((len & 0xfff8) + 5);
    c->f2 = (unsigned short)(ctl | 1);
}
