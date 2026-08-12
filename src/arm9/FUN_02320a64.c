// decomp: module=unk_autoload_0 addr=0x02320a64 name=FUN_02320a64
#pragma thumb on

extern int FUN_023215d0(void);
extern void FUN_02321634(int, void *, void *, int);
extern int FUN_02322820(void);
extern void FUN_023216e0(void *, int);
extern int G_0236c860[];
extern int G_0236c7e0[];
extern int G_0236c820[];
extern int G_0233ba78[];

void FUN_02320a64(int a)
{
    FUN_02321634(FUN_023215d0(), G_0236c860, G_0233ba78, 0x6a);
    FUN_02321634(FUN_023215d0(), G_0236c7e0, G_0233ba78, 0x58);
    FUN_02321634(FUN_023215d0(), G_0236c820, G_0233ba78, 0x59);
    G_0236c860[0x40 / 4] = 0;
    G_0236c860[0x44 / 4] = 0;
    FUN_023216e0(G_0236c860, FUN_02322820());
    if (a == 2) {
        G_0236c860[0x40 / 4] = 0xa;
        G_0236c860[0x44 / 4] = 1;
    }
}
