// decomp: module=arm7 addr=0x022dbb84 name=FUN_022dbb84
// flags: -O4,s -noThumb

// Allocates a 0x18-byte command block out of the pool at +0x188, fills it in as
// a "type 0x84, length 4" request carrying a 6-byte MAC plus one halfword, and
// queues it.  On allocation failure it raises error bit 1 and reports 0.

extern void *FUN_037c58fc(void *heap, int size);   // alloc from block pool
extern void FUN_037c5de8(void *heap, void *block); // enqueue block
extern void FUN_022d9088(int bits);
extern void FUN_022d811c(unsigned short *dst, const unsigned short *src);

typedef struct Cmd {
    char pad[0xc];
    unsigned short type;   /* 0x0c */
    unsigned short len;    /* 0x0e */
    unsigned short mac[3]; /* 0x10 */
    unsigned short arg;    /* 0x16 */
} Cmd;

int FUN_022dbb84(const unsigned short *mac, unsigned short arg)
{
    Cmd *c = (Cmd *)FUN_037c58fc((char *)*(void **)0x0380fff4 + 0x188, 0x18);

    if (c == 0) {
        FUN_022d9088(1);
        return 0;
    }

    c->type = 0x84;
    c->len = 4;
    FUN_022d811c(c->mac, mac);
    c->arg = arg;
    FUN_037c5de8((char *)*(void **)0x0380fff4 + 0x188, c);
    return 1;
}
