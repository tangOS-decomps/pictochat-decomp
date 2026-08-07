// decomp: module=arm7 addr=0x022d90cc name=FUN_022d90cc
// flags: -O4,s -noThumb

// If the pending-bits halfword at +0x3f4 of the ARM7 state block is non-zero,
// grabs a 0x12-byte message off the pool at +0x188, stamps it (0x186, 1),
// snapshots and clears the pending bits under lock 0x01000000 and posts the
// message back to the same pool.
// NOTE: verify with --size 0x80, not funcs.json's 0x78 - the stated size
// excludes this function's own trailing pool words.

extern void *FUN_037c58fc(void *pool, int size);
extern void FUN_037c5de8(void *pool, void *msg);
extern int FUN_037c9084(int lock);
extern void FUN_037c904c(int token);

typedef struct Sub90cc {
    char pad[0xb0];
    unsigned short pending; /* +0x3f4 of the block */
} Sub90cc;

typedef struct Blk90cc {
    char pad[0x188];
    char pool[0x1bc];
    Sub90cc sub; /* +0x344 */
} Blk90cc;

extern Blk90cc *G_0380fff4;

typedef struct Msg90cc {
    char pad[0xc];
    unsigned short kind;
    unsigned short f0e;
    unsigned short bits;
} Msg90cc;

void FUN_022d90cc(void)
{
    Blk90cc *b = G_0380fff4;
    Sub90cc *s = &b->sub;
    Msg90cc *m;
    int token;

    if (s->pending == 0) {
        return;
    }

    m = (Msg90cc *)FUN_037c58fc(b->pool, 0x12);
    if (m == 0) {
        return;
    }

    m->kind = 0x186;
    m->f0e = 1;

    token = FUN_037c9084(0x01000000);
    m->bits = s->pending;
    s->pending = 0;
    FUN_037c904c(token);

    FUN_037c5de8(G_0380fff4->pool, m);
}
