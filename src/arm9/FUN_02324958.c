// decomp: module=unk_autoload_0 addr=0x02324958 name=FUN_02324958
// flags: -O4,s

// Per-frame step of the picker's two-phase transition. Phase one ramps the
// sub screen's blend over 16 frames (and scrolls by 4 each frame), then sets
// up the sub BG layers. Phase two ramps the main screen for 16 frames, then
// fades both screens over the next 16. Returns 1 once phase two reaches 32.

typedef unsigned short u16;

struct Picker {
    char pad00[0xc];
    int f0c;
    int f10;
    int f14;
    int f18;
};

extern struct Picker G_0239be54;

extern unsigned short FUN_02322884(int, int);
extern unsigned short FUN_02322894(int, int);
extern void FUN_02336428(unsigned int *, unsigned int, unsigned int,
                         unsigned int, unsigned int);
extern void FUN_023224b4(void);
extern void FUN_0232234c(void);
extern void FUN_02322004(void);
extern void FUN_02325040(void);

#define REG_DISPCNT     (*(volatile unsigned int *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile unsigned int *)0x04001000)
#define REG_DB_BG1CNT   (*(volatile u16 *)0x0400100a)
#define REG_04001012    (*(volatile unsigned int *)0x04001012)

int FUN_02324958(void)
{
    unsigned int a;
    unsigned int b;
    int t;
    int n;

    if (G_0239be54.f0c < 0x10) {
        G_0239be54.f0c++;
        G_0239be54.f10 += 4;
        REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1800;
        a = FUN_02322884(G_0239be54.f0c, 0x10);
        b = FUN_02322894(G_0239be54.f0c, 0x10);
        FUN_02336428((unsigned int *)0x04001050, 0, 8, b, a);
        if (G_0239be54.f0c == 0x10) {
            G_0239be54.f14 = 0;
            REG_DB_BG1CNT = (u16)((REG_DB_BG1CNT & 0x43) | 0x4110);
            REG_04001012 = 0x00190011;
            REG_DB_BG1CNT = (u16)((REG_DB_BG1CNT & ~3) | 3);
            FUN_023224b4();
        }
    } else {
        t = ++G_0239be54.f14;
        if (t < 0x10) {
            G_0239be54.f18 = -(t * 2);
            REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0xd00;
            a = FUN_02322884(G_0239be54.f14, 0x10);
            b = FUN_02322894(G_0239be54.f14, 0x10);
            FUN_02336428((unsigned int *)0x04000050, 4, 8, b, a);
        } else {
            REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x900;
            REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0xa00;
            n = t - 0x10;
            a = FUN_02322884(n, 0x10);
            b = FUN_02322894(n, 0x10);
            FUN_02336428((unsigned int *)0x04000050, 8, 1, b, a);
            a = FUN_02322884(n, 0x10);
            b = FUN_02322894(n, 0x10);
            FUN_02336428((unsigned int *)0x04001050, 8, 2, b, a);
        }
    }
    FUN_0232234c();
    FUN_02322004();
    FUN_02325040();
    if (G_0239be54.f14 == 0x20)
        return 1;
    return 0;
}
