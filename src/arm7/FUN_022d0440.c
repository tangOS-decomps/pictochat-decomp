// decomp: module=arm7 addr=0x022d0440 name=FUN_022d0440
// flags: -noThumb

// Resets a channel descriptor: clears the six header words, sets the default
// span (0x200) and start slot (0x48), seeds the pair of slot entries at that
// start with the span and a 1, re-registers the channel and returns a pointer
// to the pair it just seeded.

typedef unsigned short u16;

typedef struct Chan {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fa;
    u16 span;
    u16 start;
    u16 slot[1];
} Chan;

// The slot pair seen from a cursor sitting `start` halfwords into the channel:
// the two entries land at the array's base offset (+0x10) and the one after it.
typedef struct Cursor {
    char pad[0x10];
    u16 slot0;
    u16 slot1;
} Cursor;

extern void FUN_022ce1d8(Chan *chan);

u16 *FUN_022d0440(Chan *chan) {
    Cursor *cur;
    int start;
    chan->f0 = 0;
    chan->f2 = 0;
    chan->f4 = 0;
    chan->f6 = 0;
    chan->f8 = 0;
    chan->fa = 0;
    chan->span = 0x200;
    chan->start = 0x48;
    start = chan->start;
    cur = (Cursor *)((u16 *)chan + start);
    cur->slot0 = chan->span;
    cur->slot1 = 1;
    FUN_022ce1d8(chan);
    return &cur->slot0;
}
