// decomp: module=arm7 addr=0x022c8150 name=FUN_022c8150
// Constructor-style init: clears a flag byte, copies a 12-byte struct from
// `src`, stashes `p2`, then delegates to FUN_022c864c with `p3`. Always
// returns 1 (likely a "success" boolean by convention).
struct Small { int a, b, c; };

struct Self {
    char pad0;
    unsigned char flag;
    char pad2[0x38 - 2];
    struct Small copy;
    int field44;
};

extern int FUN_022c864c(struct Self *self, int x);

int FUN_022c8150(struct Self *self, struct Small *src, int p2, int p3)
{
    self->flag = 0;
    self->copy = *src;
    self->field44 = p2;
    FUN_022c864c(self, p3);
    return 1;
}
