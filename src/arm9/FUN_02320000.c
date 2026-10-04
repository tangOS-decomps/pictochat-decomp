// decomp: module=unk_autoload_0 addr=0x02320000 name=FUN_02320000

// Application main: brings up the heap, alarms, VRAM/OAM/palette clears,
// the V-blank handler and IRQs, initialises every subsystem, applies the
// touch-panel calibration from the user settings block, then runs the
// per-frame loop until the state machine reports exit (1).

typedef struct TPCalib {
    unsigned short x1;
    unsigned short y1;
    unsigned char dx1;
    unsigned char dy1;
    unsigned short x2;
    unsigned short y2;
    unsigned char dx2;
    unsigned char dy2;
} TPCalib;

extern char G_02339f1c[];
extern char G_0236a1a8[];
extern char G_0236a1d4[];
extern struct { int f0; int f4; } G_0236a1a0;

extern void FUN_0232d108(void *);
extern void FUN_02331554(void);
extern void FUN_02331c10(void);
extern void FUN_02331d84(void);
extern void FUN_02322d8c(void);
extern void FUN_02331dd4(void *);
extern void FUN_02336234(void);
extern void FUN_02331ea8(void *, unsigned long long, void (*)(void *), void *);
extern void FUN_02338c74(void);
extern void FUN_0233702c(int);
extern void FUN_0233746c(int, void *, int);
extern void FUN_02337194(void);
extern void FUN_02330728(int, void (*)(void));
extern void FUN_023307d4(int);
extern void FUN_0233206c(void);
extern void FUN_02336310(int);
extern void FUN_02339908(void);
extern void FUN_02322530(void);
extern void FUN_0232d3c8(void);
extern void FUN_02322554(void);
extern void FUN_0232270c(void);
extern void FUN_0232d260(int);
extern void FUN_02331ef0(void *);
extern void FUN_02322c18(void);
extern int FUN_0232d168(void);
extern void FUN_02322940(void);
extern void FUN_02321be0(void);
extern void FUN_02321c70(void);
extern void FUN_02320938(void);
extern void FUN_023202b0(int);
extern void FUN_0233219c(void *);
extern void FUN_02322c1c(void);
extern void FUN_02338df8(void *, unsigned short, unsigned short, unsigned char,
                         unsigned char, unsigned short, unsigned short,
                         unsigned char, unsigned char);
extern void FUN_02338cbc(void *);
extern void FUN_02321310(void);
extern void FUN_02320b9c(void);
extern void *FUN_023215d0(void);
extern void *FUN_023215e4(void);
extern void FUN_02321770(void *);
extern void FUN_02322b90(void);
extern void FUN_0232d250(void);
extern void FUN_0232d238(void);
extern void FUN_02320970(void);
extern void FUN_02320190(void);
extern void FUN_023201a8(void *);

static inline unsigned short EnableIrq(void)
{
    unsigned short prev = *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 1;
    return prev;
}

void FUN_02320000(void)
{
    unsigned char param[8];
    int first;
    int state;
    int r;
    TPCalib *c;

    FUN_0232d108(G_02339f1c);
    FUN_02331554();
    FUN_02331c10();
    FUN_02331d84();
    FUN_02322d8c();
    FUN_02331dd4(G_0236a1a8);
    FUN_02336234();
    FUN_02331ea8(G_0236a1a8, 0x2cbef, FUN_023201a8, 0);
    FUN_02338c74();
    FUN_0233702c(0x1ff);
    FUN_0233746c(0, (void *)0x06800000, 0xa4000);
    FUN_02337194();
    FUN_0233746c(0xc0, (void *)0x07000000, 0x400);
    FUN_0233746c(0, (void *)0x05000000, 0x400);
    FUN_02330728(1, FUN_02320190);
    FUN_023307d4(1);
    EnableIrq();
    FUN_0233206c();
    FUN_02336310(1);
    FUN_02339908();
    FUN_02322530();
    FUN_0232d3c8();
    FUN_02322554();
    FUN_0232270c();
    FUN_0232d260(0x10000);
    FUN_02331ef0(G_0236a1a8);
    FUN_02322c18();
    FUN_0232d168();
    FUN_02322940();
    FUN_02321be0();
    FUN_02321c70();
    FUN_02320938();
    FUN_023202b0(0);
    G_0236a1a0.f4 = 0;
    state = 2;
    first = 1;
    FUN_0233219c(G_0236a1d4);
    FUN_02322c1c();
    c = (TPCalib *)0x02fffcd8;
    FUN_02338df8(param, c->x1, c->y1, c->dx1, c->dy1, c->x2, c->y2, c->dx2, c->dy2);
    FUN_02338cbc(param);
    FUN_02321310();
    for (;;) {
        FUN_02320b9c();
        FUN_02321770(FUN_023215d0());
        FUN_02321770(FUN_023215e4());
        FUN_02322b90();
        r = FUN_0232d168();
        if (r == 1)
            return;
        if (r >= 2) {
            FUN_023202b0(r);
            first = 1;
            state = 0;
        }
        if (first && state) {
            if (state == 2)
                FUN_0232d250();
            first = 0;
        }
        switch (state) {
        case 1:
        case 2:
        case 3:
            FUN_0232d238();
            break;
        }
        FUN_02320970();
    }
}
