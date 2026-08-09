//cpp
// decomp: module=unk_autoload_0 addr=0x0232bcfc name=FUN_0232bcfc
#pragma thumb on

extern "C" {
typedef unsigned char u8;
typedef unsigned short u16;

extern u16 FUN_0232a4e8(void);
extern int FUN_0232a4c8(void);
extern void FUN_02337584(void *, const void *, int);
extern void FUN_0232c100(int, const void *, int, int, void (*)(void));
extern int FUN_0232b794(const void *, const void *, int);
extern void FUN_0232a480(void);
extern void FUN_02329bd8(int);
extern void FUN_0232bd8c(void);
extern void FUN_0232bf8c(void);
extern int G_023bd814[];
extern char G_023bd864[];

struct Msg0232bcfc {
    u16 zero;
    u16 size;
    u8 value;
    u8 pad;
    u16 invalid;
    int arg;
    int unused;
    int handle;
};

void FUN_0232bcfc(void)
{
    Msg0232bcfc msg;
    msg.zero = 0;
    msg.size = 20;
    msg.value = FUN_0232a4e8();
    msg.invalid = 0xffff;
    msg.arg = G_023bd814[10];
    msg.handle = FUN_0232a4c8();
    G_023bd814[1] = msg.handle;

    if (FUN_0232a4e8() != 0) {
        FUN_02337584(&msg, (const void *)G_023bd814[13], 20);
        FUN_0232c100(13, (const void *)G_023bd814[13], 20, 1, FUN_0232bf8c);
        return;
    }

    if (FUN_0232b794(G_023bd864, &msg, 20) == 0) {
        FUN_0232a480();
        FUN_02329bd8(12);
        return;
    }
    if (G_023bd814[14] == 0) {
        FUN_0232bd8c();
    }
}
}
