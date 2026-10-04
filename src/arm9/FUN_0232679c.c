// decomp: module=unk_autoload_0 addr=0x0232679c name=FUN_0232679c
// flags: -O4,s
//
// Appends a block to the 1024-slot scroll ring at 0x0239c930: a blank lead
// slot, then `size >> 11` pairs of 1 KiB tile slots copied from `src`, with
// matching 64-byte map rows (top/middle/bottom templates) rebased onto the
// tile slots and tagged with the palette chosen by `mode`. Every slot gets a
// 0x1c-byte record (tile pointer, optional 0x14-byte info on the first data
// slot, palette and block length). The write cursor and fill count advance;
// once the ring is full the oldest blocks past the cursor are cleared and the
// read cursor is moved onto the next live block.
//
// Phrasing that the bytes depend on:
//  - C, not C++: as C++ the 0x1c-byte record copies become helper calls
//    instead of the inline ldm/stm loop;
//  - the declaration order of nblk..n2 sets their spill slots, and the run
//    loop needs its own q2 (a reused q would become a low split-web slot);
//  - `i = 0` before `p = G.wr` makes p spill and keeps `p << 6` in r5;
//  - `o + (int)G.map` keeps the add's operand order (pointer + int is
//    canonicalised to base-first);
//  - the read-cursor loops carry G.rd in a local and store it back.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u8 *tiles;      /* +0x00 */
    u16 info[10];   /* +0x04 */
    u16 pad18;
    u8 pal;         /* +0x1a */
    u8 len;         /* +0x1b */
} Rec;

typedef struct Ring {
    int f0;
    int count;      /* +0x04 */
    Rec *recs;      /* +0x08 */
    u8 *tiles;      /* +0x0c */
    u8 *map;        /* +0x10 */
    int f14;
    int rd;         /* +0x18 */
    int f1c;
    int wr;         /* +0x20 */
} Ring;

extern Ring G_0239c930;
#define G G_0239c930

int FUN_02326764(int pos);
int FUN_0232673c(int pos);
int FUN_02326774(int pos);
void FUN_0233746c(int fill, void *dst, int size);
void FUN_023374b8(const void *src, void *dst, int size);
void FUN_02337424(const void *src, void *dst, int size);
void *FUN_02332e10(void *dst, int fill, int size);

void FUN_0232679c(u8 *src, u32 size, int mode, void *info)
{
    Rec blank2;
    Rec scan;
    Rec cur;
    Rec scan2;
    Rec blank;
    int nblk;
    int pos2;
    int off;
    int bound;
    u8 *tiles;
    int q;
    int q2;
    int end;
    int palBits;
    int n2;
    int pos;
    int i;
    int j;
    int k;
    int pal;
    int cnt;
    int p;
    u16 *row;
    int o;
    int wrap;
    int run;
    int v;

    nblk = size >> 11;
    if (src == 0)
        return;

    pos = G.wr;
    FUN_0233746c(0, G.tiles + (pos << 10), 0x400);
    pos2 = FUN_02326764(pos);
    n2 = nblk * 2;
    for (i = 0; i < n2; i++) {
        FUN_023374b8(src + (i << 10), G.tiles + (pos2 << 10), 0x400);
        pos2 = FUN_02326764(pos2);
    }

    pos = G.wr;
    FUN_023374b8((void *)0x02347ce4, G.map + (pos << 6), 0x40);
    pos = FUN_02326764(pos);
    bound = (nblk - 1) * 2 + 1;
    for (j = 0; j < bound; j++) {
        FUN_023374b8((void *)0x02347d24, G.map + (pos << 6), 0x40);
        pos = FUN_02326764(pos);
    }
    FUN_023374b8((void *)0x02347d64, G.map + (pos << 6), 0x40);
    pos = FUN_02326764(pos);

    if (mode < 16) {
        pal = mode / 2 + 8;
        off = (mode % 2) << 5;
    } else {
        switch (mode) {
        case 16:
            off = 0;
            pal = 3;
            break;
        case 17:
            off = 0;
            pal = 3;
            break;
        case 18:
            off = 0;
            pal = 4;
            break;
        case 19:
            off = 0x20;
            pal = 4;
            break;
        }
    }

    i = 0;
    p = G.wr;
    palBits = pal << 12;
    cnt = n2 + 1;
    for (; i < cnt; i++) {
        o = p << 6;
        for (k = 0; k < 32; k++) {
            u16 e;
            row = (u16 *)(o + (int)G.map);
            e = row[k];
            row[k] = palBits | (((e & 0x3ff) + off) | (e & 0x400) | (e & 0x800));
        }
        p = FUN_02326764(p);
    }

    tiles = G.tiles + (FUN_02326764(G.wr) << 10);
    q = G.wr;
    for (i = 0; i < cnt; i++) {
        if (info != 0 && i == 1)
            FUN_02337424(info, &G.recs[q].info, 0x14);
        else
            G.recs[q].info[0] = 0;
        if (mode < 16)
            G.recs[q].pal = (u8)mode;
        else
            G.recs[q].pal = 0x10;
        G.recs[q].tiles = tiles;
        G.recs[q].len = (u8)nblk;
        q = FUN_02326764(q);
    }

    wrap = 0;
    if (G.wr == G.rd)
        wrap = 1;
    G.wr = FUN_0232673c(G.wr + n2 + 1);
    if (wrap == 1) {
        G.rd = G.wr;
        G.f1c = G.wr;
    }
    G.count += cnt;
    if (G.count > 0x380)
        G.count = 0x380;
    if (G.count + n2 + 1 <= 0x380)
        return;

    FUN_02332e10(&blank, 0, sizeof(Rec));
    p = G.wr;
    end = FUN_0232673c(p + 0x80);
    while (p != end) {
        if (G.recs[p].tiles != 0) {
            FUN_0233746c(0, G.tiles + (p << 10), 0x400);
            FUN_0233746c(0, G.map + (p << 6), 0x40);
            G.recs[p] = blank;
        }
        p = FUN_02326764(p);
    }

    q2 = end;
    run = 0;
    cur = G.recs[end];
    if (cur.tiles != 0) {
        while (cur.tiles == G.recs[q2].tiles) {
            run++;
            q2 = FUN_02326764(q2);
        }
    }
    if (run != G.recs[end].len * 2 + 1) {
        FUN_02332e10(&blank2, 0, sizeof(Rec));
        scan = G.recs[end];
        while (scan.tiles == G.recs[end].tiles) {
            FUN_0233746c(0, G.tiles + (end << 10), 0x400);
            FUN_0233746c(0, G.map + (end << 6), 0x40);
            G.recs[end] = blank2;
            end = FUN_02326764(end);
        }
    }

    if (G.recs[FUN_02326774(G.rd)].tiles != 0)
        return;
    if (G.count + n2 + 1 <= 0x380)
        return;
    v = G.rd;
    while (G.recs[v].tiles == 0) {
        v = FUN_02326764(v);
        G.rd = v;
    }
    scan2 = G.recs[v];
    v = G.rd;
    while (scan2.tiles == G.recs[v].tiles) {
        v = FUN_02326764(v);
        G.rd = v;
    }
}
