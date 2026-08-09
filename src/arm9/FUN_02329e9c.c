// decomp: module=unk_autoload_0 addr=0x02329e9c name=FUN_02329e9c
#pragma thumb on

typedef struct Q {
    unsigned int f0;
    unsigned short f4;
    unsigned short f6;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned char fc;
    unsigned char fd;
} Q;

typedef struct P {
    unsigned char pad0[4];
    unsigned short f4;
    unsigned char pad1[0x18 - 6];
    Q *f18;
    unsigned char pad2[0x24 - 0x1c];
    unsigned int f24;
} P;

#define G ((P *)0x023bd60c)

void FUN_02329e9c(void)
{
    P *p = G;

    p->f18->f0 = p->f24;
    p->f18->f4 = p->f4;
    p->f18->f6 = 0x14;
    p->f18->f8 = 0xff;
    p->f18->f9 = 0xff;
    p->f18->fa = 0xff;
    p->f18->fb = 0xff;
    p->f18->fc = 0xff;
    p->f18->fd = 0xff;
}
