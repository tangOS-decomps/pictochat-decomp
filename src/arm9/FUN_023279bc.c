// decomp: module=unk_autoload_0 addr=0x023279bc name=FUN_023279bc

// One-shot boot of the chat screen: clears the shared state block, wipes the
// three VRAM regions it draws into, programs the capture/blend register, then
// registers the four screen handlers and their per-screen data before handing
// control to the first one.

typedef unsigned short u16;

extern char G_0239fe78[];
extern char G_0239fe80[];
extern char G_023488e4[];      /* start of the second region */
extern char G_endB_02348ae4[]; /* one past its end */
extern char G_02348d24[];
extern char G_023486e4[];      /* start of the first region */
extern char G_endA_023488e4[]; /* one past its end */
extern char G_02348ae4[];      /* per-slot table */
extern char G_0233b4ac[];
extern char G_02348704[];
extern char G_023464e4[];
extern char G_02346ce4[];
extern char G_0235ed70[];
extern char G_02349a1c[];
extern char G_023a060c[];
extern char G_0233b904[];
extern char G_023a064c[];
extern char G_023a068c[];
extern char G_023a06cc[];
extern char G_023a0098[];

struct State {
    char pad00[0x20];
    int f20;    /* 0x20 */
};

extern struct State G_0239fe68;

#define REG_DISPCAPCNT (*(volatile u16 *)0x04001008)
#define REG_04001010   (*(volatile int *)0x04001010)

extern void FUN_0233746c(int, void *, int);
extern void FUN_023234c0(void);
extern void FUN_0232517c(void *);
extern void FUN_02336880(void *, int, int);
extern int FUN_02322870(void);
extern void FUN_02328da8(void);
extern void FUN_02336800(void *, int, int);
extern void FUN_023369fc(void *, int, int);
extern void *FUN_02320c7c(void);
extern void FUN_02320ac8(void *);
extern void FUN_02320afc(void *, void *);
extern void *FUN_023215e4(void);
extern void FUN_02321600(void *, int);
extern void FUN_02321664(void *, void *, void *, int);
extern int FUN_02322820(void);
extern void FUN_023216e0(void *, int);
extern void FUN_02321634(void *, void *, void *, int);
extern int FUN_02321d04(int);
extern void FUN_023274b4(void);
extern void FUN_0232575c(void);
extern void FUN_0232571c(void *);
extern void FUN_02321df4(void);
extern void FUN_02321e24(void *);

void FUN_023279bc(void)
{
    FUN_0233746c(0, G_0239fe78, 0x20);
    FUN_023234c0();
    G_0239fe68.f20 = -1;
    FUN_0232517c(G_0239fe80);
    FUN_02336880(G_023488e4, 0, G_endB_02348ae4 - G_023488e4);
    FUN_02336880(G_02348d24, 0x40, 0x20);
    FUN_02322870();
    FUN_02328da8();
    FUN_02336800(G_023486e4, 0, G_endA_023488e4 - G_023486e4);
    FUN_02336800(G_0233b4ac, 0, 2);
    FUN_02336800(G_02348704, 5 << 6, 0x16);
    FUN_02336800(&G_02348ae4[FUN_02322870() * 16] + 6, 0x156, 0xa);
    REG_DISPCAPCNT = (u16)((REG_DISPCAPCNT & 0x43) | 4);
    FUN_023369fc(G_023464e4, 0, G_02346ce4 - G_023464e4);
    REG_04001010 = 0;
    FUN_02320ac8(FUN_02320c7c());
    FUN_02320afc(FUN_02320c7c(), G_0235ed70);
    FUN_02320afc(FUN_02320c7c(), G_02349a1c);
    FUN_02321600(FUN_023215e4(), *(int *)((char *)FUN_02320c7c() + 0x62c));
    FUN_02321664(FUN_023215e4(), G_023a060c, G_0233b904, 0);
    FUN_023216e0(G_023a060c, FUN_02322820());
    FUN_02321634(FUN_023215e4(), G_023a064c, G_0233b904, 3);
    FUN_023216e0(G_023a064c, FUN_02321d04(0x1b));
    FUN_02321634(FUN_023215e4(), G_023a068c, G_0233b904, 3);
    FUN_02321664(FUN_023215e4(), G_023a06cc, G_0233b904, 5);
    FUN_023274b4();
    FUN_0232575c();
    FUN_0232571c(G_023a0098);
    FUN_02321df4();
    FUN_02321e24(FUN_023215e4());
}
