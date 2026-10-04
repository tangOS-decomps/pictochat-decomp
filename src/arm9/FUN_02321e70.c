// decomp: module=unk_autoload_0 addr=0x02321e70 name=FUN_02321e70

// Redraws the scroll widgets at the current scroll position (state block at
// G_0238e028). In mode 2 it also draws the thumb, the two arrows (only while
// the position is within 0x4c), and the two up/down buttons with their
// pressed state; then it always places the list body and the two edge sprites
// relative to the position.

struct Scroll {
    /* 0x00 */ int pos;
    /* 0x04 */ int bodyOfs;
    /* 0x08 */ int edgeOfs;
    /* 0x0c */ int thumb;
    /* 0x10 */ int unk10;
    /* 0x14 */ int active;
    /* 0x18 */ int mode;
};

extern struct Scroll G_0238e028;
extern int G_0238e050[];
extern int G_0238e05c[];
extern int G_0238e09c[];
extern int G_0238e0dc[];
extern int G_02349a1c[];
extern int G_0233b59c[];

extern int FUN_02320c7c(void);
extern void FUN_02320e14(int, void *, void *, int, int, int);
extern void FUN_02320e60(int, void *, void *, int, int, int, int);
extern void FUN_023210c8(void *, int, int, int, int);
extern int FUN_023213e8(void *, int);

void FUN_02321e70(void)
{
    int pressed;

    if (G_0238e028.active < 0)
        return;
    if (G_0238e028.mode == 2) {
        FUN_02320e14(FUN_02320c7c(), G_02349a1c, G_0233b59c, 4, G_0238e028.thumb, G_0238e028.pos);
        if (G_0238e028.pos <= 0x4c)
            FUN_023210c8(G_0238e09c, 0, G_0238e028.pos, 0, 0);
        if (G_0238e028.pos <= 0x4c)
            FUN_023210c8(G_0238e0dc, 0, G_0238e028.pos, 0, 0);
        pressed = FUN_023213e8(G_0238e050, 1);
        FUN_02320e60(FUN_02320c7c(), G_02349a1c, G_0233b59c, 2, 0, G_0238e028.pos, pressed);
        pressed = FUN_023213e8(G_0238e050, 0);
        FUN_02320e60(FUN_02320c7c(), G_02349a1c, G_0233b59c, 3, 0, G_0238e028.pos, pressed);
    }
    FUN_023210c8(G_0238e05c, 0, G_0238e028.pos + G_0238e028.bodyOfs, 0, 0);
    FUN_02320e14(FUN_02320c7c(), G_02349a1c, G_0233b59c, 1, 0, G_0238e028.pos + G_0238e028.edgeOfs);
    FUN_02320e14(FUN_02320c7c(), G_02349a1c, G_0233b59c, 0, 0, G_0238e028.pos + G_0238e028.bodyOfs);
}
