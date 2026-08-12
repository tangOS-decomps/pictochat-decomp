// decomp: module=unk_autoload_0 addr=0x02332c04 name=FUN_02332c04
#pragma thumb on

extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern void FUN_02332c68(void *);
extern void FUN_02330da0(void *, void *, void *, void *, int, int);
extern void FUN_02330fb4(void *);
extern void FUN_02332c74(void *);
extern int G_023c14e8;
extern int G_023c14ec;
extern unsigned char G_023c1910[];

void FUN_02332c04(char *owner)
{
    int state = FUN_02332080();

    if (G_023c14e8 == 0) {
        G_023c14e8 = (int)owner;
        FUN_02332c68(owner + 0xc4);
        FUN_02332c68(&G_023c14ec);
        *(int *)(owner + 0xc0) = 0;
        FUN_02330da0(owner, FUN_02332c74, owner, G_023c1910, 0x400, 0x14);
        FUN_02330fb4(owner);
    }

    FUN_02332094(state);
}
