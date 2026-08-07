// decomp: module=arm7 addr=0x022c0f00 name=FUN_022c0f00
// flags: -O4,s -noThumb
// NOTE: verify with --size 0x78, not the nominal 0x6c - the stated size
// excludes this function's own trailing 3-word literal pool.
//
// Pops the head entry off one of the four intrusive u16 queues that live at
// the front of the ARM7 state block. The queue nodes are the 8-byte records
// at +0xbc, chained through their first halfword; 0xffff is the end/NIL
// marker. Runs with IRQs masked (FUN_022c48a4 / FUN_022c486c) and returns
// the index of the entry that was unlinked, or 0xffff if the queue is empty.

typedef struct Node {
    unsigned short next;    /* +0x0 */
    unsigned short state;   /* +0x2 */
    unsigned char pad[4];
} Node;

typedef struct Ctx {
    unsigned short head[4]; /* +0x00 */
    unsigned short tail[4]; /* +0x08 */
    unsigned char pad[0xbc - 0x10];
    Node nodes[1];          /* +0xbc */
} Ctx;

extern Ctx *G_0380fff4;
extern unsigned int FUN_022c48a4(unsigned int mask);
extern unsigned int FUN_022c486c(unsigned int mask);

unsigned short FUN_022c0f00(unsigned int q)
{
    Ctx *ctx = G_0380fff4;
    unsigned int save;
    unsigned short e;

    save = FUN_022c48a4(0x01000010);
    e = ctx->head[q];
    if (e != 0xffff) {
        Node *nodes = ctx->nodes;
        unsigned short n;

        nodes[e].state = 0;
        n = nodes[e].next;
        if (n == 0xffff) {
            ctx->head[q] = 0xffff;
            ctx->tail[q] = 0xffff;
        } else {
            ctx->head[q] = n;
            nodes[e].next = 0xffff;
        }
    }
    FUN_022c486c(save);
    return e;
}
