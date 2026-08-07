// decomp: module=arm7 addr=0x022d69d0 name=FUN_022d69d0
// flags: -O4,s -noThumb
typedef struct Ctx69d0 {
    char pad[0x31c];
    int f31c;
    unsigned short f320;
} Ctx69d0;

extern Ctx69d0 *G_0380fff4;

extern void FUN_022d8bfc(void);
extern void FUN_022d7d30(void);
extern void FUN_022d875c(void);
extern void FUN_022d6d80(void);
extern void FUN_022d6c00(void);
extern void FUN_022d6e18(int a, unsigned short b);
extern void FUN_022da700(void);
extern void FUN_022dc0cc(void);
extern void FUN_022da490(void);
extern void FUN_022d77ec(void);

void FUN_022d69d0(void) {
    Ctx69d0 *c;
    FUN_022d8bfc();
    FUN_022d7d30();
    FUN_022d875c();
    FUN_022d6d80();
    FUN_022d6c00();
    c = G_0380fff4;
    FUN_022d6e18(c->f31c, c->f320);
    FUN_022da700();
    FUN_022dc0cc();
    FUN_022da490();
    FUN_022d77ec();
}
