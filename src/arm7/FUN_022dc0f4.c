// decomp: module=arm7 addr=0x022dc0f4 name=FUN_022dc0f4
// flags: -O4,s -noThumb
//
// Applies a whole MAC configuration block field by field, OR-ing every
// setter's error code together. The caller's status halfword is primed with 1
// up front, which doubles as the return value when the state machine at
// +0x34c is not in state 0x10.

extern int FUN_022d6e98(void *mac);
extern int FUN_022d6ef8(unsigned int v);
extern int FUN_022d6f2c(unsigned int v);
extern int FUN_022d6f6c(unsigned int v);
extern int FUN_022d6fec(unsigned int v);
extern int FUN_022d7020(unsigned int v);
extern int FUN_022d70c0(unsigned int v);
extern int FUN_022d70e4(void *p);
extern int FUN_022d7144(unsigned int v);
extern int FUN_022d717c(unsigned int v);
extern int FUN_022d71b4(unsigned int v);
extern int FUN_022d71ec(unsigned int v, int flag);
extern int FUN_022d729c(void *p);
extern int FUN_022d72cc(unsigned int v);
extern int FUN_022d7374(unsigned int v);

typedef struct Cfgc0f4 {
    char pad0[0x10];
    unsigned char f10[6];
    unsigned short f16;
    unsigned short f18;
    char pad1[2];
    unsigned short f1c;
    unsigned short f1e;
    unsigned short f20;
    unsigned short f22;
    unsigned char f24[0x50];
    unsigned short f74;
    unsigned short f76;
    unsigned short f78;
    unsigned short f7a;
    unsigned char f7c[0x20];
    unsigned short f9c;
    unsigned short f9e;
} Cfgc0f4;

typedef struct Blkc0f4 {
    char pad[0x4c];
    unsigned short f4c;
} Blkc0f4;

int FUN_022dc0f4(Cfgc0f4 *cfg, unsigned short *status)
{
    int r;

    status[1] = 1;
    if (((Blkc0f4 *)(*(char **)0x0380fff4 + 0x300))->f4c != 0x10) {
        return 1;
    }
    r = FUN_022d6e98(cfg->f10);
    r |= FUN_022d6ef8(cfg->f16);
    r |= FUN_022d6f2c(cfg->f18);
    r |= FUN_022d6f6c(cfg->f1c);
    r |= FUN_022d6fec(cfg->f1e);
    r |= FUN_022d7020(cfg->f20);
    r |= FUN_022d70c0(cfg->f22);
    r |= FUN_022d70e4(cfg->f24);
    r |= FUN_022d7144(cfg->f74);
    r |= FUN_022d717c(cfg->f76);
    r |= FUN_022d71b4(cfg->f78);
    r |= FUN_022d71ec(cfg->f7a, 0);
    r |= FUN_022d729c(cfg->f7c);
    r |= FUN_022d72cc(cfg->f9c);
    r |= FUN_022d7374(cfg->f9e);
    return r;
}
