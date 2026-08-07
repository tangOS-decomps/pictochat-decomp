// decomp: module=arm7 addr=0x022db560 name=FUN_022db560
// flags: -O4,s -noThumb
//
// Per-frame step for channel 1 of the block at 0x0380fff4. In state 0x30 it
// asks FUN_022dfe18 for a transfer descriptor: on failure the channel's slot is
// marked 8, the channel drops to state 0x35 and the SDK notifier is poked; on
// success the descriptor is filled in from the channel's block and handed on,
// and the channel advances to state 0x31. State 0x35 runs the three shutdown
// calls and returns the channel to state 0.
//
// The channel array lives at +4 with a 0x400 stride, which is why the state
// halfword is reached as (root + 0x400)[4] while the channel pointer itself is
// built as (root + 4) + 0x400.

typedef struct Blk {
    char pad00[0x10];
    char f10[6];
    unsigned short f16;
    unsigned short f18;
} Blk;

typedef struct Slot {
    char pad00[4];
    unsigned short f04;
} Slot;

typedef struct Desc {
    char pad00[0x2c];
    unsigned short f2c;
    unsigned short f2e;
    unsigned short f30;
} Desc;

typedef struct Chan {
    unsigned short state;
    char pad02[0x18 - 2];
    Blk *blk;
    Slot *slot;
    char pad20[0x400 - 0x20];
} Chan;

typedef struct Root {
    char pad00[4];
    Chan chan[2];
} Root;

extern char G_0230e8f4[];

extern Desc *FUN_022dfe18(void *buf, int a, int b);
extern void FUN_022df098(Desc *d);
extern void FUN_022d8b1c(unsigned short id, char *tag);
extern void FUN_022decf0(int chan);
extern void FUN_022dec8c(int chan);
extern void FUN_022df00c(int chan, int flag);
extern void FUN_022dbb30(void);
extern void func_037c5628(int a, int b);

void FUN_022db560(void)
{
    Root *root = *(Root **)0x0380fff4;
    unsigned short st = root->chan[1].state;
    Chan *c = &root->chan[1];
    Desc *d;

    switch (st) {
    case 0x30:
        d = FUN_022dfe18(c->blk->f10, 0, 0);
        if (d == 0) {
            c->slot->f04 = 8;
            c->state = 0x35;
            func_037c5628(2, 2);
        } else {
            d->f2c = c->blk->f16;
            d->f2e = 1;
            d->f30 = 0;
            c->state = 0x31;
            FUN_022df098(d);
            FUN_022d8b1c(c->blk->f18, G_0230e8f4);
        }
        break;

    case 0x35:
        FUN_022decf0(1);
        FUN_022dec8c(1);
        FUN_022df00c(1, 0);
        c->state = 0;
        FUN_022dbb30();
        break;
    }
}
