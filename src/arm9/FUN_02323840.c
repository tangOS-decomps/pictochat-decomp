// decomp: module=unk_autoload_0 addr=0x02323840 name=FUN_02323840
// flags: -O4,s
//
// Per-frame input handler for a key grid (the on-screen keyboard style
// selector at 0x0238ef0c). Resolves this frame's selection from, in order:
// a pending programmatic press, the A button, Select (cycles the 4/5 mode
// keys), D-pad up (scans the grid above the cursor, wrapping at 200x106),
// D-pad down/left/right (FUN_0232414c), or Start. Touch input then hit-tests
// the pen position: a tap selects the key under it, a held pen auto-repeats
// it while it stays on the same key, and releasing over a key with a code of
// 0x20 or more records it. Each accepted key plays its click sound; the
// selection is published at +0x2e and passed to the key-set callback.
//
// Phrasing that the bytes depend on:
//  - Item's first two halfwords are 8-bit bitfields (the shift-pair extracts);
//  - the key rectangle is read into ix/iy/iw in that order;
//  - y is declared before x (loop registers r4/r5);
//  - the tap block reads the pen into tx/ty first (call arguments are
//    otherwise evaluated right to left).

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Item {
    u16 x : 8;      /* +0x0: in 2-pixel units */
    u16 y : 8;
    u16 w : 8;      /* +0x2 */
    u16 h : 8;
    u16 f4;
    u16 id;         /* +0x6 */
} Item;

typedef struct Cfg {
    void *keys;                 /* +0x0 */
    int f4;
    void (*onSelect)(void *);   /* +0x8 */
    u16 count;                  /* +0xc */
} Cfg;

typedef struct Grid {
    int f0;
    int x;          /* +0x04 */
    int y;          /* +0x08 */
    Item *hit;      /* +0x0c */
    Item *hover;    /* +0x10 */
    Cfg *cfg;       /* +0x14 */
    void (*onRelease)(void *, u16, int, int); /* +0x18 */
    void *releaseArg;   /* +0x1c */
    int f20;
    u16 timer[4];   /* +0x24 */
    u16 sel;        /* +0x2c */
    u16 code;       /* +0x2e */
    u16 released;   /* +0x30 */
    u16 mode;       /* +0x32 */
    int lock;       /* +0x34 */
    Item *cur;      /* +0x38 */
    int pending;    /* +0x3c */
    int shifted;    /* +0x40 */
} Grid;

extern Grid G_0238ef0c;
#define G G_0238ef0c

/* The hit-test list (&G.hit) and hold timer (G.timer) are referenced through
   their own address-named symbols. */
extern char G_0238ef18[];
extern u16 G_0238ef30[];
#define LIST ((void *)G_0238ef18)
#define TIMER G_0238ef30

extern void FUN_02320978(int se);
extern int FUN_023212bc(int mask);
extern int FUN_023212e0(void);
extern int FUN_023212ec(void);
extern int FUN_023212f8(void);
extern int FUN_02321304(void);
extern int FUN_02322da8(void);
extern Item *FUN_0232310c(void *list, int x, int y);
extern void FUN_023232e8(void *list);
extern u16 FUN_02323c90(void *list, u16 id);
extern Item *FUN_0232414c(int dir, Item *cur, void *keys);
extern void FUN_0232519c(u16 *t);
extern void FUN_023251c4(u16 *t);
extern int FUN_023251cc(u16 *t);
extern int FUN_023251e4(u16 *t);
extern unsigned int FUN_02325278(void);

void FUN_02323840(void)
{
    int half;
    int ylim;
    int xlim;
    Item *it;
    Item *hit;
    int x0;
    int ix;
    int iy;
    int iw;
    int y;
    int x;
    int tx;
    int ty;
    u16 id;
    int same;
    int both;
    u16 code;

    G.sel = 0;
    G.code = 0;
    if (G.pending != 0) {
        G.pending = 0;
        G.sel = G.cur->id;
        if (G.cur->id == 0)
            goto input_done;
        id = G.sel;
        if (id == 1) {
            if (G.shifted == 0 || FUN_02322da8() != 0)
                FUN_02320978(8);
        } else if (id == 2) {
            if (G.shifted != 0)
                FUN_02320978(0xf);
            else
                FUN_02320978(0xa);
        } else if (id != 0 && id <= G.cfg->count) {
            FUN_02320978(6);
        } else if (id != 0) {
            FUN_02320978(6);
        }
    } else if (FUN_02325278() & 2) {
        G.sel = 1;
        if (G.shifted == 0 || FUN_02322da8() != 0)
            FUN_02320978(8);
    } else if (FUN_02325278() & 0x400) {
        if (G.lock == 0) {
            if (G.mode == 0)
                G.sel = 4;
            else if (G.mode == 4)
                G.sel = 5;
            else if (G.mode == 5)
                G.sel = 5;
        }
        FUN_02320978(6);
    } else if (FUN_02325278() & 0x40) {
        it = G.cur;
        FUN_02320978(0x28);
        x0 = G.x;
        ix = it->x * 2;
        iy = it->y;
        iw = it->w;
        half = (ix + iw) / 2;
        xlim = x0 + half - 0x10;
        y = G.y + iy;
        ylim = y - 0x50;
        for (; y != ylim; y -= 8) {
            for (x = x0 + half; x != xlim; x -= 8) {
                int wx = x;
                int wy = y;
                if (x - G.x < 0)
                    wx += 0xc8;
                else if (x - G.x > 0xc8)
                    wx -= 0xc8;
                if (y - G.y < 0)
                    wy += 0x6a;
                else if (y - G.y > 0x6a)
                    wy -= 0x6a;
                hit = FUN_0232310c(LIST, wx, wy);
                if (hit != 0 && hit != it)
                    goto found;
            }
        }
        hit = it;
    found:
        G.cur = hit;
    } else if (FUN_02325278() & 0x80) {
        G.cur = FUN_0232414c(0x80, G.cur, G.cfg->keys);
    } else if (FUN_02325278() & 0x20) {
        G.cur = FUN_0232414c(0x20, G.cur, G.cfg->keys);
    } else if (FUN_02325278() & 0x10) {
        G.cur = FUN_0232414c(0x10, G.cur, G.cfg->keys);
    } else if (FUN_023212bc(8) != 0) {
        if (G.shifted != 0)
            G.cur = (Item *)0x0233af1c;
    }

input_done:
    if (FUN_023212e0() != 0)
        G.hover = FUN_0232310c(LIST, FUN_023212f8(), FUN_02321304());

    if (FUN_023212ec() == 1) {
        tx = FUN_023212f8();
        ty = FUN_02321304();
        G.hit = hit = FUN_0232310c(LIST, tx, ty);
        if (hit == 0)
            goto touch_done;
        id = hit->id;
        if (id == 1) {
            if (G.shifted == 0 || FUN_02322da8() != 0)
                FUN_02320978(8);
        } else if (id == 2) {
            if (G.shifted == 0)
                FUN_02320978(0xa);
        } else if (id != 0 && id <= G.cfg->count) {
            FUN_02320978(6);
        } else if (id != 0) {
            FUN_02320978(6);
        }
    } else if (FUN_023212ec() == 3) {
        if (G.hit != 0 && FUN_023251e4(TIMER) == 0) {
            hit = FUN_0232310c(LIST, FUN_023212f8(), FUN_02321304());
            if (hit != 0 && hit->id == G.hit->id) {
                G.sel = G.hit->id;
                id = G.hit->id;
                if (id == 1) {
                    if (G.shifted == 0 || FUN_02322da8() != 0)
                        FUN_02320978(9);
                } else if (id == 2) {
                    if (G.shifted == 0)
                        FUN_02320978(0xb);
                } else if (id != 0 && id <= G.cfg->count) {
                    FUN_02320978(7);
                } else if (id != 0) {
                    FUN_02320978(7);
                }
            }
        }
        if (G.onRelease != 0 && G.released != 0) {
            tx = FUN_023212f8();
            ty = FUN_02321304();
            G.onRelease(G.releaseArg, G.released, tx, ty);
        }
        G.released = 0;
        G.hit = 0;
    }

touch_done:
    same = 0;
    both = 0;
    if (G.hit != 0 && G.hover != 0)
        both = 1;
    if (both && G.hover->id == G.hit->id)
        same = 1;
    if (same) {
        FUN_0232519c(TIMER);
        if (FUN_023251cc(TIMER) != 0) {
            G.sel = G.hit->id;
            id = G.hit->id;
            if (id == 1) {
                if (G.shifted == 0 || FUN_02322da8() != 0)
                    FUN_02320978(8);
            } else if (id == 2) {
                if (G.shifted == 0)
                    FUN_02320978(0xa);
            } else if (id != 0 && id <= G.cfg->count) {
                FUN_02320978(6);
            } else if (id != 0) {
                FUN_02320978(6);
            }
        }
    } else {
        FUN_023251c4(TIMER);
    }

    hit = FUN_0232310c(LIST, FUN_023212f8(), FUN_02321304());
    if (G.hit != 0 && (hit == 0 || G.hit != hit)) {
        code = FUN_02323c90(LIST, G.hit->id);
        if (code >= 0x20)
            G.released = code;
    }
    G.code = FUN_02323c90(LIST, G.sel);
    if (G.sel != 0)
        G.cfg->onSelect(LIST);
    FUN_023232e8(LIST);
}
