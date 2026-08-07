// decomp: module=arm7 addr=0x022c5e30 name=FUN_022c5e30
// flags: -O4,s -noThumb
//
// Publishes a fixed-slot allocator into slot `idx` of the table at G_03805168
// and initialises it: the entry array lives immediately behind the 0x14-byte
// header, every entry is stamped free (-1 / 0 / 0), and the heap that follows
// the entries is rounded up to a 32-byte boundary. Returns that heap base.

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);

extern void *G_03805168[];

typedef struct Ent5e30 {
    int f0;
    int f4;
    int f8;
} Ent5e30;

typedef struct Pool5e30 {
    int f0;
    int count;
    unsigned int f8;
    unsigned int fc;
    Ent5e30 *ents;
} Pool5e30;

unsigned int FUN_022c5e30(int idx, Pool5e30 *p, unsigned int limit, int count)
{
    int state = FUN_022c6d40();
    unsigned int bytes;
    int i;

    G_03805168[idx] = p;
    p->ents = (Ent5e30 *)(p + 1);
    bytes = count * 12;
    p->count = count;
    for (i = 0; i < p->count; i++) {
        Ent5e30 *e = &p->ents[i];
        e->f0 = -1;
        e->f8 = 0;
        e->f4 = 0;
    }
    p->f0 = -1;
    p->f8 = ((unsigned int)p->ents + bytes + 0x1f) & ~0x1f;
    p->fc = limit & ~0x1f;
    FUN_022c6d54(state);
    return p->f8;
}
