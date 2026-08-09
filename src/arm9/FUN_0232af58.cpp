//cpp
// decomp: module=unk_autoload_0 addr=0x0232af58 name=FUN_0232af58
// verify: python tools/match.py --c src/arm9/FUN_0232af58.cpp --func FUN_0232af58 --addr 0x0232af58 --size 0xb4 --module unk_autoload_0 --version 2.0/sp1

extern "C" {
typedef unsigned short u16;

int FUN_0232981c(void);
void FUN_02329734(void);
void FUN_0232acb4(void *);
void FUN_0232acb8(void *);
void FUN_0232acd4(void *);
void FUN_0232acd8(void *);
void FUN_02329b2c(void *, int);
void FUN_02329bd8(int);

struct Global_023bd698 {
    char pad00[0x30];
    int field30;
    char pad34[0x14];
    int field48;
};

extern Global_023bd698 G_023bd698;

void FUN_0232af58(void *arg)
{
    char *p = (char *)arg;
    u16 state;

    if (FUN_0232981c() != 0) {
        return;
    }

    state = *(u16 *)(p + 2);
    if (state == 0 && *(u16 *)(p + 8) == 9 && G_023bd698.field30 != 0) {
        FUN_02329734();
        return;
    }

    if (state == 0) {
        switch (*(u16 *)(p + 8)) {
        case 6:
            FUN_0232acb4(arg);
            return;
        case 7:
            FUN_0232acb8(arg);
            return;
        case 8:
            FUN_0232acd4(arg);
            return;
        case 9:
            FUN_0232acd8(arg);
            return;
        default:
            FUN_02329bd8(12);
            return;
        }
    }

    if (state == 1) {
        if (G_023bd698.field48 != 0) {
            FUN_02329b2c((void *)0x0232b321, 0);
        } else {
            FUN_02329bd8(1);
        }
        return;
    }
    if (state == 12) {
        FUN_02329bd8(13);
        return;
    }
    FUN_02329bd8(12);
}
}
