// decomp: module=arm7 addr=0x022c47d4 name=FUN_022c47d4
// flags: -noThumb

// Fills slot `i` of the 12-byte-stride handler table at 0x03804f24 with
// `handler`/`arg`, unmasks the matching interrupt line (bit i+3) and only then
// marks the slot live.
//
// Two spellings are load-bearing. The three columns are reached through their
// own base symbols rather than one struct base plus field offsets: that is
// what puts each column address in the pool as its own relocated word and
// lets the shared `i * 12` sit in the index register of all three stores.
// And the slot word is `volatile`, which stops mwcc sinking the first store
// past the `1 << (i + 3)` computation - without it `handler` stays live across
// the shift, the constant 1 needs a third scratch register and both column
// bases come out one register higher.

extern void FUN_022c486c(unsigned int mask);

typedef struct {
    volatile int v;
    int pad[2];
} Slot022c47d4;

extern Slot022c47d4 G_03804f24[]; /* handler column */
extern Slot022c47d4 G_03804f28[]; /* live flag column */
extern Slot022c47d4 G_03804f2c[]; /* argument column */

void FUN_022c47d4(int i, int handler, int arg)
{
    G_03804f24[i].v = handler;
    G_03804f2c[i].v = arg;
    FUN_022c486c(1 << (i + 3));
    G_03804f28[i].v = 1;
}
